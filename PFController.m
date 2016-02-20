//
//  PFController.m
//  PagesFontSetter
//
//  Created by Yung-Luen Lan on 5/6/09.
//  Copyright 2009 yllan.org. All rights reserved.
//

#import "PFController.h"
#import <ScriptingBridge/ScriptingBridge.h>
#import "Pages.h"

NSUInteger decodeSurrogate(unichar a, unichar b)
{
    NSUInteger result = 0x010000;
    result += (a - 0xD800) * 0x400 + (b - 0xDC00);
    return result;
}

BOOL isCJK(NSUInteger codepoint) 
{
    // Punct & Radicals
    if (codepoint >= 0x2e80 && codepoint <= 0x33ff) return YES;
        
    // Fullwidth Latin Characters
    if (codepoint >= 0xff00 && codepoint <= 0xffef) return YES;
    
    // CJK Unified Ideographs & CJK Unified Ideographs Extension A
    if (codepoint >= 0x4e00 && codepoint <= 0x9fbb) return YES;

    // CJK Compatibility Ideographs
    if (codepoint >= 0xf900 && codepoint <= 0xfad9) return YES;
                    
    // CJK Unified Ideographs Extension B
    if (codepoint >= 0x20000 && codepoint <= 0x2a6d6) return YES;
                        
    // CJK Compatibility Supplement
    if (codepoint >= 0x2f8000 && codepoint <= 0x2fa1d) return YES;
    
    return NO;
}

unichar unicharOfPagesCharacter(PagesCharacter *c)
{
    return [(NSString *)[c get] characterAtIndex: 0];
}

BOOL isFirstSurrogate(PagesCharacter *ch)
{
    unichar c = unicharOfPagesCharacter(ch);
    return (c >= 0xD800 && c <= 0xDBFF);
}

BOOL isSecondSurrogate(PagesCharacter *ch)
{
    unichar c = unicharOfPagesCharacter(ch);
    return (c >= 0xDC00 && c <= 0xDFFF);
}

BOOL isSurrogate(PagesCharacter *c)
{
    return isFirstSurrogate(c) || isSecondSurrogate(c);
}

@implementation PFController
@synthesize latinFont = _latinFont;
@synthesize cjkFont = _cjkFont;
@synthesize needSetLatinFont = _needSetLatinFont;
@synthesize needSetCJKFont = _needSetCJKFont;
@synthesize documentLabel = _documentLabel;
@synthesize progressBar = _progressBar;
@synthesize progressWindow = _progressWindow;
@synthesize mainWindow = _mainWindow;

- (void) awakeFromNib
{
    self.latinFont = [[NSUserDefaults standardUserDefaults] objectForKey: @"LatinFontName"] ?: @"Times";
    self.cjkFont = [[NSUserDefaults standardUserDefaults] objectForKey: @"CJKFontName"] ?: @"Arial Unicode MS";
    self.needSetCJKFont = YES;
    self.needSetLatinFont = NO;
}

- (void) setProgressMax: (NSNumber *)n
{
    [_progressBar setMaxValue: [n doubleValue]];
}

- (void) setProgress: (NSNumber *)n
{
    [_progressBar setDoubleValue: [n doubleValue]];
}

- (void) setForDocument: (PagesDocument *)document
{
    NSAutoreleasePool *pool = [NSAutoreleasePool new];
    PagesRichText *text = document.bodyText;
    NSUInteger charactersCount = [[text characters] count];
    NSUInteger i;
    
    [self performSelectorOnMainThread: @selector(setProgressMax:) withObject: [NSNumber numberWithUnsignedInteger: charactersCount] waitUntilDone: NO];
    
    PagesCharacter *highSurrogateChar = nil;
    for (i = 0; i < charactersCount; i++) {
        [self performSelectorOnMainThread: @selector(setProgress:) withObject: [NSNumber numberWithUnsignedInteger: i] waitUntilDone: NO];
        PagesCharacter *character = [[text characters] objectAtIndex: i];
        NSUInteger codepoint = unicharOfPagesCharacter(character);
        
        if (isFirstSurrogate(character)) {
            highSurrogateChar = character;
            continue;
        } 
        
        if (isSecondSurrogate(character)) 
            codepoint = decodeSurrogate(unicharOfPagesCharacter(highSurrogateChar), unicharOfPagesCharacter(character));
        
        PagesWord *containedLatinWord = nil;
        if (!isCJK(codepoint) && [[character words] count] == 1) {
            containedLatinWord = [[character words] objectAtIndex: 0];
            i += [containedLatinWord.characters count] - 1;
        }
        
        if (isCJK(codepoint) && !self.needSetCJKFont) continue;
        if (!isCJK(codepoint) && !self.needSetLatinFont) continue;
        
        if (isCJK(codepoint)) {
            character.font = self.cjkFont;
            highSurrogateChar.font = self.cjkFont;
        } else {
            character.font = self.latinFont;
            highSurrogateChar.font = self.latinFont;
            containedLatinWord.font = self.latinFont;
        }
        highSurrogateChar = nil;
    }
    [pool drain];
}

- (void) allDocumentsForApp: (PagesApplication *)pages
{
    NSAutoreleasePool *pool = [NSAutoreleasePool new];
    int i = 0;
    for (PagesDocument *document in [pages documents]) {
        i++;
        [_documentLabel performSelectorOnMainThread: @selector(setStringValue:) withObject: [NSString stringWithFormat: @"%d/%d %@", i, [[pages documents] count], document.name] waitUntilDone: NO];
        [self setForDocument: document];
    }
    [NSApp performSelectorOnMainThread: @selector(endSheet:) withObject: _progressWindow waitUntilDone: YES];
    [_progressWindow performSelectorOnMainThread: @selector(orderOut:) withObject: self waitUntilDone: YES];
    [pool drain];
}

- (IBAction) setAllOpenedDocuments: (id)sender
{
    [NSApp beginSheet: _progressWindow modalForWindow: _mainWindow modalDelegate: self didEndSelector: NULL contextInfo: nil];
    PagesApplication *pages = [SBApplication applicationWithBundleIdentifier: @"com.apple.iWork.Pages"];
    
    [self performSelectorInBackground: @selector(allDocumentsForApp:) withObject: pages];
}

- (IBAction) setClipboard: (id)sender
{
    NSPasteboard *pb = [NSPasteboard generalPasteboard];
    NSArray *types = [NSArray arrayWithObjects: NSRTFDPboardType, NSRTFPboardType, NSStringPboardType, nil];
//    NSDictionary *backupPBContents = [NSMutableDictionary dictionary];
//    
//    for (NSString *type in [pb types]) {
//        [backupPBContents setValue: [pb dataForType: type] forKey: type];
//    }
    
    NSString *bestType = [pb availableTypeFromArray: types];

    if ([bestType isEqualToString: NSRTFDPboardType] || [bestType isEqualToString: NSRTFPboardType] || [bestType isEqualToString: NSStringPboardType]) {
        NSData *data = [pb dataForType: bestType];
        NSAttributedString *attrString;
        if ([bestType isEqualToString: NSStringPboardType])
            attrString = [[[NSAttributedString alloc] initWithString: [pb stringForType: NSStringPboardType]] autorelease];
        else if ([bestType isEqualToString: NSRTFDPboardType])
            attrString = [[[NSAttributedString alloc] initWithRTFD: data documentAttributes: NULL] autorelease];
        else
            attrString = [[[NSAttributedString alloc] initWithRTF: data documentAttributes: NULL] autorelease];

        NSMutableAttributedString *mutableAttrString = [[[NSMutableAttributedString alloc] initWithAttributedString: attrString] autorelease];
        NSString *plainString = [mutableAttrString string];
        NSUInteger cursor = 0;
        
        while (cursor < [plainString length]) {
            NSRange range = [plainString rangeOfComposedCharacterSequenceAtIndex: cursor];
            NSUInteger codepoint = 0;
            if (range.length == 1) {
                codepoint = [plainString characterAtIndex: cursor];
            } else if (range.length == 2) { // Surrogate Pair
                codepoint = decodeSurrogate([plainString characterAtIndex: cursor], [plainString characterAtIndex: cursor + 1]);
            }
            
            if ((isCJK(codepoint) && self.needSetCJKFont) || (!isCJK(codepoint) && self.needSetLatinFont)) {
                NSMutableDictionary *attrDictionary = [NSMutableDictionary dictionaryWithDictionary: [mutableAttrString attributesAtIndex: cursor effectiveRange: NULL]];
                NSFont *font = [attrDictionary valueForKey: NSFontAttributeName];
                NSFont *replacedFont = [NSFont fontWithName: isCJK(codepoint) ? self.cjkFont : self.latinFont size: font ? [font pointSize] : 12.0];
                [attrDictionary setValue: replacedFont forKey: NSFontAttributeName];
                [mutableAttrString setAttributes: attrDictionary range: range];
            }
            cursor += range.length;
        }
        
        [pb declareTypes: types owner: self];
        
        [pb setData: [mutableAttrString RTFDFromRange: NSMakeRange(0, [plainString length]) documentAttributes: nil] forType: NSRTFDPboardType];
        [pb setData: [mutableAttrString RTFFromRange: NSMakeRange(0, [plainString length]) documentAttributes: nil] forType: NSRTFPboardType];
        [pb setString: plainString forType: NSStringPboardType];
    } else {
        NSBeep();
    }
}

@end

//
//  PFController.h
//  PagesFontSetter
//
//  Created by Yung-Luen Lan on 5/6/09.
//  Copyright 2009 yllan.org. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface PFController : NSObject {
    NSString *_latinFont;
    NSString *_cjkFont;
    BOOL _needSetLatinFont;
    BOOL _needSetCJKFont;
    
    NSTextField *_documentLabel;
    NSProgressIndicator *_progressBar;
    NSWindow *_progressWindow;
}

@property (nonatomic, copy) NSString *latinFont;
@property (nonatomic, copy) NSString *cjkFont;

@property (nonatomic, retain) IBOutlet NSTextField *documentLabel;
@property (nonatomic, retain) IBOutlet NSProgressIndicator *progressBar;
@property (nonatomic, retain) IBOutlet NSWindow *progressWindow;

@property BOOL needSetLatinFont;
@property BOOL needSetCJKFont;

- (IBAction) setAllOpenedDocuments: (id)sender;

@end

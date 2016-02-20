/*
 * Pages.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class PagesApplication, PagesDocument, PagesWindow, PagesRichText, PagesCharacter, PagesParagraph, PagesWord, PagesIWorkContainer, PagesIWorkItem, PagesAudioClip, PagesShape, PagesChart, PagesImage, PagesGroup, PagesLine, PagesMovie, PagesTable, PagesTextItem, PagesRange, PagesCell, PagesRow, PagesColumn, PagesTemplate, PagesSection, PagesPage, PagesPlaceholderText;

enum PagesSaveOptions {
	PagesSaveOptionsYes = 'yes ' /* Save the file. */,
	PagesSaveOptionsNo = 'no  ' /* Do not save the file. */,
	PagesSaveOptionsAsk = 'ask ' /* Ask the user whether or not to save the file. */
};
typedef enum PagesSaveOptions PagesSaveOptions;

enum PagesPrintingErrorHandling {
	PagesPrintingErrorHandlingStandard = 'lwst' /* Standard PostScript error handling */,
	PagesPrintingErrorHandlingDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum PagesPrintingErrorHandling PagesPrintingErrorHandling;

enum PagesTAVT {
	PagesTAVTBottom = 'avbt' /* Right-align content. */,
	PagesTAVTCenter = 'actr' /* Center-align content. */,
	PagesTAVTTop = 'avtp' /* Top-align content. */
};
typedef enum PagesTAVT PagesTAVT;

enum PagesTAHT {
	PagesTAHTAutoAlign = 'aaut' /* Auto-align based on content type. */,
	PagesTAHTCenter = 'actr' /* Center-align content. */,
	PagesTAHTJustify = 'ajst' /* Fully justify (left and right) content. */,
	PagesTAHTLeft = 'alft' /* Left-align content. */,
	PagesTAHTRight = 'arit' /* Right-align content. */
};
typedef enum PagesTAHT PagesTAHT;

enum PagesNMSD {
	PagesNMSDAscending = 'ascn' /* Sort in increasing value order */,
	PagesNMSDDescending = 'dscn' /* Sort in decreasing value order */
};
typedef enum PagesNMSD PagesNMSD;

enum PagesNMCT {
	PagesNMCTAutomatic = 'faut' /* Automatic format */,
	PagesNMCTCheckbox = 'fcch' /* Checkbox control format (Numbers only) */,
	PagesNMCTCurrency = 'fcur' /* Currency number format */,
	PagesNMCTDateAndTime = 'fdtm' /* Date and time format */,
	PagesNMCTFraction = 'ffra' /* Fraction number format */,
	PagesNMCTNumber = 'nmbr' /* Decimal number format */,
	PagesNMCTPercent = 'fper' /* Percentage number format */,
	PagesNMCTPopUpMenu = 'fcpp' /* Pop-up menu control format (Numbers only) */,
	PagesNMCTScientific = 'fsci' /* Scientific notation format */,
	PagesNMCTSlider = 'fcsl' /* Slider control format (Numbers only) */,
	PagesNMCTStepper = 'fcst' /* Stepper control format (Numbers only) */,
	PagesNMCTText = 'ctxt' /* Text format */,
	PagesNMCTDuration = 'fdur' /* Duration format */,
	PagesNMCTRating = 'frat' /* Rating format. (Numbers only) */,
	PagesNMCTNumeralSystem = 'fcns' /* Numeral System */
};
typedef enum PagesNMCT PagesNMCT;

enum PagesItemFillOptions {
	PagesItemFillOptionsNoFill = 'fino' /*  */,
	PagesItemFillOptionsColorFill = 'fico' /*  */,
	PagesItemFillOptionsGradientFill = 'figr' /*  */,
	PagesItemFillOptionsAdvancedGradientFill = 'fiag' /*  */,
	PagesItemFillOptionsImageFill = 'fiim' /*  */,
	PagesItemFillOptionsAdvancedImageFill = 'fiai' /*  */
};
typedef enum PagesItemFillOptions PagesItemFillOptions;

enum PagesPlaybackRepetitionMethod {
	PagesPlaybackRepetitionMethodNone = 'mvrn' /*  */,
	PagesPlaybackRepetitionMethodLoop = 'mvlp' /*  */,
	PagesPlaybackRepetitionMethodLoopBackAndForth = 'mvbf' /*  */
};
typedef enum PagesPlaybackRepetitionMethod PagesPlaybackRepetitionMethod;

enum PagesSaveableFileFormat {
	PagesSaveableFileFormatPagesFormat = 'Pgff' /* The Pages native file format */
};
typedef enum PagesSaveableFileFormat PagesSaveableFileFormat;

enum PagesExportFormat {
	PagesExportFormatEpub = 'Pepu' /* ePub */,
	PagesExportFormatUnformattedText = 'Ptxf' /* Plain text */,
	PagesExportFormatPDF = 'Ppdf' /* PDF */,
	PagesExportFormatMicrosoftWord = 'Pwrd' /* Microsoft Word */,
	PagesExportFormatPages09 = 'PPag' /* Pages 09 */
};
typedef enum PagesExportFormat PagesExportFormat;

enum PagesImageQuality {
	PagesImageQualityGood = 'PgP0' /* good quality */,
	PagesImageQualityBetter = 'PgP1' /* better quality */,
	PagesImageQualityBest = 'PgP2' /* best quality */
};
typedef enum PagesImageQuality PagesImageQuality;

@protocol PagesGenericMethods

- (void) closeSaving:(PagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(PagesSaveableFileFormat)as;  // Save a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy an object.
- (void) moveTo:(SBObject *)to;  // Move an object to a new location.
- (void) delete;  // Delete an object.

@end



/*
 * Standard Suite
 */

// The application's top-level scripting object.
@interface PagesApplication : SBApplication

- (SBElementArray<PagesDocument *> *) documents;
- (SBElementArray<PagesWindow *> *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the active application?
@property (copy, readonly) NSString *version;  // The version number of the application.

- (id) open:(id)x;  // Open a document.
- (void) print:(id)x withProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) quitSaving:(PagesSaveOptions)saving;  // Quit the application.
- (BOOL) exists:(id)x;  // Verify that an object exists.

@end

// A document.
@interface PagesDocument : SBObject <PagesGenericMethods>

@property (copy, readonly) NSString *name;  // Its name.
@property (readonly) BOOL modified;  // Has it been modified since the last save?
@property (copy, readonly) NSURL *file;  // Its location on disk, if it has one.

- (void) exportTo:(NSURL *)to as:(PagesExportFormat)as withProperties:(NSDictionary *)withProperties;  // Export a document to another file

@end

// A window.
@interface PagesWindow : SBObject <PagesGenericMethods>

@property (copy, readonly) NSString *name;  // The title of the window.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Does the window have a close button?
@property (readonly) BOOL miniaturizable;  // Does the window have a minimize button?
@property BOOL miniaturized;  // Is the window minimized right now?
@property (readonly) BOOL resizable;  // Can the window be resized?
@property BOOL visible;  // Is the window visible right now?
@property (readonly) BOOL zoomable;  // Does the window have a zoom button?
@property BOOL zoomed;  // Is the window zoomed right now?
@property (copy, readonly) PagesDocument *document;  // The document whose contents are displayed in the window.


@end



/*
 * iWork Text Suite
 */

// This provides the base rich text class for all iWork applications.
@interface PagesRichText : SBObject <PagesGenericMethods>

- (SBElementArray<PagesCharacter *> *) characters;
- (SBElementArray<PagesParagraph *> *) paragraphs;
- (SBElementArray<PagesWord *> *) words;

@property (copy) NSColor *color;  // The color of the font. Expressed as an RGB value consisting of a list of three color values from 0 to 65535. ex: Blue = {0, 0, 65535}.
@property (copy) NSString *font;  // The name of the font.  Can be the PostScript name, such as: “TimesNewRomanPS-ItalicMT”, or display name: “Times New Roman Italic”. TIP: Use the Font Book application get the information about a typeface.
@property NSInteger size;  // The size of the font.


@end

// One of some text's characters.
@interface PagesCharacter : PagesRichText


@end

// One of some text's paragraphs.
@interface PagesParagraph : PagesRichText

- (SBElementArray<PagesCharacter *> *) characters;
- (SBElementArray<PagesWord *> *) words;


@end

// One of some text's words.
@interface PagesWord : PagesRichText

- (SBElementArray<PagesCharacter *> *) characters;


@end



/*
 * iWork Suite
 */

// A container for iWork items
@interface PagesIWorkContainer : SBObject <PagesGenericMethods>

- (SBElementArray<PagesAudioClip *> *) audioClips;
- (SBElementArray<PagesChart *> *) charts;
- (SBElementArray<PagesImage *> *) images;
- (SBElementArray<PagesIWorkItem *> *) iWorkItems;
- (SBElementArray<PagesGroup *> *) groups;
- (SBElementArray<PagesLine *> *) lines;
- (SBElementArray<PagesMovie *> *) movies;
- (SBElementArray<PagesShape *> *) shapes;
- (SBElementArray<PagesTable *> *) tables;
- (SBElementArray<PagesTextItem *> *) textItems;


@end

// An item which supports formatting
@interface PagesIWorkItem : SBObject <PagesGenericMethods>

@property NSInteger height;  // The height of the iWork item.
@property BOOL locked;  // Whether the object is locked.
@property (copy, readonly) PagesIWorkContainer *parent;  // The iWork container containing this iWork item.
@property NSPoint position;  // The horizontal and vertical coordinates of the top left point of the iWork item.
@property NSInteger width;  // The width of the iWork item.


@end

// An audio clip
@interface PagesAudioClip : PagesIWorkItem

@property (copy) id fileName;  // The name of the audio file.
@property NSInteger clipVolume;  // The volume setting for the audio clip, from 0 (none) to 100 (full volume).
@property PagesPlaybackRepetitionMethod repetitionMethod;  // If or how the audio clip repeats.


@end

// A shape container
@interface PagesShape : PagesIWorkItem

@property (readonly) PagesItemFillOptions backgroundFillType;  // The background, if any, for the shape.
@property (copy) PagesRichText *objectText;  // The text contained within the shape.
@property BOOL reflectionShowing;  // Is the iWork item displaying a reflection?
@property NSInteger reflectionValue;  // The percentage of reflection of the iWork item, from 0 (none) to 100 (full).
@property NSInteger rotation;  // The rotation of the iWork item, in degrees from 0 to 359.
@property NSInteger opacity;  // The opacity of the object, in percent.


@end

// A chart
@interface PagesChart : PagesIWorkItem


@end

// An image container
@interface PagesImage : PagesIWorkItem

@property (copy) NSString *objectDescription;  // Text associated with the image, read aloud by VoiceOver.
@property (copy, readonly) NSURL *file;  // The image file.
@property (copy) id fileName;  // The name of the image file.
@property NSInteger opacity;  // The opacity of the object, in percent.
@property BOOL reflectionShowing;  // Is the iWork item displaying a reflection?
@property NSInteger reflectionValue;  // The percentage of reflection of the iWork item, from 0 (none) to 100 (full).
@property NSInteger rotation;  // The rotation of the iWork item, in degrees from 0 to 359.


@end

// A group container
@interface PagesGroup : PagesIWorkContainer

@property NSInteger height;  // The height of the iWork item.
@property (copy, readonly) PagesIWorkContainer *parent;  // The iWork container containing this iWork item.
@property NSPoint position;  // The horizontal and vertical coordinates of the top left point of the iWork item.
@property NSInteger width;  // The width of the iWork item.
@property NSInteger rotation;  // The rotation of the iWork item, in degrees from 0 to 359.


@end

// A line
@interface PagesLine : PagesIWorkItem

@property NSPoint endPoint;  // A list of two numbers indicating the horizontal and vertical position of the line ending point.
@property BOOL reflectionShowing;  // Is the iWork item displaying a reflection?
@property NSInteger reflectionValue;  // The percentage of reflection of the iWork item, from 0 (none) to 100 (full).
@property NSInteger rotation;  // The rotation of the iWork item, in degrees from 0 to 359.
@property NSPoint startPoint;  // A list of two numbers indicating the horizontal and vertical position of the line starting point.


@end

// A movie container
@interface PagesMovie : PagesIWorkItem

@property (copy) id fileName;  // The name of the movie file.
@property NSInteger movieVolume;  // The volume setting for the movie, from 0 (none) to 100 (full volume).
@property NSInteger opacity;  // The opacity of the object, in percent.
@property BOOL reflectionShowing;  // Is the iWork item displaying a reflection?
@property NSInteger reflectionValue;  // The percentage of reflection of the iWork item, from 0 (none) to 100 (full).
@property PagesPlaybackRepetitionMethod repetitionMethod;  // If or how the movie repeats.
@property NSInteger rotation;  // The rotation of the iWork item, in degrees from 0 to 359.


@end

// A table
@interface PagesTable : PagesIWorkItem

- (SBElementArray<PagesCell *> *) cells;
- (SBElementArray<PagesRow *> *) rows;
- (SBElementArray<PagesColumn *> *) columns;
- (SBElementArray<PagesRange *> *) ranges;

@property (copy) NSString *name;  // The item's name.
@property (copy, readonly) PagesRange *cellRange;  // The range describing every cell in the table.
@property (copy) PagesRange *selectionRange;  // The cells currently selected in the table.
@property NSInteger rowCount;  // The number of rows in the table.
@property NSInteger columnCount;  // The number of columns in the table.
@property NSInteger headerRowCount;  // The number of header rows in the table.
@property NSInteger headerColumnCount;  // The number of header columns in the table.
@property NSInteger footerRowCount;  // The number of footer rows in the table.

- (void) sortBy:(PagesColumn *)by direction:(PagesNMSD)direction inRows:(PagesRange *)inRows;  // Sort the rows of the table.

@end

// A text container
@interface PagesTextItem : PagesIWorkItem

@property (readonly) PagesItemFillOptions backgroundFillType;  // The background, if any, for the text item.
@property (copy) PagesRichText *objectText;  // The text contained within the text item.
@property NSInteger opacity;  // The opacity of the object, in percent.
@property BOOL reflectionShowing;  // Is the iWork item displaying a reflection?
@property NSInteger reflectionValue;  // The percentage of reflection of the iWork item, from 0 (none) to 100 (full).
@property NSInteger rotation;  // The rotation of the iWork item, in degrees from 0 to 359.


@end

// A range of cells in a table
@interface PagesRange : SBObject <PagesGenericMethods>

- (SBElementArray<PagesCell *> *) cells;
- (SBElementArray<PagesColumn *> *) columns;
- (SBElementArray<PagesRow *> *) rows;

@property (copy) NSString *fontName;  // The font of the range's cells.
@property double fontSize;  // The font size of the range's cells.
@property PagesNMCT format;  // The format of the range's cells.
@property PagesTAHT alignment;  // The horizontal alignment of content in the range's cells.
@property (copy, readonly) NSString *name;  // The range's coordinates.
@property (copy) NSColor *textColor;  // The text color of the range's cells.
@property BOOL textWrap;  // Whether text should wrap in the range's cells.
@property (copy) NSColor *backgroundColor;  // The background color of the range's cells.
@property PagesTAVT verticalAlignment;  // The vertical alignment of content in the range's cells.

- (void) clear;  // Clear the contents of a specified range of cells, including formatting and style.
- (void) merge;  // Merge a specified range of cells.
- (void) unmerge;  // Unmerge all merged cells in a specified range.

@end

// A cell in a table
@interface PagesCell : PagesRange

@property (copy, readonly) PagesColumn *column;  // The cell's column.
@property (copy, readonly) PagesRow *row;  // The cell's row.
@property (copy) id value;  // The actual value in the cell, or missing value if the cell is empty.
@property (copy, readonly) NSString *formattedValue;  // The formatted value in the cell, or missing value if the cell is empty.
@property (copy, readonly) NSString *formula;  // The formula in the cell, as text, e.g. =SUM(40+2). If the cell does not contain a formula, returns missing value. To set the value of a cell to a formula as text, use the value property.


@end

// A row of cells in a table
@interface PagesRow : PagesRange

@property (readonly) NSInteger address;  // The row's index in the table (e.g., the second row has address 2).
@property double height;  // The height of the row.


@end

// A column of cells in a table
@interface PagesColumn : PagesRange

@property (readonly) NSInteger address;  // The column's index in the table (e.g., the second column has address 2).
@property double width;  // The width of the column.


@end



/*
 * Pages Suite
 */

// The Pages application.
@interface PagesApplication (PagesSuite)

- (SBElementArray<PagesTemplate *> *) templates;

@end

// A Pages document.
@interface PagesDocument (PagesSuite)

- (SBElementArray<PagesAudioClip *> *) audioClips;
- (SBElementArray<PagesChart *> *) charts;
- (SBElementArray<PagesGroup *> *) groups;
- (SBElementArray<PagesImage *> *) images;
- (SBElementArray<PagesIWorkItem *> *) iWorkItems;
- (SBElementArray<PagesLine *> *) lines;
- (SBElementArray<PagesMovie *> *) movies;
- (SBElementArray<PagesPage *> *) pages;
- (SBElementArray<PagesSection *> *) sections;
- (SBElementArray<PagesShape *> *) shapes;
- (SBElementArray<PagesTable *> *) tables;
- (SBElementArray<PagesTextItem *> *) textItems;
- (SBElementArray<PagesPlaceholderText *> *) placeholderTexts;

- (NSString *) id;  // Document ID.
@property (copy, readonly) PagesTemplate *documentTemplate;  // The template assigned to the document.
@property (copy) PagesRichText *bodyText;  // The document body text.
@property (readonly) BOOL documentBody;  // Whether the document has body text.
@property (copy, readonly) PagesPage *currentPage;  // Current page of the document.

@end

// A styled document layout.
@interface PagesTemplate : SBObject <PagesGenericMethods>

- (NSString *) id;  // The identifier used by the application.
@property (copy, readonly) NSString *name;  // The localized name displayed to the user.


@end

// A section within a document.
@interface PagesSection : SBObject <PagesGenericMethods>

- (SBElementArray<PagesAudioClip *> *) audioClips;
- (SBElementArray<PagesChart *> *) charts;
- (SBElementArray<PagesGroup *> *) groups;
- (SBElementArray<PagesImage *> *) images;
- (SBElementArray<PagesIWorkItem *> *) iWorkItems;
- (SBElementArray<PagesLine *> *) lines;
- (SBElementArray<PagesMovie *> *) movies;
- (SBElementArray<PagesPage *> *) pages;
- (SBElementArray<PagesShape *> *) shapes;
- (SBElementArray<PagesTable *> *) tables;
- (SBElementArray<PagesTextItem *> *) textItems;

@property (copy) PagesRichText *bodyText;  // The section body text.


@end

// A page of the document.
@interface PagesPage : PagesIWorkContainer

@property (copy) PagesRichText *bodyText;  // The page body text.


@end

// This modifies the iWork rich text class for all Pages.
@interface PagesRichText (PagesSuite)

- (SBElementArray<PagesPlaceholderText *> *) placeholderTexts;

@end

// One of some text's paragraphs.
@interface PagesParagraph (PagesSuite)

- (SBElementArray<PagesPlaceholderText *> *) placeholderTexts;

@end

// One of some text's placeholders.
@interface PagesPlaceholderText : PagesRichText

@property (copy) NSString *tag;  // Its script tag.


@end


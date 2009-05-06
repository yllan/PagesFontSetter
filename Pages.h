/*
 * Pages.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class PagesItem, PagesApplication, PagesColor, PagesDocument, PagesWindow, PagesAttributeRun, PagesCharacter, PagesParagraph, PagesText, PagesWord, PagesApplication, PagesCapturedPage, PagesDocument, PagesLayer, PagesMasterPage, PagesPage, PagesPageSetup, PagesSection, PagesSelectionObject, PagesWindow, PagesGraphic, PagesChart, PagesImage, PagesImageBinary, PagesLine, PagesShape, PagesTable, PagesTextBox, PagesCharacter, PagesCharacterStyle, PagesInsertionPoint, PagesListLevel, PagesListStyle, PagesParagraph, PagesParagraphStyle, PagesTableAttachment, PagesText, PagesAttachment, PagesWord, PagesPrintSettings;

typedef enum {
	PagesSavoAsk = 'ask ' /* Ask the user whether or not to save the file. */,
	PagesSavoNo = 'no  ' /* Do not save the file. */,
	PagesSavoYes = 'yes ' /* Save the file. */
} PagesSavo;

typedef enum {
	PagesTSPKAnyPage = 'nxtP' /* The section starts on the next page after the previous section. */,
	PagesTSPKLeftPage = 'lftP' /* The section always starts on a left page. */,
	PagesTSPKRightPage = 'rgtP' /* The section always starts on a right page. */
} PagesTSPK;

typedef enum {
	PagesPPgOLandscape = 'pLnd' /* The page is oriented in landscape mode. */,
	PagesPPgOPortrait = 'pPor' /* The page is oriented in portrait mode. */
} PagesPPgO;

typedef enum {
	PagesTPNKContinuous = 'pnkC' /* Continue page numbers from previous section. */,
	PagesTPNKRestart = 'pnkR' /* Restart page numbers for the section. */
} PagesTPNK;

typedef enum {
	PagesTARUCentimeters = 'pUCm' /* Ruler units are in centimeters. */,
	PagesTARUInches = 'pUIn' /* Ruler units are in inches. */,
	PagesTARUPicas = 'pUPc' /* Ruler units are in picas. */,
	PagesTARUPoints = 'pUPx' /* Ruler units are in points. */
} PagesTARU;

typedef enum {
	PagesTIFTOriginal = 'orsz' /* Use the original size. Center the image and clip, if necessary, to the shape's frame. */,
	PagesTIFTScaleFill = 'sclt' /* Scale proportionally to fill the frame of the shape, clipping if necessary. */,
	PagesTIFTScaleFit = 'sclf' /* Scale proportionally to fit the frame of the shape. */,
	PagesTIFTStretch = 'strc' /* Scale proportionally and then fill the frame of the shape by stretching if necessary. */,
	PagesTIFTTile = 'tile' /* Render the image into the shape without scaling, starting with the top left corner, rendering multiple copies if necessary to fill the frame. */
} PagesTIFT;

typedef enum {
	PagesTDwPFixed = 'fixd' /* The object location is fixed on a page. */,
	PagesTDwPMaster = 'mstr' /* The object location is fixed on each page of a section. */,
	PagesTDwPMoving = 'move' /* The object location moves with the text around it as you type. */
} PagesTDwP;

typedef enum {
	PagesKCctArea_2d = 'are2' /* two-dimensional area chart. */,
	PagesKCctArea_3d = 'are3' /* three-dimensional area chart */,
	PagesKCctHorizontal_bar_2d = 'hbr2' /* two-dimensional horizontal bar chart */,
	PagesKCctHorizontal_bar_3d = 'hbr3' /* three-dimensional horizontal bar chart */,
	PagesKCctLine_2d = 'lin2' /*  two-dimensional line chart. */,
	PagesKCctLine_3d = 'lin3' /* three-dimensional line chart */,
	PagesKCctPie_2d = 'pie2' /* two-dimensional pie chart */,
	PagesKCctPie_3d = 'pie3' /* three-dimensional pie chart. */,
	PagesKCctScatterplot_2d = 'scp2' /* two-dimensional scatterplot chart */,
	PagesKCctStacked_area_2d = 'sar2' /* two-dimensional stacked area chart */,
	PagesKCctStacked_area_3d = 'sar3' /* three-dimensional stacked area chart */,
	PagesKCctStacked_horizontal_bar_2d = 'shb2' /* two-dimensional stacked horizontal bar chart */,
	PagesKCctStacked_horizontal_bar_3d = 'shb3' /* three-dimensional stacked horizontal bar chart */,
	PagesKCctStacked_vertical_bar_2d = 'svb2' /* two-dimensional stacked vertical bar chart */,
	PagesKCctStacked_vertical_bar_3d = 'svb3' /* three-dimensional stacked bar chart */,
	PagesKCctVertical_bar_2d = 'vbr2' /* two-dimensional vertical bar chart */,
	PagesKCctVertical_bar_3d = 'vbr3' /* three-dimensional vertical bar chart */
} PagesKCct;

typedef enum {
	PagesKCgbColumn = 'KCgc' /* group by column */,
	PagesKCgbRow = 'KCgr' /* group by row */
} PagesKCgb;

typedef enum {
	PagesTDSTArrow = 'arow' /* A polygon shape with an arrowhead at one end. */,
	PagesTDSTDiamond = 'dmnd' /* A diamond shape. */,
	PagesTDSTDoubleArrow = 'darw' /* A polygon shape with an arrowhead at opposite ends. */,
	PagesTDSTOval = 'oval' /* An oval shape. */,
	PagesTDSTPolygon = 'poly' /* A polygon shape. */,
	PagesTDSTQuote = 'qwot' /* A quote bubble shape. */,
	PagesTDSTRectangle = 'rect' /* A rectangle shape. */,
	PagesTDSTRightTriangle = 'rtrg' /* A right triangle shape. */,
	PagesTDSTRoundedRectangle = 'rrct' /* A rectangle shape with rounded corners. */,
	PagesTDSTStar = 'star' /* A star shape. */,
	PagesTDSTTriangle = 'trng' /* An isosceles triangle shape. */
} PagesTDST;

typedef enum {
	PagesTLEpFilledArrow = 'arfl' /* A fancier filled arrowhead. */,
	PagesTLEpFilledCircle = 'flcr' /* A filled circle. */,
	PagesTLEpFilledDiamond = 'fldm' /* A filled diamond. */,
	PagesTLEpFilledSquare = 'flsq' /* A filled square */,
	PagesTLEpInvertedArrow = 'arin' /* An inverted arrow. */,
	PagesTLEpNone = 'noLE' /* No endpoint adornment. */,
	PagesTLEpOpenArrow = 'arop' /* A simple non-filled triangular arrowhead. */,
	PagesTLEpOpenCircle = 'opcr' /* An open circle. */,
	PagesTLEpOpenSquare = 'opsq' /* An open square. */,
	PagesTLEpPerpendicularLine = 'lnLE' /* A perpendicular line. */,
	PagesTLEpSimpleArrow = 'arsm' /* A simple triangular arrowhead. */
} PagesTLEp;

typedef enum {
	PagesTWFTCenter = 'cntr' /* For fixed objects, wrap text around the object. For moving objects, center the object and wrap text around it. */,
	PagesTWFTCenterSplit = 'sptc' /* Center the moving object and wrap text above and below only. */,
	PagesTWFTLargest = 'lgst' /* Wrap text to the side of a fixed object with the most available space. */,
	PagesTWFTLeft = 'left' /* For fixed objects, wrap text to the left of the object. For moving objects, align object to the left and wrap text around it. */,
	PagesTWFTLeftSplit = 'sptl' /* Align moving object to the left and wrap text above and below only. */,
	PagesTWFTNeither = 'nthr' /* Wrap text above and below a fixed object only. */,
	PagesTWFTNone = 'noWT' /* Object will not cause text to wrap around it. */,
	PagesTWFTRight = 'rite' /* For fixed objects, wrap text to the right of the object. For moving objects, align object to the right and wrap text around it. */,
	PagesTWFTRightSplit = 'sptr' /* Align moving object to the right and wrap text above and below only. */
} PagesTWFT;

typedef enum {
	PagesTWFtContour = 'cont' /* Wrap text follows the contour of the object. */,
	PagesTWFtRectangular = 'rctg' /* Wrap text follows a rectangular border around the object. */
} PagesTWFt;

typedef enum {
	PagesTFTpColor = 'colr' /* A single color fill. */,
	PagesTFTpGradient = 'grad' /* A gradient color fill. */,
	PagesTFTpNone = 'noFT' /* No fill. */,
	PagesTFTpPlainImage = 'imag' /* A raster image fill. */,
	PagesTFTpTintedImage = 'tint' /* A tinted raster image fill. */
} PagesTFTp;

typedef enum {
	PagesTSTpLongDash = 'dshl' /* A long dash stroke. */,
	PagesTSTpMediumDash = 'dshm' /* A medium dash stroke. */,
	PagesTSTpNone = 'noST' /* No stroke will be used. */,
	PagesTSTpShortDash = 'dshs' /* A short dash stroke. */,
	PagesTSTpSolid = 'sold' /* A continuous stroke. */
} PagesTSTp;

typedef enum {
	PagesTCapAllCaps = 'capa' /* All capital letters. */,
	PagesTCapNormalCapitalization = 'capn' /* Absence of capitalization overrides. */,
	PagesTCapSmallCaps = 'caps' /* All small capital letters. */
} PagesTCap;

typedef enum {
	PagesTNmTLetterLowerParenOne = 'lwp1',
	PagesTNmTLetterLowerParenTwo = 'lwp2',
	PagesTNmTLetterLowerParenZero = 'lwrs',
	PagesTNmTLetterUpperParenOne = 'cpp1',
	PagesTNmTLetterUpperParenTwo = 'cpp2',
	PagesTNmTLetterUpperParenZero = 'caps',
	PagesTNmTNumberParenOne = 'nmp1',
	PagesTNmTNumberParenTwo = 'nmp2',
	PagesTNmTNumberParenZero = 'nmbr',
	PagesTNmTRomanLowerParenOne = 'rsp1',
	PagesTNmTRomanLowerParenTwo = 'rsp2',
	PagesTNmTRomanLowerParenZero = 'rmns',
	PagesTNmTRomanUpperParenOne = 'rcp1',
	PagesTNmTRomanUpperParenTwo = 'rcp2',
	PagesTNmTRomanUpperParenZero = 'rmnc'
} PagesTNmT;

typedef enum {
	PagesTLigAllLigatures = 'alll' /* Use all ligatures defined by the font. */,
	PagesTLigDefaultLigatures = 'dflt' /* Use default ligatures defined by the font. */,
	PagesTLigNone = 'noLG' /* No ligatures. */
} PagesTLig;

typedef enum {
	PagesTStkDoubleStrikethrough = 'dubl' /* Two lines are drawn through characters. */,
	PagesTStkNone = 'noSU' /* Characters are not drawn with a line through them. */,
	PagesTStkSingleStrikethrough = 'sngl' /* A single line is drawn through characters. */
} PagesTStk;

typedef enum {
	PagesTUndDoubleUnderline = 'dubl' /* A double underline. */,
	PagesTUndNone = 'noUT' /* Characters are not underlined. */,
	PagesTUndSingleUnderline = 'sngl' /* A single underline. */
} PagesTUnd;

typedef enum {
	PagesTAHTCenter = 'cntr' /* Center-align text. */,
	PagesTAHTJustify = 'just' /* Fully justify (left and right) text. */,
	PagesTAHTLeft = 'left' /* Left-align text. */,
	PagesTAHTRight = 'rite' /* Right-align text. */
} PagesTAHT;

typedef enum {
	PagesTLbTImageBullet = 'blti' /* A bitmap image will be used for the bullet. */,
	PagesTLbTNone = 'noLB' /* No label will be drawn for the list level. */,
	PagesTLbTNumber = 'bltn' /* Sequential alphanumeric values will be used. */,
	PagesTLbTTextBullet = 'bltt' /* A text bullet will be used. */,
	PagesTLbTTieredNumber = 'bltr' /* Sequential alphanumeric values will be used and all value labels are displayed for each list level. */
} PagesTLbT;

typedef enum {
	PagesTLSTAtLeast = 'smin' /* Use at least the specified amount. */,
	PagesTLSTInbetween = 'btwn' /* Apply spacing between lines of text. */,
	PagesTLSTRelative = 'rltv' /* Use relative (i.e. "Multiple") amount. */
} PagesTLST;

typedef enum {
	PagesEnumStandard = 'lwst' /* Standard PostScript error handling */,
	PagesEnumDetailed = 'lwdt' /* print a detailed report of PostScript errors */
} PagesEnum;



/*
 * Standard Suite
 */

// A scriptable object.
@interface PagesItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) closeSaving:(PagesSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) addChartColumnNames:(NSString *)columnNames data:(NSInteger)data groupBy:(PagesKCgb)groupBy rowNames:(NSString *)rowNames type:(PagesKCct)type;  // Add a chart.
- (void) addTableData:(NSString *)data headerColumn:(BOOL)headerColumn headerRow:(BOOL)headerRow;  // Add a table.
- (void) reveal;  // Make the object visible within the document (by scrolling to it).
- (void) select;  // Select an object.
- (void) insertPageBreak;  // Insert a page break in the body text at the current insertion point. Only the body text of a document is a legal receiver for this command.
- (void) insertTableOfContents;  // Insert a table of contents in the body text at the current insertion point. Only the body text of a document is a legal receiver for this command.

@end

// An application's top level scripting object.
@interface PagesApplication : SBApplication
+ (PagesApplication *) application;

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *name;  // The name of the application.
@property (copy, readonly) NSString *version;  // The version of the application.

- (PagesDocument *) open:(NSURL *)x;  // Open an object.
- (void) print:(NSURL *)x printDialog:(BOOL)printDialog withProperties:(PagesPrintSettings *)withProperties;  // Print an object.
- (void) quitSaving:(PagesSavo)saving;  // Quit an application.

@end

// A color.
@interface PagesColor : PagesItem


@end

// A document.
@interface PagesDocument : PagesItem

@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.
@property (copy) NSString *path;  // The document's path.


@end

// A window.
@interface PagesWindow : PagesItem

@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (copy, readonly) PagesDocument *document;  // The document whose contents are being displayed in the window.
@property (readonly) BOOL floating;  // Whether the window floats.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property (readonly) BOOL miniaturizable;  // Whether the window can be miniaturized.
@property BOOL miniaturized;  // Whether the window is currently miniaturized.
@property (readonly) BOOL modal;  // Whether the window is the application's current modal window.
@property (copy) NSString *name;  // The full title of the window.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property (readonly) BOOL titled;  // Whether the window has a title bar.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.


@end



/*
 * Text Suite
 */

// This subdivides the text into chunks that all have the same attributes.
@interface PagesAttributeRun : PagesItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into characters.
@interface PagesCharacter : PagesItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into paragraphs.
@interface PagesParagraph : PagesItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// Rich (styled) text
@interface PagesText : PagesItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into words.
@interface PagesWord : PagesItem

- (SBElementArray *) attachments;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end



/*
 * Pages Application Suite
 */

// The Pages application.
@interface PagesApplication (PagesApplicationSuite)

@property PagesTARU rulerUnits;  // The allowable ruler units.
@property (copy) PagesSelectionObject *selection;  // The current selection in the frontmost document.
@property (copy, readonly) id templates;  // Names of all templates available for creating new documents.

@end

// A captured page which can be used as a template for new pages.
@interface PagesCapturedPage : PagesItem

- (NSInteger) id;  // The unique identifier of the captured page.
@property (copy) NSString *name;  // The name of the captured page.


@end

// A Pages document.
@interface PagesDocument (PagesApplicationSuite)

- (SBElementArray *) capturedPages;
- (SBElementArray *) characterStyles;
- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) lines;
- (SBElementArray *) listStyles;
- (SBElementArray *) pages;
- (SBElementArray *) paragraphStyles;
- (SBElementArray *) sections;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) textBoxes;

@property (copy) PagesText *bodyText;  // The main text flow of the document.
@property double bottomMargin;  // The bottom margin of the publication.
@property BOOL facingPages;  // Whether or not the view is set to facing pages.
@property double footerMargin;  // The footer margin of the publication.
@property double headerMargin;  // The header margin of the publication.
- (NSInteger) id;  // The unique identifier of the document.
@property double insideMargin;  // The inside margin of the publication when facing pages is enabled.
@property double leftMargin;  // The left margin of the publication.
@property double outsideMargin;  // The outside margin of the publication when facing pages is enabled.
@property (copy) PagesPageSetup *pageAttributes;  // Page settings for printing
@property double rightMargin;  // The right margin of the publication.
@property (copy) PagesSelectionObject *selection;  // The current selection or insertion point.  Use the "select" command to change the selection.  Setting of this property replaces the current selected object.  E.g., set selection of document 1 to "hello".
@property (copy) NSString *templateName;  // The name of a template to use when make new object is used (it is a write-only property).
@property double topMargin;  // The top margin of the publication.
@property (copy, readonly) PagesWindow *window;  // The document's main content window.

@end

// A layer within a page or master page.  The layer will be either foreground or background.
@interface PagesLayer : PagesItem

- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) lines;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) textBoxes;

@property (copy, readonly) PagesPage *containingPage;  // The page to which the layer belongs.  Not set if the layer is on a master page.
@property (readonly) BOOL foreground;  // True if the layer is a foreground layer.
@property (copy, readonly) PagesMasterPage *masterPage;  // The master page to which this layer belongs.  Not set if the layer is on a regular page.


@end

// A master page of a section. This contains the graphic objects which are displayed on all specified pages.  Every section has a master page for odd and even pages, one for the first page (if the first page is different) and one for all pages (if odd and ev
@interface PagesMasterPage : PagesItem

- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) lines;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) textBoxes;

@property (copy, readonly) PagesLayer *backgroundLayer;  // The background layer of graphic objects (behind the body text).
@property (copy, readonly) PagesSection *containingSection;  // The section to which this master page belongs.
@property (copy, readonly) PagesLayer *foregroundLayer;  // The foreground layer of graphic objects (in front of the body text).


@end

// A page of the document. Only the count, exists, and get core suite commands can be used with this class. The "insert page break" command of the text class will create a page.
@interface PagesPage : PagesItem

- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) lines;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) textBoxes;

@property (copy, readonly) PagesLayer *backgroundLayer;  // The background layer of graphic objects (behind the body text).
@property (copy, readonly) PagesSection *containingSection;  // The section to which this page belongs.
@property (copy, readonly) PagesText *footer;  // The footer for the page.
@property (copy, readonly) PagesLayer *foregroundLayer;  // The foreground layer of graphic objects (in front of the body text).
@property (copy, readonly) PagesText *header;  // The header for the page.
@property (readonly) double height;  // The height of the page.
@property (copy, readonly) PagesMasterPage *masterPage;  // The section master page which contributes to the drawing of this page.
@property (readonly) NSInteger pageNumber;  // The page number.
@property (readonly) double width;  // The width of the page.


@end

// Page settings for printing
@interface PagesPageSetup : PagesItem

@property PagesPPgO orientation;  // Orientation of the pages.
@property (copy) PagesText *paperName;  // Name of the paper type.
@property (copy) NSDictionary *paperSize;  // Size of the paper in points.
@property (copy, readonly) NSDictionary *printerMargins;  // Margins imposed by the printer.
@property double scale;  // Factor by which the page is scaled when printing.


@end

// A section within a document.
@interface PagesSection : PagesItem

- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) lines;
- (SBElementArray *) pages;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) textBoxes;

@property (copy) PagesText *bodyText;  // The body text of the section.
@property BOOL differentFirstPage;  // Whether the first page of the section can have different headers, footers, and master objects.
@property BOOL differentLeftAndRightPages;  // Whether the left and right pages of the section can have different headers, footers, and master objects.
@property (copy) PagesText *evenFooter;  // The footer for even-numbered pages.
@property (copy) PagesText *evenHeader;  // The header for even-numbered pages.
@property (copy, readonly) PagesMasterPage *evenMasterPage;  // List of section master graphic objects for even pages.
@property (copy, readonly) PagesMasterPage *firstMasterPage;  // Section master page for the first page.
@property (copy) PagesText *firstPageFooter;  // The footer for the first (i.e. title) page of a section.
@property (copy) PagesText *firstPageHeader;  // The header for the first (i.e. title) page of a section.
@property (copy, readonly) PagesMasterPage *mainMasterPage;  // Section master page for all pages, when odd and even pages are the same.
@property (copy) NSString *name;  // The name of the section.
@property (copy) PagesText *oddFooter;  // The footer for odd-numbered pages.
@property (copy) PagesText *oddHeader;  // The header for odd-numbered pages.
@property (copy, readonly) PagesMasterPage *oddMasterPage;  // Section master page for odd pages.
@property PagesTPNK pageNumberKind;  // How page numbers for the section should relate, if at all, to the previous section.
@property NSInteger pageNumberStart;  // The starting page number for the section when page number kind is "restart."
@property BOOL reuseHeadersAndFooters;  // Whether the current section headers and footers are the same as the previous section's.
@property (readonly) NSInteger sectionNumber;  // The section number.
@property PagesTSPK startPageKind;  // Start the section on the next, right, or left page.
@property (copy) NSString *templateName;  // The name of a template to use when make new object is used (it is a write-only property).


@end

// A way to refer to the state of the current of the selection.  Use the "select" command to make a new selection.
@interface PagesSelectionObject : PagesItem

@property (copy) id contents;  // The information currently selected.  Use "contents of selection" to get or change information in a document.


@end

// A window for a Pages document.
@interface PagesWindow (PagesApplicationSuite)

@property BOOL fitPage;  // Whether the view is scaled to show an entire page.
@property BOOL fitWidth;  // Whether the view is scaled to fit the width of the window.
@property BOOL fullScreen;  // Whether the window is in full screen mode.
@property BOOL outlineVisible;  // Whether the document outline is visible.
@property BOOL rulerVisible;  // Whether the window's ruler is visible.
@property BOOL stylesVisible;  // Whether the styles sidebar is visible.
@property BOOL thumbnailsVisible;  // Whether the window's page thumbnails are visible.
@property BOOL toolbarVisible;  // Whether the window's toolbar is visible.
@property BOOL twoUp;  // Whether the window is displaying pages as two up.
@property double viewScale;  // The scale of the window's view, in percent. When setting a value, it will be rounded toward 100% to the nearest supported value.
@property (copy, readonly) id visiblePages;  // List of the pages visible in the window.  Use "reveal" to scroll to a particular page.

@end



/*
 * Pages Graphics Suite
 */

// An abstract base class from which other more specific graphic objects are derived. Cannot use 'make' command with this class.
@interface PagesGraphic : PagesItem

@property (copy, readonly) PagesLayer *containingLayer;  // The layer which contains this graphic object.
@property (copy, readonly) PagesPage *containingPage;  // The page on which the graphic is located.
@property NSInteger extraSpace;  // The number of points of space between the shape and the text wrapped around it.
@property double height;  // The height of the shape
@property double horizontalPosition;  // The left-most point of the smallest rectangular bounding box of the shape.
- (NSInteger) id;  // The unique identifier of the object.
@property NSInteger locked;  // Whether the object is locked.
@property (copy) NSString *name;  // The name of the object.
@property double opacity;  // The opacity of the object, fill and stroke, in percent.
@property PagesTDwP placement;  // The way a drawable's location is determined.
@property double rotation;  // The amount of rotation, in degrees, of the object.
@property BOOL shadow;  // Whether the object casts a shadow or not.
@property double shadowAngle;  // The directional angle, in degrees, that the shadow is cast.
@property NSInteger shadowBlur;  // The relative amount of blur of images seen through the shadow.
@property (copy) NSColor *shadowColor;  // The color of the shadow.
@property double shadowOffset;  // The offset from the shape that the shadow extends to.
@property double shadowOpacity;  // The amount of opacity for the shadow, in percent.
@property (copy) NSColor *strokeColor;  // The stroke color.
@property double strokeWidth;  // The width of the stroke.
@property PagesTWFt textFit;  // Whether the text wrap follows the contour of the shape.
@property double verticalPosition;  // The top-most point of the smallest rectangular bounding box of the shape.
@property double width;  // Width of the shape.
@property PagesTWFT wrap;  // The style of text wrap for the shape, if any.


@end

// A chart. Cannot use 'make' command with this class. Use 'add chart' command.
@interface PagesChart : PagesGraphic


@end

// A raster image.
@interface PagesImage : PagesGraphic

@property double alphaThreshold;  // How transparent, in percent, the image must be for text to show through it.
@property (copy) PagesImageBinary *imageData;  // The image data.
@property BOOL replaceable;  // Whether the image data is replaceable or not. Images created through the scripting interface are initially set to be replaceable.
@property PagesTSTp strokeType;  // The type of stroke to frame the image.


@end

// The internal representation of bitmap image data. Cannot use 'make' command with this class.
@interface PagesImageBinary : PagesItem


@end

// A single stroke line.
@interface PagesLine : PagesGraphic

@property PagesTLEp headEndpointType;  // The style of the start of the line.
@property double horizontalLineEnd;  // The horizontal point where the line ends.
@property double horizontalLineStart;  // The horizontal point where the line starts.
@property PagesTSTp strokeType;  // The type of stroke to frame the shape.
@property PagesTLEp tailEndpointType;  // The style of the end of the line.
@property double verticalLineEnd;  // The vertical point where the line ends.
@property double verticalLineStart;  // The vertical point where the line starts.


@end

// A shape.
@interface PagesShape : PagesGraphic

@property double colorAngle;  // The angle, in degrees, from the start color to the end color.
@property (copy) NSColor *endColor;  // End color for gradient fill.
@property PagesTFTp fillType;  // The type of fill for the shape.
@property (copy) PagesImageBinary *imageData;  // The image data. Currently supports a file path only.
@property PagesTIFT imageFillType;  // The way in which to render an image fill into the shape.
@property (copy) NSColor *imageTintColor;  // The color to apply to a tinted image fill.
@property (copy) PagesText *objectText;  // The text, if any within the object.
@property PagesTDST shapeType;  // The type of shape. Only useful when using 'make new shape' command.
@property (copy) NSColor *singleColor;  // The color for single color fill.
@property (copy) NSColor *startColor;  // The start color for gradient fill.
@property PagesTSTp strokeType;  // The type of stroke to frame the shape.


@end

// A table. Cannot use 'make' command with this class. Use 'add table' command.
@interface PagesTable : PagesGraphic


@end

// A text box.
@interface PagesTextBox : PagesGraphic

@property double colorAngle;  // The angle, in degrees, from the start color to the end color.
@property (copy) NSColor *endColor;  // End color for gradient fill.
@property PagesTFTp fillType;  // The type of fill for the text box.
@property (copy) PagesImageBinary *imageData;  // The image data. Currently supports a file path only.
@property PagesTIFT imageFillType;  // The way in which to render an image fill into the shape.
@property (copy) PagesText *objectText;  // The text, if any within the object.
@property (copy) NSColor *singleColor;  // The color for single color fill.
@property (copy) NSColor *startColor;  // The start color for gradient fill.
@property PagesTSTp strokeType;  // The type of stroke to frame the text box.


@end



/*
 * Pages Text Suite
 */

// This subdivides the text into characters.
@interface PagesCharacter (PagesTextSuite)

- (SBElementArray *) characters;
- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) insertionPoints;
- (SBElementArray *) lines;
- (SBElementArray *) paragraphs;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) text;
- (SBElementArray *) textBoxes;
- (SBElementArray *) words;

@property PagesTAHT alignment;  // The horizontal alignment.
@property double baselineShift;  // Raise or lower the target text.
@property BOOL bold;  // Whether the font style is bold.
@property PagesTCap capitalizationType;  // Whether a capitalization style is applied.
@property (copy) NSColor *characterBackgroundColor;  // The color of the character's background.
@property (readonly) NSInteger characterOffset;  // The offset of the text from the beginning of the enclosing text object.
@property (copy) PagesCharacterStyle *characterStyle;  // The representative character style of the object.
@property BOOL collapsed;  // Whether the paragraph is collapsed in the outline view.
@property (copy) NSColor *color;  // The color of the font.
@property (copy, readonly) PagesPage *containingPage;  // The page on which this text starts.
@property (copy) id contents;
@property double firstLineIndent;  // The space between the first line of the paragraph and the left margin.
@property (copy) NSString *followingParagraphStyle;  // The name of the following paragraph style. The empty string implies this style.
@property (copy) NSString *fontName;  // The name of the font.
@property double fontSize;  // The size of the font.
@property BOOL hidden;  // Whether the paragraph is hidden in the outline view.
@property NSInteger indentLevel;  // The list indent level assigned to the paragraph, from 1 through 9.
@property BOOL italic;  // Whether the font style is italic.
@property BOOL keepLinesTogether;  // Keep all lines of the paragraph on the same page.
@property BOOL keepWithNextParagraph;  // Keep the target and following paragraph on the same page.
@property double labelBaselineShift;  // The amount to move the label up (+) or down (-) relative to the first line of the paragraph.
@property (copy) PagesImageBinary *labelImageData;  // The image used for the label.
@property double labelIndent;  // The distance from the left margin to the list label.
@property double labelSize;  // When "scale with text" is disabled the label size is a text point size for text labels or a multiplier of original image size for image labels. When enabled, it is always a multiplier of the representative font size of the paragraph.
@property PagesTLbT labelType;  // The type of label to use.
@property double leftIndent;  // The space between the paragraph and the left margin.
@property (readonly) NSInteger length;  // The length of the text, in characters.
@property PagesTLig ligatures;  // Remove ligatures from the target text if the document is set to use ligatures.
@property double lineSpacing;  // The amount of space between lines in the current spacing style.
@property PagesTLST lineSpacingType;  // The type of line spacing.
@property (copy) PagesListStyle *listStyle;  // The list style, if any, for the target.
@property PagesTNmT numberLabelStyle;  // The type of label for number and tiered number types.
@property BOOL numberLabelTiered;  // Whether a numeric label displays the complete hierarchy for each level or just the label of the level.
@property BOOL outline;  // Whether the font style is outline.
@property (copy) NSColor *paragraphBackgroundColor;  // The color of the object's fill.
@property (copy) PagesParagraphStyle *paragraphStyle;  // The representative paragraph style of the text.
@property BOOL preventWidowsAndOrphans;  // Prevent the first or last line of a paragraph from appearing alone on a page.
@property BOOL removeHyphenation;  // Remove hyphenation from the paragraph if the document is set to hyphenate words automatically.
@property double rightIndent;  // The space between the paragraph and the right margin.
@property BOOL scaleWithText;  // Whether the label size proportionally changes with the paragraph text size.
@property BOOL shadow;  // Whether the object casts a shadow or not.
@property double shadowAngle;  // The directional angle, in degrees, that the shadow is cast.
@property NSInteger shadowBlur;  // The relative amount of blur of images seen through the shadow.
@property (copy) NSColor *shadowColor;  // The color of the shadow.
@property double shadowOffset;  // The offset from the text box content that the shadow extends to.
@property double shadowOpacity;  // The amount of opacity for the shadow, in percent.
@property double spaceAfter;  // The space after the paragraph, in points.
@property double spaceBefore;  // The space before the paragraph, in points.
@property BOOL startNewPage;  // Start the paragraph at the beginning of the next page.
@property (copy) NSColor *strikethroughColor;  // The color of the strikethrough line(s).
@property PagesTStk strikethroughType;  // Whether one or more lines are drawn through the characters.
@property BOOL subscript;  // Decrease the font size and lower the baseline of the text.
@property BOOL superscript;  // Decrease the font size and raise the baseline of the text.
@property double textIndent;  // The distance from the label to the text.
@property (copy) NSString *textLabelString;  // One to nine characters can be specified for a text label.
@property double tracking;  // The space between text characters, in percent.
@property (copy) NSColor *underlineColor;  // The color of the underline(s).
@property PagesTUnd underlineType;  // Whether the font style is underline.

@end

// A character style.
@interface PagesCharacterStyle : PagesItem

@property double baselineShift;  // Raise or lower the target text.
@property BOOL bold;  // Whether the font style is bold.
@property PagesTCap capitalizationType;  // Whether a capitalization style is applied.
@property (copy) NSColor *characterBackgroundColor;  // The color of the character's background.
@property (copy) NSColor *color;  // The color of the font.
@property (copy) NSString *fontName;  // The name of the font.
@property double fontSize;  // The size of the font.
@property BOOL italic;  // Whether the font style is italic.
@property PagesTLig ligatures;  // Remove ligatures from the target text if the document is set to use ligatures.
@property (copy) NSString *name;  // The name of the style.
@property BOOL outline;  // Whether the font style is outline.
@property BOOL shadow;  // Whether the text box content casts a shadow or not.
@property double shadowAngle;  // The directional angle, in degrees, that the shadow is cast.
@property NSInteger shadowBlur;  // The relative amount of blur of images seen through the shadow.
@property (copy) NSColor *shadowColor;  // The color of the shadow.
@property double shadowOffset;  // The offset from the text box content that the shadow extends to.
@property double shadowOpacity;  // The amount of opacity for the shadow, in percent.
@property (copy) NSColor *strikethroughColor;  // The color of the strikethrough line(s).
@property PagesTStk strikethroughType;  // Whether one or more lines are drawn through the characters.
@property BOOL subscript;  // Decrease the font size and lower the baseline of the text.
@property BOOL superscript;  // Decrease the font size and raise the baseline of the text.
@property double tracking;  // The space between text characters, in percent.
@property (copy) NSColor *underlineColor;  // The color of the underline(s).
@property PagesTUnd underlineType;  // Whether the font style is underline.


@end

// location between two characters
@interface PagesInsertionPoint : PagesItem

- (SBElementArray *) characters;
- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) insertionPoints;
- (SBElementArray *) lines;
- (SBElementArray *) paragraphs;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) text;
- (SBElementArray *) textBoxes;
- (SBElementArray *) words;

@property PagesTAHT alignment;  // The horizontal alignment.
@property double baselineShift;  // Raise or lower the target text.
@property BOOL bold;  // Whether the font style is bold.
@property PagesTCap capitalizationType;  // Whether a capitalization style is applied.
@property (copy) NSColor *characterBackgroundColor;  // The color of the character's background.
@property (readonly) NSInteger characterOffset;  // The offset of the text from the beginning of the enclosing text object.
@property (copy) PagesCharacterStyle *characterStyle;  // The representative character style of the object.
@property BOOL collapsed;  // Whether the paragraph is collapsed in the outline view.
@property (copy) NSColor *color;  // The color of the font.
@property (copy, readonly) PagesPage *containingPage;  // The page on which this text starts.
@property (copy) id contents;
@property double firstLineIndent;  // The space between the first line of the paragraph and the left margin.
@property (copy) NSString *followingParagraphStyle;  // The name of the following paragraph style. The empty string implies this style.
@property (copy) NSString *fontName;  // The name of the font.
@property double fontSize;  // The size of the font.
@property BOOL hidden;  // Whether the paragraph is hidden in the outline view.
@property NSInteger indentLevel;  // The list indent level assigned to the paragraph, from 1 through 9.
@property BOOL italic;  // Whether the font style is italic.
@property BOOL keepLinesTogether;  // Keep all lines of the paragraph on the same page.
@property BOOL keepWithNextParagraph;  // Keep the target and following paragraph on the same page.
@property double labelBaselineShift;  // The amount to move the label up (+) or down (-) relative to the first line of the paragraph.
@property (copy) PagesImageBinary *labelImageData;  // The image used for the label.
@property double labelIndent;  // The distance from the left margin to the list label.
@property double labelSize;  // When "scale with text" is disabled the label size is a text point size for text labels or a multiplier of original image size for image labels. When enabled, it is always a multiplier of the representative font size of the paragraph.
@property PagesTLbT labelType;  // The type of label to use.
@property double leftIndent;  // The space between the paragraph and the left margin.
@property (readonly) NSInteger length;  // The length of the text, in characters.
@property PagesTLig ligatures;  // Remove ligatures from the target text if the document is set to use ligatures.
@property double lineSpacing;  // The amount of space between lines in the current spacing style.
@property PagesTLST lineSpacingType;  // The type of line spacing.
@property (copy) PagesListStyle *listStyle;  // The list style, if any, for the target.
@property PagesTNmT numberLabelStyle;  // The type of label for number and tiered number types.
@property BOOL numberLabelTiered;  // Whether a numeric label displays the complete hierarchy for each level or just the label of the level.
@property BOOL outline;  // Whether the font style is outline.
@property (copy) NSColor *paragraphBackgroundColor;  // The color of the object's fill.
@property (copy) PagesParagraphStyle *paragraphStyle;  // The representative paragraph style of the text.
@property BOOL preventWidowsAndOrphans;  // Prevent the first or last line of a paragraph from appearing alone on a page.
@property BOOL removeHyphenation;  // Remove hyphenation from the paragraph if the document is set to hyphenate words automatically.
@property double rightIndent;  // The space between the paragraph and the right margin.
@property BOOL scaleWithText;  // Whether the label size proportionally changes with the paragraph text size.
@property BOOL shadow;  // Whether the object casts a shadow or not.
@property double shadowAngle;  // The directional angle, in degrees, that the shadow is cast.
@property NSInteger shadowBlur;  // The relative amount of blur of images seen through the shadow.
@property (copy) NSColor *shadowColor;  // The color of the shadow.
@property double shadowOffset;  // The offset from the text box content that the shadow extends to.
@property double shadowOpacity;  // The amount of opacity for the shadow, in percent.
@property double spaceAfter;  // The space after the paragraph, in points.
@property double spaceBefore;  // The space before the paragraph, in points.
@property BOOL startNewPage;  // Start the paragraph at the beginning of the next page.
@property (copy) NSColor *strikethroughColor;  // The color of the strikethrough line(s).
@property PagesTStk strikethroughType;  // Whether one or more lines are drawn through the characters.
@property BOOL subscript;  // Decrease the font size and lower the baseline of the text.
@property BOOL superscript;  // Decrease the font size and raise the baseline of the text.
@property double textIndent;  // The distance from the label to the text.
@property (copy) NSString *textLabelString;  // One to nine characters can be specified for a text label.
@property double tracking;  // The space between text characters, in percent.
@property (copy) NSColor *underlineColor;  // The color of the underline(s).
@property PagesTUnd underlineType;  // Whether the font style is underline.


@end

// One of nine list levels of a list style.
@interface PagesListLevel : PagesItem

@property (copy) PagesCharacterStyle *characterStyle;  // The representative character style of the object.
@property double labelBaselineShift;  // The amount to move the label up (+) or down (-) relative to the first line of the paragraph.
@property (copy) PagesImageBinary *labelImageData;  // The image used for the label.
@property double labelIndent;  // The distance from the left margin to the list label.
@property double labelSize;  // When "scale with text" is disabled the label size is a text point size for text labels or a multiplier of original image size for image labels. When enabled, it is always a multiplier of the representative font size of the paragraph.
@property PagesTLbT labelType;  // The type of label to use.
@property PagesTNmT numberLabelStyle;  // The type of label for number and tiered number types.
@property BOOL numberLabelTiered;  // Whether a numeric label displays the complete hierarchy for each level or just that level's label.
@property BOOL scaleWithText;  // Whether the label size proportionally changes with the paragraph text size.
@property double textIndent;  // The distance from the label to the text.
@property (copy) NSString *textLabelString;  // One to nine characters can be specified for a text label.


@end

// A list style.
@interface PagesListStyle : PagesItem

- (SBElementArray *) characterStyles;
- (SBElementArray *) listLevels;

@property (copy) NSString *name;  // The name of the style.


@end

// This subdivides the text into paragraphs.
@interface PagesParagraph (PagesTextSuite)

- (SBElementArray *) characters;
- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) insertionPoints;
- (SBElementArray *) lines;
- (SBElementArray *) paragraphs;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) text;
- (SBElementArray *) textBoxes;
- (SBElementArray *) words;

@property PagesTAHT alignment;  // The horizontal alignment.
@property double baselineShift;  // Raise or lower the target text.
@property BOOL bold;  // Whether the font style is bold.
@property PagesTCap capitalizationType;  // Whether a capitalization style is applied.
@property (copy) NSColor *characterBackgroundColor;  // The color of the character's background.
@property (readonly) NSInteger characterOffset;  // The offset of the text from the beginning of the enclosing text object.
@property (copy) PagesCharacterStyle *characterStyle;  // The representative character style of the object.
@property BOOL collapsed;  // Whether the paragraph is collapsed in the outline view.
@property (copy) NSColor *color;  // The color of the font.
@property (copy, readonly) PagesPage *containingPage;  // The page on which this text starts.
@property (copy) id contents;
@property double firstLineIndent;  // The space between the first line of the paragraph and the left margin.
@property (copy) NSString *followingParagraphStyle;  // The name of the following paragraph style. The empty string implies this style.
@property (copy) NSString *fontName;  // The name of the font.
@property double fontSize;  // The size of the font.
@property BOOL hidden;  // Whether the paragraph is hidden in the outline view.
@property NSInteger indentLevel;  // The list indent level assigned to the paragraph, from 1 through 9.
@property BOOL italic;  // Whether the font style is italic.
@property BOOL keepLinesTogether;  // Keep all lines of the paragraph on the same page.
@property BOOL keepWithNextParagraph;  // Keep the target and following paragraph on the same page.
@property double labelBaselineShift;  // The amount to move the label up (+) or down (-) relative to the first line of the paragraph.
@property (copy) PagesImageBinary *labelImageData;  // The image used for the label.
@property double labelIndent;  // The distance from the left margin to the list label.
@property double labelSize;  // When "scale with text" is disabled the label size is a text point size for text labels or a multiplier of original image size for image labels. When enabled, it is always a multiplier of the representative font size of the paragraph.
@property PagesTLbT labelType;  // The type of label to use.
@property double leftIndent;  // The space between the paragraph and the left margin.
@property (readonly) NSInteger length;  // The length of the text, in characters.
@property PagesTLig ligatures;  // Remove ligatures from the target text if the document is set to use ligatures.
@property double lineSpacing;  // The amount of space between lines in the current spacing style.
@property PagesTLST lineSpacingType;  // The type of line spacing.
@property (copy) PagesListStyle *listStyle;  // The list style, if any, for the target.
@property PagesTNmT numberLabelStyle;  // The type of label for number and tiered number types.
@property BOOL numberLabelTiered;  // Whether a numeric label displays the complete hierarchy for each level or just the label of the level.
@property BOOL outline;  // Whether the font style is outline.
@property (copy) NSColor *paragraphBackgroundColor;  // The color of the object's fill.
@property (copy) PagesParagraphStyle *paragraphStyle;  // The representative paragraph style of the text.
@property BOOL preventWidowsAndOrphans;  // Prevent the first or last line of a paragraph from appearing alone on a page.
@property BOOL removeHyphenation;  // Remove hyphenation from the paragraph if the document is set to hyphenate words automatically.
@property double rightIndent;  // The space between the paragraph and the right margin.
@property BOOL scaleWithText;  // Whether the label size proportionally changes with the paragraph text size.
@property BOOL shadow;  // Whether the object casts a shadow or not.
@property double shadowAngle;  // The directional angle, in degrees, that the shadow is cast.
@property NSInteger shadowBlur;  // The relative amount of blur of images seen through the shadow.
@property (copy) NSColor *shadowColor;  // The color of the shadow.
@property double shadowOffset;  // The offset from the text box content that the shadow extends to.
@property double shadowOpacity;  // The amount of opacity for the shadow, in percent.
@property double spaceAfter;  // The space after the paragraph, in points.
@property double spaceBefore;  // The space before the paragraph, in points.
@property BOOL startNewPage;  // Start the paragraph at the beginning of the next page.
@property (copy) NSColor *strikethroughColor;  // The color of the strikethrough line(s).
@property PagesTStk strikethroughType;  // Whether one or more lines are drawn through the characters.
@property BOOL subscript;  // Decrease the font size and lower the baseline of the text.
@property BOOL superscript;  // Decrease the font size and raise the baseline of the text.
@property double textIndent;  // The distance from the label to the text.
@property (copy) NSString *textLabelString;  // One to nine characters can be specified for a text label.
@property double tracking;  // The space between text characters, in percent.
@property (copy) NSColor *underlineColor;  // The color of the underline(s).
@property PagesTUnd underlineType;  // Whether the font style is underline.

@end

// A paragraph style.
@interface PagesParagraphStyle : PagesCharacterStyle

@property PagesTAHT alignment;  // The horizontal alignment.
@property double firstLineIndent;  // The space between the first line of the paragraph and the left margin.
@property (copy) PagesParagraphStyle *followingParagraphStyle;  // The following paragraph style. A missing value implies the target paragraph style.
@property BOOL keepLinesTogether;  // Keep all lines of the paragraph on the same page.
@property BOOL keepWithNextParagraph;  // Keep the target and following paragraph on the same page.
@property double leftIndent;  // The space between the paragraph and the left margin.
@property double lineSpacing;  // The amount of space between lines in the current spacing style.
@property PagesTLST lineSpacingType;  // The type of line spacing.
@property (copy) PagesListStyle *listStyle;  // The list style, if any, for the target.
@property (copy) NSColor *paragraphBackgroundColor;  // The color of the object's fill.
@property BOOL preventWidowsAndOrphans;  // Prevent the first or last line of a paragraph from appearing alone on a page.
@property BOOL removeHyphenation;  // Remove hyphenation from the paragraph if the document is set to hyphenate words automatically.
@property double rightIndent;  // The space between the paragraph and the right margin.
@property double spaceAfter;  // The space after the paragraph, in points.
@property double spaceBefore;  // The space before the paragraph, in points.
@property BOOL startNewPage;  // Start the paragraph at the beginning of the next page.


@end

// This class is necessary for Cocoa terminology resolution, but should not be used when scripting.  Use "table" instead.
@interface PagesTableAttachment : PagesGraphic


@end

// Rich (styled) text.
@interface PagesText (PagesTextSuite)

- (SBElementArray *) characters;
- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) insertionPoints;
- (SBElementArray *) lines;
- (SBElementArray *) paragraphs;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) text;
- (SBElementArray *) textBoxes;
- (SBElementArray *) words;

@property PagesTAHT alignment;  // The horizontal alignment.
@property double baselineShift;  // Raise or lower the target text.
@property BOOL bold;  // Whether the font style is bold.
@property PagesTCap capitalizationType;  // Whether a capitalization style is applied.
@property (copy) NSColor *characterBackgroundColor;  // The color of the character's background.
@property (readonly) NSInteger characterOffset;  // The offset of the text from the beginning of the enclosing text object.
@property (copy) PagesCharacterStyle *characterStyle;  // The representative character style of the object.
@property BOOL collapsed;  // Whether the paragraph is collapsed in the outline view.
@property (copy) NSColor *color;  // The color of the font.
@property (copy, readonly) PagesPage *containingPage;  // The page on which this text starts.
@property (copy) id contents;
@property double firstLineIndent;  // The space between the first line of the paragraph and the left margin.
@property (copy) NSString *followingParagraphStyle;  // The name of the following paragraph style. The empty string implies this style.
@property (copy) NSString *fontName;  // The name of the font.
@property double fontSize;  // The size of the font.
@property BOOL hidden;  // Whether the paragraph is hidden in the outline view.
@property NSInteger indentLevel;  // The list indent level assigned to the paragraph, from 1 through 9.
@property BOOL italic;  // Whether the font style is italic.
@property BOOL keepLinesTogether;  // Keep all lines of the paragraph on the same page.
@property BOOL keepWithNextParagraph;  // Keep the target and following paragraph on the same page.
@property double labelBaselineShift;  // The amount to move the label up (+) or down (-) relative to the first line of the paragraph.
@property (copy) PagesImageBinary *labelImageData;  // The image used for the label.
@property double labelIndent;  // The distance from the left margin to the list label.
@property double labelSize;  // When "scale with text" is disabled the label size is a text point size for text labels or a multiplier of original image size for image labels. When enabled, it is always a multiplier of the representative font size of the paragraph.
@property PagesTLbT labelType;  // The type of label to use.
@property double leftIndent;  // The space between the paragraph and the left margin.
@property (readonly) NSInteger length;  // The length of the text, in characters.
@property PagesTLig ligatures;  // Remove ligatures from the target text if the document is set to use ligatures.
@property double lineSpacing;  // The amount of space between lines in the current spacing style.
@property PagesTLST lineSpacingType;  // The type of line spacing.
@property (copy) PagesListStyle *listStyle;  // The list style, if any, for the target.
@property PagesTNmT numberLabelStyle;  // The type of label for number and tiered number types.
@property BOOL numberLabelTiered;  // Whether a numeric label displays the complete hierarchy for each level or just the label of the level.
@property BOOL outline;  // Whether the font style is outline.
@property (copy) NSColor *paragraphBackgroundColor;  // The color of the object's fill.
@property (copy) PagesParagraphStyle *paragraphStyle;  // The representative paragraph style of the text.
@property BOOL preventWidowsAndOrphans;  // Prevent the first or last line of a paragraph from appearing alone on a page.
@property BOOL removeHyphenation;  // Remove hyphenation from the paragraph if the document is set to hyphenate words automatically.
@property double rightIndent;  // The space between the paragraph and the right margin.
@property BOOL scaleWithText;  // Whether the label size proportionally changes with the paragraph text size.
@property BOOL shadow;  // Whether the object casts a shadow or not.
@property double shadowAngle;  // The directional angle, in degrees, that the shadow is cast.
@property NSInteger shadowBlur;  // The relative amount of blur of images seen through the shadow.
@property (copy) NSColor *shadowColor;  // The color of the shadow.
@property double shadowOffset;  // The offset from the text box content that the shadow extends to.
@property double shadowOpacity;  // The amount of opacity for the shadow, in percent.
@property double spaceAfter;  // The space after the paragraph, in points.
@property double spaceBefore;  // The space before the paragraph, in points.
@property BOOL startNewPage;  // Start the paragraph at the beginning of the next page.
@property (copy) NSColor *strikethroughColor;  // The color of the strikethrough line(s).
@property PagesTStk strikethroughType;  // Whether one or more lines are drawn through the characters.
@property BOOL subscript;  // Decrease the font size and lower the baseline of the text.
@property BOOL superscript;  // Decrease the font size and raise the baseline of the text.
@property double textIndent;  // The distance from the label to the text.
@property (copy) NSString *textLabelString;  // One to nine characters can be specified for a text label.
@property double tracking;  // The space between text characters, in percent.
@property (copy) NSColor *underlineColor;  // The color of the underline(s).
@property PagesTUnd underlineType;  // Whether the font style is underline.

@end



/*
 * Text Suite
 */

// Represents an inline text attachment.  This class is used mainly for make commands.
@interface PagesAttachment : PagesText

@property (copy) NSString *fileName;  // The path to the file for the attachment


@end



/*
 * Pages Text Suite
 */

// This subdivides the text into words.
@interface PagesWord (PagesTextSuite)

- (SBElementArray *) characters;
- (SBElementArray *) charts;
- (SBElementArray *) graphics;
- (SBElementArray *) images;
- (SBElementArray *) insertionPoints;
- (SBElementArray *) lines;
- (SBElementArray *) paragraphs;
- (SBElementArray *) shapes;
- (SBElementArray *) tables;
- (SBElementArray *) text;
- (SBElementArray *) textBoxes;
- (SBElementArray *) words;

@property PagesTAHT alignment;  // The horizontal alignment.
@property double baselineShift;  // Raise or lower the target text.
@property BOOL bold;  // Whether the font style is bold.
@property PagesTCap capitalizationType;  // Whether a capitalization style is applied.
@property (copy) NSColor *characterBackgroundColor;  // The color of the character's background.
@property (readonly) NSInteger characterOffset;  // The offset of the text from the beginning of the enclosing text object.
@property (copy) PagesCharacterStyle *characterStyle;  // The representative character style of the object.
@property BOOL collapsed;  // Whether the paragraph is collapsed in the outline view.
@property (copy) NSColor *color;  // The color of the font.
@property (copy, readonly) PagesPage *containingPage;  // The page on which this text starts.
@property (copy) id contents;
@property double firstLineIndent;  // The space between the first line of the paragraph and the left margin.
@property (copy) NSString *followingParagraphStyle;  // The name of the following paragraph style. The empty string implies this style.
@property (copy) NSString *fontName;  // The name of the font.
@property double fontSize;  // The size of the font.
@property BOOL hidden;  // Whether the paragraph is hidden in the outline view.
@property NSInteger indentLevel;  // The list indent level assigned to the paragraph, from 1 through 9.
@property BOOL italic;  // Whether the font style is italic.
@property BOOL keepLinesTogether;  // Keep all lines of the paragraph on the same page.
@property BOOL keepWithNextParagraph;  // Keep the target and following paragraph on the same page.
@property double labelBaselineShift;  // The amount to move the label up (+) or down (-) relative to the first line of the paragraph.
@property (copy) PagesImageBinary *labelImageData;  // The image used for the label.
@property double labelIndent;  // The distance from the left margin to the list label.
@property double labelSize;  // When "scale with text" is disabled the label size is a text point size for text labels or a multiplier of original image size for image labels. When enabled, it is always a multiplier of the representative font size of the paragraph.
@property PagesTLbT labelType;  // The type of label to use.
@property double leftIndent;  // The space between the paragraph and the left margin.
@property (readonly) NSInteger length;  // The length of the text, in characters.
@property PagesTLig ligatures;  // Remove ligatures from the target text if the document is set to use ligatures.
@property double lineSpacing;  // The amount of space between lines in the current spacing style.
@property PagesTLST lineSpacingType;  // The type of line spacing.
@property (copy) PagesListStyle *listStyle;  // The list style, if any, for the target.
@property PagesTNmT numberLabelStyle;  // The type of label for number and tiered number types.
@property BOOL numberLabelTiered;  // Whether a numeric label displays the complete hierarchy for each level or just the label of the level.
@property BOOL outline;  // Whether the font style is outline.
@property (copy) NSColor *paragraphBackgroundColor;  // The color of the object's fill.
@property (copy) PagesParagraphStyle *paragraphStyle;  // The representative paragraph style of the text.
@property BOOL preventWidowsAndOrphans;  // Prevent the first or last line of a paragraph from appearing alone on a page.
@property BOOL removeHyphenation;  // Remove hyphenation from the paragraph if the document is set to hyphenate words automatically.
@property double rightIndent;  // The space between the paragraph and the right margin.
@property BOOL scaleWithText;  // Whether the label size proportionally changes with the paragraph text size.
@property BOOL shadow;  // Whether the object casts a shadow or not.
@property double shadowAngle;  // The directional angle, in degrees, that the shadow is cast.
@property NSInteger shadowBlur;  // The relative amount of blur of images seen through the shadow.
@property (copy) NSColor *shadowColor;  // The color of the shadow.
@property double shadowOffset;  // The offset from the text box content that the shadow extends to.
@property double shadowOpacity;  // The amount of opacity for the shadow, in percent.
@property double spaceAfter;  // The space after the paragraph, in points.
@property double spaceBefore;  // The space before the paragraph, in points.
@property BOOL startNewPage;  // Start the paragraph at the beginning of the next page.
@property (copy) NSColor *strikethroughColor;  // The color of the strikethrough line(s).
@property PagesTStk strikethroughType;  // Whether one or more lines are drawn through the characters.
@property BOOL subscript;  // Decrease the font size and lower the baseline of the text.
@property BOOL superscript;  // Decrease the font size and raise the baseline of the text.
@property double textIndent;  // The distance from the label to the text.
@property (copy) NSString *textLabelString;  // One to nine characters can be specified for a text label.
@property double tracking;  // The space between text characters, in percent.
@property (copy) NSColor *underlineColor;  // The color of the underline(s).
@property PagesTUnd underlineType;  // Whether the font style is underline.

@end



/*
 * Type Definitions
 */

@interface PagesPrintSettings : SBObject

@property NSInteger copies;  // the number of copies of a document to be printed
@property BOOL collating;  // Should printed copies be collated?
@property NSInteger startingPage;  // the first page of the document to be printed
@property NSInteger endingPage;  // the last page of the document to be printed
@property NSInteger pagesAcross;  // number of logical pages laid across a physical page
@property NSInteger pagesDown;  // number of logical pages laid out down a physical page
@property (copy) NSDate *requestedPrintTime;  // the time at which the desktop printer should print the document
@property PagesEnum errorHandling;  // how errors are handled
@property (copy) NSString *faxNumber;  // for fax number
@property (copy) NSString *targetPrinter;  // for target printer

- (void) closeSaving:(PagesSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) addChartColumnNames:(NSString *)columnNames data:(NSInteger)data groupBy:(PagesKCgb)groupBy rowNames:(NSString *)rowNames type:(PagesKCct)type;  // Add a chart.
- (void) addTableData:(NSString *)data headerColumn:(BOOL)headerColumn headerRow:(BOOL)headerRow;  // Add a table.
- (void) reveal;  // Make the object visible within the document (by scrolling to it).
- (void) select;  // Select an object.
- (void) insertPageBreak;  // Insert a page break in the body text at the current insertion point. Only the body text of a document is a legal receiver for this command.
- (void) insertTableOfContents;  // Insert a table of contents in the body text at the current insertion point. Only the body text of a document is a legal receiver for this command.

@end


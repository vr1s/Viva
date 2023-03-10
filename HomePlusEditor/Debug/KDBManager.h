#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

@interface KDBManager : NSObject

@property (readonly) UIView *overlayView;
@property (readonly) UITextView *textView;
@property (readonly) NSString *textQueue;
@property BOOL open;

+(instancetype)sharedInstance;


- (void)setupOverlayView;

-(void)logString:(NSString *)string file:(char *)file line:(int)line;

@end
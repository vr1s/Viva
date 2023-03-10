#include "HomePlusEditor/Gesture/HPGestureManager.h"

// #define NSLog(...) [KDBManager.sharedInstance logString:[NSString stringWithFormat:__VA_ARGS__] file:__FILE__ line:__LINE__]

#define kViewframeWidth UIScreen.mainScreen.bounds.size.width/2
#define kViewframeHeight UIScreen.mainScreen.bounds.size.height/3


@interface KDBOverlayView : UIView
@end

@interface KDBManager : NSObject

@property (readonly) UIView *overlayView;
@property (readonly) UITextView *textView;
@property (readonly) NSString *textQueue;
@property BOOL open;
@property BOOL started;

+(instancetype)sharedInstance;


- (void)setupOverlayView;

-(void)logString:(NSString *)string file:(char *)file line:(int)line;

@end

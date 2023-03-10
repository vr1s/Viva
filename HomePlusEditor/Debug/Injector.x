#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>


#define NSLog(...) [KDBManager.sharedInstance logString:[NSString stringWithFormat:__VA_ARGS__] file:__FILE__ line:__LINE__]


@interface UISystemGestureView : UIView

@end

%hook UISystemGestureView

-(void)movedToSuperview:(UIView *)view
{
    %orig(view);
    
}

%end
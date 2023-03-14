
#include <UIKit/UIKit.h>

#include "VIVAUIManager.h"

@interface PBUIPosterViewController : UIViewController
@end

%hook PBUIPosterViewController 

-(void)scene:(id)arg1 clientDidConnect:(id)arg2
{
    %orig;

    // 
    // With iOS 16, Wallpapers are now rendered in another process
    // In lieu of fucking with that process, since all we need is a blurred version anyways,
    // We can just take a "screenshot" of that view once and call it a day
    // 

    UIGraphicsBeginImageContext([self view].frame.size);
    [[self view].layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *viewImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    [[VIVAUIManager sharedInstance] loadUpImagesFromWallpaper:viewImage];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CreateBackgroundObject" object:nil];
}

%end
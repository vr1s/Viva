
#include <UIKit/UIKit.h>

#include "VIVAUIManager.h"

@interface PBUIPosterViewController : UIViewController
@end

%hook PBUIPosterViewController 

-(void)scene:(id)arg1 clientDidConnect:(id)arg2
{
    %orig;

    UIGraphicsBeginImageContext([self view].frame.size);
    [[self view].layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *viewImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    [[VIVAUIManager sharedInstance] loadUpImagesFromWallpaper:viewImage];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CreateBackgroundObject" object:nil];
}

%end
#include <UIKit/UIKit.h>

#include "VIVAUIManager.h"

// iOS 13-15 Wallpaper backing.
// Removed entirely with iOS 16 as background is handled by an entire other process

@hook SBFStaticWallpaperImageView

// Whenever a wallpaper image is created for the homescreen, pass it to the manager
// We then use this FB/UIRootWindow in the tweak to give the awesome blurred bg UI feel

- (void)setImage:(UIImage *)img 
{
    @orig(img);
    [[VIVAUIManager sharedInstance] loadUpImagesFromWallpaper:img];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CreateBackgroundObject" object:nil];
}

@end



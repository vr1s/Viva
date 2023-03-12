#include <UIKit/UIKit.h>

#include "VIVAUIManager.h"
#include "UIRootSceneWindow.h"

#pragma mark Dynamic Window Background

%hook UIRootSceneWindow

//
// iOS 13-16 - Dynamic editor background
// We use this to set the background image for the editor
//

- (id)initWithDisplayConfiguration:(id)arg
{
    id o = %orig(arg);

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(recieveNotification:) name:@"CreateBackgroundObject" object:nil];

    return o;
}

%new
- (void)recieveNotification:(NSNotification *)notification
{
    self.backgroundColor = [UIColor colorWithPatternImage:[VIVAUIManager sharedInstance].blurredAndDarkenedWallpaper];
}

%end

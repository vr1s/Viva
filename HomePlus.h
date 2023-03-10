// this is pretty horrible, dont use this.
// in my defense, most of this is from October 2019. 

// TODO: CLEAN THIS UP
// TODO: PLEASE ITS SO BAD


#include "Prefix.h"

#define kEditingModeEnabledNotificationName @"HomePlusEditingModeEnabled"
#define kEditingModeDisabledNotificationName @"HomePlusEditingModeDisabled"
#define kEditorKickViewsUp @"HomePlusKickWindowsUp"
#define kEditorKickViewsBack @"HomePlusKickWindowsBack"
#define kFadeFloatingDockNotificationName @"HomePlusFadeFloatingDock"
#define kShowFloatingDockNotificationName @"HomePlusShowFloatingDock"

#define kIdentifier @"me.kritanta.homeplusprefs"
#define kSettingsChangedNotification (CFStringRef)@"me.kritanta.homeplusprefs/settingschanged"
#define kSettingsPath @"/var/mobile/Library/Preferences/me.kritanta.homeplusprefs.plist"

#ifndef HPPH
#define HPPH

@class _SBWallpaperWindow;

@class SBHomeScreenWindow;

#include <SpringBoardHome/SBIconListGridLayoutConfiguration.h>
#include <SpringBoardHome/SBIconListModel.h>
#include <SpringBoard/SBIconController.h>
#include <SpringBoardHome/SBRootFolderController.h>
#include <SpringBoardHome/SBIconListFlowLayout.h>
#include <SpringBoard/SBIconModel.h>

@interface SpringBoard : UIApplication
-(BOOL)isShowingHomescreen;
@end

@interface SBHDefaultIconListLayoutProvider : NSObject

-(SBIconListFlowLayout *)layoutForIconLocation:(NSString *)location;

@end

@interface SBHIconManager : NSObject

@property (nonatomic, retain) SBHDefaultIconListLayoutProvider *listLayoutProvider;

@end

@interface SBIconListView : UIView
-(void)layoutIconsNow;
@end

@interface SBHLibraryPodFolderController : UIViewController

-(SBIconListView *)currentIconListView;

@end
@interface SBHLibraryViewController : UIViewController

- (SBHLibraryPodFolderController *)_podFolderViewController;

@end

@interface SBUIController : NSObject

+(SBUIController *)sharedInstance;
-(SBHomeScreenWindow *)window;

@end

@interface SBWallpaperController : NSObject

+(SBWallpaperController *)sharedInstance;
-(_SBWallpaperWindow *)_window;

@end

@interface SBFloatingDockView : UIView
@property(retain, nonatomic) UIView *backgroundView;
@end

@interface UIRootSceneWindow : UIWindow
@end


#endif
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

#include "SBIconListGridLayoutConfiguration.h"
#include "SBIconListModel.h"
#include "SBIconController.h"
#include "SBIconListFlowLayout.h"
#include "SBIconModel.h"

@interface SBFloatingDockViewController
@property (nonatomic, assign) CGFloat dockOffscreenProgress;
@end

@class SBFloatingDockWindow;

@interface SBFloatingDockController
@property (nonatomic, retain) SBFloatingDockWindow *floatingDockWindow;
@end


@interface SBIconListGridLayoutConfiguration (fourteen)
-(void)setIconGridSizeClassSizes:(SBHIconGridSizeClassSizes)sizes;
@end

@interface i15SBIconListGridLayoutConfiguration : NSObject
-(void)setIconGridSizeClassSizes:(SBHIconGridSizeClassSizes *)sizes;
@end

@interface SpringBoard : UIApplication
-(BOOL)isShowingHomescreen;
@end

@interface SBHDefaultIconListLayoutProvider : NSObject

-(SBIconListFlowLayout *)layoutForIconLocation:(NSString *)location;

@end

@interface SBHIconManager : NSObject

@property (nonatomic, retain) SBFloatingDockViewController *floatingDockViewController;
@property (nonatomic, retain) SBHDefaultIconListLayoutProvider *listLayoutProvider;

@end

@interface SBIconListView : UIView
-(void)layoutIconsNow;
-(void)setIconsLabelAlpha:(CGFloat)alpha;

-(NSArray *)visibleIcons;
-(double)horizontalIconPadding;
@property (assign,getter=isEditing,nonatomic) BOOL editing;
@property (nonatomic,readonly) SBIconListGridLayout* layout;
@property (nonatomic, assign) NSUInteger firstFreeSlotIndex;
@property (nonatomic, assign) NSInteger iconsInRowForSpacingCalculation;
@property (nonatomic, retain) NSString *iconLocation;
@property (nonatomic,readonly) CGSize alignmentIconSize;
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

@interface SBRootFolderView : UIView
@property (nonatomic, retain) SBIconListView *dockListView;
@property (nonatomic, retain) UIView *dockView;
@property (nonatomic, assign) BOOL pageControlHidden;
@end

@interface SBIconView : UIView
@property (nonatomic, retain) NSString *location;
@property (nonatomic, assign) CGFloat iconLabelAlpha;
-(void)configureForLabelAllowed:(BOOL)allowed;
@end
@interface SBIcon : NSObject
@property (nonatomic, assign) NSInteger gridSizeClass;
@end


@interface SBWindow : UIWindow
-(UIView *)recycledViewsContainer;
@end

@interface SBRootFolderController : NSObject 
-(NSArray *)iconListViews;
-(UIView *)contentView;
@end

@interface SBFloatingDockWindow : UIView
@end

#endif
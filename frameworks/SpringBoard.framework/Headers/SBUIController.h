// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBUICONTROLLER_H
#define SBUICONTROLLER_H


@class BCBatteryDeviceController;
@class ATXAppDirectoryClient;
@class ACCConnectionInfo;
@class BSTimer;
@class BSPersistentTimer;
@class CSAccessory;
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBHomeScreenWindow;
@class SBIconContentView;
@class SBMainScreenActiveInterfaceOrientationWindow;
@class SBHomeScreenBackdropViewBase;
@class SBWindow;
@class SBWallpaperEffectView;
@class SBAppStatusBarSettingsAssertion;
@class SBHIDUILockAssertion;
@class SBHomeGestureParticipant;
@class SBHUDController;
@class SBVolumeControl;
@class SBDismissOnlyAlertItem;
@class SBAppSwitcherSettings;
@class SBFMotionAlarmController;
@class SBIconController;
@protocol SBWallpaperObserver;
@protocol PTSettingsKeyObserver;
@protocol UIInteractionProgressObserver;
@protocol SBWallpaperOrientationProvider;
@protocol SBReachabilityObserver;
@protocol SBHomeScreenBackdropViewBaseDelegate;
@protocol BCBatteryDeviceObserving;
@protocol ACCConnectionInfoDelegateProtocol;
@protocol SBFMotionAlarmDelegate;
@protocol UIWindowDelegate;
@protocol CSPowerStatusProviding;
@protocol CSAccessoryStatusProviding;

@interface SBUIController : NSObject <SBWallpaperObserver, PTSettingsKeyObserver, UIInteractionProgressObserver, SBWallpaperOrientationProvider, SBReachabilityObserver, SBHomeScreenBackdropViewBaseDelegate, BCBatteryDeviceObserving, ACCConnectionInfoDelegateProtocol, SBFMotionAlarmDelegate, UIWindowDelegate, CSPowerStatusProviding, CSAccessoryStatusProviding>

{
SBHomeScreenWindow *_window;
SBIconContentView *_iconsView;
UIView *_contentView;
SBMainScreenActiveInterfaceOrientationWindow *_fakeSpringBoardStatusBarWindow;
SBHomeScreenBackdropViewBase *_homeScreenBackdropView;
SBWindow *_homeScreenDimmingWindow;
SBWallpaperEffectView *_reachabilityWallpaperEffectView;
SBAppStatusBarSettingsAssertion *_statusBarAssertion;
// UIForceStageInteractionProgress *_homeButtonForceProgress;
BCBatteryDeviceController *_batteryDeviceController;
BOOL _lastVolumeDownToControl;
BOOL _isBatteryCharging;
BOOL _isFullyCharged;
BOOL _isBatteryCritical;
BOOL _isOnAC;
BOOL _isConnectedToExternalChargingAccessory;
BOOL _isConnectedToPoweredExternalChargingAccessory;
BOOL _isConnectedToUnsupportedChargingAccessory;
BOOL _isConnectedToChargeIncapablePowerSource;
BOOL _wasConnectedToWirelessChargingAccessory;
BOOL _isConnectedToWirelessInternalCharger;
BOOL _isConnectedToWirelessInternalChargingAccessory;
BOOL _isConnectedToWirelessInternalAccessory;
BOOL _isConnectedToWindowedAccessory;
CGRect _visibleScreenCoordinatesForWindowedAccessory;
SBHIDUILockAssertion *_suspendProximityForAttachedWindowedAccessoryAssertion;
SBHomeGestureParticipant *_homeGestureParticipant;
BOOL _isConnectedToQiPower;
SBHUDController *_HUDController;
SBVolumeControl *_volumeControl;
float _batteryCapacity;
BOOL _supportsDetailedBatteryCapacity;
BOOL _disableAppSwitchForcePressDueToHomeButtonForce;
int _powerStateUpdateToken;
NSMutableDictionary *_powerSourceHasChimed;
int _batteryLoggingStartCapacity;
SBDismissOnlyAlertItem *_unsupportedChargerAlert;
SBAppSwitcherSettings *_switcherSettings;
NSMutableSet *_contentRequiringReasons;
ATXAppDirectoryClient *_appDirectoryClient;
BOOL _disallowsPointerInteraction;
int _firmwareUpdateStateToken;
ACCConnectionInfo *_accessoryConnectionInfo;
BSTimer *_accessoryAttachmentAnimationBlockingTimer;
SBFMotionAlarmController *_motionAlarmController;
BOOL _disableChimeForWirelessCharging;
BOOL _disableScreenWakeForWirelessCharging;
BSPersistentTimer *_debounceWirelessChargingTimer;
BOOL _isAccessoryAnimationAllowed;
CSAccessory *_lastAttachedAccessory;
CSAccessory *_lastDetachedAccessory;
NSMutableDictionary *_accessoriesAttachedByUUID;
}


@property (readonly, nonatomic) SBIconController *iconController; // ivar: _iconController
@property (nonatomic) BOOL chargingChimeEnabled; // ivar: _chargingChimeEnabled
@property (nonatomic) BOOL homeScreenAutorotatesEvenWhenIconIsDragging;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) BOOL onAC;
@property (readonly, nonatomic) BOOL connectedToExternalChargingSource;
@property (readonly, nonatomic) BOOL connectedToWirelessInternalCharger;
@property (readonly, nonatomic) BOOL connectedToWirelessInternalChargingAccessory;
@property (readonly, nonatomic) BOOL connectedToQiPower;
@property (readonly, nonatomic) CSAccessory *lastAttachedAccessory;
@property (readonly, nonatomic) CSAccessory *lastDetachedAccessory;
@property (readonly, nonatomic) BOOL isAccessoryAnimationAllowed;


-(void)disableAnimationForNextIconRotation;
-(float)batteryCapacity;
-(void)_hideKeyboard;
-(void)wallpaperLegibilitySettingsDidChange:(id)arg0 forVariant:(NSInteger)arg1 ;
-(void)cancelInProcessAnimations;
-(BOOL)handleHomeButtonDoublePressDown;
-(void)wallpaperDidChangeForVariant:(NSInteger)arg0 ;
-(void)setAllowIconRotation:(BOOL)arg0 forReason:(id)arg1 ;
-(void)_setConnectedToWindowedAccessory:(BOOL)arg0 ;
-(BOOL)homeScreenAutorotatesEvenWhenIconIsDragging;
-(void)nudgeIconInterfaceOrientation:(NSInteger)arg0 duration:(CGFloat)arg1 ;
-(void)cancelVolumeEvent;
-(id)_legibilitySettings;
-(void)_playAccessoryChimeIfAppropriateForAccessory:(id)arg0 attaching:(BOOL)arg1 withDelay:(CGFloat)arg2 ;
-(void)handleWillBeginReachabilityAnimation;
-(void)connectedDevicesDidChange:(id)arg0 ;
-(void)endRequiringContentForReason:(id)arg0 ;
-(void)activateApplication:(id)arg0 fromIcon:(id)arg1 location:(id)arg2 activationSettings:(id)arg3 actions:(id)arg4 ;
-(void)settings:(id)arg0 changedValueForKey:(id)arg1 ;
-(void)beginRequiringLiveBackdropViewForReason:(id)arg0 ;
-(void)_resetWirelessChargingState;
-(void)_switchToHomeScreenWallpaperAnimated:(BOOL)arg0 ;
-(void)restoreContentAndUnscatterIconsAnimated:(BOOL)arg0 withCompletion:(id)arg1 ;
-(BOOL)isHeadsetDocked;
-(void)setHomeScreenAlpha:(CGFloat)arg0 behaviorMode:(NSInteger)arg1 completion:(id)arg2 ;
-(void)tearDownIconListAndBar;
-(BOOL)isFakeStatusBarStyleEffectivelyDoubleHeight:(NSInteger)arg0 ;
-(void)handleVolumeButtonWithType:(NSInteger)arg0 down:(BOOL)arg1 ;
-(void)setPointerInteractionsEnabled:(BOOL)arg0 ;
-(void)_disableWirelessChargingChimeAndScreenWakeForDuration:(CGFloat)arg0 withMotionAlarm:(BOOL)arg1 ;
-(void)_setupHomeScreenDimmingWindow;
-(void)noteStatusBarHeightChanged:(id)arg0 ;
-(BOOL)isBackdropVisible;
-(void)setLastDetachedAccessory:(id)arg0 ;
-(BOOL)_shouldInitiateAnimationForAccessory:(id)arg0 ;
-(void)_enumeratePowerSourcesWithBlock:(id)arg0 ;
-(void)setIsAccessoryAnimationAllowed:(BOOL)arg0 ;
-(void)configureFakeSpringBoardStatusBarWithStyleRequest:(id)arg0 ;
-(BOOL)isConnectedToWindowedAccessory;
-(void)animateFakeStatusBarWithParameters:(id)arg0 transition:(id)arg1 ;
-(void)updateStatusBarLegibility;
-(void)restoreContent;
-(void)_deviceUILocked;
-(void)beginRequiringBackdropViewForReason:(id)arg0 ;
-(void)_updateLegibility;
-(void)endRequiringBackdropViewForReason:(id)arg0 ;
-(id)window;
-(BOOL)_powerSourceWantsToPlayChime;
-(void)removeDetachedAccessory:(id)arg0 ;
-(void)_backgroundContrastDidChange:(id)arg0 ;
-(void)homeScreenBackdropView:(id)arg0 opaquenessDidChange:(BOOL)arg1 ;
-(void)_disableWirelessChargingChimeAndScreenWakeForDuration:(CGFloat)arg0 ;
-(id)contentView;
-(void)setHomeScreenScale:(CGFloat)arg0 behaviorMode:(NSInteger)arg1 completion:(id)arg2 ;
-(id)scalingView;
-(void)restoreContentAndUnscatterIconsAnimated:(BOOL)arg0 afterDelay:(CGFloat)arg1 withCompletion:(id)arg2 ;
-(void)handleDidEndReachabilityAnimation;
-(id)succinctDescriptionBuilder;
-(NSInteger)transitionSourceForIcon:(id)arg0 iconLocation:(id)arg1 ;
-(void)_setDebounceWirelessChargingTimerWithDuration:(CGFloat)arg0 ;
-(void)windowedAccessoryDismissed;
-(void)restoreContentAndUnscatterIconsAnimated:(BOOL)arg0 ;
-(void)setHomeScreenBlurProgress:(CGFloat)arg0 behaviorMode:(NSInteger)arg1 completion:(id)arg2 ;
-(void)endRequiringLiveBackdropViewForReason:(id)arg0 ;
-(void)beginRequiringContentForReason:(id)arg0 options:(NSUInteger)arg1 ;
-(void)_activateApplicationFromAccessibility:(id)arg0 ;
-(BOOL)dissmissAlertItemsAndSheetsIfPossible;
-(BOOL)isBatteryCharging;
-(void)removeFakeSpringBoardStatusBar;
-(void)interactionProgressDidUpdate:(id)arg0 ;
-(void)possiblyWakeForPowerStatusChangeWithUnlockSource:(int)arg0 ;
-(void)_setAccessoryAttachmentAnimationBlockingTimerWithDuration:(CGFloat)arg0 ;
-(void)_activateWorkspaceEntity:(id)arg0 fromIcon:(id)arg1 location:(id)arg2 validator:(id)arg3 ;
-(id)_currentHomeScreenLegibilitySettings;
-(id)init;
-(BOOL)_isAccessoryAttached:(NSInteger)arg0 ;
-(void)_cancelDebounceWirelessChargingTimer;
-(id)workflowClientFromWebClip:(id)arg0 appToLaunch:(id)arg1 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(void)_debounceWirelessChargingTimerFired;
-(int)batteryCapacityAsPercentage;
-(void)suppressChimeForConnectedPowerSources;
-(BOOL)isHeadsetBatteryCharging;
-(BOOL)_shouldShowAnimationForAccessory:(id)arg0 ;
-(id)succinctDescription;
-(void)interactionProgress:(id)arg0 didEnd:(BOOL)arg1 ;
-(BOOL)isFullyCharged;
-(void)_accessibilityWillBeginAppSwitcherRevealAnimation;
-(BOOL)supportsDetailedBatteryCapacity;
-(void)playChargingChimeIfAppropriate;
-(BOOL)_isConnectedToWirelessCharging;
-(void)didDetectDeviceMotion;
-(void)windowedAccessoryPresented;
-(struct CGRect )visibleScreenCoordinatesForWindowedAccessory;
-(void)setFakeSpringBoardStatusBarVisible:(BOOL)arg0 ;
-(BOOL)chargingChimeEnabled;
-(BOOL)isConnectedToUnsupportedChargingAccessory;
-(void)accessoryEndpointAttached:(id)arg0 transportType:(int)arg1 protocol:(int)arg2 properties:(id)arg3 forConnection:(id)arg4 ;
-(void)setIsConnectedToUnsupportedChargingAccessory:(BOOL)arg0 ;
-(void)_removeReachabilityEffectViewIfNecessary;
-(BOOL)isIconListViewTornDown;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)_setupHomeScreenContentBackdropView;
-(void)beginRequiringContentForReason:(id)arg0 ;
-(void)_animationBlockingTimerFired;
-(void)restoreContentWithOptions:(NSUInteger)arg0 ;
-(void)_reduceMotionStatusDidChange:(id)arg0 ;
-(void)statusBarOverridesDidChange:(id)arg0 ;
-(void)configureFakeSpringBoardStatusBarWithDefaultStyleRequestForStyle:(NSInteger)arg0 ;
-(BOOL)handleHomeButtonSinglePressUpWithSourceType:(NSUInteger)arg0 ;
-(BOOL)handleHomeButtonSinglePressUp;
-(void)ACPowerChanged;
-(void)updateBatteryState:(id)arg0 ;
-(NSInteger)interfaceOrientationForWallpaperController:(id)arg0 ;
-(unsigned char)headsetBatteryCapacity;
-(BOOL)isAccessoryAnimationAllowed;
-(void)_willRevealOrHideContentView;
-(BOOL)isConnectedToChargeIncapablePowerSource;
-(void)storeAttachedAccessory:(id)arg0 ;
-(void)dealloc;
-(void)setLastAttachedAccessory:(id)arg0 ;
-(BOOL)isConnectedToWirelessInternalAccessory;
-(void)setHomeScreenDimmingAlpha:(CGFloat)arg0 behaviorMode:(NSInteger)arg1 completion:(id)arg2 ;
-(void)_closeOpenFolderIfNecessary;
-(id)fakeStatusBarStyleRequestForStyle:(NSInteger)arg0 ;
+(struct CGRect )statusBarFrameForSnapshotFrame:(struct CGRect )arg0 orientation:(NSInteger)arg1 statusBarStyleRequest:(id)arg2 hidden:(BOOL)arg3 ;
+(id)sharedInstance;
+(id)zoomViewForDeviceApplicationSceneHandle:(id)arg0 displayConfiguration:(id)arg1 interfaceOrientation:(NSInteger)arg2 snapshot:(id)arg3 snapshotSize:(struct CGSize )arg4 statusBarDescriptor:(id)arg5 decodeImage:(BOOL)arg6 ;
+(struct CGRect )statusBarFrameForDeviceApplicationSceneHandle:(id)arg0 displayConfiguration:(id)arg1 interfaceOrientation:(NSInteger)arg2 statusBarStyleRequest:(id)arg3 withinBounds:(struct CGRect )arg4 inReferenceSpace:(BOOL)arg5 ;
+(id)_effectiveStatusBarSettingsForSnapshot:(id)arg0 sceneHandle:(id)arg1 ;
+(struct CGAffineTransform )_transformAndFrame:(struct CGRect *)arg0 forLaunchImageHostViewWithOrientation:(NSInteger)arg1 statusBarHeight:(CGFloat)arg2 inJailRect:(struct CGRect )arg3 ;
+(id)sharedInstanceIfExists;
+(struct CGRect )statusBarFrameForSnapshotFrame:(struct CGRect )arg0 remainderFrame:(struct CGRect *)arg1 orientation:(NSInteger)arg2 statusBarStyleRequest:(id)arg3 hidden:(BOOL)arg4 ;


@end


#endif


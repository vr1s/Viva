// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SPRINGBOARD_H
#define SPRINGBOARD_H

@protocol OS_dispatch_source, OS_os_transaction, SBFLockOutStatusProvider;

@class SBSStatusBarStyleOverridesAssertion;
@class SSScreenCapturer;
@class SBScreenTimeTrackingController;
@class DNDAWDMetricsService;
@class DNDNotificationsService;
@class DNDToggleManager;
@class STMediaStatusDomain;
@class RSPeerToPeerServerController;
@class SBFUserAuthenticationController;
@class STStatusServer;
@class STDynamicActivityAttributionManager;
@class STTelephonyStateProvider;
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBUIController;
@class SBApplication;
@class SBCardItemsController;
@class SBAppStatusBarSettingsAssertion;
@class SBBluetoothAccessoryBatteryMonitor;
@class SBDeveloperBuildExpirationTrigger;
@class SBSynchronizeCloudCriticalDataOperation;
@class SBModalAlertPresenter;
@class SBMainDisplayInterfaceOrientationAggregator;
@class SBDeviceOrientationUpdateManager;
@class SBPressPrecedenceArbiter;
@class SBMainWorkspace;
@class SBModalUIFluidDismissGestureManager;
@class SBCarDoNotDisturbController;
@class SBExternalDisplayManager;
@class SBSpuriousScreenUndimmingAssertion;
@class SBHomeScreenService;
@class SBChronoHomeScreenUsageObserver;
@class SBChronoApplicationProcessStateObserver;
@class SBAppSwitcherSystemService;
@class SBRemoteAlertHandleServer;
@class SBTestAutomationService;
@class SBStateDumpService;
@class SBSpotlightTransientOverlayViewController;
@class SBMousePointerManager;
@class SBAccessibilityWindowHostingControllerServer;
@class SBKeyboardBrightnessController;
@class SBDisplayBrightnessController;
@class SBCombinationHardwareButton;
@class SBUserSessionController;
@class SBHomeHardwareButton;
@class SBLockHardwareButton;
@class SBVolumeHardwareButton;
@class SBCameraHardwareButton;
@class SBVoiceCommandButton;
@class SBScreenshotManager;
@class SBNCNotificationDispatcher;
@class SBBannerManager;
@class SBWidgetController;
@class SBAvocadoDebuggingController;
@class SBRestartManager;
@class SBModalAlertPresentationCoordinator;
@class SBAccountStoreManager;
@class SBLockScreenService;
@class SBApplicationAutoLaunchService;
@class SBApplicationLaunchAlertService;
@class SBIdleTimerPolicyAggregator;
@class SBInteractiveScreenshotGestureManager;
@class SBProximitySensorManager;
@class SBSoftwareUpdatePasscodePolicyManager;
@class SBSensorActivityDataProvider;
@class SBRecordingIndicatorManager;
@class SBSystemPointerInteractionManager;
@class SBLockedPointerManager;
@class SBWebClipService;
@class SBAppClipOverlayCoordinator;
@class SBRemoteTransientOverlaySessionManager;
@protocol MCProfileConnectionObserver;
@protocol RSPeerToPeerConnectionControllerDataSource;
@protocol SBRestartManagerDelegate;
@protocol SBModalAlertPresentationCoordinatorDelegate;
@protocol UIStatusBarStyleDelegate_SpringBoardOnly;
@protocol SSScreenCapturerDelegate;
@protocol SBBacklightControllerObserver;
@protocol SBInteractiveScreenshotGestureManagerDelegate;
@protocol SBRemoteTransientOverlaySessionManagerDelegate;
@protocol SBSpotlightTransientOverlayViewControllerDelegate;
@protocol _UIApplicationInitializationContextFactory;
@protocol SBAVSystemControllerCacheObserver;
@protocol UIApplicationDelegate;
@protocol SBIdleTimerProviding;
@protocol SBProximityBacklightPolicy;
@protocol BSInvalidatable;
@protocol BSInvalidatable;
@protocol SBIdleTimer;
@protocol SBUIUserAgent;

@interface SpringBoard : UIApplication <MCProfileConnectionObserver, RSPeerToPeerConnectionControllerDataSource,
SBRestartManagerDelegate, SBModalAlertPresentationCoordinatorDelegate, UIStatusBarStyleDelegate_SpringBoardOnly,
SSScreenCapturerDelegate, SBBacklightControllerObserver, SBInteractiveScreenshotGestureManagerDelegate,
SBRemoteTransientOverlaySessionManagerDelegate, SBSpotlightTransientOverlayViewControllerDelegate,
_UIApplicationInitializationContextFactory, SBAVSystemControllerCacheObserver, UIApplicationDelegate,
SBIdleTimerProviding>

@property (retain, nonatomic) NSMutableArray *nowLocatingApps; // ivar: _nowLocatingApps
@property (retain, nonatomic) NSObject<SBIdleTimer> *idleTimer; // ivar: _idleTimer
@property (retain, nonatomic) NSTimer *daylightSavingsTimer; // ivar: _daylightSavingsTimer
@property (nonatomic) int nowPlayingProcessPID; // ivar: _nowPlayingProcessPID
@property (nonatomic) BOOL batterySaverModeActive; // ivar: _batterySaverModeActive
@property (readonly, nonatomic) SBCombinationHardwareButton *combinationHardwareButton; // ivar: _combinationHardwareButton
@property (retain, nonatomic) RSPeerToPeerServerController *stateDumpServerController; // ivar: _stateDumpServerController
@property BOOL hasFinishedLaunching; // ivar: _hasFinishedLaunching
@property (nonatomic) BOOL typingActive; // ivar: _typingActive
@property (nonatomic) CGFloat bottomEdgeAmbiguousActivationMargin; // ivar: _bottomEdgeAmbiguousActivationMargin
@property (readonly, nonatomic) NSObject<SBUIUserAgent> *pluginUserAgent; // ivar: _pluginUserAgent
@property (readonly, nonatomic) SBApplication *leastRecentlyForegroundLocatingApp;
@property (readonly, nonatomic) SBUserSessionController *userSessionController; // ivar: _userSessionController
@property (readonly, nonatomic) SBHomeHardwareButton *homeHardwareButton; // ivar: _homeHardwareButton
@property (readonly, nonatomic) SBLockHardwareButton *lockHardwareButton; // ivar: _lockHardwareButton
@property (readonly, nonatomic) SBVolumeHardwareButton *volumeHardwareButton; // ivar: _volumeHardwareButton
@property (readonly, nonatomic) SBCameraHardwareButton *cameraHardwareButton; // ivar: _cameraHardwareButton
@property (readonly, nonatomic) SBVoiceCommandButton *voiceCommandButton; // ivar: _voiceCommandButton
@property (readonly, nonatomic) NSObject<SBFLockOutStatusProvider> *lockOutController; // ivar: _lockOutController
@property (readonly, nonatomic) SBFUserAuthenticationController *authenticationController; // ivar: _authenticationController
@property (readonly, nonatomic) SBScreenshotManager *screenshotManager; // ivar: _screenshotManager
@property (readonly, nonatomic) SBNCNotificationDispatcher *notificationDispatcher; // ivar: _notificationDispatcher
@property (readonly, nonatomic) SBBannerManager *bannerManager; // ivar: _bannerManager
@property (readonly, nonatomic) SBWidgetController *widgetController; // ivar: _widgetController
@property (readonly, nonatomic) SBAvocadoDebuggingController *avocadoController; // ivar: _avocadoController
@property (readonly, nonatomic) SBRestartManager *restartManager; // ivar: _restartManager
@property (readonly, nonatomic) SBModalAlertPresentationCoordinator *modalAlertPresentationCoordinator; // ivar: _modalAlertPresentationCoordinator
@property (readonly, nonatomic) SBAccountStoreManager *accountStoreController; // ivar: _accountStoreController
@property (readonly, nonatomic) NSArray *appsRegisteredForVolumeEvents; // ivar: _appsRegisteredForVolumeEvents
@property (readonly, nonatomic) NSArray *appsRegisteredForLockButtonEvents; // ivar: _appsRegisteredForLockButtonEvents
@property (readonly, nonatomic) SBLockScreenService *lockScreenService; // ivar: _lockScreenService
@property (readonly, nonatomic) SBApplicationAutoLaunchService *applicationAutoLaunchService; // ivar: _applicationAutoLaunchService
@property (readonly, nonatomic) SBApplicationLaunchAlertService *applicationLaunchAlertService; // ivar: _applicationLaunchAlertService
@property (readonly, nonatomic) SBIdleTimerPolicyAggregator *idleTimerPolicyAggregator; // ivar: _idleTimerPolicyAggregator
@property (readonly, nonatomic) SBInteractiveScreenshotGestureManager *interactiveScreenshotGestureManager; // ivar: _interactiveScreenshotGestureManager
@property (readonly, nonatomic) SBProximitySensorManager *proximitySensorManager; // ivar: _proximitySensorManager
@property (readonly, nonatomic) SBMainDisplayInterfaceOrientationAggregator *orientationAggregator;
@property (readonly, nonatomic) SBSoftwareUpdatePasscodePolicyManager *softwareUpdatePasscodePolicyManager; // ivar: _softwareUpdatePasscodePolicyManager
@property (readonly, nonatomic) STStatusServer *systemStatusServer; // ivar: _systemStatusServer
@property (readonly, nonatomic) STDynamicActivityAttributionManager *dynamicAttributionManager; // ivar: _dynamicAttributionManager
@property (readonly, nonatomic) STTelephonyStateProvider *telephonyStateProvider; // ivar: _telephonyStateProvider
@property (readonly, nonatomic) SBSensorActivityDataProvider *sensorActivityDataProvider; // ivar: _sensorActivityDataProvider
@property (readonly, nonatomic) SBRecordingIndicatorManager *recordingIndicatorManager; // ivar: _recordingIndicatorManager
@property (readonly, nonatomic) SBSystemPointerInteractionManager *systemPointerInteractionManager; // ivar: _systemPointerInteractionManager
@property (readonly, nonatomic) SBLockedPointerManager *lockedPointerManager; // ivar: _lockedPointerManager
@property (readonly, nonatomic) SBWebClipService *webClipService; // ivar: _webClipService
@property (readonly, nonatomic) SBAppClipOverlayCoordinator *appClipOverlayCoordinator; // ivar: _appClipOverlayCoordinator
@property (readonly, nonatomic) int ringerSwitchState; // ivar: _ringerSwitchState
@property (readonly, nonatomic) SBRemoteTransientOverlaySessionManager *remoteTransientOverlaySessionManager; // ivar: _remoteTransientOverlaySessionManager
@property (readonly, nonatomic) BOOL wantsOrientationEvents;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (retain, nonatomic) UIWindow *window;


-(void)addInCallApp:(id)arg0 ;
-(BOOL)canOpenURL:(id)arg0 ;
-(void)_handleKeyUIEvent:(id)arg0 ;
-(void)endIgnoringInteractionEvents;
-(void)_toggleFloatingDockVisibility:(id)arg0 ;
-(BOOL)underMemoryPressure;
-(void)_takeScreenshotAndEdit:(BOOL)arg0 ;
-(BOOL)expectsFaceContact;
-(NSInteger)startupInterfaceOrientation;
-(void)_runSpotlightTodayViewRotation;
-(void)_performPanWithComposer:(id)arg0 startLocation:(struct CGPoint )arg1 endLocation:(struct CGPoint )arg2 duration:(CGFloat)arg3 ;
-(BOOL)handleDoubleHeightStatusBarTapWithStyleOverride:(int)arg0 ;
-(BOOL)_shouldSwallowHIDEvent:(struct __IOHIDEvent *)arg0 ;
-(void)_handleKeyDownEvent_KeyboardBrightnessChange:(struct __IOHIDEvent *)arg0 modifiers:(NSInteger)arg1 ;
-(void)_adjustDaylightSavingsTimerAfterSleep;
-(void)_nowPlayingAppDidChangeNotification:(id)arg0 ;
-(BOOL)_handlePhysicalButtonEvent:(id)arg0 ;
-(void)_runTodayViewScrollWidgetsTestWithOptions:(id)arg0 ;
-(BOOL)menuButtonInterceptAppEnabledForever;
-(BOOL)handleStatusBarHoverActionForRegion:(NSInteger)arg0 ;
-(id)transactionForDismissingSearchTransientOverlay;
-(void)_runLockScreenScrollNotificationsTestWithOptions:(id)arg0 ;
-(void)endIgnoringInteractionEventsForReason:(id)arg0 ;
-(void)_runFourFingerSwipeMultipleAppsTest;
-(void)noteInterfaceOrientationChanged:(NSInteger)arg0 logMessage:(id)arg1 ;
-(void)_runDashBoardScrollToLeftPageTestWithBlur:(BOOL)arg0 ;
-(BOOL)iapIsInExtendedMode;
-(CGFloat)_accessibilityDeactivationAnimationStartDelay;
-(void)_batterySaverModeChanged:(int)arg0 ;
-(void)_runWidgetConfigurationTransitionFromEditingMode:(BOOL)arg0 ;
-(void)_handleScreenShotShortcut:(id)arg0 ;
-(void)_handleShutDownAndReboot;
-(void)restartManagerWillReboot:(id)arg0 ;
-(void)_pullDownToSpotlightForView:(id)arg0 offset:(CGFloat)arg1 duration:(CGFloat)arg2 completion:(id)arg3 ;
-(BOOL)launchedForUserTransition;
-(id)formattedPercentStringForNumber:(id)arg0 ;
-(void)_performOrbAtPoint:(struct CGPoint )arg0 fromView:(id)arg1 withCompletion:(id)arg2 ;
-(void)requestDeviceUnlock;
-(void)wipeDeviceNowWithReason:(id)arg0 ;
-(void)_iapExtendedModeReset;
-(void)_preheatScreenshotsWithPresentationOptions:(id)arg0 ;
-(BOOL)remoteTransientOverlaySessionManager:(id)arg0 shouldActivateOverlayWithContext:(id)arg1 forSession:(id)arg2 ;
-(void)setAppRegisteredForLockButtonEvents:(id)arg0 isActive:(BOOL)arg1 ;
-(void)_performDelayedHeadsetClickTimeout;
-(void)_runDashBoardPresentDismissPasscode;
-(void)_runFourFingerSwipeTest;
-(void)_waitForCloudCriticalData;
-(void)removeDisableActiveInterfaceOrientationChangeAssertion:(id)arg0 nudgeOrientationIfRemovingLast:(BOOL)arg1 ;
-(void)setSystemVolumeHUDEnabled:(BOOL)arg0 forAudioCategory:(id)arg1 ;
-(void)localeChanged;
-(void)_lockdownActivationChanged:(id)arg0 ;
-(void)_setStatusBarOrientation:(NSInteger)arg0 logMessage:(id)arg1 ;
-(void)_runArcSwipeMultipleAppsTest;
-(id)coordinatorRequestedIdleTimerBehavior:(id)arg0 ;
-(void)addDisableActiveInterfaceOrientationChangeAssertion:(id)arg0 ;
-(void)_runTodayViewPullDownToSpotlight;
-(void)handleLockButtonPressFromTransientOverlayViewController:(id)arg0 ;
-(void)_endRequiringSpotlightTransientOverlayForReason:(id)arg0 ;
-(BOOL)disablesFrontBoardImplicitWindowScenes;
-(void)startLaunchTestNamed:(id)arg0 options:(id)arg1 withCompletionBlock:(id)arg2 ;
-(void)_simulateHomeButtonPress;
-(void)restartManagerWillShutdown:(id)arg0 ;
-(void)removeInCallApp;
-(void)_caseLatchWantsToAttemptLock;
-(id)_accessibilityTopDisplay;
-(void)_runDashBoardRotateCameraPage;
-(void)_removeRecordingStatusBarStyleOverrideAssertion;
-(BOOL)_statusBarOrientationFollowsWindow:(id)arg0 ;
-(id)_dashBoardTodayControllerForTestingIfExists;
-(void)applicationOpenURL:(id)arg0 ;
-(BOOL)shouldNeverLock;
-(id)_leadingNotificationRequest;
-(id)modalAlertPresentationCoordinatorRequestedForegroundScenes:(id)arg0 ;
-(void)_turnScreenOnAndUnlockWithCompletion:(id)arg0 ;
-(void)_runAutoPiPWithGestureTest:(id)arg0 ;
-(void)_applicationOpenURL:(id)arg0 withApplication:(id)arg1 animating:(BOOL)arg2 activationSettings:(id)arg3 origin:(id)arg4 withResult:(id)arg5 ;
-(NSInteger)activeInterfaceOrientation;
-(void)_significantTimeDidChange:(BOOL)arg0 ;
-(void)willDisplayMiniAlert;
-(void)_cleanupMainWorkspaceForMedusaTestWithCompletion:(id)arg0 ;
-(void)_runDoSiDoTest;
-(void)_setupMainWorkspaceForMedusaTestWithOptions:(id)arg0 completion:(id)arg1 ;
-(id)allowedRemotePeerDisplayNames;
-(void)_handleDeviceOrientationChangedEvent:(struct __GSEvent *)arg0 ;
-(BOOL)smartCoverIsClosed;
-(void)spotlightTransientOverlayViewControllerWillDismiss:(id)arg0 ;
-(void)_handleApplicationProcessStateDidChangeNotification:(id)arg0 ;
-(void)_runDashBoardDismissFromTodayViewWhileAuthenticatedTest;
-(void)_disableRemoteStateDumpWithCompletion:(id)arg0 ;
-(void)_runDashBoardDismissFromPasscodeViewAfterAuthenticationTest;
-(void)_performExpandingCoalescedBundleForNotificationRequest:(id)arg0 withCompletion:(id)arg1 ;
-(void)_handleGotoHomeScreenShortcut:(id)arg0 ;
-(void)_performNotificationPublishingWithCount:(NSUInteger)arg0 uniqueThreadCount:(NSUInteger)arg1 withCompletion:(id)arg2 ;
-(void)spotlightTransientOverlayViewControllerRequestsDismissal:(id)arg0 ;
-(NSInteger)remoteTransientOverlaySessionManager:(id)arg0 activeWallpaperVariantForSession:(id)arg1 ;
-(id)_accessibilityFrontMostApplication;
-(void)_screenshotWindowWillBeDisplayed;
-(void)restartManager:(id)arg0 willRestartWithTransitionRequest:(id)arg1 ;
-(BOOL)isCurrentlyDeferringOrientationUpdates;
-(void)_unscatterWillBegin:(id)arg0 ;
-(id)keyCommands;
-(void)_handleSnapshotButtonHIDEvent:(struct __IOHIDEvent *)arg0 buttonIsDown:(BOOL)arg1 fromSource:(int)arg2 ;
-(void)_runAppSearchDismiss;
-(void)setUpDaylightSavingsTimer;
-(NSInteger)_currentNonFlatDeviceOrientation;
-(void)_runScrollIconListTestEditing:(BOOL)arg0 withFolders:(BOOL)arg1 withWidgets:(BOOL)arg2 ;
-(void)_simulateLockButtonPress;
-(void)_handleKeyDownEvent_DisplayBrightnessChange:(struct __IOHIDEvent *)arg0 modifiers:(NSInteger)arg1 ;
-(void)_setAmbiguousControlCenterActivationMargin:(CGFloat)arg0 ;
-(void)startLaunchTestNamed:(id)arg0 options:(id)arg1 ;
-(void)_significantTimeChangeNotificationReceived;
-(BOOL)_isDim;
-(void)_takeScreenshotWithOptionsCollection:(id)arg0 presentationOptions:(id)arg1 ;
-(void)_setDeferredHeadsetButtonDownEvent:(struct __IOHIDEvent *)arg0 ;
-(void)applicationDidFinishLaunching:(id)arg0 ;
-(void)modalAlertPresentationCoordinator:(id)arg0 didChangeShowingSystemModalAlert:(BOOL)arg1 ;
-(BOOL)_accessibilityShouldAllowIconLaunch;
-(void)_runMedusaSplitViewResizeTest:(id)arg0 withOptions:(id)arg1 ;
-(void)_performTapAtPoint:(struct CGPoint )arg0 fromView:(id)arg1 withCompletion:(id)arg2 ;
-(void)_runDashBoardRotationTestWithCompletion:(id)arg0 ;
-(void)_performPanGesturesOnScreenUntilOnDefaultHomeScreenIconPageWithCompletion:(id)arg0 ;
-(void)runFolderRotationTest:(int)arg0 ;
-(void)backlightController:(id)arg0 willAnimateBacklightToFactor:(float)arg1 source:(NSInteger)arg2 ;
-(id)_dashBoardCombinedListViewController;
-(void)_runSwipeToHomeOverFolderTest;
-(void)_headsetButtonDown:(struct __IOHIDEvent *)arg0 ;
-(void)noteMainTransientOverlayPresentationManagerWillChangeToInterfaceOrientation:(NSInteger)arg0 ;
-(BOOL)application:(id)arg0 handleOpenURL:(id)arg1 ;
-(void)_updateRecordingPIDFromActivities:(id)arg0 ;
-(void)_handleEndOfScrollingTest:(id)arg0 ;
-(id)_applicationToUseForScrollTesting;
-(void)_runDashBoardScrollToRightPageTestWithBlur:(BOOL)arg0 ;
-(void)_runTodayViewFocusSearchFieldToSpotlight;
-(NSInteger)homeScreenRotationStyle;
-(void)_performRestackingExpandedBundleForNotificationRequest:(id)arg0 withCompletion:(id)arg1 ;
-(void)_runAppSwitcherDismissTestOverApp:(BOOL)arg0 rotated:(BOOL)arg1 completion:(id)arg2 ;\
-(BOOL)isLocked;
-(void)_removeTransientActiveInterfaceOrientationOverrideForReason:(id)arg0 ;
-(void)addNowLocatingApp:(id)arg0 ;
-(void)setSuspensionAnimationDelay:(CGFloat)arg0 ;
-(void)handleKeyHIDEvent:(struct __IOHIDEvent *)arg0 ;
-(void)_postSpringBoardSignificantTimeChangedNotificationWithLogMessage:(id)arg0 ;
-(void)setNowPlayingInfo:(id)arg0 forProcessWithPID:(int)arg1 ;
-(void)_runBottomEdgeSwipeTestFromHomeScreen:(BOOL)arg0 ;
-(NSInteger)activeInterfaceOrientationWithoutConsideringTransientOverlays;
-(void)launchMusicPlayerSuspended;
-(BOOL)_isRemoteStateDumpEnabled;
-(id)_combinedListViewController;
-(void)_resetHomeScreenToPageIndex:(NSUInteger)arg0 animated:(BOOL)arg1 completion:(id)arg2 ;
-(void)_deactivateReachability;
-(BOOL)lockScreenCameraSupported;
-(void)handleDeferredUILockForInCallPresentation;
-(BOOL)isBundleIdentifierRestrictionDisabled:(id)arg0 ;
-(void)cache:(id)arg0 didUpdateActiveAudioRoute:(id)arg1 ;
-(void)_performArcSwipeWithComposer:(id)arg0 ;
-(void)_ringerChanged:(struct __IOHIDEvent *)arg0 ;
-(void)_adjustSignificantTimersAfterSleep;
-(void)_handleLockShortcut:(id)arg0 ;
-(void)_runAppSwitcherBringupTestOverApp:(BOOL)arg0 rotated:(BOOL)arg1 completion:(id)arg2 ;
-(void)_runPresentContinuityBannerInSwitcherTestWithCompletion:(id)arg0 ;
-(void)noteBacklightFadeFinished;
-(void)_runMedusaPinFloatingApplicationTest:(id)arg0 withOptions:(id)arg1 ;
-(void)_resetToHomeScreen;
-(void)setWantsVolumeButtonEvents:(BOOL)arg0 ;
-(void)_runHomeScreenSwipeLeftToTodayView;
-(void)_runNotificationCoalescingExpandingTestWithOptions:(id)arg0 ;
-(BOOL)runTest:(id)arg0 options:(id)arg1 ;
-(void)_cleanUpLaunchTestState;
-(id)_homeScreenTodayViewEventStreamWithDismissal:(BOOL)arg0 ;
-(void)_broadcastStateCaptureToConnectedRemotePeers:(id)arg0 ;
-(void)screenCapturer:(id)arg0 didCaptureScreenshotsOfScreens:(id)arg1 ;
-(void)frontDisplayDidChange:(id)arg0 ;
-(void)_setupNotificationListTest;
-(void)nowLocatingAppDidEnterForeground:(id)arg0 ;
-(void)_handleApplicationExit:(id)arg0 ;
-(void)_localeChanged;
-(void)_runScrollAppSwitcherTest:(id)arg0 overApp:(BOOL)arg1 completion:(id)arg2 ;
-(void)_handleCommandQ:(id)arg0 ;
-(void)_performAfterDelay:(CGFloat)arg0 block:(id)arg1 ;
-(void)_runSwipeUpHomeToAutoPiPTest;
-(void)noteBacklightLevelChanged;
-(void)noteSubstantialTransitionOccured;
-(void)_performFourFingerSwipeWithComposer:(id)arg0 vertically:(BOOL)arg1 duration:(CGFloat)arg2 ;
-(void)_performFiveFingerScrunchWithComposer:(id)arg0 scrunchProgress:(CGFloat)arg1 duration:(CGFloat)arg2 withContinuationBlock:(id)arg3 ;
-(id)_dashBoardControllerForTesting;
-(void)_pauseWithComposer:(id)arg0 locations:(struct CGPoint *)arg1 touchCount:(NSUInteger)arg2 ;
-(void)noteCaseHardwarePresent;
-(id)_doubleHomeButtonPressEventStream;
-(void)_openURLCore:(id)arg0 display:(id)arg1 animating:(BOOL)arg2 activationSettings:(id)arg3 origin:(id)arg4 withResult:(id)arg5 ;
-(void)beginIgnoringInteractionEvents;
-(BOOL)__handleHIDEvent:(struct __IOHIDEvent *)arg0 withUIEvent:(id)arg1 ;
-(void)_rotateView:(id)arg0 toOrientation:(NSInteger)arg1 ;
-(void)_simulateHomeButtonPressWithCompletion:(id)arg0 ;
-(void)_handleCommandTab:(id)arg0 ;
-(void)runFieldTestScript;
-(void)_toggleSearch;
-(void)_runDeweyPullToLibrarySearchWithCompletion:(id)arg0 ;
-(void)_runScrollDeweyLibrarySearchWithCompletion:(id)arg0 ;
-(BOOL)remoteTransientOverlaySessionManager:(id)arg0 performPresentationRequest:(id)arg1 forSession:(id)arg2 ;
-(void)_createInitialAppScene;
-(BOOL)canShowLockScreenCameraGrabber;
-(void)_performPanGesturesOnScreenUntilOnPage:(NSUInteger)arg0 withCompletion:(id)arg1 ;
-(BOOL)caseIsEnabledAndLatched;
-(void)_continueRunningScrollAppSwitcherTest:(id)arg0 runColdTest:(BOOL)arg1 completion:(id)arg2 ;
-(void)_runScrollDeweyTestWithCompletion:(id)arg0 ;
-(id)_findView:(id)arg0 passingTest:(id)arg1 ;
-(BOOL)_accessibilitySystemGesturesDisabledByAccessibility;
-(void)startResumeTestNamed:(id)arg0 options:(id)arg1 ;
-(BOOL)expectsFaceContactInLandscape;
-(void)_removeAllFakeNotifications;
-(void)installNotificationObserverForNotificationName:(id)arg0 forOneNotification:(BOOL)arg1 usingBlock:(id)arg2 ;
-(void)_prepareToRunSwitcherGestureTestsFromHomeScreen:(BOOL)arg0 withCompletion:(id)arg1 ;
-(void)_performScrunchAndSwipeWithComposer:(id)arg0 ;
-(void)_performRightToLeftPanGestureOnScreenWithDuration:(CGFloat)arg0 completion:(id)arg1 ;
-(void)noteKeybagRefetchTransactionIsActive:(BOOL)arg0 ;
-(void)_returnToHomeScreenWithCompletion:(id)arg0 ;
-(void)_runMedusaSplitViewSuspendTest:(id)arg0 withOptions:(id)arg1 ;
-(void)setNextAssistantRecognitionStrings:(id)arg0 ;
-(void)spotlightTransientOverlayViewControllerDidPresent:(id)arg0 ;
-(BOOL)_isStatusBarEffectivelyHiddenForContentOverlayInsetsForWindow:(id)arg0 ;
-(void)_screenshotWindowWasDismissed;
-(void)removeNowLocatingApp:(id)arg0 ;
-(void)_runScrunchHomeToAutoPiPTest;
-(void)setWantsOrientationEvents:(BOOL)arg0 logMessage:(id)arg1 ;
-(void)_runSwipeAndPauseForSwitcherTestFromHomeScreen:(BOOL)arg0 completion:(id)arg1 ;
-(void)_continueRunningDismissAppSwitcherTestWithCompletion:(id)arg0 ;
-(void)takeScreenshot;
-(NSInteger)interfaceOrientationForCurrentDeviceOrientation:(BOOL)arg0 ;
-(void)beginIgnoringInteractionEventsForReason:(id)arg0 ;
-(void)_performDeferredLaunchWork;
-(void)_runDismissContinuityBannerInSwitcherTestWithCompletion:(id)arg0 ;
-(void)_runMedusaMoveFloatingApplicationTest:(id)arg0 withOptions:(id)arg1 ;
-(void)updateNativeOrientationWithOrientation:(NSInteger)arg0 logMessage:(id)arg1 ;
-(NSInteger)_frontMostAppOrientation;
-(CGFloat)_accessibilityActivationAnimationStartDelay;
-(void)_accessibilityDeactivationAnimationWillBegin;
-(void)runHomeScreenRotationIterationWithRemainingIterations:(int)arg0 completionHandler:(id)arg1 ;
-(void)interactiveScreenshotGestureManager:(id)arg0 requestsScreenshotPreheatWithPresentationOptions:(id)arg1 ;
-(void)setupMidnightTimer;
-(void)_setupKeyboardAnimationSubTestsForTestName:(id)arg0 ;
-(id)formattedDecimalStringForNumber:(id)arg0 ;
-(void)_runTapContinuityBannerInSwitcherTestWithCompletion:(id)arg0 ;
-(void)applicationOpenURL:(id)arg0 withApplication:(id)arg1 animating:(BOOL)arg2 activationSettings:(id)arg3 origin:
        (id)arg4 notifyLSOnFailure:(BOOL)arg5 withResult:(id)arg6 ;
-(void)_setReachabilitySupported:(BOOL)arg0 ;
-(void)noteSceneLayoutDidUpdateOnDisplayWithIdentity:(id)arg0 ;
-(void)_rotationCompletion:(id)arg0 ;
-(BOOL)_frontBoardWantsKeyboardSceneLayerOrderedIntoScene;
-(void)_updateHomeScreenPresenceNotification:(id)arg0 ;
-(void)_runScrunchToAppSwitcherTest;
-(void)_runSwipeFromDeweyTestWithCompletion:(id)arg0 ;
-(void)runHomeScreenRotationTest:(int)arg0 ;
-(void)profileConnectionDidReceivePasscodePolicyChangedNotification:(id)arg0 userInfo:(id)arg1 ;
-(void)_performDragFromPoint:(struct CGPoint )arg0 andDragTo:(struct CGPoint )arg1 duration:(CGFloat)arg2 fromView:(id)arg3 withCompletion:(id)arg4 ;
-(void)_prepareToRunSwitcherGestureTestsWithForegroundApp:(id)arg0 shouldStartTest:(BOOL)arg1 withCompletion:(id)arg2 ;
-(void)_midnightPassed;
-(void)_runArcSwipeTestFromHomeScreen:(BOOL)arg0 ;
-(BOOL)_hasForegroundAppWithPID:(int)arg0 ;
-(void)_runDashboardTodayViewScrollWidgetsTestWithOptions:(id)arg0 ;
-(void)restartManagerExitImminent:(id)arg0 ;
-(void)_updateRingerState:(int)arg0 withVisuals:(BOOL)arg1 updatePreferenceRegister:(BOOL)arg2 ;
-(void)_headsetButtonUp:(struct __IOHIDEvent *)arg0 ;
-(id)_defaultExpirationComponents;
-(void)_setDeviceOrientation:(NSInteger)arg0 animated:(BOOL)arg1 logMessage:(id)arg2 ;
-(void)noteInterfaceOrientationChanged:(NSInteger)arg0 duration:(CGFloat)arg1 updateMirroredDisplays:(BOOL)arg2 logMessage:(id)arg3 ;
-(void)_accessibilityActivationAnimationWillBegin;
-(BOOL)remoteTransientOverlaySessionManager:(id)arg0 prefersStatusBarActivityItemVisibleForServiceBundleIdentifier:(id)arg1 forSession:(id)arg2 ;
-(void)_runSpotlightPulldownRotation;
-(BOOL)_accessibilityObjectWithinProximity;
-(void)_handleKeyDownEvent_DoNotDisturb:(struct __IOHIDEvent *)arg0 modifiers:(NSInteger)arg1 ;
-(void)_iapServerConnectionDiedNotification:(id)arg0 ;
-(void)_resetForceRotate;
-(void)_runScrunchAndSwipeTest;
-(void)_basicRotationTestForCurrentConfigurationWithTeardown:(id)arg0 ;
-(void)_runToggleSearchTest;
-(void)rotateIfNeeded:(NSInteger)arg0 completion:(id)arg1 ;
-(BOOL)homeScreenRotationStyleWantsUIKitRotation;
-(void)pushTransientActiveInterfaceOrientation:(NSInteger)arg0 forReason:(id)arg1 ;
-(void)interactiveScreenshotGestureManager:(id)arg0 requestsScreenshotWithOptionsCollection:(id)arg1 presentationOptions:(id)arg2 ;
-(void)batteryStatusDidChange:(id)arg0 ;
-(void)_runDashBoardDismissTestFromPageIndex:(NSUInteger)arg0 showPasscodeView:(BOOL)arg1 ;
-(void)didReceiveMemoryWarning;
-(void)_runCoverSheetNotificationListHistoryRevealTest;
-(void)setAppRegisteredForVolumeEvents:(id)arg0 isActive:(BOOL)arg1 ;
-(id)init;
-(BOOL)allowCaseLatchLockAndUnlock;
-(id)menuButtonInterceptApp;
-(void)didDismissMiniAlert;
-(void)_keyboardAvailabilityChanged;
-(id)_windowForSystemAppButtonEventsForScreen:(id)arg0 ;
-(void)setMenuButtonInterceptApp:(id)arg0 forever:(BOOL)arg1 ;
-(void)_beginRequiringSpotlightTransientOverlayForReason:(id)arg0 ;
-(BOOL)shouldShowAlertForUnhandledURL:(id)arg0 error:(int)arg1 ;
-(id)nowRecordingApp;
-(void)_prepareToRunSwitcherGestureTestsWithCompletion:(id)arg0 ;
-(void)_initializeAndStartObservingDefaultsIfNecessary;
-(void)noteInterfaceOrientationChanged:(NSInteger)arg0 force:(BOOL)arg1 logMessage:(id)arg2 ;
-(void)_runHomeScreenIconPullToSpotlightDismiss;
-(void)removeActiveOrientationObserver:(id)arg0 ;
-(id)_keyWindowForScreen:(id)arg0 ;
-(void)updateNativeOrientationAnimated:(BOOL)arg0 logMessage:(id)arg1 ;
-(void)_turnScreenOnAndAuthenticateWithCompletion:(id)arg0 ;
-(void)showAlertForUnhandledURL:(id)arg0 error:(int)arg1 ;
-(void)_runSwipeToHomeTestWithCompletion:(id)arg0 ;
-(id)_flickTimingFunction;
-(BOOL)isShowingHomescreen;
-(void)_initializeDeferredItems;
-(void)_runScrunchToHomeTest;
-(void)_performMainWorkspaceTransitionWithPrimaryWorkspaceEntity:(id)arg0 sideWorkspaceEntity:(id)arg1 floatingWorkspaceEntity:(id)arg2 spaceConfiguration:(NSInteger)arg3 floatingConfiguration:(NSInteger)arg4 animated:(BOOL)arg5 completion:(id)arg6 ;
-(void)_handleShiftCommandTab:(id)arg0 ;
-(void)updateNativeOrientationAndMirroredDisplays:(BOOL)arg0 logMessage:(id)arg1 ;
-(void)_postActiveInterfaceOrientationChangedNotificationAnimated:(BOOL)arg0 ;
-(void)_runVolumeChangeWithCompletion:(id)arg0 ;
-(BOOL)wantsOrientationEvents;
-(void)_publishFakeThreadedLockScreenNotificationsWithCount:(NSUInteger)arg0 uniqueThreadCount:(NSUInteger)arg1 completion:(id)arg2 ;
-(void)_smartCoverMightHaveOpened:(struct __IOHIDEvent *)arg0 ;
-(BOOL)isNowPlayingAppPlaying;
-(void)_setStatusBarOrientation:(NSInteger)arg0 animated:(BOOL)arg1 logMessage:(id)arg2 ;
-(BOOL)hasFinishedLaunching;
-(void)_returnToHomescreenWithCompletion:(id)arg0 ;
-(void)_updateOrientationDetectionSettings;
-(id)_accessibilityRunningApplications;
-(BOOL)isDeterminingBootTransition;
-(void)_runEnterPageHiding;
-(void)setExpectsFaceContact:(BOOL)arg0 ;
-(id)_applicationToUseForOpenAndCloseTesting;
-(BOOL)interactiveScreenshotGestureManagerShouldPreventGestureRecognition:(id)arg0 ;
-(void)_runSpotlightCoverSheetTodayViewRotation;
-(void)_runSwipeToDeweyTestWithCompletion:(id)arg0 ;
-(void)_performPanGestureTowardsUserInterfaceLayoutDirectionOnScreenWithDuration:(CGFloat)arg0 completion:(id)arg1 ;
-(BOOL)_accessibilityIsSystemGestureActive;
-(NSInteger)rawDeviceOrientationIgnoringOrientationLocks;
-(void)_unlockAnimationDidFinish:(id)arg0 ;
-(void)_performSwipeHomeWithComposer:(id)arg0 ;
-(void)_simulateUserScrollForNotificationListWithCount:(NSUInteger)arg0 completion:(id)arg1 ;
-(void)failedTest:(id)arg0 withResults:(id)arg1 ;
-(void)_runSwipeAndPauseForSwitcherOverFolderTest;
-(void)_runNotificationCoalescingRestackingFromBottomTestWithOptions:(id)arg0 ;
-(void)handleDeferredUILockForInCallPresentationAnimateIfNeeded:(BOOL)arg0 inCallPresentationActive:(BOOL)arg1 ;
-(void)_runDashBoardRotateMainPage;
-(BOOL)supportsPortraitUpsideDownOrientation;
-(void)_keyboardOrCaseLatchWantsToAttemptUnlock:(int)arg0 ;
-(BOOL)launchApplicationWithIdentifier:(id)arg0 suspended:(BOOL)arg1 ;
-(void)registerRemoteAlertSceneViewProvider:(id)arg0 ;
-(BOOL)hasDisableActiveInterfaceOrientationChangeAssertions;
-(void)_daylightSavingsTimeChanged;
-(void)_runHomeScreenSearchPresent;
-(void)_activateSafariWithCompletion:(id)arg0 ;
-(void)_runHomeScreenIconPullToSpotlightWithTestName:(id)arg0 cold:(BOOL)arg1 ;
-(void)_runTodayViewEditingScrollWidgetsTestWithOptions:(id)arg0 ;
-(void)addActiveOrientationObserver:(id)arg0 ;
-(void)_logReliabilityInfoForEvent:(struct __IOHIDEvent *)arg0 source:(int)arg1 ;
-(NSInteger)alertInterfaceOrientation;
-(void)noteInterfaceOrientationChanged:(NSInteger)arg0 duration:(CGFloat)arg1 updateMirroredDisplays:(BOOL)arg2 force:(BOOL)arg3 logMessage:(id)arg4 ;
-(void)_smartCoverDidOpen:(struct __IOHIDEvent *)arg0 ;
-(void)setExpectsFaceContact:(BOOL)arg0 inLandscape:(BOOL)arg1 ;
-(void)_performPanGesturesOnScreenUntilOnDeweyOverlayWithCompletion:(id)arg0 ;
-(BOOL)isKeybagRefetchTransactionActive;
-(void)_application:(id)arg0 statusBarTouchesEnded:(id)arg1 ;
-(void)finishedTest:(id)arg0 extraResults:(id)arg1 waitForNotification:(id)arg2 withTeardownBlock:(id)arg3;
-(void)startedTest:(id)arg0 ;
-(void)languageChanged;
-(void)_runHomeScreenSwipeRightFromTodayView;
-(void)_turnScreenOnOnDashBoardWithCompletion:(id)arg0 ;
-(void)_adjustMidnightTimerAfterSleep;
-(void)_medusaTestWithName:(id)arg0 testOptions:(id)arg1 ;
-(void)stateForStateType:(NSUInteger)arg0 withCompletionHandler:(id)arg1 ;
-(void)_smartCoverDidClose:(struct __IOHIDEvent *)arg0 ;
-(void)_handleHIDEvent:(struct __IOHIDEvent *)arg0 ;
-(void)_runDashBoardScrollFromLeftToRightPageTestWithBlur:(BOOL)arg0 ;
-(void)_performPanGestureAwayFromUserInterfaceLayoutDirectionOnScreenWithDuration:(CGFloat)arg0 completion:(id)arg1 ;
-(id)deviceOrientationUpdateDeferralAssertionWithReason:(id)arg0 ;
-(void)_runHomeScreenSearchDismiss;
-(BOOL)homeScreenSupportsRotation;
-(int)statusBar:(id)arg0 effectiveStyleOverridesForRequestedStyle:(NSInteger)arg1 overrides:(int)arg2 ;
-(BOOL)remoteTransientOverlaySessionManager:(id)arg0 performDismissalRequest:(id)arg1 forSession:(id)arg2 ;
-(void)remoteTransientOverlaySessionManager:(id)arg0 requestsHandlingForButtonEvents:(NSUInteger)arg1 forSession:(id)arg2 viewController:(id)arg3 ;
-(void)_runBottomEdgeSwipeMultipleAppsTest;
-(id)_dumpStateCaptureData;
-(void)_handleStandardFunctionKeyActionWithPreferencesURLString:(id)arg0 modifiers:(NSInteger)arg1 block:(id)arg2 ;
-(void)_runScrunchAndSwipeMultipleAppsTest;
-(BOOL)_shouldPendAlertsForTest:(id)arg0 ;
-(void)endLaunchTest;
-(BOOL)_accessibilityShouldAllowAppLaunch;
-(NSInteger)_testOrientation:(id)arg0 options:(id)arg1 ;
-(void)_runScrollAppSwitcherLandscapeTest:(id)arg0 overApp:(BOOL)arg1 completion:(id)arg2 ;
-(void)registerAnalyticsEventHandlers;
-(void)_startSeekWithDirection:(id)arg0 ;
-(void)unregisterRemoteAlertSceneViewProvider:(id)arg0 ;
-(id)supportedStateTypes;
-(void)_runDashBoardDismissWhileAuthenticatedTest;
-(void)_uninstallModelForTestsAndRestoreAppLayouts:(id)arg0 ;
-(void)_enableRemoteStateDumpWithTimeout:(NSInteger)arg0 withCompletion:(id)arg1 ;
-(void)noteInterfaceOrientationChanged:(NSInteger)arg0 duration:(CGFloat)arg1 logMessage:(id)arg2 ;
-(void)popTransientActiveInterfaceOrientationForReason:(id)arg0 ;
-(id)_installSwitcherModelForSwitcherTests;
-(BOOL)_handleStatusBarHoverActionForRegion:(NSInteger)arg0 ;
-(void)_runNotificationCoalescingExpandingScrollingTestWithOptions:(id)arg0 ;
-(void)_startBulletinBoardServer;
-(void)updateNativeOrientationWithOrientation:(NSInteger)arg0 updateMirroredDisplays:(BOOL)arg1 animated:(BOOL)arg2 logMessage:(id)arg3 ;
-(void)_startScrollAppSwitcherTest:(id)arg0 overApp:(BOOL)arg1 runColdTest:(BOOL)arg2 completion:(id)arg3 ;
-(id)_singleHomeButtonPressEventStream;
-(NSInteger)deviceOrientationForDeferredUpdateIfAny;
-(void)_runDashBoardRotateTodayViewPage;
-(NSInteger)interfaceOrientationForRawOrientation:(NSInteger)arg0 validOrientation:(NSInteger)arg1 ignoringHomeScreenRotationStyle:(BOOL)arg2 ;
-(void)_performLeftToRightPanGestureOnScreenWithDuration:(CGFloat)arg0 completion:(id)arg1 ;
-(void)_runExitPageHiding;
-(id)_settingLanguageStringForNewLanguage;
-(void)_runScrollTestWithScrollView:(id)arg0 options:(id)arg1 completion:(id)arg2 ;
-(void)_runAppSearchPresent;
-(void)updateMirroredDisplayOrientationWithLogMessage:(id)arg0 ;
-(void)_runAppOpen:(BOOL)arg0 withCompletion:(id)arg1 ;
-(BOOL)isSpringBoardStatusBarHidden;
-(void)_dumpLoggingStateCaptureWithCompletion:(id)arg0 ;
-(void)updateNativeOrientationWithLogMessage:(id)arg0 ;
-(id)setNextVoiceRecognitionAudioInputPaths:(id)arg0 ;
+(id)_newApplicationInitializationContext;
+(void)initializeSystemServicesBeforeApplicationDidFinishLaunching;
+(id)_defaultSceneIdentity;


@end


#endif


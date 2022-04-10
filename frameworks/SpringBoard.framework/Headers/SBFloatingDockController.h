// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBFLOATINGDOCKCONTROLLER_H
#define SBFLOATINGDOCKCONTROLLER_H


@class SBFAnalyticsClient;
@class SBReusableViewMap;
@class PTToggleTestRecipe;
@class SBFolderController;

#include <SpringBoardHome/SBFloatingDockViewController.h>
#include <SpringBoardHome/SBIconListView.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBFloatingDockBehaviorAssertion;
@class SBDeviceOrientationUpdateDeferralAssertion;
@class SBFailingSystemGestureRecognizer;
@class SBIconController;
@class SBMainScreenActiveInterfaceOrientationWindow;
@class SBLayoutStateTransitionCoordinator;
@class SBHomeGestureParticipant;
@class SBIndirectPanGestureRecognizer;
@class SBApplication;
@protocol SBFloatingDockRootViewControllerDelegate;
@protocol SBFolderPresentationObserver;
@protocol SBSystemGestureRecognizerDelegate;
@protocol SBRootFolderPageStateObserver;
@protocol SBAssistantObserver;
@protocol BSDescriptionProviding;
@protocol SBReusableViewMapDelegate;
@protocol SBLayoutStateTransitionObserver;
@protocol SBHomeGestureParticipantDelegate;
@protocol SBIconViewQuerying;
@protocol SBIconLocationPresenting;
@protocol SBIconViewProviding;
@protocol BSInvalidatable;
@protocol BSInvalidatable;
@protocol SBFloatingDockControllerDelegate;

@interface SBFloatingDockController : NSObject <SBFloatingDockRootViewControllerDelegate, SBFolderPresentationObserver, SBSystemGestureRecognizerDelegate, SBRootFolderPageStateObserver, SBAssistantObserver, BSDescriptionProviding, SBReusableViewMapDelegate, SBLayoutStateTransitionObserver, SBHomeGestureParticipantDelegate, SBIconViewQuerying, SBIconLocationPresenting, SBIconViewProviding>

{
BOOL _homeScreenTransitioningToTodayView;
BOOL _homeScreenTodayViewTransitioning;
NSPointerArray *_floatingDockBehaviorAssertionsByLevel;
NSPointerArray *floatingDockWindowLevelAssertionsByPriority;
SBFAnalyticsClient *_analyticsClient;
SBFloatingDockBehaviorAssertion *_inAppFloatingDockBehaviorAssertion;
SBFloatingDockBehaviorAssertion *_todayViewFloatingDockBehaviorAssertion;
SBFloatingDockBehaviorAssertion *_iconPullSearchGestureShowingFloatingDockBehaviorAssertion;
SBFloatingDockBehaviorAssertion *_openFolderOverHomeScreenFloatingDockBehaviorAssertion;
SBFloatingDockBehaviorAssertion *_openFolderOverSceneLayoutFloatingDockBehaviorAssertion;
SBFloatingDockBehaviorAssertion *_activeGestureFloatingDockBehaviorAssertion;
SBFloatingDockBehaviorAssertion *_assistantFloatingDockBehaviorAssertion;
SBDeviceOrientationUpdateDeferralAssertion *_deferOrientationUpdatesAssertion;
SBReusableViewMap *_iconViewMap;
NSObject<BSInvalidatable> *_floatingDockStateDumpHandle;
NSObject<BSInvalidatable> *_floatingDockRecursiveHitTestingStateDumpHandle;
PTToggleTestRecipe *_testRecipe;
}


@property (readonly, nonatomic) SBFailingSystemGestureRecognizer *dismissFloatingDockSystemGestureRecognizer; // ivar: _dismissFloatingDockSystemGestureRecognizer
@property (readonly, nonatomic) SBIconController *iconController; // ivar: _iconController
@property (readonly, nonatomic) SBMainScreenActiveInterfaceOrientationWindow *floatingDockWindow; // ivar: _floatingDockWindow
@property (weak, nonatomic) SBFloatingDockBehaviorAssertion *activeAssertion; // ivar: _activeAssertion
@property (weak, nonatomic) SBLayoutStateTransitionCoordinator *transitionCoordinator; // ivar: _transitionCoordinator
@property (retain, nonatomic) SBHomeGestureParticipant *homeGestureParticipant; // ivar: _homeGestureParticipant
@property (readonly, nonatomic) BOOL presentingFolder;
@property (readonly, nonatomic) SBFolderController *presentedFolderController;
@property (readonly, nonatomic) SBFloatingDockViewController *floatingDockViewController;
@property (weak, nonatomic) NSObject<SBFloatingDockControllerDelegate> *delegate; // ivar: _delegate
@property (readonly, nonatomic) UIViewController *viewController; // ivar: _viewController
@property (readonly, nonatomic) BOOL floatingDockPresented;
@property (readonly, nonatomic) BOOL floatingDockFullyPresented;
@property (nonatomic) BOOL wasFloatingDockPresentedByPointer; // ivar: _wasFloatingDockPresentedByPointer
@property (readonly, nonatomic) BOOL gesturePossible;
@property (readonly, nonatomic) SBIndirectPanGestureRecognizer *presentFloatingDockIndirectPanGestureRecognizer; // ivar: _presentFloatingDockIndirectPanGestureRecognizer
@property (readonly, nonatomic) UIHoverGestureRecognizer *dismissFloatingDockHoverGestureRecognizer; // ivar: _dismissFloatingDockHoverGestureRecognizer
@property (readonly, nonatomic) CGFloat maximumFloatingDockHeight;
@property (readonly, nonatomic) CGFloat floatingDockHeight;
@property (readonly, nonatomic) CGFloat effectiveFloatingDockHeight;
@property (readonly, nonatomic) CGFloat preferredVerticalMargin;
@property (readonly, nonatomic) CGFloat floatingDockViewTopMargin;
@property (readonly, nonatomic) CGFloat translationFromFullyPresentedFrame;
@property (readonly, nonatomic) CGRect floatingDockScreenFrame;
@property (readonly, nonatomic) CGRect floatingDockScreenPresentationFrame;
@property (readonly, nonatomic) CGFloat maximumDockContinuousCornerRadius;
@property (readonly, nonatomic) SBIconListView *userIconListView;
@property (readonly, nonatomic) SBIconListView *suggestionsIconListView;
@property (retain, nonatomic) SBApplication *requestedSuggestedApplication;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy, nonatomic) NSSet *presentedIconLocations;


-(void)assistantDidDisappear:(id)arg0 ;
-(void)recycleIconView:(id)arg0 ;
-(id)firstIconViewForIcon:(id)arg0 inLocations:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocations:(id)arg1 ;
-(void)layoutStateTransitionCoordinator:(id)arg0 transitionDidEndWithTransitionContext:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 ;
-(void)assistantWillAppear:(id)arg0 ;
-(BOOL)gestureRecognizerShouldBegin:(id)arg0 ;
-(id)dequeueReusableIconViewOfClass:(Class)arg0 ;
-(void)_setupStateDumper;
-(void)enumerateDisplayedIconViewsUsingBlock:(id)arg0 ;
-(void)enumerateDisplayedIconViewsForIcon:(id)arg0 usingBlock:(id)arg1 ;
-(BOOL)isPresentingIconLocation:(id)arg0 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 excludingLocations:(id)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 ;
-(void)homeGestureParticipantOwningHomeGestureDidChange:(id)arg0 ;
-(NSUInteger)viewMap:(id)arg0 maxRecycledViewsOfClass:(Class)arg1 ;
-(void)configureIconView:(id)arg0 forIcon:(id)arg1 ;
-(void)iconManager:(id)arg0 willPerformTransitionWithFolder:(id)arg1 presenting:(BOOL)arg2 withTransitionCoordinator:(id)arg3 ;
-(id)iconViewMap;
-(void)dismissPresentedFolderAnimated:(BOOL)arg0 completion:(id)arg1 ;
-(void)_gestureRecognizerFailed:(id)arg0 ;
-(id)recycledViewsContainerProviderForViewMap:(id)arg0 ;
-(id)succinctDescriptionBuilder;
-(BOOL)isIconViewRecycled:(id)arg0 ;
-(BOOL)isDisplayingIconView:(id)arg0 ;
-(void)rootFolderPageStateProvider:(id)arg0 didEndTransitionFromState:(NSInteger)arg1 toState:(NSInteger)arg2 successfully:(BOOL)arg3 ;
-(void)layoutUserControlledIconLists:(CGFloat)arg0 animationType:(NSInteger)arg1 forceRelayout:(BOOL)arg2 ;
-(void)presentFolderForIcon:(id)arg0 location:(id)arg1 animated:(BOOL)arg2 completion:(id)arg3 ;
-(void)rootFolderPageStateProvider:(id)arg0 willEndTransitionToState:(NSInteger)arg1 successfully:(BOOL)arg2 ;
-(BOOL)viewMap:(id)arg0 shouldRecycleView:(id)arg1 ;
-(void)layoutStateTransitionCoordinator:(id)arg0 transitionDidBeginWithTransitionContext:(id)arg1 ;
-(id)init;
-(BOOL)gestureRecognizer:(id)arg0 shouldReceiveTouch:(id)arg1 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)succinctDescription;
-(void)rootFolderPageStateProvider:(id)arg0 willBeginTransitionToState:(NSInteger)arg1 animated:(BOOL)arg2 interactive:(BOOL)arg3 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)initWithIconController:(id)arg0 ;
-(void)rootFolderPageStateProvider:(id)arg0 didContinueTransitionToState:(NSInteger)arg1 progress:(CGFloat)arg2 ;
-(void)dealloc;
-(id)initWithAnalyticsClient:(id)arg0 ;
-(void)presentFloatingDockIfDismissedAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(void)dismissFloatingDockIfPresentedAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(void)registerAsSharedInstance;
-(BOOL)shouldShowHideSuggestionForIconView:(id)arg0 proposedValue:(BOOL)arg1 ;
-(BOOL)shouldShowCloseBoxForIconView:(id)arg0 proposedValue:(BOOL)arg1 ;
-(BOOL)handlePromptingUserToUninstallIcon:(id)arg0 location:(id)arg1 ;
-(void)handlePresentFloatingDockHoverGesture:(id)arg0 ;
-(void)_handleDismissFloatingDockHoverGesture:(id)arg0 ;
-(id)initWithIconController:(id)arg0 applicationController:(id)arg1 recentsController:(id)arg2 recentsDataStore:(id)arg3 transitionCoordinator:(id)arg4 appSuggestionManager:(id)arg5 analyticsClient:(id)arg6 ;
-(id)initWithIconController:(id)arg0 analyticsClient:(id)arg1 ;
-(void)_presentFloatingDockIfDismissedAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(void)_dismissFloatingDockIfPresentedAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(void)dismissPresentedFolderAnimated:(BOOL)arg0 withTransitionContext:(id)arg1 completion:(id)arg2 ;
-(void)_recalculateWindowLevelForWindowLevelAssertions;
-(void)_clearGestureAssertion;
-(void)_evaluateAssertions:(NSUInteger)arg0 interactive:(BOOL)arg1 withCompletion:(id)arg2 ;
-(BOOL)wasFloatingDockPresentedByPointer;
-(CGFloat)_dockProgressForHoverTranslation:(CGFloat)arg0 ;
-(void)floatingDockRootViewController:(id)arg0 modifyProgress:(CGFloat)arg1 interactive:(BOOL)arg2 completion:(id)arg3 ;
-(BOOL)_allowGestureRecognizers;
-(void)_handleTransitionForFolder:(id)arg0 atLevel:(NSUInteger)arg1 presenting:(BOOL)arg2 withTransitionCoordinator:(id)arg3 ;
-(void)_configureFloatingDockBehaviorAssertionForOpenFolder:(id)arg0 atLevel:(NSUInteger)arg1 ;
-(void)floatingDockRootViewController:(id)arg0 willChangeToHeight:(CGFloat)arg1 ;
-(void)floatingDockRootViewController:(id)arg0 didChangeToFrame:(struct CGRect )arg1 ;
-(void)floatingDockRootViewController:(id)arg0 floatingDockWantsToBePresented:(BOOL)arg1 ;
-(BOOL)floatingDockRootViewControllerShouldHandlePanGestureRecognizer:(id)arg0 ;
-(void)floatingDockRootViewController:(id)arg0 willPerformTransitionWithFolder:(id)arg1 presenting:(BOOL)arg2 withTransitionCoordinator:(id)arg3 ;
-(void)floatingDockRootViewControllerDidEndPresentationTransition:(id)arg0 ;
-(CGFloat)minimumHomeScreenScaleForFloatingDockRootViewController:(id)arg0 ;
-(void)_addFloatingDockWindowLevelAssertion:(id)arg0 ;
-(void)_removeFloatingDockWindowLevelAssertion:(id)arg0 ;
-(void)_addFloatingDockBehaviorAssertion:(id)arg0 withCompletion:(id)arg1 ;
-(void)_removeFloatingDockBehaviorAssertion:(id)arg0 withCompletion:(id)arg1 ;
-(void)_updateFloatingDockBehaviorAssertionsInteractive:(BOOL)arg0 completion:(id)arg1 ;
-(void)_handleSystemGestureRecognizer:(id)arg0 ;
+(void)initialize;
+(BOOL)isFloatingDockSupported;


@end


#endif


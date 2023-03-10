// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBROOTFOLDERCONTROLLER_H
#define SBROOTFOLDERCONTROLLER_H

@class SBFParallaxSettings;
@protocol SBRootFolderControllerAccessoryViewControllerDelegate;
@protocol SBHLegibility, SBHLibraryProvider, SBHSidebarProvider;

@class CHSAvocadoDescriptorProvider;
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <UIKit/UIKit.h>
#include "SBFolderController.h"
@class SBViewControllerTransitionContext;
@class SBFramewiseInteractiveTransitionAnimator;
@class SBPercentPassthroughInteractiveTransition;
@class SBHAddWidgetSheetViewController;
@class SBRootFolderView;
@class SBSearchGesture;
@class _SBRootFolderPageTransitionHandle;
@class SBHRecentsDocumentExtensionProvider;
@class SBRootFolder;
@class SBFolderIconImageCache;
@class SBHIconImageCache;
@protocol SBFramewiseInteractiveTransitionAnimatorDelegate;
@protocol SBViewControllerTransitionContextDelegate;
@protocol SBRootFolderViewDelegate;
@protocol SBSearchGestureObserver;
@protocol SBHAddWidgetSheetViewControllerDelegate;
@protocol UIGestureRecognizerDelegate;
@protocol SBHWidgetSheetViewControllerPresenter;
@protocol SBHStackConfigurationViewControllerAppearanceDelegate;
@protocol SBHWidgetDragHandling;
@protocol SBRootFolderPageStateTransitioning;
@protocol SBHIconRootViewProviding;
@protocol BSInvalidatable;
@protocol SBRootFolderPageTransition;
@protocol SBRootFolderPageTransition;
@protocol SBRootFolderControllerDelegate;
@protocol SBHWidgetDragHandling;

@interface SBRootFolderController : SBFolderController <SBFramewiseInteractiveTransitionAnimatorDelegate, SBViewControllerTransitionContextDelegate, SBRootFolderViewDelegate, SBSearchGestureObserver, SBHAddWidgetSheetViewControllerDelegate, UIGestureRecognizerDelegate, SBHWidgetSheetViewControllerPresenter, SBHStackConfigurationViewControllerAppearanceDelegate, SBHWidgetDragHandling, SBRootFolderPageStateTransitioning, SBHIconRootViewProviding>

{
SBViewControllerTransitionContext *_currentTransitionContext;
SBFramewiseInteractiveTransitionAnimator *_currentTransitionAnimator;
SBPercentPassthroughInteractiveTransition *_currentTransitionInteractor;
NSHashTable *_pageStateObservers;
NSArray *_editingSuggestedWidgetItems;
SBHAddWidgetSheetViewController *_addSheetViewController;
}


@property (nonatomic) BOOL managesStatusBarWidth; // ivar: _managesStatusBarWidth
@property (readonly, nonatomic) SBRootFolderView *rootFolderView;
@property (retain, nonatomic) SBSearchGesture *searchGesture; // ivar: _searchGesture
@property (retain, nonatomic) NSObject<BSInvalidatable> *searchGestureIconViewTouchCancellationAssertion; // ivar: _searchGestureIconViewTouchCancellationAssertion
@property (nonatomic) NSInteger pageState; // ivar: _pageState
@property (retain, nonatomic) _SBRootFolderPageTransitionHandle *currentTransitionHandle; // ivar: _currentTransitionHandle
@property (retain, nonatomic) NSObject<SBRootFolderPageTransition> *searchGestureTransition; // ivar: _searchGestureTransition
@property (retain, nonatomic) NSObject<SBRootFolderPageTransition> *implicitScrollTransition; // ivar: _implicitScrollTransition
@property (retain, nonatomic) SBHRecentsDocumentExtensionProvider *recentsDocumentExtensionProvider; // ivar: _recentsDocumentExtensionProvider
@property (readonly, nonatomic) NSInteger todayViewPageIndex;
@property (readonly, nonatomic) NSInteger favoriteTodayViewPageIndex;
@property (readonly, nonatomic) NSInteger sidebarPageIndex;
@property (readonly, nonatomic) NSInteger trailingCustomViewPageIndex;
@property (readonly, nonatomic) CHSAvocadoDescriptorProvider *avocadoDescriptorProvider; // ivar: _avocadoDescriptorProvider
@property (weak, nonatomic) NSObject<SBRootFolderControllerDelegate> *folderDelegate;
@property (retain, nonatomic) SBRootFolder *folder;
@property (nonatomic) NSUInteger dockEdge;
@property (readonly, nonatomic) CGFloat dockHeight;
@property (readonly, nonatomic) BOOL dockExternal;
@property (readonly, nonatomic) BOOL dockPinnedForRotation;
@property (readonly, copy, nonatomic) NSSet *nonDockPresentedIconLocations;
@property (readonly, nonatomic) BOOL showsDoneButtonWhileEditing; // ivar: _showsDoneButtonWhileEditing
@property (readonly, nonatomic) BOOL showsAddWidgetButtonWhileEditing; // ivar: _showsAddWidgetButtonWhileEditing
@property (nonatomic) BOOL suppressesExtraEditingButtons; // ivar: _suppressesExtraEditingButtons
@property (readonly, nonatomic) UIViewController *pullDownSearchViewController; // ivar: _pullDownSearchViewController
@property (readonly, nonatomic) UIViewController<SBHLegibility> *todayViewController; // ivar: _todayViewController
@property (readonly, nonatomic) UIViewController<SBHLibraryProvider> *trailingCustomViewController; // ivar: _trailingCustomViewController
@property (readonly, nonatomic) UIViewController<SBHSidebarProvider> *sidebarViewController; // ivar: _sidebarViewController
@property (readonly, nonatomic) CGFloat spotlightFirstIconRowOffset;
@property (weak, nonatomic) NSObject<SBRootFolderControllerAccessoryViewControllerDelegate> *accessoryViewControllerDelegate; // ivar: _accessoryViewControllerDelegate
@property (nonatomic) NSUInteger presentationSource; // ivar: _presentationSource
@property (readonly, copy, nonatomic) NSArray *folderControllers;
@property (nonatomic) BOOL allowsAutoscrollToTodayView;
@property (readonly, nonatomic) BOOL todayViewVisible;
@property (readonly, nonatomic) BOOL favoriteTodayViewVisible; // ivar: _favoriteTodayViewVisible
@property (readonly, nonatomic) BOOL todayViewTransitioning;
@property (nonatomic) BOOL todayViewPageHidden;
@property (readonly, nonatomic) BOOL pullDownSearchVisible;
@property (readonly, nonatomic) BOOL pullDownSearchVisibleOrTransitioningToVisible;
@property (readonly, nonatomic) BOOL pullDownSearchTransitioning;
@property (readonly, nonatomic) BOOL pullDownSearchVisibleOrTransitioning;
@property (readonly, nonatomic) BOOL todayPage;
@property (readonly, nonatomic) BOOL todayViewVisibleOrTransitionDestination;
@property (readonly, nonatomic) BOOL todayViewSearchVisible;
@property (readonly, nonatomic) BOOL todayViewSearchTransitioning;
@property (readonly, nonatomic) BOOL todayViewSearchVisibleOrTransitioning;
@property (readonly, nonatomic) BOOL anySearchVisible;
@property (readonly, nonatomic) BOOL anySearchVisibleOrTransitioning;
@property (readonly, nonatomic) UIView *searchableTodayWrapperView;
@property (readonly, nonatomic) UIView *searchBackdropView;
@property (nonatomic) CGFloat sidebarVisibilityProgress;
@property (nonatomic) CGFloat effectiveSidebarVisibilityProgress; // ivar: _effectiveSidebarVisibilityProgress
@property (readonly, nonatomic) BOOL sidebarVisible;
@property (readonly, nonatomic) BOOL sidebarEffectivelyVisible;
@property (readonly, nonatomic) BOOL sidebarEffectivelyAtLeastHalfVisible;
@property (nonatomic) BOOL sidebarPinned;
@property (readonly, nonatomic) BOOL sidebarVisibilityGestureActive;
@property (readonly, nonatomic) SBFParallaxSettings *parallaxSettings;
@property (readonly, nonatomic) BOOL pageManagementUIVisible;
@property (nonatomic) BOOL occludedByOverlay;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, weak, nonatomic) NSObject<SBHWidgetDragHandling> *widgetDragHandler;
@property (nonatomic) CGFloat titledButtonsAlpha;
@property (readonly, nonatomic) BOOL transitioningPageState;
@property (readonly, nonatomic) NSInteger destinationPageState;
@property (readonly, nonatomic) UIView *contentView;
@property (readonly, nonatomic) UIViewController *deepestFolderController;
@property (nonatomic) BOOL editing;
@property (readonly, nonatomic) BOOL scrolling;
@property (readonly, nonatomic) BOOL scrollTracking;
@property (nonatomic) NSInteger currentPageIndex;
@property (retain, nonatomic) SBFolderIconImageCache *folderIconImageCache;
@property (retain, nonatomic) SBHIconImageCache *iconImageCache;
@property (readonly, copy, nonatomic) NSSet *presentedIconLocations;


-(void)setSidebarViewController:(id)arg0 ;
-(void)setIdleText:(id)arg0 ;
-(void)searchGesture:(id)arg0 changedPercentComplete:(CGFloat)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 ;
-(CGFloat)pageTransitionProgress;
-(void)removePageStateObserver:(id)arg0 ;
-(void)_doPageManagementEducation;
-(void)enumerateDisplayedIconViewsUsingBlock:(id)arg0 ;
-(id)animationControllerForDismissedController:(id)arg0 ;
-(NSUInteger)_depth;
-(void)enumerateDisplayedIconViewsForIcon:(id)arg0 usingBlock:(id)arg1 ;
-(BOOL)isPresentingIconLocation:(id)arg0 ;
-(void)prepareToOpen;
-(id)beginModifyingDockOffscreenFractionForReason:(id)arg0 ;
-(BOOL)isDisplayingIconView:(id)arg0 inLocation:(id)arg1 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 ;
-(BOOL)suspendsWallpaperAnimationWhileOpen;
-(void)transitionWillBegin:(id)arg0 ;
-(void)transitionDidFinish:(id)arg0 ;
-(id)interactionControllerForPresentation:(id)arg0 ;
-(id)extraViews;
-(void)prepareToTearDown;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 ;
-(void)viewDidLoad;
-(id)animationControllerForPresentedController:(id)arg0 presentingController:(id)arg1 sourceController:(id)arg2 ;
-(BOOL)allowsAutoscrollToTodayView;
-(void)enumeratePageStateObserversUsingBlock:(id)arg0 ;
-(void)stackConfigurationViewControllerViewWillAppear:(id)arg0 ;
-(void)stackConfigurationViewControllerViewDidAppear:(id)arg0 ;
-(void)stackConfigurationViewControllerViewWillDisappear:(id)arg0 ;
-(void)stackConfigurationViewControllerViewDidDisappear:(id)arg0 ;
-(struct UIEdgeInsets )statusBarInsetsForOrientation:(NSInteger)arg0 ;
-(id)_makeContentViewWithConfiguration:(id)arg0 ;
-(id)_viewControllersToNotifyForViewObscuration;
-(void)prepareToClose;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 options:(NSUInteger)arg2 ;
-(void)setTodayViewController:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 options:(NSUInteger)arg1 ;
-(BOOL)shouldAnimateFirstTwoViewsAsOne;
-(NSUInteger)presenterType;
-(void)addWidgetSheetViewControllerDidCancel:(id)arg0 ;
-(void)dismissSpotlightAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(void)searchGesture:(id)arg0 completedShowing:(BOOL)arg1 ;
-(void)searchGesture:(id)arg0 resetAnimated:(BOOL)arg1 ;
-(void)_reduceTransparencyChanged;
-(BOOL)closesAfterDragExits;
-(BOOL)canAcceptFolderIconDrags;
-(BOOL)_listIndexIsVisible:(NSUInteger)arg0 ;
-(BOOL)shouldOpenFolderIcon:(id)arg0 ;
-(BOOL)shouldAnimateLastTwoViewsAsOne;
-(void)setSuppressesEditingStateForListView:(BOOL)arg0 ;
-(void)viewWillAppear:(BOOL)arg0 ;
-(id)interactionControllerForDismissal:(id)arg0 ;
-(void)addWidgetSheetViewController:(id)arg0 didSelectWidgetIconView:(id)arg1 ;
-(BOOL)showsAddWidgetButtonWhileEditing;
-(id)initWithConfiguration:(id)arg0 ;
-(void)viewDidDisappear:(BOOL)arg0 ;
-(id)viewControllersForPageIndex:(NSInteger)arg0 ;
-(void)exitPageManagementUIWithCompletionHandler:(id)arg0 ;
-(id)addWidgetSheetViewController:(id)arg0 widgetIconForDescriptor:(id)arg1 sizeClass:(NSInteger)arg2 ;
-(BOOL)isDisplayingIconView:(id)arg0 options:(NSUInteger)arg1 ;
-(BOOL)showsDoneButtonWhileEditing;
-(BOOL)isOnTodayPage;
-(void)_handleWidgetSheetViewControllerDidAppear:(id)arg0 ;
-(void)_handleWidgetSheetViewControllerWillDisappear:(id)arg0 ;
-(void)_handleWidgetSheetViewControllerDidDisappear:(id)arg0 ;
-(id)viewControllerForPageState:(NSInteger)arg0 ;
-(BOOL)_isDockSwitchedForOrientation:(NSInteger)arg0 ;
-(BOOL)_dockLayoutReversedForInterfaceOrientation:(NSInteger)arg0 ;
-(NSUInteger)_dockEdgeForInterfaceOrientation:(NSInteger)arg0 ;
-(void)_configureDockViewForOrientationWithoutAnimation:(NSInteger)arg0 ;
-(void)_configureAppStatusBarInsetsForOrientation:(NSInteger)arg0 ;
-(void)configureAppStatusBarInsets;
-(BOOL)managesStatusBarWidth;
-(void)_configureTodayViewPageForOrientation:(NSInteger)arg0 ;
-(BOOL)_todayViewPageIsVisibleForOrientation:(NSInteger)arg0 ;
-(id)firstIconViewForIcon:(id)arg0 options:(NSUInteger)arg1 ;
-(BOOL)disablesScrollingWhileIconDragIsDropping;
-(void)folderViewDidScroll:(id)arg0 ;
-(CGFloat)_todayViewVisibilityProgress;
-(CGFloat)_trailingCustomViewVisibilityProgress;
-(void)updateViewsAfterOrientationChange;
-(id)extraViewsContainers;
-(void)viewWillTransitionToSize:(struct CGSize )arg0 forOperation:(NSInteger)arg1 withTransitionCoordinator:(id)arg2 ;
-(void)orientationDidChange:(NSInteger)arg0 ;
-(BOOL)_shouldUseDockAnimationWindowForRotationToInterfaceOrientation:(NSInteger)arg0 duration:(CGFloat)arg1 ;
-(BOOL)_shouldSlideDockOutDuringRotationFromOrientation:(NSInteger)arg0 toOrientation:(NSInteger)arg1 ;
-(void)_configureDockViewForOrientationDuringAnimation:(NSInteger)arg0 dockAnimationWindow:(id)arg1 dockBorrowedAssertion:(id)arg2 ;
-(void)_configureViewForOrientationWithoutAnimation:(NSInteger)arg0 ;
-(BOOL)isTransitiongBetweenPageStateVerticalGroups;
-(struct SBRootFolderPageStateTransitionSnapshot )pageStateTransitionSnapshotForScrollOffset:(CGFloat)arg0 ;
-(void)searchGesture:(id)arg0 startedShowing:(BOOL)arg1 ;
-(void)performPageStateTransitionToState:(NSInteger)arg0 reason:(id)arg1 animated:(BOOL)arg2 completionHandler:(id)arg3 ;
-(BOOL)canTransitionPageStateToState:(NSInteger)arg0 ;
-(BOOL)isAnySearchTransitioning;
-(void)performDefaultPageStateTransitionToState:(NSInteger)arg0 reason:(id)arg1 animated:(BOOL)arg2 completionHandler:(id)arg3 ;
-(id)beginPageStateTransitionToState:(NSInteger)arg0 reason:(id)arg1 animated:(BOOL)arg2 interactive:(BOOL)arg3 ;
-(CGFloat)visibilityProgressTowardPageStateMatchingTest:(id)arg0 ;
-(void)viewWillTransitionToSize:(struct CGSize )arg0 withTransitionCoordinator:(id)arg1 ;
-(void)willBeginTransitionToState:(NSInteger)arg0 animated:(BOOL)arg1 interactive:(BOOL)arg2 ;
-(CGFloat)_anySearchVisibilityProgress;
-(id)defaultTransitionForTransitioningFromPageState:(NSInteger)arg0 toPageState:(NSInteger)arg1 animated:(BOOL)arg2 interactive:(BOOL)arg3 ;
-(void)_checkForImproperScrollOffsetForPageState;
-(void)didContinueTransitionToState:(NSInteger)arg0 progress:(CGFloat)arg1 ;
-(void)willEndTransitionToState:(NSInteger)arg0 successfully:(BOOL)arg1 ;
-(void)didEndTransitionFromState:(NSInteger)arg0 toState:(NSInteger)arg1 successfully:(BOOL)arg2 ;
-(void)_cancelTouchesForSearchGestureOnIconView:(id)arg0 ;
-(void)_invalidateSearchGestureIconViewTouchCancellationAssertion;
-(void)updateExtraButtonVisibilityAnimated:(BOOL)arg0 ;
-(void)presentWidgetEditingViewControllerFromViewController:(id)arg0 ;
-(BOOL)_isDescriptorAllowed:(id)arg0 ;
-(void)_addShortcutsSpecialAvocadoToApplicationWidgetCollections:(id)arg0 ;
-(void)_addSiriSuggestionsSpecialAvocadosToApplicationWidgetCollections:(id)arg0 ;
-(void)_addFilesSpecialAvocadosToApplicationWidgetCollections:(id)arg0 ;
-(void)_addBatteriesSpecialAvocadosToApplicationWidgetCollections:(id)arg0 ;
-(BOOL)isDockVisible;
-(void)folderView:(id)arg0 currentPageIndexWillChange:(NSInteger)arg1 ;
-(void)folderView:(id)arg0 currentPageIndexDidChange:(NSInteger)arg1 ;
-(void)folderViewWillBeginDragging:(id)arg0 ;
-(void)folderViewWillBeginScrolling:(id)arg0 ;
-(void)folderViewWillEndDragging:(id)arg0 ;
-(void)folderViewWillUpdatePageDuringScrolling:(id)arg0 ;
-(void)folderViewDidEndScrolling:(id)arg0 ;
-(void)folderView:(id)arg0 willAnimateScrollToPageIndex:(NSInteger)arg1 ;
-(id)viewControllerForTransitioningFromPageState:(NSInteger)arg0 toPageState:(NSInteger)arg1 ;
-(id)_widgetIconAnimationExtraViewsProvider;
-(void)transitionContext:(id)arg0 updateTransitionProgress:(CGFloat)arg1 ;
-(void)rootFolderView:(id)arg0 wantsToAdjustTodayContentForEdgeBounceForScrollOffset:(struct CGPoint )arg1 ;
-(CGFloat)distanceToTopOfSpotlightIconsForRootFolderView:(id)arg0 ;
-(CGFloat)maxExternalDockHeightForRootFolderView:(id)arg0 ;
-(CGFloat)externalDockHeightForRootFolderView:(id)arg0 ;
-(CGFloat)preferredExternalDockVerticalMarginForRootFolderView:(id)arg0 ;
-(id)backgroundViewForDockForRootFolderView:(id)arg0 ;
-(void)rootFolderViewWantsToEndEditing:(id)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)transitionWillReverse:(id)arg0 ;
-(void)transitionWillFinish:(id)arg0 ;
-(id)backgroundViewForEditingDoneButtonForRootFolderView:(id)arg0 ;
-(void)rootFolderView:(id)arg0 didChangeSidebarVisibilityProgress:(CGFloat)arg1 ;
-(void)rootFolderView:(id)arg0 didChangeEffectiveSidebarVisibilityProgress:(CGFloat)arg1 ;
-(void)rootFolderView:(id)arg0 didEndSidebarVisibilityTransitionWithEffectiveProgress:(CGFloat)arg1 ;
-(void)rootFolderView:(id)arg0 didOverscrollOnFirstPageByAmount:(CGFloat)arg1 ;
-(void)rootFolderView:(id)arg0 didEndOverscrollOnFirstPageWithVelocity:(CGFloat)arg1 translation:(CGFloat)arg2 ;
-(void)rootFolderView:(id)arg0 didOverscrollOnLastPageByAmount:(CGFloat)arg1 ;
-(void)rootFolderView:(id)arg0 didEndOverscrollOnLastPageWithVelocity:(CGFloat)arg1 translation:(CGFloat)arg2 ;
-(void)rootFolderViewWantsWidgetEditingViewControllerPresented:(id)arg0 ;
-(void)rootFolderView:(id)arg0 willPresentPageManagementUsingAnimator:(id)arg1 context:(id)arg2 ;
-(void)didBeginDraggingWidgetIcon:(id)arg0 ;
-(id)dockIconListView;
-(void)rootFolderView:(id)arg0 willDismissPageManagementUsingAnimator:(id)arg1 context:(id)arg2 ;
-(void)rootFolderView:(id)arg0 didDismissPageManagementWithContext:(id)arg1 ;
-(id)widgetIconForGalleryItem:(id)arg0 sizeClass:(NSInteger)arg1 ;
-(void)setPullDownSearchViewController:(id)arg0 ;
-(void)setParallaxDisabled:(BOOL)arg0 forReason:(id)arg1 ;
-(void)_configureAppStatusBarInsetsAnimated:(BOOL)arg0 ;
-(void)presentSpotlightAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(BOOL)isTodayViewOrTodayViewSearchVisible;
-(BOOL)isTransitioningBetweenIconPageAndTodayPage;
-(BOOL)isTransitioningBetweenIconAndTrailingCustomView;
-(BOOL)isTransitioningBetweenIconPageAndTrailingCustomPage;
-(BOOL)isTransitioningBetweenHorizontalPageStates;
-(void)pageTransitionHandle:(id)arg0 updateCurrentPageStateTransitionToProgress:(CGFloat)arg1 ;
-(void)pageTransitionHandle:(id)arg0 endPageStateTransitionSuccessfully:(BOOL)arg1 ;
-(void)_setupDebugTapGestureRecognizerForDockIconListView:(id)arg0 ;
-(BOOL)suppressesExtraEditingButtons;
-(void)addPageStateObserver:(id)arg0 ;
-(void)enterPageManagementUIWithCompletionHandler:(id)arg0 ;
-(void)folderController:(id)arg0 didBeginEditingTitle:(id)arg1 ;
-(id)_vendorNameForBundleIdentifier:(id)arg0 ;
-(void)_insertSmartStackSpecialAvocadosAtTheTopOfApplicationWidgetCollections:(id)arg0 ;
-(CGFloat)_additionalMinimumOffsetForSheetPresentation;
-(BOOL)_isVisibilityWidgetDefined:(NSInteger)arg0 ;
-(BOOL)_isDescriptorVisibleByDefault:(id)arg0 ;
-(BOOL)_shouldAddSpecialAvocadoOfType:(NSUInteger)arg0 ;
-(id)widgetIconForDescriptor:(id)arg0 sizeClass:(NSInteger)arg1 ;
-(id)_widgetIconForDescriptors:(id)arg0 sizeClass:(NSInteger)arg1 ;
-(void)addWidgetSheetViewControllerWillAppear:(id)arg0 ;
-(void)addWidgetSheetViewControllerDidAppear:(id)arg0 ;
-(void)addWidgetSheetViewControllerWillDisappear:(id)arg0 ;
-(void)addWidgetSheetViewControllerDidDisappear:(id)arg0 ;
-(void)folderController:(id)arg0 didEndEditingTitle:(id)arg1 ;
-(void)folderView:(id)arg0 didBeginEditingTitle:(id)arg1 ;
-(void)folderView:(id)arg0 didEndEditingTitle:(id)arg1 ;
+(Class)configurationClass;
+(BOOL)_shouldForwardViewWillTransitionToSize;
+(id)iconLocation;
+(id)dockIconLocation;


@end


#endif


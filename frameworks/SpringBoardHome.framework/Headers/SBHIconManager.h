// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBHICONMANAGER_H
#define SBHICONMANAGER_H

@class SBFParallaxSettings;
@protocol OS_os_activity, SBHIconManagerDelegate;


@protocol SBIconListLayoutProvider

-(id)layoutForIconLocation:(id)arg0 ;

@end


@class SBReusableViewMap;
@class BSEventQueue;
@class SBHomeScreenDefaults;
@class CHSAvocadoDescriptorProvider;
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBIconLabelImageCache;
@class SBIconPreviousLocationTracker;
@class SBFolderIconImageCache;
@class SBHIconImageCache;
@class SBHMultiplexingManager;
@class SBFolderIcon;
@class SBIconView;
@class SBRootFolderController;
@class SBFolder;
@class SBHomeScreenIconTransitionAnimator;
@class SBRootFolder;
@class SBWorkspaceInteractionContext;
@class SBHHomeScreenSettings;
@class SBHRootFolderSettings;
@class SBHHomeScreenUsageMonitor;
@class SBIconListView;
@class SBHWidgetMetricsProvider;
@class SBHIconModel;
@class SBFolderController;
@class SBFloatingDockViewController;
@class SBHLibraryViewController;
@class SBIcon;
@class SBIconDragManager;
@class SBSearchGesture;
@class SBIconPageIndicatorImageSetCache;
@protocol SBHIconRootViewProviding, SBHLibraryProvider, SBHSidebarProvider, SBHLegibility, SBHTodayViewController;
@protocol UIPopoverPresentationControllerDelegate;
@protocol SBReusableViewMapDelegate;
@protocol SBRootFolderPageStateObserver;
@protocol SBNestingViewControllerDelegate;
@protocol SBHIconModelDelegate;
@protocol PTSettingsKeyObserver;
@protocol SBRootFolderDelegate;
@protocol SBIconViewObserver;
@protocol SBHWidgetStackViewControllerDataSource;
@protocol SBHWidgetStackViewControllerDelegate;
@protocol SBLeafIconObserver;
@protocol CHUISAvocadoHostViewControllerDelegate;
@protocol SBHWidgetMetricsProviderDelegate;
@protocol CHSAvocadoDescriptorProviderObserver;
@protocol SBHMultiplexingManagerDelegate;
@protocol SBHTodayViewControllerObserver;
@protocol SBIconViewDelegate;
@protocol SBIconViewQuerying;
@protocol SBHomeScreenIconTransitionAnimatorDelegate;
@protocol SBIconViewProviding;
@protocol SBRootFolderControllerDelegate;
@protocol SBIconLocationPresenting;
@protocol SBHLibraryViewControllerObserver;
@protocol BSInvalidatable;
@protocol BSInvalidatable;

@interface SBHIconManager : NSObject <UIPopoverPresentationControllerDelegate, SBReusableViewMapDelegate, SBRootFolderPageStateObserver, SBNestingViewControllerDelegate, SBHIconModelDelegate, PTSettingsKeyObserver, SBRootFolderDelegate, SBIconViewObserver, SBHWidgetStackViewControllerDataSource, SBHWidgetStackViewControllerDelegate, SBLeafIconObserver, CHUISAvocadoHostViewControllerDelegate, SBHWidgetMetricsProviderDelegate, CHSAvocadoDescriptorProviderObserver, SBHMultiplexingManagerDelegate, SBHTodayViewControllerObserver, SBIconViewDelegate, SBIconViewQuerying, SBHomeScreenIconTransitionAnimatorDelegate, SBIconViewProviding, SBRootFolderControllerDelegate, SBIconLocationPresenting, SBHLibraryViewControllerObserver>

{
SBReusableViewMap *_iconViewMap;
SBReusableViewMap *_homescreenIconAccessoryViewMap;
SBReusableViewMap *_homescreenIconLabelAccessoryViewMap;
SBReusableViewMap *_homescreenIconImageViewMap;
SBIconLabelImageCache *_labelImageCache;
UIImpactFeedbackGenerator *_iconEditingFeedbackBehavior;
NSMutableSet *_touchedIconViews;
NSMutableArray *_iconTouchesFinishedBlocks;
NSUInteger _maxIconViewsInHierarchy;
NSCountedSet *_reasonsToNotRestartEditingTimer;
NSHashTable *_pageStateObservers;
NSHashTable *_folderPresentationObservers;
NSMutableArray *_currentExpandCompletions;
NSMutableArray *_currentCollapseCompletions;
SBIconPreviousLocationTracker *_previousIconLocationTracker;
SBFolderIconImageCache *_folderIconImageCache;
SBHIconImageCache *_iconImageCache;
NSUInteger _relayoutCount;
BOOL _editingShouldBeReEnabledAfterLibrarySearchControllerIsDismissed;
Class _subclassIconViewClass;
SBHMultiplexingManager *_widgetMultiplexingManager;
NSMapTable *_widgetViewControllersForIconView;
NSMapTable *_iconViewsForCustomIconImageViewController;
NSMapTable *_iconViewsForWidgetMultiplexingViewController;
NSMapTable *_appPredictionViewControllersForUniqueIdentifier;
NSMutableDictionary *_widgetIntents;
NSUInteger _descriptorsChangedSequenceNumber;
NSMutableSet *_pendingWidgetIntentConfigurationInitializations;
NSMutableSet *_activeWidgetIntentConfigurationInitializations;
NSMutableArray *_performAfterPendingWidgetIntentConfigurationBlocks;
NSCountedSet *_reasonsToIgnoreUserPreferenceForAddingNewIconsToHomeScreen;
NSObject<OS_os_activity> *_editingActivity;
NSObject<BSInvalidatable> *_stateCaptureHandle;
SBFolderIcon *_pendingFolderIconToOpen;
}


@property (retain, nonatomic) SBIconView *highlightedIconView; // ivar: _highlightedIconView
@property (retain, nonatomic) NSTimer *editingEndTimer; // ivar: _editingEndTimer
@property (retain, nonatomic) SBRootFolderController *rootFolderController; // ivar: _rootFolderController
@property (retain, nonatomic) UIViewController<SBHIconRootViewProviding> *rootViewController; // ivar: _rootViewController
@property (copy, nonatomic) NSArray *postResetPathIdentifiers; // ivar: _postResetPathIdentifiers
@property (nonatomic) BOOL needsRelayout; // ivar: _needsRelayout
@property (nonatomic) BOOL animatingFolderCreation; // ivar: _animatingFolderCreation
@property (nonatomic) BOOL animatingFolderOpeningOrClosing; // ivar: _animatingFolderOpeningOrClosing
@property (nonatomic) BOOL animatingForUnscatter; // ivar: _animatingForUnscatter
@property (retain, nonatomic) SBFolder *closingFolder; // ivar: _closingFolder
@property (readonly, nonatomic) BSEventQueue *transitionEventQueue; // ivar: _transitionEventQueue
@property (retain, nonatomic) SBHomeScreenIconTransitionAnimator *currentTransitionAnimator; // ivar: _currentTransitionAnimator
@property (retain, nonatomic) SBRootFolder *rootFolder; // ivar: _rootFolder
@property (retain, nonatomic) SBWorkspaceInteractionContext *currentInteractionContext; // ivar: _currentInteractionContext
@property (readonly, nonatomic) SBHHomeScreenSettings *homeScreenSettings; // ivar: _homeScreenSettings
@property (readonly, nonatomic) SBHRootFolderSettings *rootFolderSettings; // ivar: _rootFolderSettings
@property (copy, nonatomic) NSString *precachedContentSizeCategory; // ivar: _precachedContentSizeCategory
@property (retain, nonatomic) SBIconView *popoverIconView; // ivar: _popoverIconView
@property (readonly, nonatomic) SBHomeScreenDefaults *homeScreenDefaults; // ivar: _homeScreenDefaults
@property (retain, nonatomic) UIViewController<SBHLibraryProvider> *trailingCustomViewController; // ivar: _trailingCustomViewController
@property (retain, nonatomic) UIViewController<SBHSidebarProvider> *sidebarViewController; // ivar: _sidebarViewController
@property (retain, nonatomic) UIViewController<SBHLegibility> *todayViewController; // ivar: _todayViewController
@property (nonatomic) BOOL resettingRootIconLists; // ivar: _resettingRootIconLists
@property (retain, nonatomic) SBHHomeScreenUsageMonitor *usageMonitor; // ivar: _usageMonitor
@property (retain, nonatomic) NSObject<BSInvalidatable> *editingAutosaveDisableAssertion; // ivar: _editingAutosaveDisableAssertion
@property (retain, nonatomic) SBIconView *currentConfiguringIconView; // ivar: _currentConfiguringIconView
@property (readonly, nonatomic) SBFParallaxSettings *badgeParallaxSettings; // ivar: _badgeParallaxSettings
@property (readonly, nonatomic) SBIconListView *currentRootIconList;
@property (readonly, nonatomic) SBIconListView *dockListView;
@property (readonly, nonatomic) SBIconListView *floatingDockListView;
@property (readonly, nonatomic) SBIconListView *floatingDockSuggestionsListView;
@property (readonly, nonatomic) SBIconListView *effectiveDockListView;
@property (retain, nonatomic) SBIconView *previewInteractingIconView; // ivar: _previewInteractingIconView
@property (readonly, nonatomic) SBIconLabelImageCache *iconLabelImageCache;
@property (readonly, nonatomic) BOOL libraryViewControllerVisible;
@property (readonly, nonatomic) SBHWidgetMetricsProvider *widgetMetricsProvider; // ivar: _widgetMetricsProvider
@property (weak, nonatomic) NSObject<SBHIconManagerDelegate> *delegate; // ivar: _delegate
@property (readonly, nonatomic) NSInteger interfaceOrientation;
@property (retain, nonatomic) SBHIconModel *iconModel; // ivar: _iconModel
@property (readonly, nonatomic) SBFolderController *openedFolderController;
@property (retain, nonatomic) SBFloatingDockViewController *floatingDockViewController; // ivar: _floatingDockViewController
@property (retain, nonatomic) UIViewController<SBHTodayViewController> *overlayTodayViewController; // ivar: _overlayTodayViewController
@property (retain, nonatomic) SBHLibraryViewController *overlayLibraryViewController; // ivar: _overlayLibraryViewController
@property (nonatomic) BOOL overlayTodayViewVisible; // ivar: _overlayTodayViewVisible
@property (nonatomic) BOOL overlayCoverSheetTodayViewVisible; // ivar: _overlayCoverSheetTodayViewVisible
@property (nonatomic) BOOL overlayLibraryViewVisible; // ivar: _overlayLibraryViewVisible
@property (nonatomic) BOOL dockPinnedForRotation; // ivar: _dockPinnedForRotation
@property (nonatomic) BOOL showsDoneButtonWhileEditing; // ivar: _showsDoneButtonWhileEditing
@property (nonatomic) BOOL showsAddWidgetButtonWhileEditing; // ivar: _showsAddWidgetButtonWhileEditing
@property (nonatomic) BOOL editing; // ivar: _editing
@property (readonly, nonatomic) BOOL editingAllowed;
@property (readonly, nonatomic) BOOL folderPageManagementUIVisible;
@property (readonly, nonatomic) BOOL iconDragging;
@property (readonly, nonatomic) BOOL rootFolderContentVisible;
@property (readonly, nonatomic) BOOL iconContentPossiblyVisibleOverApplication;
@property (nonatomic) BOOL rootFolderContentOccluded; // ivar: _rootFolderContentOccluded
@property (readonly, nonatomic) UIImpactFeedbackGenerator *iconEditingFeedbackBehavior;
@property (retain, nonatomic) NSObject<SBIconListLayoutProvider> *listLayoutProvider; // ivar: _listLayoutProvider
@property (nonatomic) NSUInteger listLayoutProviderLayoutOptions; // ivar: _listLayoutProviderLayoutOptions
@property (retain, nonatomic) SBIcon *iconToReveal; // ivar: _iconToReveal
@property (readonly, nonatomic) CHSAvocadoDescriptorProvider *avocadoDescriptorProvider; // ivar: _avocadoDescriptorProvider
@property (readonly, nonatomic) BOOL allowsNestedFolders;
@property (readonly, nonatomic) BOOL scrolling;
@property (readonly, nonatomic) BOOL rootFolderScrolling;
@property (readonly, nonatomic) BOOL folderScrolling;
@property (readonly, nonatomic) BOOL trackingScroll;
@property (readonly, nonatomic) BOOL hasOpenFolder;
@property (readonly, nonatomic) SBFolder *openedFolder;
@property (readonly, nonatomic) BOOL canCloseFolders;
@property (readonly, nonatomic) BOOL hasAnimatingFolder;
@property (readonly, nonatomic) BOOL transitioning;
@property (readonly, nonatomic) BOOL performingExpandTransition;
@property (readonly, nonatomic) BOOL performingCancelledCollapseTransition;
@property (readonly, nonatomic) SBIconDragManager *iconDragManager; // ivar: _iconDragManager
@property (readonly, nonatomic) BOOL iconTouched;
@property (readonly, nonatomic) BOOL showingIconContextMenu;
@property (readonly, nonatomic) BOOL showingPullDownSearch;
@property (readonly, nonatomic) BOOL showingPullDownSearchOrTransitioningToVisible;
@property (readonly, nonatomic) BOOL showingPullDownOrTodayViewSearch;
@property (readonly, nonatomic) BOOL showingSpotlightOrTodayView;
@property (readonly, nonatomic) BOOL showingTodayView;
@property (readonly, nonatomic) BOOL showingOrTransitioningToTodayView;
@property (readonly, nonatomic) BOOL transitioningHomeScreenState;
@property (readonly, nonatomic) BOOL sidebarVisible;
@property (readonly, nonatomic) BOOL sidebarEffectivelyVisible;
@property (readonly, nonatomic) BOOL sidebarVisibilityGestureActive;
@property (readonly, nonatomic) SBSearchGesture *searchGesture;
@property (readonly, nonatomic) SBIconPageIndicatorImageSetCache *iconPageIndicatorImageSetCache; // ivar: _iconPageIndicatorImageSetCache
@property (readonly, nonatomic) SBFolderIconImageCache *folderIconImageCache;
@property (readonly, nonatomic) SBHIconImageCache *iconImageCache;
@property (readonly, nonatomic) BOOL showsBadgesInAppLibrary; // ivar: _showsBadgesInAppLibrary
@property (readonly, copy, nonatomic) NSString *statisticsSummary;
@property (nonatomic) BOOL usageMonitoringEnabled; // ivar: _usageMonitoringEnabled
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy, nonatomic) NSSet *presentedIconLocations;


-(void)setIdleModeText:(id)arg0 ;
-(void)folderController:(id)arg0 willRemoveFakeStatusBar:(id)arg1 ;
-(id)parallaxSettingsForComponentsOfIconView:(id)arg0 ;
-(id)stackConfigurationInteractionForIconView:(id)arg0 ;
-(BOOL)hasOpenFolderInLocation:(id)arg0 ;
-(id)widgetStackViewController:(id)arg0 viewControllerForDataSource:(id)arg1 ;
-(void)nestingViewController:(id)arg0 willPerformOperation:(NSInteger)arg1 onViewController:(id)arg2 withTransitionCoordinator:(id)arg3 ;
-(void)cancelAllDrags;
-(void)iconModel:(id)arg0 didAddIcon:(id)arg1 ;
-(id)localizedFolderNameForDefaultDisplayName:(id)arg0 ;
-(BOOL)canCloseFolders;
-(void)recycleIconView:(id)arg0 ;
-(id)homescreenIconLabelAccessoryViewMap;
-(void)layoutIconListsWithAnimationType:(NSInteger)arg0 forceRelayout:(BOOL)arg1 ;
-(void)iconTouchBegan:(id)arg0 ;
-(void)scrollToIconListContainingIcon:(id)arg0 animate:(BOOL)arg1 ;
-(void)iconModel:(id)arg0 willRemoveIcon:(id)arg1 ;
-(void)iconViewWasRecycled:(id)arg0 ;
-(void)_endObservingLeafIconsInModel:(id)arg0 ;
-(void)organizeAllIconsIntoFoldersWithPageCount:(NSUInteger)arg0 ;
-(id)firstIconViewForIcon:(id)arg0 inLocations:(id)arg1 ;
-(void)iconDragManagerIconDraggingDidChange:(id)arg0 ;
-(void)uninstallIcon:(id)arg0 animate:(BOOL)arg1 completion:(id)arg2 ;
-(void)rootFolderController:(id)arg0 didChangeSidebarVisibilityProgress:(CGFloat)arg1 ;
-(id)bestLocationForIcon:(id)arg0 ;
-(NSUInteger)maxListCountForFolders;
-(BOOL)isDisplayingIcon:(id)arg0 inLocations:(id)arg1 ;
-(NSUInteger)maxListCountForFoldersForIconModel:(id)arg0 ;
-(BOOL)shouldRecycleIconView:(id)arg0 ;
-(void)runDownloadingIconTest;
-(void)_folderDidFinishOpenClose:(BOOL)arg0 animated:(BOOL)arg1 success:(BOOL)arg2 ;
-(BOOL)isEditingAllowedForIconView:(id)arg0 ;
-(void)runRemoveAndRestoreIconTest;
-(void)moveIconToHiddenPage:(id)arg0 ;
-(void)layoutIconListsWithAnimationType:(NSInteger)arg0 duration:(CGFloat)arg1 forceRelayout:(BOOL)arg2 ;
-(void)checkForInvalidCustomElements;
-(void)_prepareToResetRootIconLists;
-(BOOL)widgetStackViewController:(id)arg0 isDataSourceBlockedForScreenTimeExpiration:(id)arg1 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDragItem:(id)arg2 willAnimateDropWithAnimator:(id)arg3 ;
-(void)_beginObservingLeafIconsInModel:(id)arg0 ;
-(id)nestingViewController:(id)arg0 interactionControllerForAnimationController:(id)arg1 ;
-(void)iconView:(id)arg0 willRemoveIconLabelAccessoryView:(id)arg1 ;
-(BOOL)isEditingAllowedForIconListView:(id)arg0 ;
-(BOOL)rootFolder:(id)arg0 shouldAllowBadgingForIcon:(id)arg1 ;
-(void)clearHighlightedIcon;
-(struct UIEdgeInsets )statusBarEdgeInsetsForFolderController:(id)arg0 ;
-(void)folderControllerWillOpen:(id)arg0 ;
-(Class)controllerClassForFolder:(id)arg0 ;
-(void)iconView:(id)arg0 willAnimateDragLiftWithAnimator:(id)arg1 session:(id)arg2 ;
-(BOOL)isDisplayingIcon:(id)arg0 ;
-(id)externalDockIconListViewForRootFolderController:(id)arg0 ;
-(void)_closeFolderController:(id)arg0 animated:(BOOL)arg1 withCompletion:(id)arg2 ;
-(id)fakeStatusBarForFolderController:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 customSpringAnimationBehaviorForDroppingItem:(id)arg2 ;
-(BOOL)isIconIgnored:(id)arg0 ;
-(BOOL)_shouldParallaxInIconLocation:(id)arg0 ;
-(void)_iconModelDidLayout:(id)arg0 ;
-(void)folderController:(id)arg0 draggedIconShouldDropFromListView:(id)arg1 ;
-(void)toggleSuggestedWidgetInStackForTestRecipe;
-(void)iconTapped:(id)arg0 ;
-(void)minimumHomeScreenScaleDidChange;
-(BOOL)allowsNestedFolders;
-(id)dequeueReusableIconViewOfClass:(Class)arg0 ;
-(Class)iconViewClass;
-(void)folderControllerWillBeginScrolling:(id)arg0 ;
-(void)removePageStateObserver:(id)arg0 ;
-(id)iconView:(id)arg0 dragPreviewForItem:(id)arg1 session:(id)arg2 previewParameters:(id)arg3 ;
-(void)folderControllerShouldEndEditing:(id)arg0 ;
-(BOOL)iconShouldAllowTap:(id)arg0 ;
-(void)settings:(id)arg0 changedValueForKey:(id)arg1 ;
-(void)libraryViewController:(id)arg0 willLaunchIcon:(id)arg1 fromLocation:(id)arg2 ;
-(CGFloat)maxExternalDockHeightForRootFolderController:(id)arg0 ;
-(void)openFolderIcon:(id)arg0 location:(id)arg1 animated:(BOOL)arg2 withCompletion:(id)arg3 ;
-(void)_setupStateCaptureHandleIfNeeded;
-(void)noteIconViewWillZoomDown:(id)arg0 ;
-(BOOL)resetTodayLayout;
-(void)folderControllerDidEndScrolling:(id)arg0 ;
-(id)folderControllerForFolder:(id)arg0 ;
-(void)enumerateDisplayedIconViewsUsingBlock:(id)arg0 ;
-(struct SBHIconGridSize )iconModel:(id)arg0 listGridSizeForFolderClass:(Class)arg1 ;
-(id)containerViewForPresentingContextMenuForIconView:(id)arg0 ;
-(void)iconView:(id)arg0 session:(id)arg1 willEndWithOperation:(NSUInteger)arg2 ;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 shouldAllowSpringLoadedInteractionForIconDropSession:(id)arg2 onIconView:(id)arg3 ;
-(void)enumerateAppPredictionViewControllersInIconLocationGroup:(id)arg0 withOptions:(NSUInteger)arg1 usingBlock:(id)arg2 ;
-(void)presentTodayOverlay;
-(BOOL)showsBadgesInAppLibrary;
-(void)activateTodayViewWithCompletion:(id)arg0 ;
-(id)appPredictionsIconViewDisplayingIconView:(id)arg0 options:(NSUInteger)arg1 ;
-(void)enumerateDisplayedIconViewsForIcon:(id)arg0 usingBlock:(id)arg1 ;
-(BOOL)isPresentingIconLocation:(id)arg0 ;
-(id)launchActionsForIconView:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 springLoadedInteractionForIconDragDidCompleteOnIconView:(id)arg2 ;
-(void)folderController:(id)arg0 willCreateInnerFolderControllerWithConfiguration:(id)arg1 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 options:(NSUInteger)arg2 ;
-(struct UIEdgeInsets )contentOverlayInsetsFromParentIfAvailableForFolderController:(id)arg0 ;
-(id)reasonToDisallowInteractionOnIconView:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 willUseIconView:(id)arg2 forDroppingIconDragItem:(id)arg3 ;
-(id)customImageViewControllerForIconView:(id)arg0 ;
-(BOOL)isIconCurrentlyOnscreen:(id)arg0 ;
-(BOOL)iconView:(id)arg0 canAddDragItemsToSession:(id)arg1 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 previewForDroppingIconDragItem:(id)arg2 proposedPreview:(id)arg3 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidExit:(id)arg2 ;
-(BOOL)isDisplayingIconView:(id)arg0 inLocation:(id)arg1 ;
-(CGFloat)minimumHomeScreenScaleForFolderController:(id)arg0 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 ;
-(BOOL)needsRelayout;
-(void)performAfterCachingWidgetIntentsUsingBlock:(id)arg0 ;
-(void)iconModel:(id)arg0 launchIcon:(id)arg1 fromLocation:(id)arg2 context:(id)arg3 ;
-(BOOL)_bundleWithIdentifierHasOpenURLEntitlement:(id)arg0 ;
-(void)removeIcon:(id)arg0 options:(NSUInteger)arg1 completion:(id)arg2 ;
-(void)rootFolderControllerViewWillAppear:(id)arg0 ;
-(id)viewControllerForPresentingViewControllers;
-(id)_widgetInsertionRippleIconAnimatorIcon:(id)arg0 iconListView:(id)arg1 withReferenceIconView:(id)arg2 ;
-(void)checkForInvalidWidgets;
-(BOOL)iconShouldAllowCloseBoxTap:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 performIconDrop:(id)arg2 ;
-(void)folderController:(id)arg0 willUseIconTransitionAnimator:(id)arg1 forOperation:(NSInteger)arg2 onViewController:(id)arg3 animated:(BOOL)arg4 ;
-(id)iconViewWillCancelDrag:(id)arg0 ;
-(void)folderControllerShouldBeginEditing:(id)arg0 withHaptic:(BOOL)arg1 ;
-(void)_willAnimateWidgetInsertion;
-(id)accessibilityTintColorForScreenRect:(struct CGRect )arg0 ;
-(id)folderControllerWantsToHideStatusBar:(id)arg0 animated:(BOOL)arg1 ;
-(BOOL)folderControllerShouldClose:(id)arg0 withPinchGesture:(id)arg1 ;
-(void)rootFolderController:(id)arg0 prepareAddSheetViewController:(id)arg1 ;
-(id)iconView:(id)arg0 iconAccessoryViewOfClass:(Class)arg1 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidEnter:(id)arg2 ;
-(void)_addTouchedIconView:(id)arg0 ;
-(void)iconView:(id)arg0 didChangeCustomImageViewController:(id)arg1 ;
-(void)unscatterAnimated:(BOOL)arg0 afterDelay:(CGFloat)arg1 withCompletion:(id)arg2 ;
-(id)folderController:(id)arg0 accessibilityTintColorForScreenRect:(struct CGRect )arg1 ;
-(void)addFolderPresentationObserver:(id)arg0 ;
-(id)firstIconViewForIcon:(id)arg0 excludingLocations:(id)arg1 ;
-(BOOL)folderController:(id)arg0 canChangeCurrentPageIndexToIndex:(NSInteger)arg1 ;
-(void)_reduceTransparencyStatusDidChange:(id)arg0 ;
-(void)removeAllWidgetIcons;
-(id)firstIconViewForIcon:(id)arg0 ;
-(void)uninstallIcon:(id)arg0 animate:(BOOL)arg1 ;
-(BOOL)_shouldRespondToIconCloseBoxes;
-(struct SBHIconGridSizeClassAreas )iconGridSizeClassAreas;
-(BOOL)iconAllowsBadging:(id)arg0 ;
-(void)rootFolderController:(id)arg0 didEndOverscrollOnFirstPageWithVelocity:(CGFloat)arg1 translation:(CGFloat)arg2 ;
-(BOOL)iconView:(id)arg0 shouldContinueToUseBackgroundViewForComponents:(id)arg1 ;
-(CGFloat)preferredExternalDockVerticalMarginForRootFolderController:(id)arg0 ;
-(void)revealIcon:(id)arg0 animated:(BOOL)arg1 completionHandler:(id)arg2 ;
-(void)rootFolderController:(id)arg0 didPresentWidgetEditingViewController:(id)arg1 ;
-(void)leafIcon:(id)arg0 didRemoveIconDataSource:(id)arg1 ;
-(void)iconViewShortcutsPresentationWillFinish:(id)arg0 ;
-(void)_tryScrollToIconToRevealAnimated:(BOOL)arg0 ;
-(void)rootFolderController:(id)arg0 didEndOverscrollOnLastPageWithVelocity:(CGFloat)arg1 translation:(CGFloat)arg2 ;
-(void)rootFolderController:(id)arg0 willPresentPageManagementUsingAnimator:(id)arg1 context:(id)arg2 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 ;
-(id)createNewFolderFromRecipientIcon:(id)arg0 grabbedIcon:(id)arg1 ;
-(BOOL)iconView:(id)arg0 supportsConfigurationForDataSource:(id)arg1 ;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 canHandleIconDropSession:(id)arg2 ;
-(void)removeReasonToIgnoreUserPreferenceForAddingNewIconsToHomeScreen:(id)arg0 ;
-(void)pushExpandedIcon:(id)arg0 location:(id)arg1 animated:(BOOL)arg2 completionHandler:(id)arg3 ;
-(id)backgroundViewForEditingDoneButtonForRootFolderController:(id)arg0 ;
-(id)rootIconListAtIndex:(NSInteger)arg0 ;
-(id)bestHomeScreenLocationForIcon:(id)arg0 ;
-(void)iconView:(id)arg0 configurationDidUpdateWithInteraction:(id)arg1 ;
-(CGFloat)additionalDragLiftScaleForIconView:(id)arg0 ;
-(id)backgroundViewForComponentsOfIconView:(id)arg0 ;
-(void)popToCurrentRootIconList;
-(id)_makeCustomViewControllerForWidgetIcon:(id)arg0 dataSource:(id)arg1 location:(id)arg2 ;
-(void)cancelAllFolderScrolling;
-(BOOL)iconModel:(id)arg0 shouldPlaceIconOnIgnoredList:(id)arg1 ;
-(void)iconView:(id)arg0 willUseContextMenuStyle:(id)arg1 ;
-(id)statusBarStyleRequestForFolderController:(id)arg0 ;
-(void)folderControllerWillClose:(id)arg0 ;
-(void)enumerateIconViewQueryableChildrenUsingBlock:(id)arg0 ;
-(id)reasonToDisallowTapOnIconView:(id)arg0 ;
-(void)rootFolderController:(id)arg0 willDismissWidgetEditingViewController:(id)arg1 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidUpdate:(id)arg2 ;
-(NSInteger)iconView:(id)arg0 draggingStartLocationWithProposedStartLocation:(NSInteger)arg1 ;
-(BOOL)iconView:(id)arg0 editingModeGestureRecognizerDidFire:(id)arg1 ;
-(id)_newIntentForDataSource:(id)arg0 inIcon:(id)arg1 ;
-(id)_proposedFolderNameForGrabbedIcon:(id)arg0 recipientIcon:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 queryOptions:(NSUInteger)arg1 ;
-(NSUInteger)supportedGridSizeClassesForIconView:(id)arg0 ;
-(void)iconView:(id)arg0 dragLiftAnimationDidChangeDirection:(NSInteger)arg1 ;
-(BOOL)iconViewDisplaysBadges:(id)arg0 ;
-(void)_iconModelDidReloadIcons:(id)arg0 ;
-(BOOL)supportsDockForIconModel:(id)arg0 ;
-(void)addReasonToIgnoreUserPreferenceForAddingNewIconsToHomeScreen:(id)arg0 ;
-(void)enumeratePageStateObserversUsingBlock:(id)arg0 ;
-(void)dismissFolderPageManagementUI;
-(void)iconView:(id)arg0 willRemoveIconAccessoryView:(id)arg1 ;
-(BOOL)_isShowingSearchableTodayView;
-(id)iconView:(id)arg0 applicationShortcutItemsWithProposedItems:(id)arg1 ;
-(id)imageViewForIconView:(id)arg0 ;
-(void)iconView:(id)arg0 willUsePreviewForCancelling:(id)arg1 targetIconView:(id)arg2 ;
-(void)_ensureWidgetIsVisibleForDebuggingWithDescriptor:(id)arg0 sizeClass:(NSInteger)arg1 ;
-(void)_finishResetRootIconLists;
-(void)rootFolderController:(id)arg0 statusBarInsetsDidChange:(struct UIEdgeInsets )arg1 ;
-(void)widgetStackViewController:(id)arg0 didActivateDataSource:(id)arg1 fromUserInteraction:(BOOL)arg2 ;
-(void)_noteUserIsInteractingWithIcons;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 options:(NSUInteger)arg2 ;
-(NSUInteger)viewMap:(id)arg0 maxRecycledViewsOfClass:(Class)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 options:(NSUInteger)arg1 ;
-(void)dismissIconConfigurationUIImmediately;
-(void)animateToDefaultStateWithCompletionHandler:(id)arg0 ;
-(id)backgroundViewForDockForRootFolderController:(id)arg0 ;
-(struct CGRect )iconView:(id)arg0 contentBoundingRectForConfigurationInteraction:(id)arg1 ;
-(void)configureIconView:(id)arg0 forIcon:(id)arg1 ;
-(void)_updateWidgetMultiplexingViewController:(id)arg0 forIconView:(id)arg1 ;
-(void)popExpandedIconFromLocation:(id)arg0 interactionContext:(id)arg1 animated:(BOOL)arg2 completionHandler:(id)arg3 ;
-(void)updateVisibleIconsToShowLeafIcons:(id)arg0 hideLeafIcons:(id)arg1 forceRelayout:(BOOL)arg2 ;
-(NSUInteger)iconModel:(id)arg0 maxRowCountForListInRootFolderWithInterfaceOrientation:(NSInteger)arg1 ;
-(void)noteFloatingDockWillChangeHeight;
-(BOOL)rootFolder:(id)arg0 canBounceIcon:(id)arg1 ;
-(BOOL)iconsShouldAllowCloseBoxes;
-(void)layoutIconListsWithAnimationType:(NSInteger)arg0 ;
-(id)firstPageLeafIdentifiersForIconModel:(id)arg0 ;
-(void)_precacheDataForRootIcons;
-(id)iconViewMap;
-(BOOL)isShowingIconConfigurationUI;
-(BOOL)resetIconLayoutWithOptions:(NSUInteger)arg0 ;
-(void)descriptorsDidChangeForAvocadoDescriptorProvider:(id)arg0 ;
-(void)iconView:(id)arg0 item:(id)arg1 willAnimateDragCancelWithAnimator:(id)arg2 ;
-(BOOL)dismissSpotlightAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(id)_effectiveTodayViewController;
-(struct SBHIconGridSizeClassSizes )gridSizeClassSizesForIconModel:(id)arg0 ;
-(BOOL)iconModel:(id)arg0 shouldAvoidPlacingIconOnFirstPage:(id)arg1 ;
-(void)noteFloatingDockWillAnimateChangeInHeight;
-(id)homescreenIconAccessoryViewMap;
-(id)_stackConfigurationForStackIcon:(id)arg0 ;
-(BOOL)relayout;
-(BOOL)iconLocationAllowsBadging:(id)arg0 ;
-(id)recycledViewsContainerProviderForViewMap:(id)arg0 ;
-(BOOL)iconView:(id)arg0 shouldActivateApplicationShortcutItem:(id)arg1 atIndex:(NSUInteger)arg2 ;
-(BOOL)icon:(id)arg0 canReceiveGrabbedIcon:(id)arg1 ;
-(id)succinctDescriptionBuilder;
-(id)_intentForDataSource:(id)arg0 inIcon:(id)arg1 creatingIfNecessary:(BOOL)arg2 ;
-(BOOL)isIconViewRecycled:(id)arg0 ;
-(void)_removeReasonToNotResetEndEditingTimer:(id)arg0 ;
-(void)removeWidget:(id)arg0 fromStack:(id)arg1 ;
-(id)defaultIconStateForIconModel:(id)arg0 ;
-(void)_handleUpdatedConfiguration:(id)arg0 forDataSource:(id)arg1 ofIcon:(id)arg2 archiving:(BOOL)arg3 ;
-(BOOL)hasOpenFolder;
-(BOOL)isFloatingDockVisible;
-(void)addIconToIgnoredList:(id)arg0 options:(NSUInteger)arg1 completion:(id)arg2 ;
-(void)iconView:(id)arg0 didEndDragSession:(id)arg1 withOperation:(NSUInteger)arg2 ;
-(void)closeFolderAnimated:(BOOL)arg0 withCompletion:(id)arg1 ;
-(BOOL)showsAddWidgetButtonWhileEditing;
-(id)_rootFolderForRootViewControllerForRootFolder:(id)arg0 ;
-(void)clearHighlightedIcon:(id)arg0 ;
-(void)icon:(id)arg0 touchMoved:(id)arg1 ;
-(void)_updateIconView:(id)arg0 forCustomIconImageViewController:(id)arg1 ;
-(void)finishInstallingIconAnimated:(BOOL)arg0 ;
-(BOOL)_isShowingOrTransitioningToSearchableTodayView;
-(NSInteger)closeBoxTypeForIconView:(id)arg0 ;
-(BOOL)isTodayViewEffectivelyVisible;
-(void)addWidgetStackToCurrentPage;
-(id)iconView:(id)arg0 iconLabelAccessoryViewOfType:(NSInteger)arg1 ;
-(void)noteIconStateChangedExternally;
-(void)presentStatistics;
-(void)widgetStackViewController:(id)arg0 didRemoveViewController:(id)arg1 ;
-(void)_sizeCategoryDidChange:(id)arg0 ;
-(id)accessibilityTintColorForIconView:(id)arg0 ;
-(id)widgetStackViewController:(id)arg0 containerApplicationNameForDataSource:(id)arg1 ;
-(BOOL)isDisplayingIconView:(id)arg0 ;
-(void)noteInterfaceOrientationChanged;
-(void)enumerateAppPredictionViewControllersWithIconViewsInIconLocationGroup:(id)arg0 withOptions:(NSUInteger)arg1 usingBlock:(id)arg2 ;
-(id)localizedDefaultFolderName;
-(void)_archiveConfiguration:(id)arg0 forDataSource:(id)arg1 ofIcon:(id)arg2 ;
-(void)enumerateKnownIconViewsUsingBlock:(id)arg0 ;
-(void)_setupApplicationShortcutItemsForPresentation:(id)arg0 ;
-(void)rootFolderPageStateProvider:(id)arg0 didEndTransitionFromState:(NSInteger)arg1 toState:(NSInteger)arg2 successfully:(BOOL)arg3 ;
-(id)iconModel:(id)arg0 localizedFolderNameForDefaultDisplayName:(id)arg1 ;
-(id)_createRootTableControllerForRootFolder:(id)arg0 ;
-(NSUInteger)iconModel:(id)arg0 maxColumnCountForListInRootFolderWithInterfaceOrientation:(NSInteger)arg1 ;
-(id)iconViewShowingContextMenu;
-(BOOL)dismissSpotlightOrTodayViewAnimated:(BOOL)arg0 ;
-(id)screenSnapshotProviderForComponentsOfIconView:(id)arg0 ;
-(void)launchFromIconView:(id)arg0 withActions:(id)arg1 ;
-(void)enumerateIconViewQueryableChildrenWithOptions:(NSUInteger)arg0 usingBlock:(id)arg1 ;
-(void)_restartEditingEndTimer;
-(void)getStatistics:(struct SBHIconManagerStatistics *)arg0 ;
-(void)rootFolderPageStateProvider:(id)arg0 willEndTransitionToState:(NSInteger)arg1 successfully:(BOOL)arg2 ;
-(CGFloat)externalDockHeightForRootFolderController:(id)arg0 ;
-(void)_compactRootListsAfterFolderCloseWithAnimation:(BOOL)arg0 ;
-(BOOL)iconViewDisplaysCloseBox:(id)arg0 ;
-(void)replaceFolderIcon:(id)arg0 byContainedIcon:(id)arg1 animated:(BOOL)arg2 ;
-(void)addWidgetsToEachPage;
-(id)animator:(id)arg0 animationSettingsForOperation:(NSUInteger)arg1 childViewController:(id)arg2 ;
-(void)popToCurrentRootIconListWhenPossible;
-(BOOL)isDisplayingIconView:(id)arg0 options:(NSUInteger)arg1 ;
-(id)iconLocationForPrecachingImages;
-(void)removeAllIconAnimations;
-(BOOL)showsDoneButtonWhileEditing;
-(BOOL)viewMap:(id)arg0 shouldRecycleView:(id)arg1 ;
-(void)rootFolderController:(id)arg0 didDismissWidgetEditingViewController:(id)arg1 ;
-(void)hideSuggestedWidgetFromStack:(id)arg0 ;
-(void)iconViewShortcutsPresentationDidCancel:(id)arg0 ;
-(BOOL)canAddIconToIgnoredList:(id)arg0 ;
-(BOOL)hasRootViewController;
-(id)_currentFolderController;
-(BOOL)iconViewShouldBeginShortcutsPresentation:(id)arg0 ;
-(void)rootFolderController:(id)arg0 wantsToAdjustTodayContentForEdgeBounceForScrollOffset:(struct CGPoint )arg1 ;
-(void)_removeTouchedIconView:(id)arg0 ;
-(BOOL)isEditingAllowedForIconLocation:(id)arg0 ;
-(void)addSuggestedActiveWidgetToStack:(id)arg0 ;
-(void)hasAnimatingFolderChanged;
-(void)iconDragManager:(id)arg0 didEndDragOriginatingFromIconView:(id)arg1 userDidBeginDrag:(BOOL)arg2 lastUserInteractionDate:(id)arg3 ;
-(void)addAllEligibleIconsToIgnoredList;
-(void)iconView:(id)arg0 willAddDragItems:(id)arg1 toSession:(id)arg2 ;
-(void)iconView:(id)arg0 willRemoveIconImageView:(id)arg1 ;
-(void)_iconModelWillReloadIcons:(id)arg0 ;
-(id)iconView:(id)arg0 labelImageWithParameters:(id)arg1 ;
-(id)init;
-(BOOL)isOverlayTodayOrLibraryViewVisible;
-(void)addNewIconToDesignatedLocation:(id)arg0 options:(NSUInteger)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 options:(NSUInteger)arg1 ;
-(id)viewMap:(id)arg0 makeNewViewOfClass:(Class)arg1 ;
-(id)addDownloadingIconsForDataSources:(id)arg0 ;
-(void)iconView:(id)arg0 configurationDidEndWithInteraction:(id)arg1 ;
-(void)_configureRootFolderConfiguration:(id)arg0 ;
-(id)widgetStackViewController:(id)arg0 containerBundleIdentifierForDataSource:(id)arg1 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)applicationBundleURLForShortcutsWithIconView:(id)arg0 ;
-(void)performAfterAllIconTouchesFinishedUsingBlock:(id)arg0 ;
-(void)libraryViewController:(id)arg0 willDismissSearchController:(id)arg1 ;
-(void)tearDownAndResetRootIconLists;
-(void)editingDidChangeWithFeedbackBehavior:(id)arg0 ;
-(CGFloat)distanceToTopOfSpotlightIconsForRootFolderController:(id)arg0 ;
-(void)_updateVisibleIconsViewsForAllowableCloseBoxes;
-(id)succinctDescription;
-(struct SBHIconGridSize )listGridSizeForFolderClass:(Class)arg0 ;
-(NSInteger)currentIconListIndex;
-(void)iconCloseBoxTapped:(id)arg0 ;
-(void)addWidgetWithIdentifier:(id)arg0 toPage:(NSInteger)arg1 withSize:(NSInteger)arg2 ;
-(id)_createAppropriateRootViewControllerForRootFolder:(id)arg0 ;
-(NSUInteger)maxIconCountForDockForIconModel:(id)arg0 ;
-(void)_ensureRootFolderController;
-(void)_finishResetRootIconListsReusingPreviousControllers:(BOOL)arg0 ;
-(id)iconModel:(id)arg0 customInsertionIndexPathForIcon:(id)arg1 inRootFolder:(id)arg2 ;
-(id)applicationShortcutWidgetBundleIdentifierForShortcutsWithIconView:(id)arg0 ;
-(Class)controllerClassForFolderClass:(Class)arg0 ;
-(void)todayViewControllerDidEndScrolling:(id)arg0 ;
-(void)multiplexingManager:(id)arg0 willRemoveViewController:(id)arg1 forIdentifier:(id)arg2 ;
-(BOOL)rootFolderControllerCanUseSeparateWindowForRotation:(id)arg0 ;
-(void)rootFolderPageStateProvider:(id)arg0 willBeginTransitionToState:(NSInteger)arg1 animated:(BOOL)arg2 interactive:(BOOL)arg3 ;
-(BOOL)canSaveIconState:(id)arg0 ;
-(BOOL)canOpenFolders;
-(void)performAfterIconContextMenuDismissesUsingBlock:(id)arg0 ;
-(void)removeFolderPresentationObserver:(id)arg0 ;
-(void)_discardEndEditingTimerAndDontResetUntilReasonIsRemoved:(id)arg0 ;
-(BOOL)hasRootFolderController;
-(void)_processPendingDefaultIntents;
-(void)rootFolderController:(id)arg0 willDismissPageManagementUsingAnimator:(id)arg1 context:(id)arg2 ;
-(void)rootFolderControllerViewDidDisappear:(id)arg0 ;
-(id)_intentForWidget:(id)arg0 ofIcon:(id)arg1 creatingIfNecessary:(BOOL)arg2 ;
-(NSUInteger)allowedInterfaceOrientations;
-(void)popExpandedIconAnimated:(BOOL)arg0 completionHandler:(id)arg1 ;
-(void)enumerateEditableViewControllersUsingBlock:(id)arg0 ;
-(void)rootFolderController:(id)arg0 didOverscrollOnLastPageByAmount:(CGFloat)arg1 ;
-(id)_multiplexingViewControllerForIcon:(id)arg0 dataSource:(id)arg1 location:(id)arg2 withPriority:(NSUInteger)arg3 ;
-(id)homescreenIconImageViewMap;
-(void)_animateFolderIcon:(id)arg0 open:(BOOL)arg1 location:(id)arg2 animated:(BOOL)arg3 withCompletion:(id)arg4 ;
-(void)rootFolderController:(id)arg0 didOverscrollOnFirstPageByAmount:(CGFloat)arg1 ;
-(void)changeSizeOfWidgetIcon:(id)arg0 toSizeClass:(NSUInteger)arg1 ;
-(id)iconView:(id)arg0 homeScreenContentViewForConfigurationInteraction:(id)arg1 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(BOOL)rootFolder:(id)arg0 canAddIcon:(id)arg1 toIconList:(id)arg2 inFolder:(id)arg3 ;
-(void)uninstallIcon:(id)arg0 ;
-(BOOL)shouldHighlightTouchedIconView:(id)arg0 ;
-(BOOL)hasAnimatingFolder;
-(void)_iconModelWillLayout:(id)arg0 ;
-(void)iconViewWillBeginDrag:(id)arg0 session:(id)arg1 ;
-(void)resetRootIconLists;
-(id)_createRootFolderControllerForRootFolder:(id)arg0 ;
-(void)organizeAllIconsAcrossPagesWithPageCount:(NSUInteger)arg0 ;
-(void)_updateOverlayOcclusionForRootFolderController;
-(id)_folderControllerForIcon:(id)arg0 inLocation:(id)arg1 ;
-(void)enumerateIconViewsDisplayedInAppPredictionsInLocationGroup:(id)arg0 withOptions:(NSUInteger)arg1 usingBlock:(id)arg2 ;
-(void)highlightIconView:(id)arg0 ;
-(void)insertIcons:(id)arg0 intoWidgetStack:(id)arg1 ;
-(id)rootFolderController:(id)arg0 vendorNameForAppWithBundleIdentifiers:(id)arg1 ;
-(void)shuffleWidgetStackForTestRecipe;
-(void)addPageStateObserver:(id)arg0 ;
-(BOOL)isPerformingCancelledExpandTransition;
-(id)_dumpRootFolderForStateCapture:(id)arg0 ;
-(void)folderController:(id)arg0 didBeginEditingTitle:(id)arg1 ;
-(void)iconView:(id)arg0 configurationWillBeginWithInteraction:(id)arg1 ;
-(void)rootFolderController:(id)arg0 didDismissPageManagementWithContext:(id)arg1 ;
-(id)iconListViewForIndexPath:(id)arg0 ;
-(void)addNewIconsToDesignatedLocations:(id)arg0 saveIconState:(BOOL)arg1 ;
-(void)didDeleteIconState:(id)arg0 ;
-(BOOL)multiplexingManager:(id)arg0 shouldCacheRecentViewController:(id)arg1 forIdentifier:(id)arg2 ;
-(BOOL)presentSpotlightFromSource:(NSUInteger)arg0 animated:(BOOL)arg1 completionHandler:(id)arg2 ;
-(id)intentForWidget:(id)arg0 ofIcon:(id)arg1 ;
-(void)iconViewShortcutsPresentationWillBegin:(id)arg0 ;
-(id)replaceDownloadingIconsForDataSources:(id)arg0 withIconsFromGenerator:(id)arg1 ;
-(void)informUsageMonitorOfVisibleIconRectsForOverlayTodayViewController;
-(id)launchURLForIconView:(id)arg0 ;
-(void)rootFolderController:(id)arg0 handleInsertionForWidgetIcon:(id)arg1 withReferenceIconView:(id)arg2 fromTodayPresenter:(BOOL)arg3 dismissViewControllerHandler:(id)arg4 ;
-(void)iconDragManagerMultiItemIconDraggingDidChange:(id)arg0 ;
-(void)rootFolderController:(id)arg0 willUsePropertyAnimator:(id)arg1 toTransitionToState:(NSInteger)arg2 ;
-(void)rootFolderPageStateProvider:(id)arg0 didContinueTransitionToState:(NSInteger)arg1 progress:(CGFloat)arg2 ;
-(void)dealloc;
-(void)folderController:(id)arg0 didEndEditingTitle:(id)arg1 ;
-(BOOL)isIconVisiblyRepresented:(id)arg0 ;
-(void)rootFolderController:(id)arg0 willPresentWidgetEditingViewController:(id)arg1 ;
-(void)dismissIconConfigurationUI;
-(void)avocadoHostViewController:(id)arg0 requestsLaunchWithAction:(id)arg1 ;
-(void)icon:(id)arg0 touchEnded:(BOOL)arg1 ;
-(void)libraryViewController:(id)arg0 willPresentSearchController:(id)arg1 ;
+(CGFloat)defaultIconLayoutAnimationDuration;


@end


#endif


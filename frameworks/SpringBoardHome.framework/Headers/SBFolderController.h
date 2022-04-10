// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBFOLDERCONTROLLER_H
#define SBFOLDERCONTROLLER_H

@class UIStatusBar;

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include "SBNestingViewController.h"
@class SBFolderContainerView;
@class SBFolderView;
@class SBFolderControllerBackgroundView;
@class SBIconAnimator;
@class SBFolderControllerConfiguration;
@class SBFolderController;
@class SBFolderControllerAnimationContext;
@class SBIconListPageControl;
@class SBFolder;
@class SBIconView;
@class SBIconListView;
@class SBIconListModel;
@class SBFolderIconImageCache;
@class SBHIconImageCache;
@class SBIconPageIndicatorImageSetCache;
@class SBHIconModel;
@protocol SBFolderControllerDelegate;
@protocol SBIconListViewDragObserver;
@protocol SBFolderControllerBackgroundViewDelegate;
@protocol SBFolderViewDelegate;
@protocol SBFolderObserver;
@protocol SBIconListLayoutObserver;
@protocol SBIconViewObserver;
@protocol SBScaleIconZoomAnimationContaining;
@protocol BSDescriptionProviding;
@protocol SBIconLocationPresenting;
@protocol SBIconViewQuerying;
@protocol BSInvalidatable;
@protocol BSInvalidatable;
@protocol SBFolderControllerDelegate;
@protocol SBIconListLayoutProvider;
@protocol SBIconViewProviding;

@interface SBFolderController : SBNestingViewController <SBFolderControllerDelegate, SBIconListViewDragObserver, SBFolderControllerBackgroundViewDelegate, SBFolderViewDelegate, SBFolderObserver, SBIconListLayoutObserver, SBIconViewObserver, SBScaleIconZoomAnimationContaining, BSDescriptionProviding, SBIconLocationPresenting, SBIconViewQuerying>

{
SBFolderContainerView *_containerView;
SBFolderView *_contentView;
SBFolderControllerBackgroundView *_backgroundView;
NSTimer *_closeFolderTimer;
BOOL _grabbedIconHasEverEnteredFolderView;
SBIconAnimator *_iconAnimator;
NSMutableSet *_draggingEnteredIconListViews;
NSMutableSet *_fakeStatusBarHidingReasons;
NSMutableSet *_realStatusBarHidingReasons;
NSInteger _leadingVisiblePageIndex;
NSInteger _trailingVisiblePageIndex;
NSHashTable *_pageViewControllerAppearStateOverrideAssertions;
NSHashTable *_iconImageViewControllerKeepStaticAssertions;
NSObject<BSInvalidatable> *_iconImageViewControllerKeepStaticForAnimatedScrollAssertion;
NSMutableSet *_iconViewsWithCustomImageViewControllers;
NSMapTable *_iconViewCustomImageViewControllerTouchCancellationAssertions;
NSMutableSet *_appearanceTransitioningCustomImageViewControllers;
}


@property (nonatomic) BOOL open; // ivar: _isOpen
@property (nonatomic) BOOL active; // ivar: _active
@property (nonatomic) BOOL rotating; // ivar: _rotating
@property (nonatomic) BOOL animating; // ivar: _isAnimating
@property (retain, nonatomic) NSObject<BSInvalidatable> *statusBarAssertion; // ivar: _statusBarAssertion
@property (retain, nonatomic) UIStatusBar *fakeStatusBar; // ivar: _fakeStatusBar
@property (copy, nonatomic) SBFolderControllerConfiguration *configuration; // ivar: _configuration
@property (nonatomic) NSInteger orientation; // ivar: _orientation
@property (readonly, copy, nonatomic) NSArray *_viewControllersToNotifyForViewObscuration;
@property (readonly, nonatomic) SBFolderView *folderView;
@property (readonly, nonatomic) SBFolderView *folderViewIfLoaded;
@property (readonly, nonatomic) SBFolderContainerView *folderContainerView;
@property (readonly, weak, nonatomic) SBFolderController *outerFolderController;
@property (readonly, nonatomic) SBFolderController *innerFolderController;
@property (retain, nonatomic) SBFolderControllerAnimationContext *animationContext; // ivar: _animationContext
@property (retain, nonatomic) SBIconListPageControl *pageControl; // ivar: _pageControl
@property (weak, nonatomic) NSObject<SBFolderControllerDelegate> *folderDelegate; // ivar: _folderDelegate
@property (retain, nonatomic) SBFolder *folder; // ivar: _folder
@property (readonly, nonatomic) NSObject<SBIconListLayoutProvider> *listLayoutProvider; // ivar: _listLayoutProvider
@property (readonly, nonatomic) NSUInteger allowedOrientations; // ivar: _allowedOrientations
@property (readonly, weak, nonatomic) NSObject<SBIconViewProviding> *iconViewProvider; // ivar: _iconViewProvider
@property (retain, nonatomic) SBIconView *folderIconView; // ivar: _folderIconView
@property (readonly, nonatomic) UIView *headerView; // ivar: _headerView
@property (readonly, nonatomic) NSInteger currentPageIndex;
@property (readonly, nonatomic) BOOL editing; // ivar: _isEditing
@property (readonly, nonatomic) BOOL scrolling;
@property (readonly, nonatomic) BOOL scrollDragging;
@property (readonly, nonatomic) BOOL scrollDecelerating;
@property (readonly, nonatomic) BOOL scrollTracking;
@property (readonly, nonatomic) NSUInteger userInterfaceLayoutDirectionHandling;
@property (readonly, nonatomic) NSInteger userInterfaceLayoutDirection;
@property (readonly, nonatomic) CGFloat currentScrollingOffset;
@property (readonly, nonatomic) NSInteger defaultPageIndex;
@property (readonly, nonatomic) NSInteger minimumPageIndex;
@property (readonly, nonatomic) NSInteger maximumPageIndex;
@property (readonly, nonatomic) NSInteger firstIconPageIndex;
@property (readonly, nonatomic) NSInteger lastIconPageIndex;
@property (readonly, nonatomic) UIView *contentView;
@property (readonly, copy, nonatomic) NSArray *iconListViews;
@property (readonly, nonatomic) NSUInteger iconListViewCount;
@property (readonly, nonatomic) SBIconListView *currentIconListView;
@property (readonly, nonatomic) SBIconListModel *currentIconListModel;
@property (copy, nonatomic) NSString *originatingIconLocation; // ivar: _originatingIconLocation
@property (readonly, nonatomic) SBFolderController *deepestFolderController;
@property (readonly, nonatomic) NSIndexPath *currentIndexPath;
@property (readonly, nonatomic) BOOL hasDock;
@property (readonly, nonatomic) SBIconListView *dockListView;
@property (readonly, nonatomic) BOOL suspendsWallpaperAnimationWhileOpen;
@property (readonly, nonatomic) BOOL closesAfterDragExits;
@property (readonly, nonatomic) BOOL canAcceptFolderIconDrags;
@property (readonly, nonatomic) BOOL disablesScrollingWhileIconDragIsDropping;
@property (nonatomic) BOOL occluded; // ivar: _occluded
@property (nonatomic) BOOL pageControlHidden;
@property (nonatomic) CGFloat pageControlAlpha;
@property (retain, nonatomic) UIColor *defaultAccessibilityTintColor; // ivar: _defaultAccessibilityTintColor
@property (readonly, nonatomic) SBFolderIconImageCache *folderIconImageCache; // ivar: _folderIconImageCache
@property (retain, nonatomic) SBHIconImageCache *iconImageCache; // ivar: _iconImageCache
@property (readonly, nonatomic) SBIconPageIndicatorImageSetCache *iconPageIndicatorImageSetCache; // ivar: _iconPageIndicatorImageSetCache
@property (readonly, nonatomic) BOOL overridingPageViewControllerAppearanceStateToRemainDisappeared;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) SBHIconModel *iconModel;
@property (readonly, nonatomic) SBIconListView *dockIconListView;
@property (readonly, nonatomic) UIView *containerView;
@property (readonly, nonatomic) UIWindow *animationWindow;
@property (readonly, nonatomic) UIView *fallbackIconContainerView;
@property (readonly, copy, nonatomic) NSArray *extraViewsContainers;
@property (readonly, copy, nonatomic) NSArray *extraViews;
@property (readonly, nonatomic) BOOL shouldAnimateLastTwoViewsAsOne;
@property (readonly, nonatomic) BOOL shouldAnimateFirstTwoViewsAsOne;
@property (readonly, copy, nonatomic) NSSet *presentedIconLocations;


-(void)folderController:(id)arg0 willRemoveFakeStatusBar:(id)arg1 ;
-(void)nestingViewController:(id)arg0 willPerformOperation:(NSInteger)arg1 onViewController:(id)arg2 withTransitionCoordinator:(id)arg3 ;
-(id)firstIconViewForIcon:(id)arg0 inLocations:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocations:(id)arg1 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDragItem:(id)arg2 willAnimateDropWithAnimator:(id)arg3 ;
-(void)iconListView:(id)arg0 didAddIconView:(id)arg1 ;
-(void)noteUserIsInteractingWithIcons;
-(struct UIEdgeInsets )statusBarEdgeInsetsForFolderController:(id)arg0 ;
-(id)iconListViewAtIndex:(NSUInteger)arg0 ;
-(void)folderControllerWillOpen:(id)arg0 ;
-(Class)controllerClassForFolder:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 ;
-(id)fakeStatusBarForFolderController:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 customSpringAnimationBehaviorForDroppingItem:(id)arg2 ;
-(NSInteger)pageIndexForIconListModelIndex:(NSUInteger)arg0 ;
-(void)folderController:(id)arg0 draggedIconShouldDropFromListView:(id)arg1 ;
-(void)minimumHomeScreenScaleDidChange;
-(BOOL)_isValidPageIndex:(NSInteger)arg0 ;
-(void)folderControllerWillBeginScrolling:(id)arg0 ;
-(void)setCurrentPageIndex:(NSInteger)arg0 ;
-(void)folderControllerShouldEndEditing:(id)arg0 ;
-(BOOL)_allowUserInteraction;
-(void)invalidate;
-(void)_invalidateAllCancelTouchesAssertions;
-(void)folderControllerDidEndScrolling:(id)arg0 ;
-(void)animateScrollToDefaultPageWithCompletionHandler:(id)arg0 ;
-(id)folderControllerForFolder:(id)arg0 ;
-(void)enumerateDisplayedIconViewsUsingBlock:(id)arg0 ;
-(void)iconListView:(id)arg0 concludeIconDrop:(id)arg1 ;
-(NSUInteger)_depth;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 shouldAllowSpringLoadedInteractionForIconDropSession:(id)arg2 onIconView:(id)arg3 ;
-(void)enumerateDisplayedIconViewsForIcon:(id)arg0 usingBlock:(id)arg1 ;
-(BOOL)isPresentingIconLocation:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 springLoadedInteractionForIconDragDidCompleteOnIconView:(id)arg2 ;
-(void)folderController:(id)arg0 willCreateInnerFolderControllerWithConfiguration:(id)arg1 ;
-(id)iconListViewForTouch:(id)arg0 ;
-(struct UIEdgeInsets )contentOverlayInsetsFromParentIfAvailableForFolderController:(id)arg0 ;
-(void)layoutIconLists:(CGFloat)arg0 animationType:(NSInteger)arg1 forceRelayout:(BOOL)arg2 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 willUseIconView:(id)arg2 forDroppingIconDragItem:(id)arg3 ;
-(void)prepareToOpen;
-(id)beginModifyingDockOffscreenFractionForReason:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 previewForDroppingIconDragItem:(id)arg2 proposedPreview:(id)arg3 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidExit:(id)arg2 ;
-(BOOL)isDisplayingIconView:(id)arg0 inLocation:(id)arg1 ;
-(CGFloat)minimumHomeScreenScaleForFolderController:(id)arg0 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 ;
-(BOOL)doesPageContainIconListView:(NSInteger)arg0 ;
-(void)removeViewFromHierarchyForNestedViewController:(id)arg0 ;
-(void)beginEditingTitle;
-(id)beginOverridingPageViewControllerAppearanceStateToRemainDisappearedForReason:(id)arg0 ;
-(void)_removePageViewControllerAppearStateOverrideAssertion:(id)arg0 ;
-(void)_removeIconImageViewControllerKeepStaticAssertion:(id)arg0 ;
-(BOOL)suspendsWallpaperAnimationWhileOpen;
-(void)setScrollingDisabled:(BOOL)arg0 forReason:(id)arg1 ;
-(void)_updateHomescreenAndDockFade;
-(void)_hideFakeStatusBarForReason:(id)arg0 animated:(BOOL)arg1 ;
-(void)_unhideFakeStatusBarForReason:(id)arg0 animated:(BOOL)arg1 ;
-(BOOL)_iconAppearsOnCurrentPage:(id)arg0 ;
-(void)pushFolderIcon:(id)arg0 location:(id)arg1 animated:(BOOL)arg2 completion:(id)arg3 ;
-(id)borrowScalingView;
-(void)folderController:(id)arg0 iconListView:(id)arg1 performIconDrop:(id)arg2 ;
-(void)folderController:(id)arg0 willUseIconTransitionAnimator:(id)arg1 forOperation:(NSInteger)arg2 onViewController:(id)arg3 animated:(BOOL)arg4 ;
-(void)folderControllerShouldBeginEditing:(id)arg0 withHaptic:(BOOL)arg1 ;
-(id)accessibilityTintColorForScreenRect:(struct CGRect )arg0 ;
-(id)folderControllerWantsToHideStatusBar:(id)arg0 animated:(BOOL)arg1 ;
-(BOOL)folderControllerShouldClose:(id)arg0 withPinchGesture:(id)arg1 ;
-(id)iconListViewAtPoint:(struct CGPoint )arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidEnter:(id)arg2 ;
-(void)iconView:(id)arg0 didChangeCustomImageViewController:(id)arg1 ;
-(void)unscatterAnimated:(BOOL)arg0 afterDelay:(CGFloat)arg1 withCompletion:(id)arg2 ;
-(void)_removeFakeStatusBar;
-(id)folderController:(id)arg0 accessibilityTintColorForScreenRect:(struct CGRect )arg1 ;
-(id)firstIconViewForIcon:(id)arg0 excludingLocations:(id)arg1 ;
-(BOOL)folderController:(id)arg0 canChangeCurrentPageIndexToIndex:(NSInteger)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 ;
-(void)returnScalingView;
-(void)revealIcon:(id)arg0 animated:(BOOL)arg1 completionHandler:(id)arg2 ;
-(void)prepareToTearDown;
-(void)iconViewWillPresentContextMenu:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 ;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 canHandleIconDropSession:(id)arg2 ;
-(void)viewDidLoad;
-(id)keyCommands;
-(id)iconListViewForIconListModelIndex:(NSUInteger)arg0 ;
-(id)statusBarStyleRequestForFolderController:(id)arg0 ;
-(void)folderControllerWillClose:(id)arg0 ;
-(void)iconListView:(id)arg0 iconDropSessionDidEnd:(id)arg1 ;
-(void)iconListViewDidChangeBoundsSize:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidUpdate:(id)arg2 ;
-(void)setContentAlpha:(CGFloat)arg0 ;
-(NSUInteger)iconListViewIndexForIconListModelIndex:(NSUInteger)arg0 ;
-(void)folder:(id)arg0 didReplaceIcon:(id)arg1 withIcon:(id)arg2 ;
-(NSInteger)pageIndexForIconListViewIndex:(NSUInteger)arg0 ;
-(BOOL)restoreExpandedPathIdentifiers:(id)arg0 ;
-(void)prepareToLaunchTappedIcon:(id)arg0 completionHandler:(id)arg1 ;
-(BOOL)_canAnyIconViewBeVisiblySettled;
-(struct UIEdgeInsets )statusBarInsetsForOrientation:(NSInteger)arg0 ;
-(void)viewDidAppear:(BOOL)arg0 ;
-(id)_makeContentViewWithConfiguration:(id)arg0 ;
-(BOOL)isEffectivelyOccluded;
-(void)updateAppearanceStateForPageViewControllers:(BOOL)arg0 ;
-(void)_cancelTouchesForAllCustomIconImageViewControllers;
-(id)visiblePageViewControllers;
-(void)_handleEndEditingKeyCommand:(id)arg0 ;
-(id)nestingViewController:(id)arg0 animationControllerForOperation:(NSInteger)arg1 onViewController:(id)arg2 animated:(BOOL)arg3 ;
-(void)_configureForInnerFolderController:(id)arg0 ;
-(void)prepareToClose;
-(void)_compactFolder;
-(void)fadeContentForMinificationFraction:(CGFloat)arg0 ;
-(BOOL)shouldAnimateFirstTwoViewsAsOne;
-(void)fadeContentForMagnificationFraction:(CGFloat)arg0 ;
-(NSUInteger)iconListModelIndexForPageIndex:(NSInteger)arg0 ;
-(BOOL)setCurrentPageIndex:(NSInteger)arg0 animated:(BOOL)arg1 completion:(id)arg2 ;
-(BOOL)setCurrentPageIndex:(NSInteger)arg0 animated:(BOOL)arg1 ;
-(id)matchMoveSourceViewForIconView:(id)arg0 ;
-(void)folderControllerDidOpen:(id)arg0 ;
-(void)folderControllerDidClose:(id)arg0 ;
// -(id)folderController:(id)arg0 iconAnimatorForOperation:(NSInteger)arg1 onViewController:(id)arg2 animated:(BOOL)
        //arg3 initialDelay:(*CGFloat)arg4 ;
-(BOOL)hasDock;
-(void)_cancelCloseFolderTimer;
-(BOOL)closesAfterDragExits;
-(void)_closeFolderTimerFired;
-(BOOL)canAcceptFolderIconDrags;
-(void)_cancelAllInteractionTimers;
-(void)noteIconDrag:(id)arg0 didChangeInIconListView:(id)arg1 ;
-(void)_setCloseFolderTimerIfNecessary;
-(void)_clearIconAnimator;
-(id)_newAnimatorForZoomUp:(BOOL)arg0 ;
-(BOOL)_listIndexIsVisible:(NSUInteger)arg0 ;
-(BOOL)shouldOpenFolderIcon:(id)arg0 ;
-(void)configureInnerFolderControllerConfiguration:(id)arg0 ;
-(void)_cancelTouchesForCustomIconImageViewController:(id)arg0 ;
-(void)noteIconDragDidEnd:(id)arg0 ;
-(BOOL)shouldAnimateLastTwoViewsAsOne;
-(id)succinctDescriptionBuilder;
-(void)viewWillAppear:(BOOL)arg0 ;
-(NSUInteger)iconListViewIndexForPageIndex:(NSInteger)arg0 ;
-(void)iconListView:(id)arg0 didRemoveIconView:(id)arg1 ;
-(void)_invalidate;
-(id)initWithConfiguration:(id)arg0 ;
-(id)iconLocation;
-(void)viewDidDisappear:(BOOL)arg0 ;
-(id)iconListViewForDrag:(id)arg0 ;
-(void)iconViewDidDismissContextMenu:(id)arg0 ;
-(void)delegateDidChange;
-(void)parentDelegateDidChange;
-(BOOL)isDisplayingIconView:(id)arg0 ;
-(id)pageViewControllersForLeadingPageIndex:(NSInteger)arg0 trailingPageIndex:(NSInteger)arg1 ;
-(id)viewControllersForPageIndex:(NSInteger)arg0 ;
-(void)_updatePresentationModeForIconViews;
-(void)_updatePresentationModeForIconView:(id)arg0 ;
-(NSUInteger)iconImageViewControllerPresentationModeForIconView:(id)arg0 ;
-(BOOL)isEffectivelyOccludedIfHasInnerFolder:(BOOL)arg0 ;
-(BOOL)_homescreenAndDockShouldFade;
-(void)_setHomescreenAndDockAlpha:(CGFloat)arg0 ;
-(void)_removeFakeStatusBarAndAssertionIfExists;
-(void)_hideStatusBarForReason:(id)arg0 animated:(BOOL)arg1 ;
-(void)_unhideStatusBarForReason:(id)arg0 ;
-(void)folder:(id)arg0 didAddIcons:(id)arg1 removedIcons:(id)arg2 ;
-(void)_enableTouchesOnAllCustomIconImageViewControllers;
-(void)setCurrentPageIndexToListDirectlyContainingIcon:(id)arg0 animated:(BOOL)arg1 ;
-(void)popFolderAnimated:(BOOL)arg0 completion:(id)arg1 ;
-(BOOL)_canAcceptIconDropSession:(id)arg0 inListView:(id)arg1 ;
-(id)nestingViewController:(id)arg0 sourceViewForPresentingViewController:(id)arg1 ;
-(void)_disableTouchesOnAllCustomIconImageViewControllers;
-(id)keepIconImageViewControllersStaticInAllPagesExcluding:(id)arg0 forReason:(id)arg1 ;
-(void)noteIconDrag:(id)arg0 didEnterIconListView:(id)arg1 ;
-(void)noteIconDrag:(id)arg0 didExitIconListView:(id)arg1 ;
-(BOOL)disablesScrollingWhileIconDragIsDropping;
-(void)folderViewDidScroll:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(void)loadView;
-(id)succinctDescription;
-(void)_addFakeStatusBarView;
-(void)_fadeHomescreenAndDockIfNecessaryForFolderOpen:(BOOL)arg0 ;
-(void)updateContentViewOcclusionWithOverriddenHasInnerFolder:(BOOL)arg0 ;
-(void)updateContentViewOcclusion;
-(void)viewWillTransitionToSize:(struct CGSize )arg0 forOperation:(NSInteger)arg1 withTransitionCoordinator:(id)arg2 ;
-(void)orientationDidChange:(NSInteger)arg0 ;
-(void)_updateAssociatedControllerStateAnimated:(BOOL)arg0 ;
-(void)_updateFolderRequiredTrailingEmptyListCount;
-(void)setCurrentPageIndexToListDirectlyContainingIcon:(id)arg0 animated:(BOOL)arg1 completion:(id)arg2 ;
-(void)_updateStateOfAssociatedController:(id)arg0 animated:(BOOL)arg1 ;
-(void)viewWillTransitionToSize:(struct CGSize )arg0 withTransitionCoordinator:(id)arg1 ;
-(void)setEditing:(BOOL)arg0 animated:(BOOL)arg1 ;
-(BOOL)_isHitTestingDisabledOnCustomIconImageViewControllers;
-(CGFloat)minimumHomeScreenScaleForFolderControllerBackgroundView:(id)arg0 ;
-(Class)iconListViewClassForFolderView:(id)arg0 ;
-(id)iconLocationForFolderView:(id)arg0 ;
-(void)folderView:(id)arg0 currentPageIndexWillChange:(NSInteger)arg1 ;
-(void)folderView:(id)arg0 currentPageIndexDidChange:(NSInteger)arg1 ;
-(void)folderViewWillBeginDragging:(id)arg0 ;
-(void)folderViewWillBeginScrolling:(id)arg0 ;
-(void)folderViewWillEndDragging:(id)arg0 ;
-(void)folderViewWillUpdatePageDuringScrolling:(id)arg0 ;
-(void)folderViewDidEndScrolling:(id)arg0 ;
-(void)folderView:(id)arg0 willAnimateScrollToPageIndex:(NSInteger)arg1 ;
-(void)folderViewShouldClose:(id)arg0 withPinchGesture:(id)arg1 ;
-(void)iconViewDidHandleTap:(id)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)folderViewShouldBeginEditing:(id)arg0 ;
-(void)folderViewShouldEndEditing:(id)arg0 ;
-(BOOL)folderView:(id)arg0 iconListView:(id)arg1 canHandleIconDropSession:(id)arg2 ;
-(id)folderView:(id)arg0 iconListView:(id)arg1 iconDropSessionDidUpdate:(id)arg2 ;
-(void)folderView:(id)arg0 iconListView:(id)arg1 iconDropSession:(id)arg2 didPauseAtLocation:(struct CGPoint )arg3 ;
-(void)folderView:(id)arg0 iconListView:(id)arg1 iconDropSessionDidExit:(id)arg2 ;
-(void)folderView:(id)arg0 iconListView:(id)arg1 performIconDrop:(id)arg2 ;
-(void)folderView:(id)arg0 iconListView:(id)arg1 willUseIconView:(id)arg2 forDroppingIconDragItem:(id)arg3 ;
-(id)folderView:(id)arg0 iconListView:(id)arg1 previewForDroppingIconDragItem:(id)arg2 proposedPreview:(id)arg3 ;
-(void)folderView:(id)arg0 iconListView:(id)arg1 iconDragItem:(id)arg2 willAnimateDropWithAnimator:(id)arg3 ;
-(void)folderViewDidChangeOrientation:(id)arg0 ;
-(void)viewWillDisappear:(BOOL)arg0 ;
-(void)prepareForAnimation:(id)arg0 withTargetIcon:(id)arg1 ;
-(void)dealloc;
-(BOOL)folderView:(id)arg0 iconListView:(id)arg1 shouldAllowSpringLoadedInteractionForIconDropSession:(id)arg2 onIconView:(id)arg3 ;
-(void)folderView:(id)arg0 iconListView:(id)arg1 springLoadedInteractionForIconDragDidCompleteOnIconView:(id)arg2 ;
-(id)folderView:(id)arg0 iconListView:(id)arg1 customSpringAnimationBehaviorForDroppingItem:(id)arg2 ;
-(void)folderView:(id)arg0 didAddIconListView:(id)arg1 ;
-(void)folderView:(id)arg0 didRemoveIconListView:(id)arg1 ;
-(CGFloat)minimumHomeScreenScaleForFolderView:(id)arg0 ;
-(struct UIEdgeInsets )contentOverlayInsetsFromParentIfAvailableForFolderView:(id)arg0 ;
-(id)folderView:(id)arg0 accessibilityTintColorForRect:(struct CGRect )arg1 ;
-(void)addViewToHierarchyForNestedViewController:(id)arg0 ;
+(id)iconLocation;
+(Class)listViewClass;


@end


#endif


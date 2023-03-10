// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBROOTFOLDERVIEW_H
#define SBROOTFOLDERVIEW_H

@class SBFParallaxSettings;

@class SBFTouchPassThroughView;
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#include "SBFolderView.h"

@class SBDockView;
@class SBIconListView;
@class _SBRootFolderLayoutWrapperView;
@class SBSearchBackdropView;
@class _SBRootFolderViewElementBorrowedAssertion;
@class SBTitledHomeScreenButton;
@class SBHRootFolderSettings;
@class SBHMinusPageStepper;
@class SBDockIconListView;
@class SBRootFolder;
@class SBSearchGesture;
@protocol _UISettingsKeyObserver;
@protocol SBDockViewDelegate;
@protocol SBFRemoteBasebandLoggingObserver;
@protocol BSInvalidatable;
@protocol SBIconListViewIconLocationTransitioning;
@protocol SBRootFolderViewLayoutManager;
@protocol SBRootFolderViewLayoutManager;
@protocol SBRootFolderViewLayoutManager;
@protocol SBRootFolderViewLayoutManager;
@protocol SBRootFolderViewDelegate;

@interface SBRootFolderView : SBFolderView <_UISettingsKeyObserver, SBDockViewDelegate, SBFRemoteBasebandLoggingObserver>

{
SBDockView *_dockView;
SBIconListView *_todayPageListView;
SBIconListView *_favoriteTodayPageListView;
_SBRootFolderLayoutWrapperView *_searchableTodayWrapperView;
SBSearchBackdropView *_searchBackdropView;
SBSearchBackdropView *_trailingCustomBackdropView;
UIView *_trailingCustomSearchDimmingView;
CGFloat _baseOffsetForDeterminingScrollToSearchThreshold;
CGFloat _pageWidthWhenScrollToSearchBeganDragging;
BOOL _scrollToSearchIsDraggingOrAnimating;
CGFloat _scrollOffsetWhenScrollingBegan;
BOOL _isTodayViewBouncing;
NSInteger _iconListFrameOrientationOverride;
NSInteger _activeSidebarAnimationCount;
NSHashTable *_dockOffscreenProgressSettingClients;
NSObject<BSInvalidatable> *_dockStateDumpHandle;
BOOL _lastEventWasAttemptingToOverscrollFirstPage;
BOOL _lastEventWasAttemptingToOverscrollLastPage;
}


@property (nonatomic) _SBRootFolderViewElementBorrowedAssertion *dockBorrowedAssertion; // ivar: _dockBorrowedAssertion
@property (nonatomic) _SBRootFolderViewElementBorrowedAssertion *pageControlBorrowedAssertion; // ivar: _pageControlBorrowedAssertion
@property (retain, nonatomic) SBFTouchPassThroughView *titledButtonsContainerView; // ivar: _titledButtonsContainerView
@property (retain, nonatomic) SBTitledHomeScreenButton *doneButton; // ivar: _doneButton
@property (retain, nonatomic) SBTitledHomeScreenButton *widgetButton; // ivar: _widgetButton
@property (nonatomic) BOOL sidebarSlideGestureActive; // ivar: _sidebarSlideGestureActive
@property (readonly, nonatomic) NSUInteger sidebarAllowedOrientations; // ivar: _sidebarAllowedOrientations
@property (retain, nonatomic) NSObject<SBIconListViewIconLocationTransitioning> *firstListViewIconLocationTransitionHandler; // ivar: _firstListViewIconLocationTransitionHandler
@property (nonatomic) BOOL sidebarVisibleWhenScrollingBegan; // ivar: _sidebarVisibleWhenScrollingBegan
@property (nonatomic) CGFloat scrollingAdjustment; // ivar: _scrollingAdjustment
@property (nonatomic) BOOL allowsFreeScrollingUntilScrollingEnds; // ivar: _allowsFreeScrollingUntilScrollingEnds
@property (retain, nonatomic) SBHRootFolderSettings *folderSettings; // ivar: _folderSettings
@property (readonly, nonatomic) NSUInteger ignoresOverscrollOnFirstPageOrientations; // ivar: _ignoresOverscrollOnFirstPageOrientations
@property (readonly, nonatomic) NSUInteger ignoresOverscrollOnLastPageOrientations; // ivar: _ignoresOverscrollOnLastPageOrientations
@property (nonatomic) BOOL userAttemptedToOverscrollFirstPageDuringCurrentGesture; // ivar: _userAttemptedToOverscrollFirstPageDuringCurrentGesture
@property (nonatomic) BOOL userAttemptedToOverscrollLastPageDuringCurrentGesture; // ivar: _userAttemptedToOverscrollLastPageDuringCurrentGesture
@property (readonly, nonatomic) UILabel *idleTextView; // ivar: _idleTextView
@property (readonly, nonatomic) _SBRootFolderLayoutWrapperView *searchPulldownWrapperView; // ivar: _searchPulldownWrapperView
@property (readonly, nonatomic) _SBRootFolderLayoutWrapperView *searchableTodayWrapperView;
@property (readonly, nonatomic) _SBRootFolderLayoutWrapperView *searchableTrailingCustomWrapperView; // ivar: _searchableTrailingCustomWrapperView
@property (readonly, nonatomic) _SBRootFolderLayoutWrapperView *sidebarWrapperView; // ivar: _sidebarWrapperView
@property (readonly, nonatomic) SBHMinusPageStepper *customPageAnimationStepper; // ivar: _customPageAnimationStepper
@property (readonly, nonatomic) SBDockIconListView *dockListView; // ivar: _dockListView
@property (readonly, nonatomic) NSObject<SBRootFolderViewLayoutManager> *layoutManager;
@property (retain, nonatomic) NSObject<SBRootFolderViewLayoutManager> *specialLayoutManager; // ivar: _specialLayoutManager
@property (retain, nonatomic) NSObject<SBRootFolderViewLayoutManager> *transitioningNewSpecialLayoutManager; // ivar: _transitioningNewSpecialLayoutManager
@property (retain, nonatomic) NSObject<SBRootFolderViewLayoutManager> *transitioningOldSpecialLayoutManager; // ivar: _transitioningOldSpecialLayoutManager
@property (readonly, nonatomic) NSUInteger folderPageManagementAllowedOrientations; // ivar: _folderPageManagementAllowedOrientations
@property (readonly, nonatomic) CGFloat todayViewPageScrollOffset;
@property (readonly, nonatomic) CGFloat trailingCustomViewPageScrollOffset;
@property (readonly, nonatomic) NSInteger todayViewPageIndex;
@property (readonly, nonatomic) NSInteger favoriteTodayViewPageIndex; // ivar: _favoriteTodayViewPageIndex
@property (readonly, nonatomic) NSInteger sidebarPageIndex;
@property (readonly, nonatomic) NSInteger trailingCustomViewPageIndex;
@property (readonly, nonatomic) BOOL hidesOffscreenCustomPageViews;
@property (readonly, nonatomic) BOOL shouldFadeDockOutDuringTransitionToTodayView;
@property (readonly, nonatomic) BOOL shouldFadePageControlOutDuringTransitionToTodayView;
@property (readonly, nonatomic) BOOL sidebarVisibilityGestureActive;
@property (weak, nonatomic) NSObject<SBRootFolderViewDelegate> *delegate;
@property (retain, nonatomic) SBRootFolder *folder;
@property (readonly, nonatomic) SBFParallaxSettings *parallaxSettings; // ivar: _parallaxSettings
@property (nonatomic) NSUInteger dockEdge; // ivar: _dockEdge
@property (readonly, nonatomic) CGFloat dockHeight;
@property (readonly, nonatomic) BOOL dockExternal; // ivar: _dockExternal
@property (readonly, nonatomic) BOOL dockPinnedForRotation; // ivar: _dockPinnedForRotation
@property (readonly, copy, nonatomic) NSString *dockIconLocation;
@property (readonly, nonatomic) CGRect enterEditingTouchRect;
@property (readonly, nonatomic) BOOL dockVisible;
@property (retain, nonatomic) SBSearchGesture *searchGesture; // ivar: _searchGesture
@property (readonly, nonatomic) CGFloat currentDockOffscreenFraction;
@property (readonly, nonatomic) SBDockView *dockView;
@property (nonatomic) BOOL allowsAutoscrollToTodayView; // ivar: _allowsAutoscrollToTodayView
@property (nonatomic) BOOL showsDoneButton; // ivar: _showsDoneButton
@property (nonatomic) BOOL showsAddWidgetButton; // ivar: _showsAddWidgetButton
@property (nonatomic) CGFloat titledButtonsAlpha; // ivar: _titledButtonsAlpha
@property (readonly, nonatomic) UIView *todayView;
@property (readonly, nonatomic) UIView *sidebarView;
@property (readonly, nonatomic) UIView *pullDownSearchView;
@property (readonly, nonatomic) UIView *trailingCustomView;
@property (readonly, nonatomic) BOOL onTodayPage;
@property (readonly, nonatomic) BOOL onTrailingCustomPage;
@property (nonatomic) BOOL todayViewPageHidden; // ivar: _todayViewPageHidden
@property (nonatomic) CGFloat sidebarVisibilityProgress; // ivar: _sidebarVisibilityProgress
@property (nonatomic) CGFloat sidebarPinned; // ivar: _sidebarPinned
@property (readonly, nonatomic) CGFloat effectiveSidebarVisibilityProgress;
@property (nonatomic) BOOL sidebarEffectivelyVisible; // ivar: _sidebarEffectivelyVisible
@property (nonatomic) BOOL todayViewBouncing; // ivar: _todayViewBouncing
@property (nonatomic) BOOL searchHidden;
@property (nonatomic) BOOL shiftsPullDownSearchForVisibility; // ivar: _shiftsPullDownSearchForVisibility
@property (readonly, nonatomic) UIView *todayViewWrapperView;
@property (readonly, nonatomic) SBSearchBackdropView *searchBackdropView;
@property (readonly, nonatomic) SBSearchBackdropView *trailingCustomBackdropView;
@property (readonly, nonatomic) UIView *trailingCustomSearchDimmingView;
@property (nonatomic) CGFloat todayViewVisibilityProgress; // ivar: _todayViewVisibilityProgress
@property (nonatomic) CGFloat trailingCustomViewVisibilityProgress; // ivar: _trailingCustomViewVisibilityProgress
@property (nonatomic) CGFloat pullDownSearchVisibilityProgress; // ivar: _pullDownSearchVisibilityProgress
@property (readonly, nonatomic) BOOL pageManagementUIVisible;
@property (nonatomic) BOOL occludedByOverlay; // ivar: _occludedByOverlay
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;


-(void)setIdleText:(id)arg0 ;
-(NSUInteger)_trailingCustomPageCount;
-(BOOL)shiftsPullDownSearchForVisibility;
-(CGFloat)_sidebarVisibilityProgressForPanGestureRecognizer:(id)arg0 presenting:(BOOL)arg1 ;
-(void)_overscrollScrollPanGestureRecognizerDidUpdate:(id)arg0 ;
-(BOOL)_shouldIgnoreOverscrollOnLastPageForOrientation:(NSInteger)arg0 ;
-(BOOL)_shouldHideSidebarView;
-(id)additionalIconListViews;
-(struct CGPoint )_scrollOffsetForPageAtIndex:(NSInteger)arg0 pageWidth:(CGFloat)arg1 ;
-(id)iconListViewAtIndex:(NSUInteger)arg0 ;
-(void)noteSidebarFinishedAnimating;
-(void)minimumHomeScreenScaleDidChange;
-(void)_updateEditingStateAnimated:(BOOL)arg0 ;
-(void)_willScrollToPageIndex:(NSInteger)arg0 animated:(BOOL)arg1 ;
-(void)_updateScrollingState:(BOOL)arg0 ;
-(void)scrollViewWillEndDragging:(id)arg0 withVelocity:(struct CGPoint )arg1 targetContentOffset:(struct CGPoint *)arg2 ;
-(void)settings:(id)arg0 changedValueForKey:(id)arg1 ;
-(void)updateIconListViews;
-(void)_doPageManagementEducation;
-(BOOL)_isSidebarCollapsed;
-(void)_setupStateDumper;
-(void)_cleanUpAfterScrolling;
-(BOOL)shouldFadeDockOutDuringTransitionToTodayView;
-(id)newDockBackgroundMaterialViewWithInitialWeighting:(CGFloat)arg0 ;
-(void)scrollViewWillBeginDragging:(id)arg0 ;
-(void)updateAccessibilityTintColors;
-(void)_updateIconListLegibilitySettings;
-(void)_currentPageIndexDidChangeFromPageIndex:(NSInteger)arg0 ;
-(void)layoutIconLists:(CGFloat)arg0 animationType:(NSInteger)arg1 forceRelayout:(BOOL)arg2 ;
-(void)enumerateScrollViewPageViewsUsingBlock:(id)arg0 ;
-(id)iconLocationForList:(id)arg0 ;
-(void)layoutDockViewWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(CGFloat)_pageWidth;
-(id)beginModifyingDockOffscreenFractionForReason:(id)arg0 ;
-(void)tearDownListViews;
-(void)_setupIdleTextPrivacyDisclosures;
-(BOOL)iconScrollView:(id)arg0 shouldSetContentOffset:(struct CGPoint *)arg1 animated:(BOOL)arg2 ;
-(BOOL)allowsFreeScrollingUntilScrollingEnds;
-(struct CGRect )_iconListFrameForPageRect:(struct CGRect )arg0 atIndex:(NSUInteger)arg1 ;
-(void)setOccluded:(BOOL)arg0 ;
-(void)scrollViewDidEndDecelerating:(id)arg0 ;
-(id)iconListViewAtPoint:(struct CGPoint )arg0 ;
-(void)layoutSearchableViewsWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(BOOL)isDockViewBorrowed;
-(void)returnScalingView;
-(id)rootFolderVisualConfiguration;
-(void)layoutSearchableViews;
-(void)prepareToTearDown;
-(void)pageControlDidReceiveButtonTap:(id)arg0 ;
-(BOOL)_shouldIgnoreOverscrollOnLastPageForCurrentOrientation;
-(BOOL)isPageControlBorrowed;
-(BOOL)_isSidebarEnabledForCurrentPage;
-(void)transitionToSize:(struct CGSize )arg0 withTransitionCoordinator:(id)arg1 ;
-(CGFloat)additionalScrollWidthToKeepVisibleInOneDirection;
-(struct CGRect )_scaledBoundsForMinimumHomeScreenScale;
-(void)_layoutSubviewsForSidebarWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(void)updateDockViewOrientation;
-(id)_createIconListViewForList:(id)arg0 ;
-(id)iconListViewForIconListModelIndex:(NSUInteger)arg0 ;
-(void)_checkSidebarVisibilityProgressAfterScroll;
-(void)cleanUpAfterTransition;
-(void)setContentAlpha:(CGFloat)arg0 ;
-(id)borrowDockViewForReason:(id)arg0 ;
-(void)setNeedsLayout;
-(void)_setupSearchBackdropViewIfNecessary;
-(void)_captureInitialSearchScrollTrackingState;
-(void)_layoutSubviews;
-(BOOL)allowsAutoscrollToTodayView;
-(void)_updateSidebarViewHidden;
-(void)resetIconListViews;
-(BOOL)_isSidebarEnabledForOrientation:(NSInteger)arg0 ;
-(void)iconScrollViewDidCancelTouchTracking:(id)arg0 ;
-(void)fadeContentForMinificationFraction:(CGFloat)arg0 ;
-(void)_cleanupAfterExtraScrollGesturesCompleted;
-(void)prepareForTransition;
-(void)_animateViewsForPullingToSearchWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(CGFloat)trailingCustomViewPageScrollOffsetUsingPageWidth:(CGFloat)arg0 ;
-(NSInteger)_pageCountForPageControl;
-(void)_setupTrailingCustomDimmingViewIfNecessary;
-(struct CGPoint )_scrollOffsetForContentAtPageIndex:(NSInteger)arg0 ;
-(CGFloat)todayViewPageScrollOffsetUsingPageWidth:(CGFloat)arg0 ;
-(BOOL)userAttemptedToOverscrollFirstPageDuringCurrentGesture;
-(NSUInteger)_leadingCustomPageCount;
-(BOOL)_isSidebarEnabledForPageIndex:(NSInteger)arg0 ;
-(struct UIEdgeInsets )_statusBarInsetsForDockEdge:(NSUInteger)arg0 dockOffscreenPercentage:(CGFloat)arg1 ;
-(id)hitTest:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(void)didMoveToSuperview;
-(CGFloat)sidebarViewPageScrollOffsetUsingPageWidth:(CGFloat)arg0 ;
-(id)iconListViewForExtraIndex:(NSUInteger)arg0 ;
-(BOOL)shouldPinScrollingToFirstOrLastPageScrollOffsetForProposedScrollOffset:(struct CGPoint *)arg0 ;
-(BOOL)iconScrollView:(id)arg0 shouldSetAutoscrollContentOffset:(struct CGPoint )arg1 ;
-(CGFloat)_minimumHomeScreenScale;
-(CGFloat)minimumHomeScreenScaleForDockView:(id)arg0 ;
-(void)_updateParallaxSettings;
-(void)getMetrics:(struct SBRootFolderViewMetrics *)arg0 dockEdge:(NSUInteger)arg1 ;
-(void)remoteBasebandLogCollectionStateDidChange:(BOOL)arg0 ;
-(void)scrollViewDidEndScrollingAnimation:(id)arg0 ;
-(id)initWithConfiguration:(id)arg0 ;
-(void)getMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(void)_animateViewsForScrollingToTodayView;
-(id)newHomeScreenButtonBackgroundView;
-(void)updateIconListIndexAndVisibility:(BOOL)arg0 ;
-(CGFloat)scrollableWidthForVisibleColumnRange;
-(void)_animateViewsForScrollingToTodayViewWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(id)newDockBackgroundView;
-(void)_setSidebarViewHidden:(BOOL)arg0 ;
-(void)_resetSearchScrollTrackingState;
-(BOOL)showsAddWidgetButton;
-(void)_updateIconListIndexSearchableAndTodayViewsWithLayout:(BOOL)arg0 ;
-(void)exitPageManagementUIWithCompletionHandler:(id)arg0 ;
-(void)_adjustTodayContentForEdgeBounce;
-(BOOL)shouldFadePageControlOutDuringTransitionToTodayView;
-(id)accessibilityTintColorForDockView:(id)arg0 ;
-(void)willMoveToWindow:(id)arg0 ;
-(BOOL)wasSidebarVisibleWhenScrollingBegan;
-(BOOL)_shouldIgnoreOverscrollOnFirstPageForOrientation:(NSInteger)arg0 ;
-(BOOL)_shouldIgnoreOverscrollOnFirstPageForCurrentOrientation;
-(void)doneButtonTriggered:(id)arg0 ;
-(void)noteSidebarIsAnimating;
-(void)setLegibilitySettings:(id)arg0 ;
-(void)_animateViewsForPullingToSearch;
-(id)makeTitledButtonOfClass:(Class)arg0 ;
-(void)_layoutSubviewsForTodayViewWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(BOOL)_isSidebarEnabledForIconListIndex:(NSUInteger)arg0 orientation:(NSInteger)arg1 ;
-(CGFloat)maxDockHeight;
-(BOOL)isOnSidebarPage;
-(struct UIEdgeInsets )statusBarInsetsForDockEdge:(NSUInteger)arg0 ;
-(void)layoutPageControlWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(BOOL)isPageIndexCustomAndRightmost:(NSInteger)arg0 ;
-(void)setOrientation:(NSInteger)arg0 ;
-(BOOL)userAttemptedToOverscrollLastPageDuringCurrentGesture;
-(CGFloat)isSidebarPinned;
-(void)elementBorrowedAssertionDidInvalidate:(id)arg0 ;
-(BOOL)_isSidebarEnabledForCurrentOrientation;
-(void)_updateDockBackgroundViewForOcclusionByOverlay;
-(void)clientDidChangeDockOffScreenFraction:(id)arg0 ;
-(void)_prepareSidebarViewForOrientationTransition;
-(void)_layoutSubviewsForPulldownSearch;
-(BOOL)hidesOffscreenCustomPageViews;
-(BOOL)showsDoneButton;
-(BOOL)shouldScrollPageControlDuringTransitionToTodayView;
-(void)setEditing:(BOOL)arg0 animated:(BOOL)arg1 ;
-(void)configurePageControlToAllowEnteringPageManagement:(BOOL)arg0 ;
-(void)_sidebarScrollPanGestureRecognizerDidUpdate:(id)arg0 ;
-(BOOL)_isSidebarEnabledForPageIndex:(NSInteger)arg0 orientation:(NSInteger)arg1 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)borrowPageControlForReason:(id)arg0 ;
-(CGFloat)internalDockPageControlVerticalMargin;
-(BOOL)shouldEndSidebarGestureWithSidebarVisibleWithCurrentProgress:(CGFloat)arg0 velocity:(CGFloat)arg1 ;
-(void)updateConfigurationOfPageControlToAllowEnteringPageManagement;
-(void)_updateDockOffscreenFractionWithMetrics:(struct SBRootFolderViewMetrics *)arg0 ;
-(CGFloat)_spotlightFirstIconRowOffset;
-(BOOL)shouldScrollDockDuringTransitionToTodayView;
-(void)_updateDockViewZOrdering;
-(void)enterPageManagementUIWithCompletionHandler:(id)arg0 ;
-(struct CGRect )_scrollViewFrameForDockEdge:(NSUInteger)arg0 ;
-(void)removeDockOffscreenFractionClient:(id)arg0 ;
-(id)rootListLayout;
-(void)scrollViewDidEndDragging:(id)arg0 willDecelerate:(BOOL)arg1 ;
-(void)dealloc;
-(void)_cleanUpAfterOverscrollScrollGestureEnded:(id)arg0 ;
-(BOOL)isModifyingDockOffscreenFraction;
-(void)_cleanupAfterSidebarSlideGestureCompleted:(id)arg0 ;
+(void)_editButtonLayoutFramesInBounds:(struct CGRect )arg0 forVisualConfiguration:(id)arg1 withTranslationOffset:(CGFloat)arg2 inRTL:(BOOL)arg3 doneButton:(id)arg4 addWidgetButton:(id)arg5 doneButtonFrame:(struct CGRect *)arg6 addWidgetButtonFrame:(struct CGRect *)arg7 ;
+(id)defaultIconLocation;


@end


#endif


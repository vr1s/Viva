// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBFOLDERVIEW_H
#define SBFOLDERVIEW_H


#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

@class SBFolderTitleTextField;
@class SBIconView;
@class SBIconListPageControl;
@class SBFolder;
@class SBIconListView;
@class SBIconListModel;
@class SBFolderIconImageCache;
@class SBHIconImageCache;
@class SBIconPageIndicatorImageSetCache;
@protocol SBIconListPageControlDelegate;
@protocol UITextFieldDelegate;
@protocol SBIconListLayoutDelegate;
@protocol SBIconScrollViewDelegate;
@protocol SBFolderObserver;
@protocol BSDescriptionProviding;
@protocol SBIconListViewDragDelegate;
@protocol SBFolderViewDelegate;
@protocol SBIconListLayoutProvider;
@protocol SBIconViewProviding;

#include "SBIconListView.h"

typedef struct SBVisibleColumnRange {
    NSUInteger iconListIndex;
    NSRange columnRange;
} SBVisibleColumnRange;


typedef struct SBFolderPredictedVisibleColumn {
    NSUInteger iconListIndex;
    SBIconListPredictedVisibleColumn predictedVisibleColumn;
} SBFolderPredictedVisibleColumn;

@interface SBFolderView : UIView <SBIconListPageControlDelegate, UITextFieldDelegate, SBIconListLayoutDelegate, SBIconScrollViewDelegate, SBFolderObserver, BSDescriptionProviding, SBIconListViewDragDelegate>

{
NSMutableArray *_iconListViews;
NSMutableSet *_scrollingDisabledReasons;
NSMutableSet *_pageControlDisabledReasons;
SBFolderTitleTextField *_titleTextField;
NSMutableSet *_scrollViewIsScrollingOverrides;
NSMutableSet *_parallaxDisabledReasons;
UIView *_scalingView;
SBVisibleColumnRange _visibleColumnRange;
SBFolderPredictedVisibleColumn _predictedVisibleColumn;
BOOL _wasScrolling;
NSMutableArray *_scrollFrames;
NSUInteger _scrollFrameCount;
CGFloat _scrollStartContentOffset;
NSInteger _scrollMinimumVisiblePageIndex;
NSInteger _scrollMaximumVisiblePageIndex;
NSUInteger _ignoreScrollingDidEndNotificationsCount;
NSMutableArray *_scrollCompletionBlocks;
NSMutableArray *_rotationCompletionBlocks;
CGFloat _headerHeight;
SBIconView *_cachedHiddenIconView;
}


@property (nonatomic) BOOL rotating; // ivar: _rotating
@property (nonatomic) BOOL hasEverBeenInAWindow; // ivar: _hasEverBeenInAWindow
@property (retain, nonatomic) UIPanGestureRecognizer *scrollingDisabledGestureRecognizer; // ivar: _scrollingDisabledGestureRecognizer
@property (readonly, nonatomic) UIView *scalingView;
@property (readonly, nonatomic) BOOL scalingViewBorrowed; // ivar: _isScalingViewBorrowed
@property (nonatomic) NSInteger orientation; // ivar: _orientation
@property (retain, nonatomic) SBIconListPageControl *pageControl; // ivar: _pageControl
@property (readonly, nonatomic) BOOL parallaxEnabled;
@property (readonly, nonatomic) CGFloat pageControlAreaHeight;
@property (readonly, nonatomic) NSInteger minimumPageIndex;
@property (readonly, nonatomic) NSInteger maximumPageIndex;
@property (readonly, nonatomic) NSInteger defaultPageIndex;
@property (readonly, nonatomic) NSInteger firstIconPageIndex;
@property (readonly, nonatomic) NSInteger lastIconPageIndex;
@property (readonly, nonatomic) NSUInteger pageCount;
@property (readonly, nonatomic) NSUInteger countOfAdditionalPagesToKeepVisibleInOneDirection;
@property (readonly, nonatomic) CGFloat additionalScrollWidthToKeepVisibleInOneDirection;
@property (readonly, nonatomic) SBFolderTitleTextField *titleTextField;
@property (readonly, nonatomic) NSInteger iconVisibilityHandling;
@property (readonly, nonatomic) BOOL updatesPredictedVisibleColumnWhileScrolling;
@property (readonly, nonatomic) CGFloat scrollableWidthForVisibleColumnRange;
@property (readonly, nonatomic) CGFloat minimumVisibleScrollOffset;
@property (readonly, nonatomic) CGFloat maximumVisibleScrollOffset;
@property (readonly, nonatomic) BOOL RTL;
@property (nonatomic) BOOL suppressesEditingStateForListViews; // ivar: _suppressesEditingStateForListViews
@property (nonatomic) BOOL automaticallyCreatesIconListViews; // ivar: _automaticallyCreatesIconListViews
@property (nonatomic) BOOL includesHiddenIconListPages; // ivar: _includesHiddenIconListPages
@property (weak, nonatomic) NSObject<SBFolderViewDelegate> *delegate; // ivar: _delegate
@property (retain, nonatomic) SBFolder *folder; // ivar: _folder
@property (readonly, nonatomic) NSObject<SBIconListLayoutProvider> *listLayoutProvider; // ivar: _listLayoutProvider
@property (readonly, nonatomic) BOOL editing; // ivar: _isEditing
@property (readonly, nonatomic) BOOL scrolling;
@property (readonly, nonatomic) NSUInteger allowedOrientations; // ivar: _allowedOrientations
@property (readonly, nonatomic) NSInteger currentPageIndex; // ivar: _currentPageIndex
@property (readonly, copy, nonatomic) NSArray *iconListViews;
@property (readonly, nonatomic) NSUInteger iconListViewCount;
@property (readonly, weak, nonatomic) NSObject<SBIconViewProviding> *iconViewProvider; // ivar: _iconViewProvider
@property (readonly, nonatomic) NSUInteger userInterfaceLayoutDirectionHandling; // ivar: _userInterfaceLayoutDirectionHandling
@property (readonly, nonatomic) NSInteger userInterfaceLayoutDirection;
@property (readonly, copy, nonatomic) NSString *iconLocation;
@property (readonly, nonatomic) UIView *headerView; // ivar: _headerView
@property (readonly, nonatomic) CGFloat headerHeight;
@property (readonly, nonatomic) UIScrollView *scrollView; // ivar: _scrollView
@property (readonly, nonatomic) SBIconListView *currentIconListView;
@property (readonly, nonatomic) SBIconListModel *currentIconListModel;
@property (nonatomic) BOOL pageControlHidden;
@property (nonatomic) CGFloat pageControlAlpha;
@property (nonatomic) BOOL occluded; // ivar: _occluded
@property (retain, nonatomic) SBFolderIconImageCache *folderIconImageCache; // ivar: _folderIconImageCache
@property (retain, nonatomic) SBHIconImageCache *iconImageCache; // ivar: _iconImageCache
@property (retain, nonatomic) SBIconPageIndicatorImageSetCache *iconPageIndicatorImageSetCache; // ivar: _iconPageIndicatorImageSetCache
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;


-(void)iconListView:(id)arg0 springLoadedInteractionForIconDragDidCompleteOnIconView:(id)arg1 ;
-(NSUInteger)_trailingCustomPageCount;
-(BOOL)textFieldShouldBeginEditing:(id)arg0 ;
-(void)iconListView:(id)arg0 iconDropSessionDidEnter:(id)arg1 ;
-(id)accessibilityLegibilitySettingsForRect:(struct CGRect )arg0 tintStyle:(NSUInteger)arg1 ;
-(NSInteger)_pageIndexForOffset:(CGFloat)arg0 ;
-(void)_updateIconListViewsWithCurrentPageIndex:(NSInteger)arg0 currentIconListModel:(id)arg1 ;
-(void)pageControl:(id)arg0 didMoveCurrentPageToPage:(NSInteger)arg1 withScrubbing:(BOOL)arg2 ;
-(struct SBHFloatRange )_scrollRangeForPageAtIndex:(NSInteger)arg0 pageWidth:(CGFloat)arg1 ;
-(id)additionalIconListViews;
-(struct CGPoint )_scrollOffsetForPageAtIndex:(NSInteger)arg0 pageWidth:(CGFloat)arg1 ;
-(void)noteUserIsInteractingWithIcons;
-(BOOL)_showsTitle;
-(id)iconListViewAtIndex:(NSUInteger)arg0 ;
-(void)_didRemoveIconListView:(id)arg0 ;
-(CGFloat)_offsetToCenterPageControlInSpaceForPageControl;
-(NSInteger)pageIndexForIconListModelIndex:(NSUInteger)arg0 ;
-(void)removeScrollViewIsScrollingOverrideReason:(id)arg0 ;
-(void)iconListView:(id)arg0 iconDropSessionDidExit:(id)arg1 ;
-(void)minimumHomeScreenScaleDidChange;
-(void)_addScrollingCompletionBlock:(id)arg0 ;
-(void)_updateEditingStateAnimated:(BOOL)arg0 ;
-(void)_willScrollToPageIndex:(NSInteger)arg0 animated:(BOOL)arg1 ;
-(void)scrollingDisabledGestureDidUpdate:(id)arg0 ;
-(NSInteger)pageIndexForIconListModel:(id)arg0 ;
-(void)textFieldDidEndEditing:(id)arg0 ;
-(BOOL)_isValidPageIndex:(NSInteger)arg0 ;
-(void)_updateScrollingState:(BOOL)arg0 ;
-(BOOL)_hasLeadingCustomPages;
-(void)willTransitionAnimated:(BOOL)arg0 withSettings:(id)arg1 ;
-(void)_setCurrentPageIndex:(NSInteger)arg0 deferringPageControlUpdate:(BOOL)arg1 ;
-(BOOL)iconListView:(id)arg0 canHandleIconDropSession:(id)arg1 ;
-(void)folder:(id)arg0 didRemoveLists:(id)arg1 atIndexes:(id)arg2 ;
-(void)scrollViewWillEndDragging:(id)arg0 withVelocity:(struct CGPoint )arg1 targetContentOffset:(struct CGPoint *)arg2 ;
-(struct CGSize )_iconListViewSize;
-(id)iconVisibilityDescription;
-(void)updateIconListViews;
-(void)_updateIconListFrames;
-(void)animateScrollToDefaultPageWithCompletionHandler:(id)arg0 ;
-(struct CGSize )scrollView:(id)arg0 contentSizeForZoomScale:(CGFloat)arg1 withProposedSize:(struct CGSize )arg2 ;
-(struct CGPoint )_scrollOffsetForPageAtIndex:(NSInteger)arg0 ;
-(void)scrollViewWillBeginDragging:(id)arg0 ;
-(void)_orientationDidChange:(NSInteger)arg0 ;
-(void)updateAccessibilityTintColors;
-(void)_updateIconListLegibilitySettings;
-(void)_currentPageIndexDidChangeFromPageIndex:(NSInteger)arg0 ;
-(void)_setCurrentPageIndex:(NSInteger)arg0 ;
-(void)_addIconListView:(id)arg0 atEnd:(BOOL)arg1 ;
-(BOOL)_hasTrailingCustomPages;
-(id)iconListViewForTouch:(id)arg0 ;
-(void)layoutIconLists:(CGFloat)arg0 animationType:(NSInteger)arg1 forceRelayout:(BOOL)arg2 ;
-(void)enumerateScrollViewPageViewsUsingBlock:(id)arg0 ;
-(id)iconLocationForList:(id)arg0 ;
-(void)folder:(id)arg0 didMoveList:(id)arg1 fromIndex:(NSUInteger)arg2 toIndex:(NSUInteger)arg3 ;
-(CGFloat)_pageWidth;
-(void)prepareToOpen;
-(BOOL)canChangeCurrentPageIndexToIndex:(NSUInteger)arg0 ;
-(void)scrollViewDidEndScrolling:(id)arg0 ;
-(void)tearDownListViews;
-(BOOL)doesPageContainIconListView:(NSInteger)arg0 ;
-(BOOL)iconScrollView:(id)arg0 shouldSetContentOffset:(struct CGPoint *)arg1 animated:(BOOL)arg2 ;
-(void)didAddSubview:(id)arg0 ;
-(id)iconListView:(id)arg0 iconDropSessionDidUpdate:(id)arg1 ;
-(id)borrowScalingView;
-(void)_unignoreScrollingDidEndNotifications;
-(struct CGRect )_iconListFrameForPageRect:(struct CGRect )arg0 atIndex:(NSUInteger)arg1 ;
-(CGFloat)currentScrollOffset;
-(void)scrollViewDidEndDecelerating:(id)arg0 ;
-(id)iconListView:(id)arg0 customSpringAnimationBehaviorForDroppingItem:(id)arg1 ;
-(id)iconListViewAtPoint:(struct CGPoint )arg0 ;
-(BOOL)_shouldManageScrolledHiddenClippedIconView;
-(void)_precacheIconImages;
-(void)_updatePageControlToIndex:(NSInteger)arg0 ;
-(void)_updateIconListContainment:(id)arg0 atIndex:(NSUInteger)arg1 ;
-(void)_noteFolderListsDidChange:(NSUInteger)arg0 ;
-(struct SBHFloatRange )_scrollRangeForPageAtIndex:(NSInteger)arg0 ;
-(void)_setScrollingDisabled:(BOOL)arg0 forReason:(id)arg1 ;
-(void)returnScalingView;
-(id)iconListView:(id)arg0 previewForDroppingIconDragItem:(id)arg1 proposedPreview:(id)arg2 ;
-(id)_findHiddenIconView;
-(id)accessibilityTintColorForRect:(struct CGRect )arg0 tintStyle:(NSUInteger)arg1 ;
-(void)pageControlDidReceiveButtonTap:(id)arg0 ;
-(BOOL)isVisibleColumnRangeValid:(struct SBVisibleColumnRange )arg0 ;
-(BOOL)locationCountsAsInsideFolder:(struct CGPoint )arg0 ;
-(void)iconListView:(id)arg0 iconDragItem:(id)arg1 willAnimateDropWithAnimator:(id)arg2 ;
-(void)transitionToSize:(struct CGSize )arg0 withTransitionCoordinator:(id)arg1 ;
-(id)_interactionTintColor;
-(id)_createIconListViewForList:(id)arg0 ;
-(void)_ignoreScrollingDidEndNotifications;
-(void)clearVisibleColumnRange;
-(id)allIconListViews;
-(void)_removeIconListView:(id)arg0 purge:(BOOL)arg1 ;
-(id)iconListViewForIconListModelIndex:(NSUInteger)arg0 ;
-(BOOL)includesHiddenIconListPages;
-(void)_checkIfScrollStateChanged;
-(void)_updateIconListViews:(NSInteger)arg0 ;
-(void)_updateIconListViewsWithCurrentIconListModel:(id)arg0 ;
-(void)cleanUpAfterTransition;
-(void)_updatePageControlNumberOfPages;
-(id)firstIconListView;
-(NSUInteger)typeForPage:(NSInteger)arg0 ;
-(BOOL)suppressesEditingStateForListViews;
-(void)setContentAlpha:(CGFloat)arg0 ;
-(void)setNeedsLayout;
-(void)_updateScalingViewFrame;
-(NSUInteger)iconListViewIndexForIconListModelIndex:(NSUInteger)arg0 ;
-(BOOL)_useParallaxOnPageControl;
-(void)folderWillChange:(id)arg0 ;
-(void)_layoutSubviews;
-(void)validateVisibleColumnRange;
-(void)resetIconListViews;
-(void)_configureIconListView:(id)arg0 ;
-(void)_enableUserInteractionAfterSignificantAnimation;
-(void)_setScrollViewContentOffset:(struct CGPoint )arg0 animated:(BOOL)arg1 ;
-(void)updateVisibleColumnRange;
-(NSInteger)pageIndexForIconListViewIndex:(NSUInteger)arg0 ;
-(BOOL)updatesPredictedVisibleColumnWhileScrolling;
-(void)updateIconListIndexAndVisibility;
-(void)_updatePageControlCurrentPage;
-(id)iconListViewWithList:(id)arg0 ;
-(void)_markListViewsAsPurged;
-(void)_resetIconListViews;
-(void)_updateHiddenIconViewForScrolling:(BOOL)arg0 ;
-(struct CGRect )_frameForIconListAtIndex:(NSUInteger)arg0 ;
-(struct SBHFloatRange )_scrollRangeForContentAtPageIndex:(NSInteger)arg0 pageWidth:(CGFloat)arg1 ;
-(void)didTransitionAnimated:(BOOL)arg0 ;
-(void)_updateTitleLegibilitySettings;
-(void)iconScrollViewDidCancelTouchTracking:(id)arg0 ;
-(BOOL)isPageTypeIcon:(NSInteger)arg0 ;
-(BOOL)_shouldIgnoreScrollingDidEndNotifications;
-(void)addScrollViewIsScrollingOverrideReason:(id)arg0 ;
-(void)fadeContentForMinificationFraction:(CGFloat)arg0 ;
-(void)iconScrollViewWillCancelTouchTracking:(id)arg0 ;
-(void)iconListView:(id)arg0 willUseIconView:(id)arg1 forDroppingIconDragItem:(id)arg2 ;
-(BOOL)hasEverBeenInAWindow;
-(NSUInteger)iconPageCount;
-(void)_removeIconListView:(id)arg0 ;
-(void)prepareForTransition;
-(BOOL)textFieldShouldReturn:(id)arg0 ;
-(void)fadeContentForMagnificationFraction:(CGFloat)arg0 ;
-(struct CGPoint )_scrollOffsetForContentAtPageIndex:(NSInteger)arg0 ;
-(id)iconListViewAtScrollPoint:(struct CGPoint )arg0 ;
-(BOOL)animatesRotationForAllVisibleIconListViews;
-(void)enumerateIconListViewsWithOptions:(NSUInteger)arg0 usingBlock:(id)arg1 ;
-(void)updateVisibleColumnRangeWithTotalLists:(NSUInteger)arg0 columnsPerList:(NSUInteger)arg1 iconVisibilityHandling:(NSInteger)arg2 ;
-(id)iconListViewForPageIndex:(NSInteger)arg0 ;
-(void)_didAddIconListView:(id)arg0 ;
-(struct SBVisibleColumnRange )visibleColumnRangeWithTotalLists:(NSUInteger)arg0 columnsPerList:(NSUInteger)arg1 iconVisibilityHandling:(NSInteger)arg2 predictedVisibleColumn:(struct SBFolderPredictedVisibleColumn *)arg3 ;
-(void)_handleClippingScrollViewDidScroll:(id)arg0 ;
-(BOOL)hasIconPages;
-(void)iconListView:(id)arg0 iconDropSession:(id)arg1 didPauseAtLocation:(struct CGPoint )arg2 ;
-(NSUInteger)iconListModelIndexForPageIndex:(NSInteger)arg0 ;
-(id)iconListViewDisplayingIconView:(id)arg0 ;
-(void)_backgroundContrastDidChange:(id)arg0 ;
-(NSUInteger)_leadingCustomPageCount;
-(id)lastIconListView;
-(BOOL)setCurrentPageIndex:(NSInteger)arg0 animated:(BOOL)arg1 completion:(id)arg2 ;
-(BOOL)iconListView:(id)arg0 shouldAllowSpringLoadedInteractionForIconDropSession:(id)arg1 onIconView:(id)arg2 ;
-(BOOL)setCurrentPageIndex:(NSInteger)arg0 animated:(BOOL)arg1 ;
-(unsigned int)scrollingDirection;
-(id)hitTest:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(CGFloat)_titleFontSize;
-(void)didMoveToSuperview;
-(id)_newPageControl;
-(void)folder:(id)arg0 didAddList:(id)arg1 ;
-(void)_addIconListView:(id)arg0 ;
-(void)_disableUserInteractionBeforeSignificantAnimation;
-(BOOL)iconScrollView:(id)arg0 shouldSetAutoscrollContentOffset:(struct CGPoint )arg1 ;
-(void)textFieldDidBeginEditing:(id)arg0 ;
-(NSInteger)closestIconPageIndexForPageIndex:(NSInteger)arg0 ;
-(struct CGRect )_frameForScalingView;
-(CGFloat)_pageSpacing;
-(void)_updateParallaxSettings;
-(id)succinctDescriptionBuilder;
-(BOOL)_isValidIconListViewIndex:(NSInteger)arg0 ;
-(NSUInteger)indexOfIconListView:(id)arg0 ;
-(BOOL)automaticallyCreatesIconListViews;
-(NSUInteger)iconListViewIndexForPageIndex:(NSInteger)arg0 ;
-(void)scrollViewDidEndScrollingAnimation:(id)arg0 ;
-(void)_updateScrollingIfNeeded;
-(void)resetContentOffsetToCurrentPageAnimated:(BOOL)arg0 ;
-(id)initWithConfiguration:(id)arg0 ;
-(id)iconListView:(id)arg0 animatorForRemovingIcons:(id)arg1 proposedAnimator:(id)arg2 ;
-(Class)listViewClass;
-(void)enumerateIconListViewsUsingBlock:(id)arg0 ;
-(void)updateIconListIndexAndVisibility:(BOOL)arg0 ;
-(id)iconListViewForDrag:(id)arg0 ;
-(void)_setParallaxDisabled:(BOOL)arg0 forReason:(id)arg1 ;
-(void)willMoveToWindow:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)succinctDescription;
-(void)traitCollectionDidChange:(id)arg0 ;
-(void)layoutSubviews;
-(id)_legibilitySettingsWithPrimaryColor:(id)arg0 ;
-(void)setEditing:(BOOL)arg0 animated:(BOOL)arg1 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)didMoveToWindow;
-(void)scrollViewDidEndDragging:(id)arg0 willDecelerate:(BOOL)arg1 ;
-(void)dealloc;
-(void)scrollViewDidScroll:(id)arg0 ;
+(Class)defaultIconListViewClass;
+(id)defaultIconLocation;


@end


#endif


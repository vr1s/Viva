// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBICONLISTVIEW_H
#define SBICONLISTVIEW_H


#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#include "SBIconListModel.h"

@class SBIconListViewDraggingDestinationDelegate;
@class SBIconListViewLayoutMetrics;
@class SBHIconSettings;
@class SBHIconEditingSettings;
@class SBIconListViewIconLocationTransitionHandler;
@class SBFolderIconImageCache;
@class SBHIconImageCache;
@protocol SBIconObserver;
@protocol PTSettingsKeyObserver;
@protocol SBIconListModelObserver;
@protocol BSDescriptionProviding;
@protocol SBIconListLayoutProvider;
@protocol SBIconListLayout;
@protocol SBIconListLayoutDelegate;
@protocol SBIconViewProviding;
@protocol SBIconListViewDragDelegate;

typedef struct SBIconListPredictedVisibleColumn {
    NSUInteger column;
    CGFloat confidence;
} SBIconListPredictedVisibleColumn;

typedef struct SBIconListPredictedVisibleRow {
    NSUInteger row;
    CGFloat confidence;
} SBIconListPredictedVisibleRow;

@interface SBIconListView : UIView <SBIconObserver, PTSettingsKeyObserver, SBIconListModelObserver, BSDescriptionProviding>

{
    NSMutableArray *_removedIcons;
    BOOL _needsLayout;
    BOOL _inLayout;
    BOOL _rotating;
    BOOL _ignoreNextWindowChange;
    BOOL _performingSpecialIconAnimations;
    NSMapTable *_iconViews;
    NSMapTable *_specialIconAnimations;
    NSMapTable *_pausedLayoutForIconViews;
    NSHashTable *_iconVisibilityAssertions;
    NSMutableDictionary *_groupNamesToCaptureOnlyBackgroundViews;
    NSMapTable *_iconsToCaptureOnlyBackgroundAssertions;
    SBIconListViewDraggingDestinationDelegate *_draggingDelegate;
    // *__CFRunLoopObserver _layoutRunLoopObserver;
    NSHashTable *_layoutObservers;
    SBIconListViewLayoutMetrics *_cachedMetrics;
    CGFloat _desiredLaserPaddingX;
    CGFloat _desiredLaserPaddingY;
    BOOL _laserPadUsesAllAvailableSpace;
    SBHIconSettings *_iconSettings;
    SBHIconEditingSettings *_iconEditingSettings;
}


@property (retain, nonatomic) SBIconListViewIconLocationTransitionHandler *currentIconLocationTransitionHandler; // ivar: _currentIconLocationTransitionHandler
@property (readonly, nonatomic) Class baseIconViewClass;
@property (readonly, nonatomic) NSUInteger iconRowsForCurrentOrientation;
@property (readonly, nonatomic) NSUInteger iconColumnsForCurrentOrientation;
@property (readonly, nonatomic) NSUInteger iconsInRowForSpacingCalculation;
@property (readonly, nonatomic) NSUInteger iconRowsForSpacingCalculation;
@property (readonly, nonatomic) NSUInteger maximumIconCount;
@property (retain, nonatomic) NSObject<SBIconListLayoutProvider> *layoutProvider; // ivar: _layoutProvider
@property (readonly, nonatomic) NSObject<SBIconListLayout> *layout;
@property (nonatomic) NSInteger orientation; // ivar: _orientation
@property (readonly, nonatomic) BOOL adaptsOrientationToTraitCollection;
@property (readonly, nonatomic) BOOL vertical;
@property (nonatomic) BOOL editing; // ivar: _editing
@property (nonatomic) BOOL purged; // ivar: _purged
@property (nonatomic) BOOL layoutReversed; // ivar: _layoutReversed
@property (nonatomic) NSUInteger automaticallyReversedLayoutOrientations; // ivar: _automaticallyReversedLayoutOrientations
@property (nonatomic) BOOL pausesIconsForScrolling; // ivar: _pausesIconsForScrolling
@property (nonatomic) BOOL adjustsColumnPositionsForFullScreenWidth; // ivar: _adjustsColumnPositionsForFullScreenWidth
@property (nonatomic) NSUInteger userInterfaceLayoutDirectionHandling; // ivar: _userInterfaceLayoutDirectionHandling
@property (readonly, nonatomic) NSInteger userInterfaceLayoutDirection;
@property (nonatomic) NSUInteger iconViewConfigurationOptions; // ivar: _iconViewConfigurationOptions
@property (weak, nonatomic) NSObject<SBIconListLayoutDelegate> *layoutDelegate; // ivar: _layoutDelegate
@property (retain, nonatomic) SBIconListModel *model; // ivar: _model
@property (weak, nonatomic) NSObject<SBIconViewProviding> *iconViewProvider; // ivar: _iconViewProvider
@property (readonly, copy, nonatomic) NSArray *icons;
@property (readonly, copy, nonatomic) NSArray *visibleIcons;
@property (readonly, nonatomic) BOOL empty;
@property (readonly, nonatomic) BOOL full;
@property (copy, nonatomic) NSString *iconLocation; // ivar: _iconLocation
@property (readonly, nonatomic) CGSize alignmentIconSize;
@property (nonatomic) BOOL automaticallyAdjustsLayoutMetricsToFit; // ivar: _automaticallyAdjustsLayoutMetricsToFit
@property (readonly, nonatomic) CGFloat horizontalIconPadding;
@property (readonly, nonatomic) CGFloat verticalIconPadding;
@property (nonatomic) UIEdgeInsets additionalLayoutInsets; // ivar: _additionalLayoutInsets
@property (readonly, nonatomic) CGRect iconLayoutRect;
@property (nonatomic) CGSize iconSpacing; // ivar: _iconSpacing
@property (readonly, nonatomic) CGSize effectiveIconSpacing;
@property (nonatomic) BOOL boundsSizeTracksContentSize; // ivar: _boundsSizeTracksContentSize
@property (readonly, nonatomic) SBIconListViewLayoutMetrics *layoutMetrics;
@property (readonly, nonatomic) NSUInteger gridCellInfoOptions;
@property (nonatomic) NSRange visibleColumnRange; // ivar: _visibleColumnRange
@property (nonatomic) NSRange visibleRowRange; // ivar: _visibleRowRange
@property (nonatomic) SBIconListPredictedVisibleColumn predictedVisibleColumn; // ivar: _predictedVisibleColumn
@property (nonatomic) SBIconListPredictedVisibleRow predictedVisibleRow; // ivar: _predictedVisibleRow
@property (readonly, nonatomic) BOOL iconsNeedLayout;
@property (nonatomic) CGFloat iconContentScale; // ivar: _iconContentScale
@property (weak, nonatomic) NSObject<SBIconListViewDragDelegate> *dragDelegate; // ivar: _dragDelegate
@property (nonatomic) BOOL wantsFastIconReordering; // ivar: _wantsFastIconReordering
@property (nonatomic) BOOL occluded; // ivar: _occluded
@property (retain, nonatomic) SBFolderIconImageCache *folderIconImageCache; // ivar: _folderIconImageCache
@property (retain, nonatomic) SBHIconImageCache *iconImageCache; // ivar: _iconImageCache
@property (readonly, nonatomic) BOOL transitioningIconLocation;
@property (nonatomic) BOOL alignsIconsOnPixelBoundaries; // ivar: _alignsIconsOnPixelBoundaries
@property (nonatomic) NSInteger layoutInsetsMode; // ivar: _layoutInsetsMode
@property (readonly, nonatomic) NSUInteger numberOfDisplayedIconViews;
@property (nonatomic) BOOL visiblySettled; // ivar: _visiblySettled
@property (readonly, nonatomic) NSUInteger iconViewUserVisibilityStatus;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;


-(BOOL)isLayoutPausedForIconView:(id)arg0 ;
-(NSUInteger)rowAtPoint:(struct CGPoint )arg0 ;
-(id)iconVisibilityInfoForRect:(struct CGRect )arg0 normalized:(BOOL)arg1 ;
-(void)layoutIconsNow;
-(void)removeAllIconViews;
-(struct CGRect )rectForIconCoordinate:(struct SBIconCoordinate )arg0 ;
-(void)addDragObserver:(id)arg0 forDropSession:(id)arg1 ;
-(NSUInteger)indexForCoordinate:(struct SBIconCoordinate )arg0 forOrientation:(NSInteger)arg1 ;
-(struct CGPoint )centerForIconCoordinate:(struct SBIconCoordinate )arg0 ;
-(NSInteger)dragPlacementForMovingIconOfGridSizeClass:(NSUInteger)arg0 toPoint:(struct CGPoint )arg1 icon:(id)arg2 options:(NSUInteger)arg3 ;
-(void)settings:(id)arg0 changedValueForKey:(id)arg1 ;
-(struct CGSize )iconImageSize;
-(id)iconAtCoordinate:(struct SBIconCoordinate )arg0 metrics:(id)arg1 ;
-(NSUInteger)iconGridSizeClassForIconGridSize:(struct SBHIconGridSize )arg0 ;
-(CGFloat)horizontalBumpForColumn:(NSUInteger)arg0 metrics:(id)arg1 ;
-(void)fadeInIcon:(id)arg0 ;
-(struct CGPoint )centerForIconAtIndex:(NSUInteger)arg0 metrics:(id)arg1 ;
-(void)iconList:(id)arg0 didMoveIcon:(id)arg1 ;
-(void)ignoreNextWindowChange;
-(id)requireAllIconsShownForReason:(id)arg0 ;
-(BOOL)wantsFastIconReordering;
-(void)didAddSubview:(id)arg0 ;
-(void)addIconViewConfigurationOption:(NSUInteger)arg0 ;
-(void)enumerateIconsUsingBlock:(id)arg0 ;
-(NSUInteger)bestGridCellIndexForInsertingIcon:(id)arg0 atCoordinate:(struct SBIconCoordinate )arg1 ;
-(struct CGSize )intrinsicContentSize;
-(struct CGPoint )originForIcon:(id)arg0 ;
-(struct UIEdgeInsets )layoutInsetsForOrientation:(NSInteger)arg0 ;
-(NSUInteger)indexForCoordinate:(struct SBIconCoordinate )arg0 forOrientation:(NSInteger)arg1 metrics:(id)arg2 ;
-(void)setIconsNeedLayout;
-(void)setFrame:(struct CGRect )arg0 ;
-(BOOL)containsIcon:(id)arg0 ;
-(BOOL)isRTL;
-(struct CGPoint )_overrideOriginForIconAtRowIndex:(NSUInteger)arg0 columnIndex:(NSUInteger)arg1 gridSize:(struct SBHIconGridSize )arg2 metrics:(id)arg3 ;
-(struct CGPoint )centerForIconCoordinate:(struct SBIconCoordinate )arg0 metrics:(id)arg1 ;
-(struct CGPoint )originForIconAtCoordinate:(struct SBIconCoordinate )arg0 metrics:(id)arg1 ;
-(void)setIconsLabelAlpha:(CGFloat)arg0 ;
-(void)_cleanupIconViewsForRemovedIcons:(id)arg0 ;
-(BOOL)isDock;
-(void)performDefaultAnimatedLayoutUpdateForIconView:(id)arg0 withParameters:(struct SBIconListLayoutAnimationParameters )arg1 ;
-(struct SBHIconGridRange )iconGridRangeForIndex:(NSUInteger)arg0 metrics:(id)arg1 ;
-(void)_updateEditingStateForIcons:(id)arg0 animated:(BOOL)arg1 ;
-(void)enumerateIconViewsUsingBlock:(id)arg0 ;
-(NSUInteger)rowAtPoint:(struct CGPoint )arg0 metrics:(id)arg1 ;
-(struct CGPoint )originForIconAtCoordinate:(struct SBIconCoordinate )arg0 metrics:(id)arg1 options:(NSUInteger)arg2 ;
-(void)_teardownLayoutRunloopObserverIfNeeded;
-(void)_updateVisibleIconViewsWithOldVisibleGridCellIndexes:(id)arg0 metrics:(id)arg1 ;
-(void)_addIconViewsForIcons:(id)arg0 metrics:(id)arg1 ;
-(NSUInteger)iconIndexForGridCellIndex:(NSUInteger)arg0 metrics:(id)arg1 ;
-(void)configureIconView:(id)arg0 forIcon:(id)arg1 ;
-(void)performSpecialIconAnimationsWithCompletionHandler:(id)arg0 ;
-(struct CGSize )alignmentIconViewSize;
-(struct CGPoint )centerForIcon:(id)arg0 metrics:(id)arg1 ;
-(BOOL)boundsSizeTracksContentSize;
-(void)pauseLayout:(BOOL)arg0 forIconView:(id)arg1 withReason:(id)arg2 ;
-(void)_captureOnlyBackgroundAssertionDidInvalidate:(id)arg0 ;
-(void)popIconView:(id)arg0 ;
-(void)removeIconViewConfigurationOption:(NSUInteger)arg0 ;
-(void)fadeInIconView:(id)arg0 ;
-(void)getLayoutMetricsParameters:(struct SBIconListLayoutMetricsParameters *)arg0 orientation:(NSInteger)arg1 ;
-(BOOL)pausesIconsForScrolling;
-(void)enumerateVisibleIconsUsingBlock:(id)arg0 ;
-(BOOL)alignsIconsOnPixelBoundaries;
-(void)setBounds:(struct CGRect )arg0 ;
-(NSUInteger)indexOfIcon:(id)arg0 ;
-(id)succinctDescriptionBuilder;
-(id)layoutMetricsForOrientation:(NSInteger)arg0 ;
-(void)removeLayoutObserver:(id)arg0 ;
-(id)visibleGridCellIndexes;
-(void)iconLocationTransitionHandler:(id)arg0 completeTransition:(BOOL)arg1 ;
-(id)beginTransitionToIconLocation:(id)arg0 reason:(id)arg1 ;
-(struct CGSize )iconImageSizeForGridSizeClass:(NSUInteger)arg0 ;
-(CGFloat)continuousCornerRadiusForGridSizeClass:(NSUInteger)arg0 ;
-(BOOL)adjustsColumnPositionsForFullScreenWidth;
-(void)iconList:(id)arg0 didAddIcon:(id)arg1 ;
-(struct _NSRange )_allIconsVisibleColumnOrRowRange;
-(BOOL)isDisplayingIconView:(id)arg0 ;
-(void)setAlphaForAllIcons:(CGFloat)arg0 ;
-(void)iconLocationTransitionHandler:(id)arg0 setProgress:(CGFloat)arg1 ;
-(void)markIcon:(id)arg0 asNeedingAnimation:(NSInteger)arg1 ;
-(id)iconViewForCoordinate:(struct SBIconCoordinate )arg0 ;
-(struct CGSize )sizeThatFits:(struct CGSize )arg0 ;
-(void)performSpecialIconAnimation:(NSInteger)arg0 icon:(id)arg1 completionHandler:(id)arg2 ;
-(id)displayedIconViewForIcon:(id)arg0 ;
-(BOOL)_iconIsGapAdjacentAtIndex:(NSUInteger)arg0 ;
-(NSUInteger)gridCellIndexForCoordinate:(struct SBIconCoordinate )arg0 metrics:(id)arg1 ;
-(id)tintColor;
-(void)_insertCaptureOnlyBackgroundViewForInsertingIconViewIfNecessary:(id)arg0 ;
-(BOOL)adaptsOrientationToTraitCollection;
-(void)removeAllIconAnimations;
-(NSUInteger)rowForIcon:(id)arg0 ;
-(struct SBIconCoordinate )coordinateForIcon:(id)arg0 ;
-(id)iconAtGridCellIndex:(NSUInteger)arg0 metrics:(id)arg1 ;
-(struct SBIconCoordinate )iconCoordinateForGridCellIndex:(NSUInteger)arg0 metrics:(id)arg1 ;
-(struct SBHIconGridSize )iconGridSizeForClass:(NSUInteger)arg0 ;
-(id)makeIconView;
-(void)willMoveToWindow:(id)arg0 ;
-(NSUInteger)bestIndexForInsertingIcon:(id)arg0 atCoordinate:(struct SBIconCoordinate )arg1 ;
-(void)iconGridSizeClassDidChange:(id)arg0 ;
-(struct CGRect )rectForIconAtIndex:(NSUInteger)arg0 ;
-(void)layoutIconsIfNeeded:(CGFloat)arg0 animationType:(NSInteger)arg1 options:(NSUInteger)arg2 ;
-(struct CGPoint )centerForIcon:(id)arg0 ;
-(BOOL)isShowingAllIcons;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(struct UIEdgeInsets )cursorHitTestingInsetsForIconSpacing:(struct CGSize )arg0 ;
-(void)layoutAndCreateIcon:(id)arg0 ;
-(id)gridCellInfo;
-(id)succinctDescription;
-(BOOL)shouldReparentView:(id)arg0 ;
-(void)iconList:(id)arg0 didReplaceIcon:(id)arg1 withIcon:(id)arg2 ;
-(struct CGRect )rectForIcon:(id)arg0 ;
-(void)willRotateWithTransitionCoordinator:(id)arg0 ;
-(void)didAddIconView:(id)arg0 ;
-(void)_addIconViewsForIcons:(id)arg0 ;
-(id)removedIcons;
-(void)removeShowAllIconsAssertion:(id)arg0 ;
-(struct SBIconCoordinate )iconCoordinateForIndex:(NSUInteger)arg0 forOrientation:(NSInteger)arg1 ;
-(void)_setupLayoutRunLoopObserver;
-(struct CGPoint )centerForIconAtIndex:(NSUInteger)arg0 ;
-(struct SBIconCoordinate )coordinateForIconAtIndex:(NSUInteger)arg0 ;
-(struct CGRect )rectForIconCoordinate:(struct SBIconCoordinate )arg0 metrics:(id)arg1 ;
-(void)performDefaultAnimatedRemovalForIconViews:(id)arg0 completionHandler:(id)arg1 ;
-(struct SBIconCoordinate )iconCoordinateForIndex:(NSUInteger)arg0 metrics:(id)arg1 ;
-(id)iconViewForIcon:(id)arg0 ;
-(struct CGPoint )originForIconAtCoordinate:(struct SBIconCoordinate )arg0 ;
-(BOOL)automaticallyAdjustsLayoutMetricsToFit;
-(struct SBHIconGridRange )gridRangeForIconAtIndex:(NSUInteger)arg0 ;
-(void)updateReversedLayoutBasedOnOrientation;
-(void)addLayoutObserver:(id)arg0 ;
-(void)removeIconView:(id)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)getLayoutMetricsParameters:(struct SBIconListLayoutMetricsParameters *)arg0 ;
-(struct SBIconImageInfo )iconImageInfoForGridSizeClass:(NSUInteger)arg0 ;
-(void)_applyIconPaddingSettings;
-(id)initWithModel:(id)arg0 layoutProvider:(id)arg1 iconLocation:(id)arg2 orientation:(NSInteger)arg3 iconViewProvider:(id)arg4 ;
-(id)visibleGridCellIndexesWithMetrics:(id)arg0 ;
//-(BOOL)getIconStartGridCellIndex:(*NSUInteger)arg0 gridSize:(struct SBHIconGridSize *)arg1 forGridCellIndex:
//        (NSUInteger)arg2 metrics:(id)arg3 ;
-(void)hideAllIcons;
-(void)_removeCaptureOnlyBackgroundViewForRemovedIconIfNecessary:(id)arg0 ;
-(struct CGPoint )originForIconAtIndex:(NSUInteger)arg0 ;
-(void)showAllIcons;
-(BOOL)_allowsFocusToLeaveViaHeading:(NSUInteger)arg0 ;
-(struct CGPoint )fractionalCoordinateAtPoint:(struct CGPoint )arg0 ;
-(void)iconList:(id)arg0 didRemoveIcon:(id)arg1 ;
-(void)dealloc;
-(void)_removeIconViewsForIcons:(id)arg0 ;
-(NSUInteger)iconIndexForCoordinate:(struct SBIconCoordinate )arg0 metrics:(id)arg1 ;
-(id)dequeueReusableIconView;
+(NSInteger)rotationAnchor;
+(struct CGRect )defaultFrameForOrientation:(NSInteger)arg0 ;
+(NSUInteger)defaultIconViewConfigurationOptions;
+(id)clusterAnimator;
+(id)multiStageAnimator;
+(id)dominoAnimator;
+(id)builtInAnimatorForAnimationType:(NSInteger)arg0 ;
+(id)defaultAnimator;
+(id)layoutMetricsForParameters:(struct SBIconListLayoutMetricsParameters *)arg0 listModel:(id)arg1 ;


@end


#endif


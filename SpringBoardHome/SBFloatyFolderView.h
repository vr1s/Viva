//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <SpringBoardHome/SBFolderView.h>

#import <SpringBoardHome/PTSettingsKeyObserver-Protocol.h>
#import <SpringBoardHome/SBFolderBackgroundViewDelegate-Protocol.h>

@class NSMapTable, NSMutableArray, SBFloatyFolderBackgroundClipView, SBHFolderSettings, SBIconView, UILongPressGestureRecognizer, UIPinchGestureRecognizer, UITapGestureRecognizer;

@interface SBFloatyFolderView : SBFolderView <UIGestureRecognizerDelegate, PTSettingsKeyObserver, SBFolderBackgroundViewDelegate>
{
    SBFloatyFolderBackgroundClipView *_scrollClipView;
    NSMutableArray *_pageBackgroundViews;
    NSMapTable *_pageBackgroundViewsForIconListViews;
    long long _scalingViewPageIndex;
    UITapGestureRecognizer *_tapGesture;
    UIPinchGestureRecognizer *_pinchGesture;
    UILongPressGestureRecognizer *_longPressGesture;
    SBHFolderSettings *_folderSettings;
    SBIconView *_cachedHiddenIconView;
    BOOL _displayingMultipleIconLists;
    BOOL _displaysMultipleIconListsInLandscapeOrientation;
    BOOL _convertingIconListStyle;
    BOOL _animatingRotation;
    NSUInteger _backgroundEffect;
}

+ (NSUInteger)countOfAdditionalPagesToKeepVisibleInOneDirection;
+ (double)defaultCornerRadius;
+ (id)defaultIconLocation;
+ (Class)_scrollViewClass;
@property(nonatomic, getter=isAnimatingRotation) BOOL animatingRotation; // @synthesize animatingRotation=_animatingRotation;
@property(nonatomic, getter=isConvertingIconListStyle) BOOL convertingIconListStyle; // @synthesize convertingIconListStyle=_convertingIconListStyle;
@property(readonly, nonatomic) BOOL displaysMultipleIconListsInLandscapeOrientation; // @synthesize displaysMultipleIconListsInLandscapeOrientation=_displaysMultipleIconListsInLandscapeOrientation;
@property(nonatomic, getter=isDisplayingMultipleIconLists) BOOL displayingMultipleIconLists; // @synthesize displayingMultipleIconLists=_displayingMultipleIconLists;
@property(nonatomic) NSUInteger backgroundEffect; // @synthesize backgroundEffect=_backgroundEffect;
// - (void).cxx_destruct;
- (id)descriptionBuilderWithMultilinePrefix:(id)arg1;
- (id)accessibilityTintColorForBackgroundView:(id)arg1;
- (void)accessibilityReduceTransparencyDidChange:(id)arg1;
- (void)settings:(id)arg1 changedValueForKey:(id)arg2;
- (BOOL)gestureRecognizer:(id)arg1 shouldRecognizeSimultaneouslyWithGestureRecognizer:(id)arg2;
- (BOOL)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (BOOL)_tapToCloseGestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2;
- (void)_handleLongPressGesture:(id)arg1;
- (void)_handlePinchGesture:(id)arg1;
- (void)_handleOutsideTap:(id)arg1;
- (void)_configureGestures;
- (CGPoint)_scrollView:(id)arg1 adjustedOffsetForOffset:(CGPoint)arg2 translation:(CGPoint)arg3 startPoint:(CGPoint)arg4 locationInView:(CGPoint)arg5 horizontalVelocity:(inout double )arg6 verticalVelocity:(inout double )arg7;
- (void)scrollViewDidScroll:(id)arg1;
- (void)findHiddenIconView;
- (void)_updateScrollingState:(BOOL)arg1;
- (void)_setScrollViewNeedsToClipCorners:(BOOL)arg1;
- (void)_convertToSingleIconListAnimated:(BOOL)arg1;
- (void)_convertToMultipleIconListsAnimated:(BOOL)arg1;
- (void)fadeContentForMinificationFraction:(double)arg1;
- (void)fadeContentForMagnificationFraction:(double)arg1;
- (void)returnScalingView;
- (id)borrowScalingView;
- (void)didTransitionAnimated:(BOOL)arg1;
- (void)willTransitionAnimated:(BOOL)arg1 withSettings:(id)arg2;
- (double)_titleVerticalOffsetForOrientation:(long long)arg1;
- (double)_titleFontSize;
- (double)_rubberBandIntervalForOverscroll;
- (BOOL)_showsTitle;
- (id)hitTest:(CGPoint)arg1 withEvent:(id)arg2;
- (id)iconListViewAtPoint:(CGPoint)arg1;
- (BOOL)locationCountsAsInsideFolder:(CGPoint)arg1;
- (double)_offsetToCenterPageControlInSpaceForPageControl;
- (void)_updateScalingViewFrame;
- (CGRect)_frameForScalingView;
- (void)_updateScalingViewLocation;
- (void)_currentPageIndexDidChange;
- (void)_updateIconListContainment:(id)arg1 atIndex:(NSUInteger)arg2;
- (CGRect)_iconListFrameForPageRect:(CGRect)arg1 atIndex:(NSUInteger)arg2;
- (CGRect)_pageBackgroundFrameForPageRect:(CGRect)arg1;
- (id)floatyFolderConfiguration;
- (void)_layoutSubviews;
- (long long)iconVisibilityHandling;
- (double)scrollableWidthForVisibleColumnRange;
- (double)minimumVisibleScrollOffset;
- (void)transitionToSize:(CGSize)arg1 withTransitionCoordinator:(id)arg2;
- (void)_orientationDidChange:(long long)arg1;
- (BOOL)_shouldConvertToMultipleIconListsInLandscapeOrientation;
- (void)_removeIconListView:(id)arg1;
- (void)_addIconListView:(id)arg1;
- (id)_newPageBackgroundView;
- (void)updateAccessibilityTintColors;
- (id)legibilitySettingsForIconListViews;
- (void)setLegibilitySettings:(id)arg1;
- (CGPoint)visibleFolderRelativeImageCenterForIcon:(id)arg1;
@property(readonly, nonatomic) double cornerRadius;
- (void)setBackgroundAlpha:(double)arg1;
- (void)enumeratePageBackgroundViewsUsingBlock:(id /* CDUnknownBlockType */)arg1;
- (void)dealloc;
- (id)initWithConfiguration:(id)arg1;

@end


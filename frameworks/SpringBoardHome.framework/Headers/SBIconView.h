// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBICONVIEW_H
#define SBICONVIEW_H

@class _UIStatesFeedbackGenerator;
@protocol SBIconViewSnapshotProviding, OS_os_activity, SBIconContinuityInfo, SBIconViewCustomImageViewControlling;

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBIcon;
@class SBIconImageView;
@class SBIconImageCrossfadeView;
@class SBCloseBoxView;
@class SBHIconEditingSettings;
@class SBHRecentsDocumentExtensionProvider;
@class SBHIconImageCache;
@class SBFolderIconImageCache;
@class SBFolderIcon;
@protocol UIPointerInteractionDelegate;
@protocol _UISettingsKeyObserver;
@protocol UIGestureRecognizerDelegate;
@protocol UIDragInteractionDelegate;
@protocol SBCloseBoxViewDelegate;
@protocol UIContextMenuInteractionDelegate;
@protocol SBSHardwareButtonEventConsuming;
@protocol SBHStackConfigurationInteractionDelegate;
@protocol SBIconViewCustomImageViewControllerObserving;
@protocol SBIconObserver;
@protocol SBReusableView;
@protocol SBIconAccessoryInfoProvider;
@protocol BSInvalidatable;
@protocol SBHIconViewConfigurationInteraction;
@protocol SBHIconViewConfigurationInteraction;
@protocol SBIconViewDelegate;
@protocol SBIconViewActionDelegate;
@protocol SBIconListLayoutProvider;
@protocol SBIconListLayout;
@protocol SBIconLabelView, SBIconAccessoryView, SBIconLabelAccessoryView;

@interface SBIconView : UIView <UIPointerInteractionDelegate, _UISettingsKeyObserver, UIGestureRecognizerDelegate, UIDragInteractionDelegate, SBCloseBoxViewDelegate, UIContextMenuInteractionDelegate, SBSHardwareButtonEventConsuming, SBHStackConfigurationInteractionDelegate, SBIconViewCustomImageViewControllerObserving, SBIconObserver, SBReusableView, SBIconAccessoryInfoProvider>

{
SBIcon *_icon;
SBIconImageView *_iconImageView;
SBIconImageCrossfadeView *_crossfadeView;
UIView *_snapshotContainerView;
UIView<SBIconAccessoryView> *_accessoryView;
SBCloseBoxView *_closeBox;
UIView<SBIconLabelView> *_labelView;
UIView<SBIconLabelAccessoryView> *_labelAccessoryView;
UIView *_dropGlow;
SBHIconEditingSettings *_iconEditingSettings;
UILabel *_iconIndexLabel;
NSObject<SBIconViewSnapshotProviding> *_snapshotProvider;
BOOL _drawsLabel;
BOOL _isEditing;
BOOL _discardClose;
BOOL _pauseReasons;
BOOL _isGrabbed;
BOOL _isOverlapping;
BOOL _refusesRecipientStatus;
BOOL _highlighted;
BOOL _launchDisabled;
BOOL _suppressesDisabledPresentation;
BOOL _iconWasTappedWhenDisabled;
BOOL _isJittering;
BOOL _allowJitter;
BOOL _allowCloseBox;
BOOL _touchDownInIcon;
BOOL _hideLabel;
BOOL _hideLabelAccessoryView;
BOOL _iconContentScalingEnabled;
BOOL _forcingIconContentScalingEnabled;
BOOL _startsDragMoreQuickly;
BOOL _isDragging;
BOOL _isDragLifted;
BOOL _folderIconFrozen;
BOOL _showingCloseBox;
BOOL _allowsAccessoryView;
BOOL _showingAccessoryView;
BOOL _allowsLabelArea;
BOOL _allowsPassthroughHitTesting;
BOOL _showsDropGlow;
BOOL _hasSetIconImageInfo;
BOOL _showsSquareCorners;
BOOL _disableContextMenuInteraction;
BOOL _disallowsBlockedForScreenTimeExpiration;
BOOL _reallyHasWidget;
BOOL _reallyHasPopover;
BOOL _imageLoadingBehavior;
BOOL _disallowCursorInteraction;
BOOL _customIconImageViewHitTestingDisabled;
BOOL _privateModeEnabled;
BOOL _labelStyle;
BOOL _allIconElementsButLabelHidden;
BOOL _userVisibilityStatus;
CGFloat _iconContentScale;
UIView *_scalingContainer;
CGRect _visibleImageRect;
NSHashTable *_observers;
NSCountedSet *_forbidEditingModeReasons;
NSCountedSet *_forbidAccessoryReasons;
SBIconImageInfo _iconImageInfo;
SBHRecentsDocumentExtensionProvider *_recentsDocumentExtensionProvider;
_UIStatesFeedbackGenerator *_feedbackGenerator;
NSMutableArray *_performAfterContextMenuBlocks;
NSHashTable *_droppingAssertions;
NSHashTable *_contextMenuInteractionConfigurations;
NSObject<OS_os_activity> *_iconContextMenuActivity;
NSCountedSet *_activePointerRegions;
}


@property (readonly, nonatomic) UIView *contentContainerView;
@property (readonly, nonatomic) UIDragInteraction *dragInteraction; // ivar: _dragInteraction
@property (readonly, nonatomic) UITapGestureRecognizer *tapGestureRecognizer; // ivar: _tapGestureRecognizer
@property (copy, nonatomic) NSDate *lastTouchDownDate; // ivar: _lastTouchDownDate
@property (retain, nonatomic) UIViewPropertyAnimator *accessoryViewAnimator; // ivar: _accessoryViewAnimator
@property (nonatomic) BOOL overlapping;
@property (readonly, nonatomic) NSInteger displayedLabelAccessoryType; // ivar: _displayedLabelAccessoryType
@property (readonly, nonatomic) UILongPressGestureRecognizer *editingModeGestureRecognizer; // ivar: _editingModeGestureRecognizer
@property (readonly, nonatomic) UIContextMenuInteraction *contextMenuInteraction; // ivar: _contextMenuInteraction
@property (retain, nonatomic) NSObject<BSInvalidatable> *homeButtonPressConsumingAssertion; // ivar: _homeButtonPressConsumingAssertion
@property (nonatomic) BOOL lastContextMenuInteractionFailedToLoad; // ivar: _lastContextMenuInteractionFailedToLoad
@property (retain, nonatomic) NSObject<SBHIconViewConfigurationInteraction> *currentConfigurationInteraction; // ivar: _currentConfigurationInteraction
@property (retain, nonatomic) NSObject<SBHIconViewConfigurationInteraction> *currentStackConfigurationInteraction; // ivar: _currentStackConfigurationInteraction
@property (readonly, nonatomic) UIPointerInteraction *iconViewCursorInteraction; // ivar: _iconViewCursorInteraction
@property (readonly, nonatomic) UIPointerInteraction *closeBoxCursorInteraction; // ivar: _closeBoxCursorInteraction
@property (retain, nonatomic) UIViewPropertyAnimator *closeBoxAnimator; // ivar: _closeBoxAnimator
@property (readonly, copy, nonatomic) NSString *representedFolderIconLocation;
@property (readonly, nonatomic) BOOL canBeginDrags;
@property (readonly, copy, nonatomic) NSString *applicationBundleIdentifierForShortcuts;
@property (readonly, copy, nonatomic) NSURL *applicationBundleURLForShortcuts;
@property (readonly, copy, nonatomic) NSArray *effectiveApplicationShortcutItems;
@property (readonly, nonatomic) CGSize maxLabelSize;
@property (nonatomic) NSInteger labelStyle;
@property (retain, nonatomic) SBIcon *icon;
@property (weak, nonatomic) NSObject<SBIconViewDelegate> *delegate; // ivar: _delegate
@property (weak, nonatomic) NSObject<SBIconViewActionDelegate> *overrideActionDelegate; // ivar: _overrideActionDelegate
@property (copy, nonatomic) NSString *location; // ivar: _iconLocation
@property (nonatomic) NSUInteger configurationOptions;
@property (nonatomic) CGFloat iconImageAlpha; // ivar: _iconImageAlpha
@property (readonly, nonatomic) CGFloat effectiveIconImageAlpha;
@property (nonatomic) CGFloat iconAccessoryAlpha; // ivar: _iconAccessoryAlpha
@property (nonatomic) CGFloat iconLabelAlpha; // ivar: _iconLabelAlpha
@property (nonatomic) BOOL allIconElementsButLabelHidden;
@property (copy, nonatomic) NSArray *applicationShortcutItems; // ivar: _applicationShortcutItems
@property (readonly, nonatomic) BOOL shouldShowLabelAccessoryView;
@property (readonly, nonatomic) BOOL allowsLabelAccessoryView;
@property (readonly, nonatomic) NSInteger currentLabelAccessoryType;
@property (readonly, nonatomic) CGFloat labelAccessoryTotalWidth;
@property (nonatomic) BOOL labelAccessoryHidden;
@property (readonly, nonatomic) CGFloat baselineOffsetFromBottom;
@property (readonly, nonatomic) CGFloat firstLineBaseline;
@property (readonly, nonatomic) CGFloat lastLineBaseline;
@property (nonatomic) BOOL enabled; // ivar: _enabled
@property (nonatomic) BOOL paused; // ivar: _paused
@property (nonatomic) BOOL editing;
@property (nonatomic) BOOL allowsEditingAnimation;
@property (nonatomic) BOOL allowsCloseBox;
@property (readonly, nonatomic) BOOL canShowCloseBox;
@property (readonly, nonatomic) BOOL shouldShowCloseBox;
@property (readonly, nonatomic) BOOL showingContextMenu;
@property (nonatomic) BOOL allowsBlockedForScreenTimeExpiration;
@property (readonly, nonatomic) UIImage *iconImageSnapshot;
@property (readonly, nonatomic) UIView *iconImageSnapshotView;
@property (readonly, nonatomic) CGRect iconImageFrame;
@property (readonly, nonatomic) CGPoint iconImageCenter;
@property (readonly, nonatomic) CGSize iconImageVisibleSize;
@property (readonly, nonatomic) CGSize iconImageSize;
@property (readonly, nonatomic) CGSize iconViewSize;
@property (nonatomic) UIEdgeInsets cursorHitTestPadding; // ivar: _cursorHitTestPadding
@property (readonly, nonatomic) BOOL isCursorActive;
@property (readonly, nonatomic) BOOL allowsTapWhileEditing;
@property (nonatomic) BOOL highlighted;
@property (nonatomic) BOOL allowsLabelArea;
@property (nonatomic) BOOL allowsPassthroughHitTesting;
@property (nonatomic) BOOL customIconImageViewHitTestingDisabled;
@property (nonatomic) BOOL labelHidden;
@property (nonatomic) BOOL showsSquareCorners;
@property (readonly, nonatomic) BOOL touchDownInIcon;
@property (nonatomic) BOOL grabbed;
@property (readonly, nonatomic) BOOL dropping;
@property (nonatomic) BOOL showsImageAndLabelDuringDrop; // ivar: _showsImageAndLabelDuringDrop
@property (readonly, nonatomic) UIView *dropContainerView;
@property (nonatomic) BOOL refusesRecipientStatus;
@property (readonly, nonatomic) BOOL showsDropGlow;
@property (readonly) BOOL crossfadingImageWithView;
@property (readonly, nonatomic) UIView<SBIconLabelView> *labelView;
@property (retain, nonatomic) UIFont *labelFont; // ivar: _labelFont
@property (readonly, nonatomic) NSInteger currentAccessoryType;
@property (nonatomic) BOOL allowsAccessoryView;
@property (readonly, nonatomic) NSInteger continuityBadgeType;
@property (retain, nonatomic) NSObject<SBIconContinuityInfo> *continuityInfo; // ivar: _continuityInfo
@property (nonatomic) CGFloat iconContentScale;
@property (nonatomic) BOOL iconContentScalingEnabled;
@property (nonatomic) BOOL startsDragMoreQuickly;
@property (readonly, nonatomic) CGFloat dragInteractionLiftDelay;
@property (readonly, nonatomic) Class expectedIconImageViewClass;
@property (nonatomic) NSUInteger customIconImageViewControllerPriority; // ivar: _customIconImageViewControllerPriority
@property (readonly, nonatomic) UIViewController<SBIconViewCustomImageViewControlling> *customIconImageViewController; // ivar: _customIconImageViewController
@property (retain, nonatomic) NSObject<SBIconListLayoutProvider> *listLayoutProvider; // ivar: _listLayoutProvider
@property (readonly, nonatomic) NSObject<SBIconListLayout> *listLayout;
@property (nonatomic) SBIconImageInfo iconImageInfo;
@property (retain, nonatomic) SBHIconImageCache *iconImageCache; // ivar: _iconImageCache
@property (retain, nonatomic) SBFolderIconImageCache *folderIconImageCache; // ivar: _folderIconImageCache
@property (retain, nonatomic) SBFolderIcon *folderIcon; // ivar: _folderIcon
@property (nonatomic) NSUInteger folderBackgroundStyle;
@property (retain, nonatomic) UIView *folderIconBackgroundView; // ivar: _folderIconBackgroundView
@property (nonatomic) BOOL folderIconFrozen;
@property (readonly, nonatomic) NSUInteger visibleMiniIconCount;
@property (readonly, nonatomic) NSUInteger visibleMiniIconListIndex;
@property (readonly, nonatomic) NSUInteger firstVisibleMiniIconIndex;
@property (readonly, nonatomic) NSUInteger centerVisibleMiniIconIndex;
@property (readonly, nonatomic) NSUInteger lastVisibleMiniIconIndex;
@property (readonly, nonatomic) BOOL animatingScrolling;
@property (retain, nonatomic) UIColor *accessibilityTintColor; // ivar: _accessibilityTintColor
@property (readonly, nonatomic) NSInteger progressState;
@property (readonly, nonatomic) BOOL supportsConfigurationCard;
@property (readonly, nonatomic) BOOL showingConfigurationCard;
@property (readonly, nonatomic) BOOL supportsStackConfigurationCard;
@property (nonatomic) NSUInteger imageLoadingBehavior;
@property (nonatomic) NSUInteger debugIconIndex; // ivar: _debugIconIndex
@property (nonatomic) BOOL iconImageSizeMatchesBoundsSize; // ivar: _iconImageSizeMatchesBoundsSize
@property (readonly, copy, nonatomic) NSString *backgroundViewGroupNameBase;
@property (nonatomic) NSUInteger userVisibilityStatus;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;


-(BOOL)isPrivateModeEnabled;
-(void)_enableContentContainerView;
-(CGFloat)_additionalLiftScale;
-(void)_notifyObserversSizeDidChange;
-(void)editingModeGestureRecognizerDidFire:(id)arg0 ;
-(void)_toggleGroupBlendingIfNecessary;
-(id)badgeParallaxSettings;
-(BOOL)allowsBlockedForScreenTimeExpiration;
-(id)sourceIconViewForConfigurationInteraction:(id)arg0 ;
-(void)_updateIconContentScale;
-(void)configureForLabelAllowed:(BOOL)allowed;
-(BOOL)_isShowingAccessoryView;
-(id)_contextMenuInteraction:(id)arg0 overrideSuggestedActionsForConfiguration:(id)arg1 ;
-(void)_createAccessoryViewIfNecessary;
-(BOOL)_shouldAnimatePropertyWithKey:(id)arg0 ;
-(BOOL)gestureRecognizerShouldBegin:(id)arg0 ;
-(void)_setForcingIconContentScalingEnabled:(BOOL)arg0 ;
-(void)scrollToFirstGapAnimated:(BOOL)arg0 ;
-(void)setTouchDownInIcon:(BOOL)arg0 ;
-(BOOL)_hasPopover;
-(void)_recursivelyUpdateBackdropMaskFrames;
-(void)_toggleContentContainerViewIfNecessary;
-(void)pointerInteraction:(id)arg0 willEnterRegion:(id)arg1 animator:(id)arg2 ;
-(void)iconAccessoriesDidUpdate:(id)arg0 ;
-(void)setCustomIconImageViewController:(id)arg0 ;
-(void)settings:(id)arg0 changedValueForKey:(id)arg1 ;
-(id)newComponentBackgroundViewOfType:(NSInteger)arg0 ;
-(id)_visiblyActiveDataSource;
-(id)initWithConfigurationOptions:(NSUInteger)arg0 ;
-(void)setDragLifted:(BOOL)arg0 ;
-(void)_insertIconImageView:(id)arg0 ;
-(void)_refreshAccessoryViewNotification:(id)arg0 ;
-(id)_labelImage;
-(id)reuseDelegate;
-(void)contextMenuInteraction:(id)arg0 willDisplayMenuForConfiguration:(id)arg1 animator:(id)arg2 ;
-(struct CGRect )visibleImageRelativeFrameForMiniIconAtIndex:(NSUInteger)arg0 ;
-(void)addObserver:(id)arg0 ;
-(struct CGPoint )_centerForAccessoryView;
-(BOOL)isFolderIcon;
-(id)referenceIconViewForConfigurationInteraction:(id)arg0 ;
-(void)_registerForAddWidgetRequestsIfNecessary;
-(void)cleanUpAfterDropAnimation;
-(BOOL)_contextMenuInteractionShouldAllowDragAfterDismiss:(id)arg0 ;
-(id)labelImageWithParameters:(id)arg0 ;
-(struct CGPoint )accessoryOffset;
-(void)_configureLabelAccessoryViewForType:(NSInteger)arg0 ;
-(CGFloat)effectiveIconLabelAlpha;
-(struct CGSize )intrinsicContentSize;
-(void)_applyOverallAlpha:(CGFloat)arg0 ;
-(BOOL)_dragInteraction:(id)arg0 canExcludeCompetingGestureRecognizer:(id)arg1 ;
-(BOOL)allowsTapWhileEditing;
-(void)_updateLabelArea;
-(id)_makeIconImageView;
-(void)_updateLabel;
-(id)shortcutsDelegate;
-(void)_applyIconAccessoryAlpha:(CGFloat)arg0 ;
-(struct CGRect )_frameForVisibleImage;
-(void)earlyTerminateContextMenuDismissAnimation;
-(void)_updateProgressAnimated:(BOOL)arg0 ;
-(BOOL)shouldActivateApplicationShortcutItem:(id)arg0 atIndex:(NSUInteger)arg1 ;
-(void)setFrame:(struct CGRect )arg0 ;
-(void)_applyIconLabelAlpha:(CGFloat)arg0 ;
-(CGFloat)effectiveOverallAlpha;
-(id)dragInteraction:(id)arg0 previewForCancellingItem:(id)arg1 withDefault:(id)arg2 ;
-(BOOL)supportsConfigurationCard;
-(id)dragDelegate;
-(id)newCaptureOnlyBackgroundView;
-(void)pressesEnded:(id)arg0 withEvent:(id)arg1 ;
-(void)_updateCursorInteractionsEnabled;
-(void)_applyIconContentScale:(CGFloat)arg0 ;
-(void)touchesBegan:(id)arg0 withEvent:(id)arg1 ;
-(void)_updateAllComponentAlphas;
-(void)_handleAddWidgetRequest:(id)arg0 ;
-(void)dragInteraction:(id)arg0 willAnimateLiftWithAnimator:(id)arg1 session:(id)arg2 ;
-(void)customImageViewControllerWantsLabelHiddenDidChange:(id)arg0 ;
-(void)contextMenuInteraction:(id)arg0 willPerformPreviewActionForMenuWithConfiguration:(id)arg1 animator:(id)arg2 ;
-(id)contextMenuInteraction:(id)arg0 previewForDismissingMenuWithConfiguration:(id)arg1 ;
-(id)_pointerStyleForWidgetIcon;
-(void)_applyIconImageAlpha:(CGFloat)arg0 ;
-(BOOL)refusesRecipientStatus;
-(void)setCrossfadeFraction:(CGFloat)arg0 ;
-(CGFloat)effectiveIconAccessoryAlpha;
-(id)_legibilitySettingsWithStyle:(NSInteger)arg0 primaryColor:(id)arg1 ;
-(void)_updateLaunchDisabled;
-(id)initWithConfigurationOptions:(NSUInteger)arg0 listLayoutProvider:(id)arg1 ;
-(id)initWithFrame:(struct CGRect )arg0 ;
-(void)dragInteraction:(id)arg0 item:(id)arg1 willAnimateCancelWithAnimator:(id)arg2 ;
-(BOOL)dragInteraction:(id)arg0 sessionIsRestrictedToDraggingApplication:(id)arg1 ;
-(void)_applyEditingStateAnimated:(BOOL)arg0 ;
-(void)prepareToCrossfadeImageWithView:(id)arg0 anchorPoint:(struct CGPoint )arg1 options:(NSUInteger)arg2 ;
-(void)presentConfigurationCard;
-(void)dragSessionWillBegin:(id)arg0 ;
-(id)dragPreviewForItem:(id)arg0 session:(id)arg1 ;
-(BOOL)shouldShowCloseBox;
-(void)prepareToCrossfadeWithFloatyFolderView:(id)arg0 allowFolderInteraction:(BOOL)arg1 ;
-(void)updateCustomIconImageViewController;
-(BOOL)canReceiveGrabbedIcon:(id)arg0 ;
-(BOOL)showsDropGlow;
-(void)_updateJitter;
-(BOOL)startsDragMoreQuickly;
-(struct CGRect )frameForMiniIconAtIndex:(NSUInteger)arg0 ;
-(void)_contextMenuConfigurationDidPresent:(id)arg0 ;
-(id)folder;
-(void)removeDroppingAssertion:(id)arg0 ;
-(void)tapGestureDidChange:(id)arg0 ;
-(void)_setShowingAccessoryView:(BOOL)arg0 ;
-(void)configureMatchingIconView:(id)arg0 ;
-(id)pointerInteraction:(id)arg0 styleForRegion:(id)arg1 ;
-(void)_updateAllComponentAlphasAnimated:(BOOL)arg0 ;
-(id)_automationID;
-(void)_updateAfterManualIconImageInfoChange;
-(void)updateParallaxSettings;
-(void)_acquireHomeButtonPressConsumingAssertionIfNecessary;
-(NSUInteger)supportedIconGridSizeClasses;
-(void)_setShowingCloseBox:(BOOL)arg0 ;
-(BOOL)canBeginDrags;
-(void)_updateCustomIconImageViewControllerBlur:(BOOL)arg0 ;
-(void)_backgroundContrastDidChange:(id)arg0 ;
-(void)configurationInteractionDidEnd:(id)arg0 ;
-(void)dismissStackConfigurationCard;
-(BOOL)_isShowingCloseBox;
-(id)dragInteraction:(id)arg0 previewForLiftingItem:(id)arg1 session:(id)arg2 ;
-(id)hitTest:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(void)presentStackConfigurationCard;
-(void)setCrossfadeCornerRadius:(CGFloat)arg0 ;
-(id)_legibilitySettingsWithParameters:(id)arg0 ;
-(id)applicationShortcutWidgetBundleIdentifier;
-(void)touchesMoved:(id)arg0 withEvent:(id)arg1 ;
-(void)setBounds:(struct CGRect )arg0 ;
-(void)pressesChanged:(id)arg0 withEvent:(id)arg1 ;
-(void)setPrivateModeEnabled:(BOOL)arg0 ;
-(void)purgeCachedEditingViewData;
-(id)succinctDescriptionBuilder;
-(id)dragInteraction:(id)arg0 itemsForAddingToSession:(id)arg1 withTouchAtPoint:(struct CGPoint )arg2 ;
-(BOOL)allIconElementsButLabelHidden;
-(void)removeObserver:(id)arg0 ;
-(id)widgetConfigurationInteractionForDataSource:(id)arg0 ;
-(BOOL)canShowCloseBox;
-(NSInteger)draggingStartLocation;
-(BOOL)_isCursorInteractionEnabled;
-(void)_recursiveNotifyInteractionTintColorDidChangeForReasons:(NSUInteger)arg0 ;
-(void)configurationInteractionDidCommit:(id)arg0 ;
-(void)setDragging:(BOOL)arg0 updateImmediately:(BOOL)arg1 ;
-(void)setBoundsSizeFromIconImageSize:(struct CGSize )arg0 ;
-(void)configureLabelImageParametersBuilder:(id)arg0 ;
-(BOOL)_dragInteraction:(id)arg0 shouldDelayCompetingGestureRecognizer:(id)arg1 ;
-(struct CGSize )accessorySize;
-(void)clearIconImageInfo;
-(void)scrollToTopOfPage:(NSUInteger)arg0 animated:(BOOL)arg1 ;
-(id)labelConfiguration;
-(NSInteger)_closeBoxType;
-(id)contentSizeCategory;
-(BOOL)allowsCloseBox;
-(void)_dragInteraction:(id)arg0 liftAnimationDidChangeDirection:(NSInteger)arg1 ;
-(void)_boldTextStatusDidChange:(id)arg0 ;
-(void)_updateLabelAccessoryView;
-(void)_updateFrameToIconViewSize;
-(struct CGSize )sizeThatFits:(struct CGSize )arg0 ;
-(void)scrollToGapOrTopIfFullOfPage:(NSUInteger)arg0 animated:(BOOL)arg1 ;
-(void)performAfterContextMenusDismissUsingBlock:(id)arg0 ;
-(void)_unregisterForAddWidgetRequests;
-(void)cancelDrag;
-(void)endForbiddingEditingModeWithReason:(id)arg0 ;
-(BOOL)isLabelTextBold;
-(struct CGSize )iconViewSizeForIconImageSize:(struct CGSize )arg0 ;
-(void)_applyIconEditingSettings;
-(id)tintColor;
-(BOOL)isDragging;
-(BOOL)allowsLabelAccessoryView;
-(void)_invalidateHomeButtonPressConsumingAssertion;
-(id)dragInteraction:(id)arg0 sessionForAddingItems:(id)arg1 withTouchAtPoint:(struct CGPoint )arg2 ;
-(void)removeAllIconAnimations;
-(void)configurationInteractionWillBegin:(id)arg0 ;
-(BOOL)supportsStackConfigurationCard;
-(void)_destroyIconImageView;
-(void)_configureIconImageView:(id)arg0 ;
-(void)dismissContextMenuWithCompletion:(id)arg0 ;
-(void)_updateCloseBoxAnimated:(BOOL)arg0 ;
-(void)pressesBegan:(id)arg0 withEvent:(id)arg1 ;
-(id)draggingLaunchURL;
-(void)_updateDragInteractionLiftDelay;
-(void)dragInteraction:(id)arg0 session:(id)arg1 willAddItems:(id)arg2 forInteraction:(id)arg3 ;
-(void)_configureViewAsFolderIconImageView:(id)arg0 ;
-(id)pointerInteraction:(id)arg0 regionForRequest:(id)arg1 defaultRegion:(id)arg2 ;
-(void)cleanupAfterCrossfade;
-(id)_contextMenuInteraction:(id)arg0 previewForIconWithConfigurationOptions:(NSUInteger)arg1 highlighted:(BOOL)arg2 ;
-(void)_checkAndRemoveCloseBoxAfterAnimation;
-(void)scrollToTopOfFirstPageAnimated:(BOOL)arg0 ;
-(void)setMorphFraction:(CGFloat)arg0 ;
-(BOOL)shouldShowLabelAccessoryView;
-(void)_destroyAccessoryView;
-(void)_contextMenuConfigurationWillDismiss:(id)arg0 ;
-(struct CGRect )_frameForLabelHighlight;
-(id)homeScreenContentViewForConfigurationInteraction:(id)arg0 ;
-(BOOL)gestureRecognizer:(id)arg0 shouldReceiveTouch:(id)arg1 ;
-(void)_updateBrightness;
-(BOOL)pointMostlyInside:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(void)iconLaunchEnabledDidChange:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(void)pressesCancelled:(id)arg0 withEvent:(id)arg1 ;
-(id)actionDelegate;
-(void)touchesCancelled:(id)arg0 withEvent:(id)arg1 ;
-(BOOL)allowsAccessoryView;
-(void)_updateCustomIconImageViewControllerHitTesting;
-(BOOL)_isForcingIconContentScalingEnabled;
-(id)succinctDescription;
-(id)recentsDocumentExtensionProvider;
-(BOOL)isTimedOut;
-(void)setShowsDropGlow:(BOOL)arg0 animator:(id)arg1 ;
-(void)_updateConfigurationForIconImageView:(id)arg0 ;
-(id)containerViewControllerForConfigurationInteraction:(id)arg0 ;
-(void)_removeUnknownSubviews;
-(void)_contextMenuConfigurationDidDismiss:(id)arg0 ;
-(BOOL)_dragInteraction:(id)arg0 competingGestureRecognizerShouldDelayLift:(id)arg1 ;
-(void)_updateAccessoryViewWithAnimation:(BOOL)arg0 ;
-(void)setDragging:(BOOL)arg0 ;
-(void)setDisallowCursorInteraction:(BOOL)arg0 ;
-(id)effectiveListLayoutProvider;
-(void)dragInteraction:(id)arg0 session:(id)arg1 willEndWithOperation:(NSUInteger)arg2 ;
-(id)displayedLabelFont;
-(BOOL)_hasWidget;
-(id)dragItems;
-(struct CGRect )_frameForImageView;
-(id)currentImageView;
-(void)layoutSubviews;
-(BOOL)allowsLabelArea;
-(id)pauseReasonsDescriptions;
-(BOOL)isDragLifted;
-(void)_contextMenuConfigurationWillPresent:(id)arg0 forInteraction:(id)arg1 ;
-(void)_handleTap;
-(void)startForbiddingAccessoryWithReason:(id)arg0 animated:(BOOL)arg1 ;
-(void)contextMenuInteraction:(id)arg0 willEndForConfiguration:(id)arg1 animator:(id)arg2 ;
-(id)contextMenuInteraction:(id)arg0 previewForHighlightingMenuWithConfiguration:(id)arg1 ;
-(void)_createCloseBoxIfNecessary;
-(void)cleanupAfterFloatyFolderCrossfade;
-(void)addGesturesAndInteractionsIfNecessary;
-(BOOL)lastContextMenuInteractionFailedToLoad;
-(void)iconImageDidUpdate:(id)arg0 ;
-(BOOL)showsSquareCorners;
-(void)_delegateTouchEnded:(BOOL)arg0 ;
-(id)_legibilitySettingsWithPrimaryColor:(id)arg0 ;
-(void)cancelDragLift;
-(struct CGRect )_frameForLabelAccessoryViewWithLabelFrame:(struct CGRect )arg0 labelImage:(id)arg1 labelImageParameters:(id)arg2 imageFrame:(struct CGRect )arg3 ;
-(CGFloat)_labelBaselineOffsetFromImage;
-(BOOL)_debugContinuity;
-(BOOL)allowsEditingAnimation;
-(void)performTap;
-(id)matchingIconViewByAddingConfigurationOptions:(NSUInteger)arg0 removingConfigurationOptions:(NSUInteger)arg1 ;
-(BOOL)allowsPassthroughHitTesting;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)setBackgroundAndIconGridImageAlpha:(CGFloat)arg0 ;
-(struct CGPoint )_centerForCloseBox;
-(void)dragSession:(id)arg0 willEndWithOperation:(NSUInteger)arg1 ;
-(void)_updatePrivateMode;
-(void)dragInteraction:(id)arg0 sessionWillBegin:(id)arg1 ;
-(void)_closeBoxTapGestureChanged:(id)arg0 ;
-(void)didMoveToWindow;
-(void)prepareForReuse;
-(BOOL)_isFolderIconFreezingSupported;
-(void)touchesEnded:(id)arg0 withEvent:(id)arg1 ;
-(id)matchingIconViewWithConfigurationOptions:(NSUInteger)arg0 ;
-(BOOL)_shouldHaveContentContainerView;
-(void)_destroyAccessoryView:(id)arg0 ;
-(id)contextMenuInteraction:(id)arg0 configurationForMenuAtLocation:(struct CGPoint )arg1 ;
-(BOOL)isCursorActive;
-(void)dragInteraction:(id)arg0 session:(id)arg1 didEndWithOperation:(NSUInteger)arg2 ;
-(void)consumeSinglePressUpForButtonKind:(NSInteger)arg0 ;
-(void)dismissConfigurationCard;
-(BOOL)isContextMenuInteractionActive;
-(CGFloat)_labelVerticalOffset;
-(void)setUserInteractionEnabled:(BOOL)arg0 ;
-(id)draggingLaunchActions;
-(void)_updateIconImageViewAnimated:(BOOL)arg0 ;
-(void)pointerInteraction:(id)arg0 willExitRegion:(id)arg1 animator:(id)arg2 ;
-(BOOL)disallowCursorInteraction;
-(id)markAsDropping;
-(void)startForbiddingEditingModeWithReason:(id)arg0 ;
-(id)_labelImageParameters;
-(id)behaviorDelegate;
-(void)_contentSizeCategoryDidChange:(id)arg0 ;
-(void)dealloc;
-(id)prepareForIconDrop;
-(struct CGRect )_frameForLabel;
-(void)_disableContentContainerView;
-(BOOL)showsImageAndLabelDuringDrop;
-(CGFloat)effectiveBrightness;
-(id)dragInteraction:(id)arg0 itemsForBeginningSession:(id)arg1 ;
-(struct CGRect )contentBoundingRectForConfigurationInteraction:(id)arg0 ;
-(BOOL)_shouldEnableGroupBlending;
-(BOOL)pointInside:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(void)dismissConfigurationCardImmediately;
+(CGFloat)defaultMaxLabelHeight;
+(struct CGSize )defaultIconImageSize;
+(NSInteger)continuityBadgeTypeForContinuityInfo:(id)arg0 ;
+(Class)_closeBoxClassForType:(NSInteger)arg0 ;
+(CGFloat)_labelHeight;
+(CGFloat)defaultIconImageCornerRadius;
+(struct CGSize )defaultIconViewSizeForIconImageSize:(struct CGSize )arg0 configurationOptions:(NSUInteger)arg1 ;
+(CGFloat)_defaultDragInteractionLiftDelay;
+(id)_jitterYTranslationAnimation;
+(CGFloat)defaultIconImageScale;
+(id)componentBackgroundViewOfType:(NSInteger)arg0 compatibleWithTraitCollection:(id)arg1 initialWeighting:(CGFloat)arg2 ;
+(CGFloat)defaultMaxLabelWidthDeltaForContentSizeCategory:(id)arg0 ;
+(id)componentBackgroundView;
+(struct CGSize )maxLabelSizeForListLayout:(id)arg0 iconImageSize:(struct CGSize )arg1 contentSizeCategory:(id)arg2 options:(NSUInteger)arg3 ;
+(id)draggedItemBundleIdentifiersInDrag:(id)arg0 ;
+(id)dragContextForDragItem:(id)arg0 ;
+(id)componentBackgroundViewOfType:(NSInteger)arg0 ;
+(struct CGSize )maxLabelSizeForIconImageSize:(struct CGSize )arg0 contentSizeCategory:(id)arg1 options:(NSUInteger)arg2 ;
+(BOOL)supportsPreviewInteraction;
+(void)configureLabelImageParametersBuilder:(id)arg0 forIcon:(id)arg1 location:(id)arg2 ;
+(BOOL)isIconTapGestureRecognizer:(id)arg0 ;
+(BOOL)supportsDragInteraction;
+(id)_jitterRotationAnimationForGridSize:(struct SBHIconGridSize )arg0 ;
+(NSUInteger)defaultImageLoadingBehavior;
+(BOOL)supportsTapGesture;
+(BOOL)_shouldAlwaysHaveContentContainerView;
+(struct CGSize )maxLabelSizeForIconImageSize:(struct CGSize )arg0 ;
+(void)setDebugContinuityBadgeType:(id)arg0 ;
+(NSInteger)debugContinuityBadgeType;
+(BOOL)allowsLabelAccessoryView;
+(NSInteger)closeBoxTypeForView:(id)arg0 ;
+(void)activateShortcut:(id)arg0 withBundleIdentifier:(id)arg1 forIconView:(id)arg2 ;
+(id)_jitterXTranslationAnimation;
+(BOOL)showsWidgets;
+(NSInteger)continuityBadgeTypeForNSString:(id)arg0 ;
+(BOOL)showsPopovers;
+(Class)defaultViewClassForAccessoryType:(NSInteger)arg0 ;
+(id)defaultIconLocation;
+(BOOL)supportsCursorInteraction;
+(BOOL)_alwaysShowsAccessoryOfType:(NSInteger)arg0 ;
+(CGFloat)labelAccessoryViewBaseRightMargin;
+(Class)defaultViewClassForLabelAccessoryType:(NSInteger)arg0 ;
+(CGFloat)labelAccessoryViewAdditionalRightMarginForType:(NSInteger)arg0 ;
+(struct CGSize )maxLabelSizeForListLayout:(id)arg0 contentSizeCategory:(id)arg1 options:(NSUInteger)arg2 ;
+(id)groupNameBaseForComponentBackgroundViewOfType:(NSInteger)arg0 ;
+(id)labelConfigurationForListLayout:(id)arg0 contentSizeCategory:(id)arg1 options:(NSUInteger)arg2 ;
+(struct CGPoint )defaultIconImageCenterForIconImageSize:(struct CGSize )arg0 ;
+(struct CGSize )defaultIconViewSize;


@end


#endif


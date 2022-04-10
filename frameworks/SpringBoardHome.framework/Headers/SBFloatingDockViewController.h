// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBFLOATINGDOCKVIEWCONTROLLER_H
#define SBFLOATINGDOCKVIEWCONTROLLER_H

@protocol SBFloatingDockViewControllerDelegate;
@protocol SBFloatingDockSuggestionsViewProviding;

@class SBFTouchPassThroughView;
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBFloatingDockView;
@class SBHIconManager;
@class SBFolderPresentingViewController;
@class SBHomeScreenIconTransitionAnimator;
@class SBHFloatingDockStyleConfiguration;
@class SBFolderController;
@protocol SBIconListViewDragDelegate;
@protocol SBIconListModelObserver;
@protocol SBFolderControllerDelegate;
@protocol SBFolderPresentingViewControllerDelegate;
@protocol SBScaleIconZoomAnimationContaining;
@protocol SBIconViewProviding;
@protocol SBFloatingDockViewDelegate;
@protocol SBUICoronaAnimationControllerParticipant;
@protocol SBIconViewQuerying;
@protocol SBIconLocationPresenting;
@protocol BSDescriptionProviding;
@protocol SBIconViewProviding;

#include "SBHIconModel.h"
#include "SBIconListView.h"
#include "SBIconListModel.h"
#include <SpringBoardFoundation/SBFTouchPassThroughViewController.h>

@interface SBFloatingDockViewController : SBFTouchPassThroughViewController <SBIconListViewDragDelegate, SBIconListModelObserver, SBFolderControllerDelegate, SBFolderPresentingViewControllerDelegate, SBScaleIconZoomAnimationContaining, SBIconViewProviding, SBFloatingDockViewDelegate, SBUICoronaAnimationControllerParticipant, SBIconViewQuerying, SBIconLocationPresenting, BSDescriptionProviding>

{
SBFloatingDockView *_dockView;
NSHashTable *_bouncedDropSessions;
}


@property (readonly, nonatomic) SBHIconManager *iconManager; // ivar: _iconManager
@property (readonly, weak, nonatomic) NSObject<SBIconViewProviding> *iconViewProvider; // ivar: _iconViewProvider
@property (retain, nonatomic) SBIconListModel *dockListModel; // ivar: _dockListModel
@property (retain, nonatomic) SBFloatingDockView *dockView;
@property (retain, nonatomic) SBFolderPresentingViewController *folderPresentingViewController; // ivar: _folderPresentingViewController
@property (retain, nonatomic) SBHomeScreenIconTransitionAnimator *currentFolderAnimator; // ivar: _currentFolderAnimator
@property (retain, nonatomic) NSMutableArray *currentExpandCompletions; // ivar: _currentExpandCompletions
@property (retain, nonatomic) NSMutableArray *currentCollapseCompletions; // ivar: _currentCollapseCompletions
@property (retain, nonatomic) SBFTouchPassThroughView *scalingView; // ivar: _scalingView
@property (nonatomic) CGFloat lastDockHeight; // ivar: _lastDockHeight
@property (copy, nonatomic) SBHFloatingDockStyleConfiguration *underlyingPresentationStyleConfiguration; // ivar: _underlyingPresentationStyleConfiguration
@property (nonatomic) BOOL transitioningUnderlyingPresentationStyleConfiguration; // ivar: _transitioningUnderlyingPresentationStyleConfiguration
@property (copy, nonatomic) SBHFloatingDockStyleConfiguration *transitionTargetUnderlyingPresentationStyleConfiguration; // ivar: _transitionTargetUnderlyingPresentationStyleConfiguration
@property (weak, nonatomic) NSObject<SBFloatingDockViewControllerDelegate> *delegate; // ivar: _delegate
@property (retain, nonatomic) UIViewController<SBFloatingDockSuggestionsViewProviding> *suggestionsViewController; // ivar: _suggestionsViewController
@property (readonly, nonatomic) CGFloat contentHeight;
@property (readonly, nonatomic) CGFloat maximumContentHeight;
@property (readonly, nonatomic) CGRect floatingDockScreenFrame;
@property (readonly, nonatomic) CGRect floatingDockScreenPresentationFrame;
@property (readonly, nonatomic) CGFloat preferredVerticalMargin;
@property (nonatomic) CGFloat requestedVerticalMargin;
@property (readonly, nonatomic) CGFloat translationFromFullyPresentedFrame;
@property (readonly, nonatomic) CGFloat maximumDockContinuousCornerRadius;
@property (nonatomic) CGFloat dockOffscreenProgress; // ivar: _dockOffscreenProgress
@property (nonatomic) BOOL wantsFastIconReordering; // ivar: _wantsFastIconReordering
@property (nonatomic) BOOL shouldIndicateImpossibleDrop; // ivar: _shouldIndicateImpossibleDrop
@property (readonly, nonatomic) BOOL presentingFolder;
@property (readonly, nonatomic) SBFolderController *presentedFolderController;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) SBHIconModel *iconModel;
@property (readonly, nonatomic) SBIconListView *currentIconListView;
@property (readonly, nonatomic) SBIconListView *dockIconListView;
@property (readonly, nonatomic) UIView *containerView;
@property (readonly, nonatomic) UIWindow *animationWindow;
@property (readonly, nonatomic) UIView *fallbackIconContainerView;
@property (readonly, copy, nonatomic) NSArray *extraViewsContainers;
@property (readonly, copy, nonatomic) NSArray *extraViews;
@property (readonly, nonatomic) BOOL shouldAnimateLastTwoViewsAsOne;
@property (readonly, nonatomic) BOOL shouldAnimateFirstTwoViewsAsOne;
@property (readonly, copy, nonatomic) NSSet *presentedIconLocations;


-(void)recycleIconView:(id)arg0 ;
-(void)iconListView:(id)arg0 springLoadedInteractionForIconDragDidCompleteOnIconView:(id)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 inLocations:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocations:(id)arg1 ;
-(void)iconListView:(id)arg0 iconDropSessionDidEnter:(id)arg1 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDragItem:(id)arg2 willAnimateDropWithAnimator:(id)arg3 ;
-(void)folderControllerWillOpen:(id)arg0 ;
-(Class)controllerClassForFolder:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 customSpringAnimationBehaviorForDroppingItem:(id)arg2 ;
-(void)iconListView:(id)arg0 iconDropSessionDidExit:(id)arg1 ;
-(void)folderController:(id)arg0 draggedIconShouldDropFromListView:(id)arg1 ;
-(id)dequeueReusableIconViewOfClass:(Class)arg0 ;
-(void)folderControllerWillBeginScrolling:(id)arg0 ;
-(BOOL)iconListView:(id)arg0 canHandleIconDropSession:(id)arg1 ;
-(void)folderControllerShouldEndEditing:(id)arg0 ;
-(void)folderControllerDidEndScrolling:(id)arg0 ;
-(void)enumerateDisplayedIconViewsUsingBlock:(id)arg0 ;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 shouldAllowSpringLoadedInteractionForIconDropSession:(id)arg2 onIconView:(id)arg3 ;
-(void)enumerateDisplayedIconViewsForIcon:(id)arg0 usingBlock:(id)arg1 ;
-(BOOL)isPresentingIconLocation:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 springLoadedInteractionForIconDragDidCompleteOnIconView:(id)arg2 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 willUseIconView:(id)arg2 forDroppingIconDragItem:(id)arg3 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 previewForDroppingIconDragItem:(id)arg2 proposedPreview:(id)arg3 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidExit:(id)arg2 ;
-(BOOL)wantsFastIconReordering;
-(BOOL)isDisplayingIconView:(id)arg0 inLocation:(id)arg1 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 ;
-(id)iconListView:(id)arg0 iconDropSessionDidUpdate:(id)arg1 ;
-(id)folderPresentationController:(id)arg0 animationControllerForTransitionWithFolder:(id)arg1 presenting:(BOOL)arg2 animated:(BOOL)arg3 ;
-(void)folderPresentationController:(id)arg0 willPerformTransitionWithFolder:(id)arg1 presenting:(BOOL)arg2 withTransitionCoordinator:(id)arg3 ;
-(CGFloat)minimumHomeScreenScaleForFolderPresentationController:(id)arg0 ;
-(id)folderPresentationController:(id)arg0 sourceViewForPresentingViewController:(id)arg1 ;
-(void)floatingDockViewMainPlatterDidChangeFrame:(id)arg0 ;
-(id)initWithIconManager:(id)arg0 iconViewProvider:(id)arg1 ;
-(id)borrowScalingView;
-(void)folderController:(id)arg0 iconListView:(id)arg1 performIconDrop:(id)arg2 ;
-(void)folderControllerShouldBeginEditing:(id)arg0 withHaptic:(BOOL)arg1 ;
-(BOOL)folderControllerShouldClose:(id)arg0 withPinchGesture:(id)arg1 ;
-(id)iconListView:(id)arg0 customSpringAnimationBehaviorForDroppingItem:(id)arg1 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidEnter:(id)arg2 ;
-(id)folderController:(id)arg0 accessibilityTintColorForScreenRect:(struct CGRect )arg1 ;
-(id)firstIconViewForIcon:(id)arg0 excludingLocations:(id)arg1 ;
-(BOOL)folderController:(id)arg0 canChangeCurrentPageIndexToIndex:(NSInteger)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 ;
-(void)returnScalingView;
-(id)iconListView:(id)arg0 previewForDroppingIconDragItem:(id)arg1 proposedPreview:(id)arg2 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 ;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 canHandleIconDropSession:(id)arg2 ;
-(void)_rebuildUserIconListView;
-(void)iconEditingDidChange:(id)arg0 ;
-(void)iconDraggingDidChange:(id)arg0 ;
-(void)reduceTransparencyEnabledStateDidChange:(id)arg0 ;
-(CGFloat)contentHeightForFrame:(struct CGRect )arg0 ;
-(id)userIconListView;
-(id)recentIconListView;
-(void)iconListView:(id)arg0 iconDragItem:(id)arg1 willAnimateDropWithAnimator:(id)arg2 ;
-(void)viewDidLoad;
-(void)folderControllerWillClose:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidUpdate:(id)arg2 ;
-(void)viewDidAppear:(BOOL)arg0 ;
-(void)iconListView:(id)arg0 willUseIconView:(id)arg1 forDroppingIconDragItem:(id)arg2 ;
-(BOOL)shouldAnimateFirstTwoViewsAsOne;
-(void)configureIconView:(id)arg0 forIcon:(id)arg1 ;
-(NSUInteger)_platterEffectForPresentedFolder;
-(BOOL)shouldIndicateImpossibleDrop;
-(void)_coalesceRequestsToResizeDockForChangedNumberOfIcons;
-(NSUInteger)_currentFolderIconBackgroundStyle;
-(void)_presentFolderForIcon:(id)arg0 location:(id)arg1 animated:(BOOL)arg2 completion:(id)arg3 ;
-(BOOL)_shouldOpenFolderIcon:(id)arg0 ;
-(BOOL)_isInAppToAppTransition;
-(void)iconListView:(id)arg0 iconDropSession:(id)arg1 didPauseAtLocation:(struct CGPoint )arg2 ;
-(id)targetIconContainerView;
-(BOOL)iconListView:(id)arg0 shouldAllowSpringLoadedInteractionForIconDropSession:(id)arg1 onIconView:(id)arg2 ;
-(void)dismissPresentedFolderAnimated:(BOOL)arg0 completion:(id)arg1 ;
-(void)folderControllerDidOpen:(id)arg0 ;
-(void)folderControllerDidClose:(id)arg0 ;
-(void)coronaAnimationController:(id)arg0 willAnimateCoronaTransitionWithAnimator:(id)arg1 ;
-(BOOL)shouldAnimateLastTwoViewsAsOne;
-(id)succinctDescriptionBuilder;
-(BOOL)isIconViewRecycled:(id)arg0 ;
-(void)viewDidDisappear:(BOOL)arg0 ;
-(void)viewDidLayoutSubviews;
-(void)enumerateIconListViewsUsingBlock:(id)arg0 ;
-(void)_sizeCategoryDidChange:(id)arg0 ;
-(void)iconList:(id)arg0 didAddIcon:(id)arg1 ;
-(BOOL)isDisplayingIconView:(id)arg0 ;
-(void)layoutUserControlledIconLists:(CGFloat)arg0 animationType:(NSInteger)arg1 forceRelayout:(BOOL)arg2 ;
-(void)enumerateIconListsUsingBlock:(id)arg0 ;
-(void)prepareForTransitionToStyleConfiguration:(id)arg0 fromDockVisible:(BOOL)arg1 toDockVisible:(BOOL)arg2 ;
-(void)cleanUpAfterUnderlyingBackgroundStyleTransition;
-(void)_addDockGestureRecognizer:(id)arg0 ;
-(void)_setPaddingEdgeInsets:(struct UIEdgeInsets )arg0 ;
-(void)floatingDockSuggestionsViewControllerDidChangeNumberOfVisibleSuggestions:(id)arg0 ;
-(void)presentFolderForIcon:(id)arg0 location:(id)arg1 animated:(BOOL)arg2 completion:(id)arg3 ;
-(BOOL)isTransitioningUnderlyingBackgroundStyle;
-(CGFloat)minimumVerticalMarginForFrame:(struct CGRect )arg0 ;
-(void)enumerateVisibleIconViewsUsingBlock:(id)arg0 ;
-(id)userIconLocation;
-(id)suggestionsIconLocation;
-(void)_updateDockForStyleConfiguration:(id)arg0 ;
-(void)_resizeDockForChangedNumberOfIconsAnimated:(BOOL)arg0 ;
-(void)_updateFolderIconBackgroundsForStyleConfiguration:(id)arg0 ;
-(void)_updatePresentedFolderBackgroundForStyleConfiguration:(id)arg0 ;
-(void)_updatePlatterShadowForStyleConfiguration:(id)arg0 ;
-(NSUInteger)_backgroundEffectForPresentedFolder;
-(void)_rebuildAfterIconModelChange;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)succinctDescription;
-(void)iconModelDidLayout:(id)arg0 ;
-(void)iconManagerDidChangeIconModel:(id)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)folderController:(id)arg0 didBeginEditingTitle:(id)arg1 ;
-(void)iconList:(id)arg0 didRemoveIcon:(id)arg1 ;
-(void)dealloc;
-(void)folderController:(id)arg0 didEndEditingTitle:(id)arg1 ;


@end


#endif


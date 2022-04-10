// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBHLIBRARYVIEWCONTROLLER_H
#define SBHLIBRARYVIEWCONTROLLER_H


@class BSEventQueue;
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SBNestingViewController;
@class SBFolderIconImageCache;
@class SBHLibraryCategoryMap;
@class _SBHLibraryCollectionOfModelThings;
@class SBHLibraryCategoriesRootFolder;
@class SBHomeScreenIconTransitionAnimator;
@class SBHSearchTextField;
@class SBHLibrarySearchController;
@class SBHIconLibraryTableViewController;
@class SBHLibraryPodFolderController;
@class SBRootFolder;
@class SBHLibraryCategoryMapProvider;
@class SBHIconModel;
@class SBHIconImageCache;
@class SBFolderController;
@protocol UISearchBarDelegate;
@protocol SBHLibrarySearchControllerDelegate;
@protocol SBHLibraryCategoryMapProviderObserver;
@protocol SBHIconLibraryTableViewControllerObserver;
@protocol SBIconViewProviding;
@protocol SBIconViewDelegate;
@protocol SBNestingViewControllerDelegate;
@protocol SBHLibraryPodFolderControllerDelegate;
@protocol SBFolderControllerDelegate;
@protocol SBHLibraryProvider;
@protocol SBHOccludable;
@protocol SBFOverlayObserving;
@protocol SBIconViewDelegate;
@protocol SBIconViewProviding;
@protocol SBIconListLayoutProvider;
@protocol SBHomeScreenIconTransitionAnimatorDelegate;

@interface SBHLibraryViewController : SBNestingViewController <UISearchBarDelegate, SBHLibrarySearchControllerDelegate, SBHLibraryCategoryMapProviderObserver, SBHIconLibraryTableViewControllerObserver, SBIconViewProviding, SBIconViewDelegate, SBNestingViewControllerDelegate, SBHLibraryPodFolderControllerDelegate, SBFolderControllerDelegate, SBHLibraryProvider, SBHOccludable, SBFOverlayObserving>

{
NSArray *_containerViewControllerConstraints;
NSMapTable *_iconViewControllerForCategoryIdentifier;
SBFolderIconImageCache *_folderIconImageCache;
SBHLibraryCategoryMap *_pendingLibraryCategoryMap;
_SBHLibraryCollectionOfModelThings *_model;
SBHLibraryCategoriesRootFolder *_categoriesFolder;
NSTimer *_searchControllerAppLaunchResetTimer;
NSTimer *_libraryViewControllerDismissalTimer;
NSHashTable *_observers;
NSMapTable *_presentedFolderControllers;
NSMapTable *_dismissingFolderControllers;
}


@property (readonly, nonatomic) SBFolderIconImageCache *folderIconImageCache;
@property (readonly, nonatomic) BSEventQueue *transitionEventQueue; // ivar: _transitionEventQueue
@property (retain, nonatomic) SBHomeScreenIconTransitionAnimator *currentTransitionAnimator; // ivar: _currentTransitionAnimator
@property (retain, nonatomic) NSMutableArray *currentExpandCompletions; // ivar: _currentExpandCompletions
@property (retain, nonatomic) NSMutableArray *currentCollapseCompletions; // ivar: _currentCollapseCompletions
@property (readonly, nonatomic) SBHSearchTextField *searchTextField; // ivar: _searchTextField
@property (readonly, nonatomic) SBHLibrarySearchController *containerViewController; // ivar: _containerViewController
@property (readonly, nonatomic) SBHIconLibraryTableViewController *iconTableViewController; // ivar: _iconTableViewController
@property (readonly, nonatomic) SBHLibraryPodFolderController *podFolderViewController; // ivar: _podFolderViewController
@property (readonly, nonatomic) SBRootFolder *categoriesRootFolder;
@property (readonly, nonatomic) SBHLibraryCategoryMap *libraryCategoryMap; // ivar: _libraryCategoryMap
@property (weak, nonatomic) NSObject<SBIconViewDelegate> *iconViewDelegate; // ivar: _iconViewDelegate
@property (readonly, nonatomic) SBHLibraryCategoryMapProvider *categoryMapProvider; // ivar: _categoryMapProvider
@property (readonly, nonatomic) BOOL presentingFolder;
@property (readonly, nonatomic) BOOL presentingSearch;
@property (nonatomic) BOOL allowsBadging; // ivar: _allowsBadging
@property (nonatomic) BOOL suppressesEditingStateForListViews; // ivar: _suppressesEditingStateForListViews
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (retain, nonatomic) SBHIconModel *iconModel; // ivar: _iconModel
@property (weak, nonatomic) NSObject<SBIconViewProviding> *iconViewProvider; // ivar: _iconViewProvider
@property (weak, nonatomic) NSObject<SBIconListLayoutProvider> *listLayoutProvider; // ivar: _listLayoutProvider
@property (retain, nonatomic) SBHIconImageCache *iconImageCache; // ivar: _iconImageCache
@property (weak, nonatomic) NSObject<SBHomeScreenIconTransitionAnimatorDelegate> *homeScreenIconTransitionAnimatorDelegate; // ivar: _homeScreenIconTransitionAnimatorDelegate
@property (readonly, nonatomic) SBFolderController *folderController;
@property (retain, nonatomic) UIView *searchDimmingView;
@property (readonly, copy, nonatomic) NSSet *presentedIconLocations;
@property (nonatomic) BOOL occluded; // ivar: _occluded


-(void)willDismissSearchController:(id)arg0 ;
-(void)nestingViewController:(id)arg0 willPerformOperation:(NSInteger)arg1 onViewController:(id)arg2 withTransitionCoordinator:(id)arg3 ;
-(void)recycleIconView:(id)arg0 ;
-(void)iconViewWasRecycled:(id)arg0 ;
-(id)firstIconViewForIcon:(id)arg0 inLocations:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocations:(id)arg1 ;
-(void)didDismissSearchController:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDragItem:(id)arg2 willAnimateDropWithAnimator:(id)arg3 ;
-(void)willPresentSearchController:(id)arg0 ;
-(Class)controllerClassForFolder:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 customSpringAnimationBehaviorForDroppingItem:(id)arg2 ;
-(void)folderController:(id)arg0 draggedIconShouldDropFromListView:(id)arg1 ;
-(void)iconTapped:(id)arg0 ;
-(id)dequeueReusableIconViewOfClass:(Class)arg0 ;
-(void)_updateEditingStateAnimated:(BOOL)arg0 ;
-(void)folderControllerWillBeginScrolling:(id)arg0 ;
-(void)folderControllerShouldEndEditing:(id)arg0 ;
-(BOOL)iconShouldAllowTap:(id)arg0 ;
-(void)noteIconViewWillZoomDown:(id)arg0 ;
-(void)folderControllerDidEndScrolling:(id)arg0 ;
-(void)enumerateDisplayedIconViewsUsingBlock:(id)arg0 ;
-(id)shortcutsDelegateForIconView:(id)arg0 ;
-(NSInteger)iconViewComponentBackgroundViewTypeForIconView:(id)arg0 ;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 shouldAllowSpringLoadedInteractionForIconDropSession:(id)arg2 onIconView:(id)arg3 ;
-(void)enumerateDisplayedIconViewsForIcon:(id)arg0 usingBlock:(id)arg1 ;
-(BOOL)isPresentingIconLocation:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 springLoadedInteractionForIconDragDidCompleteOnIconView:(id)arg2 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 options:(NSUInteger)arg2 ;
-(void)layoutIconLists:(CGFloat)arg0 animationType:(NSInteger)arg1 forceRelayout:(BOOL)arg2 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 willUseIconView:(id)arg2 forDroppingIconDragItem:(id)arg3 ;
-(id)customImageViewControllerForIconView:(id)arg0 ;
-(void)addObserver:(id)arg0 ;
-(BOOL)iconView:(id)arg0 canAddDragItemsToSession:(id)arg1 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 previewForDroppingIconDragItem:(id)arg2 proposedPreview:(id)arg3 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidExit:(id)arg2 ;
-(BOOL)isDisplayingIconView:(id)arg0 inLocation:(id)arg1 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 ;
-(BOOL)iconShouldAllowCloseBoxTap:(id)arg0 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 performIconDrop:(id)arg2 ;
-(void)folderController:(id)arg0 willUseIconTransitionAnimator:(id)arg1 forOperation:(NSInteger)arg2 onViewController:(id)arg3 animated:(BOOL)arg4 ;
-(void)folderControllerShouldBeginEditing:(id)arg0 withHaptic:(BOOL)arg1 ;
-(id)draggingDelegateForIconView:(id)arg0 ;
-(BOOL)folderControllerShouldClose:(id)arg0 withPinchGesture:(id)arg1 ;
-(void)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidEnter:(id)arg2 ;
-(id)firstIconViewForIcon:(id)arg0 excludingLocations:(id)arg1 ;
-(BOOL)folderController:(id)arg0 canChangeCurrentPageIndexToIndex:(NSInteger)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 ;
-(void)_invalidateLibraryViewControllerDismissalTimer;
-(void)_rebuildIconCache;
-(void)_scrollIconViewToVisible:(id)arg0 animated:(BOOL)arg1 ;
-(void)_notifyObserversRequestDismissal;
-(id)_wrappedCompletionBlockForNestedTransitionWithCompletion:(SEL)arg0 ;
-(void)_notifyObserversWillPresentFolderController:(id)arg0 ;
-(void)_notifyObserversWillDismissFolderController:(id)arg0 ;
-(void)_notifyObserversDidDismissFolderController:(id)arg0 ;
-(void)_notifyObserversOfAppLaunchOfIcon:(id)arg0 fromLocation:(id)arg1 ;
-(id)_iconViewControllerForCategoryIdentifier:(id)arg0 ;
-(void)_startLibraryViewControllerDismissalTimer:(id)arg0 ;
-(void)dismissSearch;
-(void)_updateViewControllerLegibility:(id)arg0 legibilitySettings:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 ;
-(BOOL)folderController:(id)arg0 iconListView:(id)arg1 canHandleIconDropSession:(id)arg2 ;
-(void)libraryCategoryMapProvider:(id)arg0 categoryMapWasRefreshed:(NSUInteger)arg1 libraryCategoryMap:(id)arg2 ;
-(void)viewDidLoad;
-(id)overrideTraitCollectionForChildViewController:(id)arg0 ;
-(void)enumerateIconViewQueryableChildrenUsingBlock:(id)arg0 ;
-(id)folderController:(id)arg0 iconListView:(id)arg1 iconDropSessionDidUpdate:(id)arg2 ;
-(BOOL)iconView:(id)arg0 editingModeGestureRecognizerDidFire:(id)arg1 ;
-(BOOL)suppressesEditingStateForListViews;
-(void)libraryPodFolderControllerRequestsDismissal:(id)arg0 ;
-(BOOL)iconViewDisplaysBadges:(id)arg0 ;
-(void)enumerateViewControllersUsingBlock:(id)arg0 ;
-(id)firstNonSuggestionsOrRecentsIconViewForIcon:(id)arg0 ;
-(void)libraryTableViewControllerDidAppear:(id)arg0 ;
-(void)libraryTableViewControllerWillDisappear:(id)arg0 ;
-(void)libraryTableViewControllerDidLaunchIcon:(id)arg0 ;
-(void)forcedSearchTextFieldNoneditable:(BOOL)arg0 ;
-(void)noteInstalledApplicationsDidChange;
-(void)viewDidAppear:(BOOL)arg0 ;
-(id)nestingViewController:(id)arg0 animationControllerForOperation:(NSInteger)arg1 onViewController:(id)arg2 animated:(BOOL)arg3 ;
-(void)_enumerateObservers:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 options:(NSUInteger)arg2 ;
-(BOOL)isDisplayingIcon:(id)arg0 options:(NSUInteger)arg1 ;
-(void)configureIconView:(id)arg0 forIcon:(id)arg1 ;
-(void)pushNestedViewController:(id)arg0 animated:(BOOL)arg1 withCompletion:(id)arg2 ;
-(void)popNestedViewControllerAnimated:(BOOL)arg0 withCompletion:(id)arg1 ;
-(BOOL)isIconViewRecycled:(id)arg0 ;
-(void)viewWillAppear:(BOOL)arg0 ;
-(void)removeObserver:(id)arg0 ;
-(void)overlayController:(id)arg0 visibilityDidChange:(BOOL)arg1 ;
-(void)viewDidDisappear:(BOOL)arg0 ;
-(void)viewDidLayoutSubviews;
-(NSInteger)closeBoxTypeForIconView:(id)arg0 ;
-(BOOL)isDisplayingIconView:(id)arg0 ;
-(void)enumerateIconViewQueryableChildrenWithOptions:(NSUInteger)arg0 usingBlock:(id)arg1 ;
-(BOOL)iconViewDisplaysCloseBox:(id)arg0 ;
-(BOOL)isDisplayingIconView:(id)arg0 options:(NSUInteger)arg1 ;
-(BOOL)iconViewShouldBeginShortcutsPresentation:(id)arg0 ;
-(void)_setupIconTableViewController:(BOOL)arg0 ;
-(id)initWithCategoryMapProvider:(id)arg0 ;
-(void)invalidateSearchControllerAppLaunchResetTimer;
-(void)_enqueueAppLibraryUpdate;
-(void)_notifyObserversWillPresent;
-(void)_notifyObserversDidPresent;
-(void)_notifyObserversWillDismiss;
-(void)_dismissExpandedPodsIfNecessary;
-(void)_flushPendingLibraryCategoryMapUpdateIfNeeded;
-(void)_notifyObserversDidDismiss;
-(void)_updateViewControllerLegibility:(id)arg0 ;
-(id)iconView:(id)arg0 labelImageWithParameters:(id)arg1 ;
-(id)init;
-(id)firstIconViewForIcon:(id)arg0 options:(NSUInteger)arg1 ;
-(void)loadView;
-(void)iconCloseBoxTapped:(id)arg0 ;
-(void)iconModelDidLayout:(id)arg0 ;
-(void)overlayControllerDidBeginChangingPresentationProgress:(id)arg0 ;
-(void)setEditing:(BOOL)arg0 animated:(BOOL)arg1 ;
-(BOOL)allowsBadging;
-(void)_updateLibraryCategoryMap:(id)arg0 ;
-(void)_notifyObserversWillPresentSearchController:(id)arg0 ;
-(void)_notifyObserversDidPresentSearchController:(id)arg0 ;
-(void)_notifyObserversWillDismissSearchController:(id)arg0 ;
-(void)_notifyObserversDidDismissSearchController:(id)arg0 ;
-(id)_additionalItemsIndicatorIconViewForFolderController:(id)arg0 ;
-(void)_precacheIconViewControllersForCategories:(id)arg0 ;
-(void)_startAppLaunchResetTimer:(id)arg0 ;
-(void)_dismissLibraryViewControllerForReason:(id)arg0 sessionIdentifier:(id)arg1 ;
-(void)_dismissSearchIfNotInUseForReason:(id)arg0 sessionIdentifier:(id)arg1 ;
-(id)_iconIdentifierForDragItem:(id)arg0 ;
-(id)contentScrollView;
-(void)overlayController:(id)arg0 didChangePresentationProgress:(CGFloat)arg1 newPresentationProgress:(CGFloat)arg2 fromLeading:(BOOL)arg3 ;
-(void)viewSafeAreaInsetsDidChange;
-(void)viewWillDisappear:(BOOL)arg0 ;
-(void)dealloc;
-(void)didPresentSearchController:(id)arg0 ;
+(id)_updateCategoryMap:(id)arg0 withCategoryDataFrom:(id)arg1 ;


@end


#endif


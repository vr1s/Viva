// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBHLIBRARYPODFOLDERCONTROLLER_H
#define SBHLIBRARYPODFOLDERCONTROLLER_H

@class ATXAppDirectoryClient;

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

#include "SBFolderController.h"
@class SBHLibraryCategoryMap;
@class SBHLibraryCategoriesFolderDataSource;
@class SBHIconImageCache;
@class SBFolderIconImageCache;
@class SBRootFolder;
@class SBHIconModel;
@class SBIconListView;
@protocol SBHLibraryCategoriesFolderDataSourceDelegate;
@protocol UIGestureRecognizerDelegate;
@protocol SBHLibraryChildViewController;
@protocol SBHLibraryPodIconZoomAnimationContaining;
@protocol SBHLibrarySearchControllerContentViewControllerScrollViewProvider;
@protocol SBHLibraryPodFolderControllerDelegate;
@protocol SBIconListLayoutProvider;
@protocol BSUIScrollViewDelegate;

@interface SBHLibraryPodFolderController : SBFolderController <SBHLibraryCategoriesFolderDataSourceDelegate, UIGestureRecognizerDelegate, SBHLibraryChildViewController, SBHLibraryPodIconZoomAnimationContaining, SBHLibrarySearchControllerContentViewControllerScrollViewProvider>



@property (readonly, nonatomic) UITapGestureRecognizer *tapToDismissRecognizer; // ivar: _tapToDismissRecognizer
@property (readonly, nonatomic) ATXAppDirectoryClient *loggingClient; // ivar: _loggingClient
@property (retain, nonatomic) SBHLibraryCategoryMap *libraryCategoryMap; // ivar: _libraryCategoryMap
@property (readonly, nonatomic) SBHLibraryCategoriesFolderDataSource *dataSource; // ivar: _dataSource
@property (weak, nonatomic) NSObject<SBHLibraryPodFolderControllerDelegate> *podFolderControllerDelegate; // ivar: _podFolderControllerDelegate
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (retain, nonatomic) SBHIconImageCache *iconImageCache; // ivar: _iconImageCache
@property (retain, nonatomic) NSObject<SBIconListLayoutProvider> *listLayoutProvider; // ivar: _listLayoutProvider
@property (retain, nonatomic) SBFolderIconImageCache *folderIconImageCache;
@property (retain, nonatomic) SBRootFolder *rootFolder;
@property (readonly, copy, nonatomic) NSSet *presentedIconLocations;
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
@property (weak, nonatomic) NSObject<BSUIScrollViewDelegate> *librarySearchControllerScrollViewDelegate;


-(id)firstIconViewForIcon:(id)arg0 inLocations:(id)arg1 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocations:(id)arg1 ;
-(void)iconListView:(id)arg0 didAddIconView:(id)arg1 ;
-(Class)controllerClassForFolder:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 ;
-(void)enumerateDisplayedIconViewsUsingBlock:(id)arg0 ;
-(void)enumerateDisplayedIconViewsForIcon:(id)arg0 usingBlock:(id)arg1 ;
-(BOOL)isPresentingIconLocation:(id)arg0 ;
-(BOOL)isDisplayingIconView:(id)arg0 inLocation:(id)arg1 ;
-(id)iconViewForIcon:(id)arg0 location:(id)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 excludingLocations:(id)arg1 ;
-(id)firstIconViewForIcon:(id)arg0 ;
-(BOOL)isDisplayingIcon:(id)arg0 inLocation:(id)arg1 ;
-(void)viewDidLoad;
-(void)setContentAlpha:(CGFloat)arg0 ;
-(id)podFolderView;
-(void)_reloadAppIcons;
-(BOOL)_ourFolderContainsFolder:(id)arg0 ;
-(id)_nestingViewControllerForPushing;
-(void)enumerateViewControllersUsingBlock:(id)arg0 ;
-(void)enumerateNonSuggestionsOrRecentsViewControllersUsingBlock:(id)arg0 ;
-(void)categoriesDataSource:(id)arg0 shouldAnimateLayoutForCategories:(id)arg1 ;
-(void)categoriesDataSourceNeedsAnimatedReload:(id)arg0 ;
-(id)firstNonSuggestionsOrRecentsIconViewForIcon:(id)arg0 ;
-(BOOL)shouldOpenFolderIcon:(id)arg0 ;
-(void)configureInnerFolderControllerConfiguration:(id)arg0 ;
-(void)pushNestedViewController:(id)arg0 animated:(BOOL)arg1 withCompletion:(id)arg2 ;
-(BOOL)_isViewControllerVisible;
-(void)viewWillAppear:(BOOL)arg0 ;
-(void)iconListView:(id)arg0 didRemoveIconView:(id)arg1 ;
-(id)initWithConfiguration:(id)arg0 ;
-(BOOL)isDisplayingIconView:(id)arg0 ;
-(BOOL)isOpen;
-(BOOL)gestureRecognizer:(id)arg0 shouldReceiveTouch:(id)arg1 ;
-(void)iconViewDidHandleTap:(id)arg0 ;
-(id)contentScrollView;
+(Class)configurationClass;
+(id)iconLocation;
+(Class)_contentViewClass;


@end


#endif


// Headers generated with ktool v0.19.3
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBHICONMODEL_H
#define SBHICONMODEL_H


#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

#include "SBIconListGridLayoutConfiguration.h"

@class SBRootFolder, SBIcon;

@interface SBHIconModel : NSObject

@property (nonatomic) BOOL allowsDownloadingIcons; // ivar: _allowsDownloadingIcons
@property (copy, nonatomic) NSSet *archivedLeafIdentifiers; // ivar: _archivedLeafIdentifiers
@property (retain, nonatomic) NSTimer *autosaveTimer; // ivar: _autosaveTimer
@property (nonatomic) BOOL checkingModelConsistency; // ivar: _checkingModelConsistency
@property (readonly, copy, nonatomic) NSSet *currentLeafIdentifiers;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy, nonatomic) NSDictionary *defaultIconState;
@property (weak, nonatomic) id delegate; // ivar: _delegate
@property (readonly, copy) NSString *description;
@property (copy, nonatomic) NSDictionary *desiredIconState; // ivar: _desiredIconState
@property (copy, nonatomic) NSOrderedSet *desiredIconStateFlattened; // ivar: _desiredIconStateFlattened
@property (readonly, copy, nonatomic) NSSet *firstPageLeafIdentifiers;
@property (readonly, nonatomic) SBHIconGridSizeClassSizes gridSizeClassSizes;
@property (readonly, nonatomic) BOOL hasDesiredIconState;
@property (readonly) NSUInteger hash;
@property (readonly, copy, nonatomic) NSSet *hiddenIconTags; // ivar: _hiddenIconTags
@property (nonatomic) BOOL iconStateDirty; // ivar: _iconStateDirty
@property (nonatomic) BOOL ignoresIconsNotInIconState; // ivar: _ignoresIconsNotInIconState
@property (nonatomic) BOOL layingOut; // ivar: _layingOut
@property (readonly, copy, nonatomic) NSSet *leafIconIdentifiers;
@property (readonly, copy, nonatomic) NSSet *leafIcons;
@property (readonly, copy, nonatomic) NSString *localizedDefaultFolderName;
@property (readonly, nonatomic) NSUInteger maxIconCountForDock;
@property (readonly, nonatomic) NSUInteger maxListCountForFolders;
@property (readonly, copy, nonatomic) NSSet *missingDesiredIconIdentifiers;
@property (nonatomic) BOOL restoring; // ivar: _restoring
@property (readonly, nonatomic) SBRootFolder *rootFolder; // ivar: _rootFolder
@property (retain, nonatomic) SBIcon *rootFolderIcon; // ivar: _rootFolderIcon
@property (nonatomic) BOOL sortsIconsAlphabetically; // ivar: _sortsIconsAlphabetically
@property (retain, nonatomic) id store; // ivar: _store
@property (readonly) Class superclass;
@property (readonly, nonatomic) BOOL supportsDock;
@property (retain, nonatomic) id todayListsStore; // ivar: _todayListsStore
@property (readonly, copy, nonatomic) NSString *unlocalizedDefaultFolderName;
@property (readonly, copy, nonatomic) NSSet *visibleIconIdentifiers;
@property (readonly, copy, nonatomic) NSSet *visibleIconTags; // ivar: _visibleIconTags


+(id)migratedIdentifierForLeafIdentifier:(id)arg0 ;
-(BOOL)_canAddDownloadingIconForBundleID:(id)arg0 ;
// -(BOOL)_saveIconStateWithError:(*NSObject)arg0 ;
-(BOOL)_shouldSkipAddingIcon:(id)arg0 toRootFolder:(id)arg1 ;
-(BOOL)allowsDownloadingIcons;
-(BOOL)deleteIconState;
-(BOOL)deleteIconStateWithOptions:(NSUInteger)arg0 ;
-(BOOL)hasDesiredIconState;
-(BOOL)ignoresIconsNotInIconState;
-(BOOL)isIconVisible:(id)arg0 ;
-(BOOL)isTrackingIcon:(id)arg0 ;
-(BOOL)saveIconStateIfNeeded;
-(BOOL)shouldAvoidPlacingIconOnFirstPage:(id)arg0 ;
-(BOOL)shouldPlaceIconOnIgnoredList:(id)arg0 ;
-(BOOL)supportsDock;
-(NSUInteger)maxColumnCountForListInRootFolderWithInterfaceOrientation:(NSInteger)arg0 ;
-(NSUInteger)maxRowCountForListInRootFolderWithInterfaceOrientation:(NSInteger)arg0 ;
-(id)_adjustedDesiredIndexPathInRootFolder:(id)arg0 forIconWithIdentifier:(id)arg1 ;
-(id)_adjustedIndexPathInRootFolder:(id)arg0 withinIconState:(id)arg1 forIconWithIdentifier:(id)arg2 ;
-(id)_adjustedPlatformIndexPathInRootFolder:(id)arg0 forIcon:(id)arg1 ;
-(id)_iconState;
-(id)_unarchiveRootFolder;
-(id)addDownloadingIconForBundleID:(id)arg0 withIdentifier:(id)arg1 ;
-(id)addDownloadingIconWithDataSource:(id)arg0 ;
-(id)desiredFolderCreationActionsForInsertingNewIcon:(id)arg0 ;
-(id)desiredIndexPathForIconWithIdentifier:(id)arg0 ;
-(id)disableIconStateAutosaveForReason:(id)arg0 ;
-(id)downloadingIconForBundleIdentifier:(id)arg0 ;
-(id)iconModelMetadata;
-(id)iconState;
-(id)iconsOfClass:(Class)arg0 ;
// -(id)indexPathInRootFolder:(id)arg0 forNewIcon:(id)arg1 isDesignatedLocation:(*BOOL)arg2
        // replaceExistingIconAtIndexPath:(*id)arg3 ;
-(id)init;
-(id)initWithStore:(id)arg0 ;
-(id)leafIconForIdentifier:(id)arg0 ;
-(id)leafIconsForIdentifiers:(id)arg0 ;
-(id)localizedFolderNameForDefaultDisplayName:(id)arg0 ;
-(id)makeFolderWithDisplayName:(id)arg0 ;
-(id)makeFolderWithDisplayName:(id)arg0 uniqueIdentifier:(id)arg1 ;
-(id)modernizeRootArchive:(id)arg0 ;
-(id)widgetIcons;
-(id)widgetIconsContainingWidgetsMatchingExtensionBundleIdentifier:(id)arg0 kind:(id)arg1 sizeClass:(NSInteger)arg2 ;
-(id)widgetIconsContainingWidgetsMatchingUniqueIdentifier:(id)arg0 ;
-(struct SBHIconGridSize )listGridSizeForFolderClass:(Class)arg0 ;
-(void)_removeIconStateAutosaveDisableAssertion:(id)arg0 ;
-(void)_rootFolder:(id)arg0 moveIconsToFirstPage:(id)arg1 placeBumpedIconsSomewhereNice:(id)arg2 ;
-(void)_saveIconState;
-(void)addIcon:(id)arg0 ;
-(void)addIconsOfClass:(Class)arg0 toSet:(id)arg1 ;
-(void)adjustIconsToShow:(id)arg0 iconsToHide:(id)arg1 afterChangeToVisibleIconTags:(id)arg2 hiddenIconTags:(id)arg3 ;
-(void)autosaveTimerDidFire:(id)arg0 ;
-(void)checkModelConsistency;
-(void)checkModelConsistencyInRootFolder:(id)arg0 ;
-(void)clearDesiredIconState;
-(void)clearDesiredIconStateIfPossible;
-(void)clearDesiredIconStateWithOptions:(NSUInteger)arg0 ;
-(void)didAddIcon:(id)arg0 ;
-(void)didUnarchiveMetadata:(id)arg0 ;
-(void)enumerateDownloadingIconsUsingBlock:(id)arg0 ;
-(void)enumerateLeafIconsUsingBlock:(id)arg0 ;
-(void)folder:(id)arg0 didAddIcons:(id)arg1 removedIcons:(id)arg2 ;
-(void)folder:(id)arg0 didAddList:(id)arg1 ;
-(void)folder:(id)arg0 didReplaceIcon:(id)arg1 withIcon:(id)arg2 ;
-(void)folder:(id)arg0 willAddIcon:(id)arg1 ;
-(void)folderIconStateDidDirty:(id)arg0 ;
-(void)icon:(id)arg0 launchFromLocation:(id)arg1 context:(id)arg2 ;
-(void)iconArchivableStateDidChange:(id)arg0 ;
-(void)importDesiredIconState:(id)arg0 ;
-(void)layout;
-(void)layoutIfNeeded;
-(void)loadAllIcons;
-(void)markIconStateClean;
-(void)markIconStateDirty;
-(void)reloadIcons;
-(void)removeAllIcons;
-(void)removeIcon:(id)arg0 ;
-(void)removeIconForIdentifier:(id)arg0 ;
-(void)removeIcons:(id)arg0 ;
-(void)saveDesiredIconState;
-(void)scheduleIconStateAutosave;
-(void)setForecastedLeavesOnIconModel:(id)arg0 includingMissingIcons:(id)arg1 ;
-(void)setLeafIconsByIdentifier:(id)arg0 ;
-(void)setVisibilityOfIconsWithVisibleTags:(id)arg0 hiddenTags:(id)arg1 ;
-(void)willLayout;


@end


#endif
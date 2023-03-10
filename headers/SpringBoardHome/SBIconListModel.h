// Headers generated with ktool v0.19.3
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBICONLISTMODEL_H
#define SBICONLISTMODEL_H


#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

#import "SBIconListGridLayoutConfiguration.h"

@class SBIconIndexMutableList;
@class SBIcon;
@class SBFolder;

@interface SBIconListModel : NSObject

@property (readonly, nonatomic) NSArray *children;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly, nonatomic) SBIcon *firstIcon;
@property (readonly, weak, nonatomic) SBFolder *folder; // ivar: _folder
@property (readonly, nonatomic) SBHIconGridSize gridSize; // ivar: _gridSize
@property (readonly) NSUInteger hash;
@property (nonatomic) BOOL hidden;
@property (copy, nonatomic) NSDate *hiddenDate; // ivar: _hiddenDate
@property (readonly, nonatomic) SBHIconGridSizeClassSizes iconGridSizeClassSizes; // ivar: _gridSizeClassSizes
@property (weak, nonatomic) id iconValidator; // ivar: _iconValidator
@property (copy, nonatomic) NSArray *icons;
@property (readonly, nonatomic) SBIcon *lastIcon;
@property (readonly, copy, nonatomic) NSString *layoutDescription;
@property (readonly, nonatomic) NSUInteger maxNumberOfIcons;
@property (readonly, nonatomic) NSUInteger numberOfIcons;
@property (readonly, nonatomic) NSUInteger numberOfNonPlaceholderIcons;
@property (readonly, nonatomic) NSUInteger numberOfUsedColumns;
@property (readonly, nonatomic) NSUInteger numberOfUsedRows;
@property (readonly, nonatomic) NSUInteger numberOfUsedSlots;
@property (nonatomic) NSUInteger overflowSlotCount; // ivar: _overflowSlotCount
@property (weak, nonatomic) id parent; // ivar: _parent
@property (readonly) Class superclass;
@property (readonly, copy, nonatomic) NSString *uniqueIdentifier; // ivar: _uniqueIdentifier


+(id)iconGridCellInfoForIcons:(id)arg0 gridSize:(struct SBHIconGridSize )arg1 gridSizeClassSizes:(struct SBHIconGridSizeClassSizes )arg2 options:(NSUInteger)arg3 ;
+(id)movedIconsWithOriginalOrder:(id)arg0 newOrder:(id)arg1 ;
-(BOOL)addIcon:(id)arg0 ;
-(BOOL)addIcon:(id)arg0 asDirty:(BOOL)arg1 ;
-(BOOL)allowsAddingIcon:(id)arg0 ;
-(BOOL)allowsAddingIcon:(id)arg0 ignoringPlaceholders:(BOOL)arg1 ;
-(BOOL)allowsAddingIcons:(id)arg0 ;
-(BOOL)allowsAddingIcons:(id)arg0 ignoringPlaceholders:(BOOL)arg1 ;
-(BOOL)canBounceIcon:(id)arg0 ;
-(BOOL)containsNodeIdentifier:(id)arg0 ;
-(BOOL)directlyContainsIcon:(id)arg0 ;
-(BOOL)directlyContainsIconWithIdentifier:(id)arg0 ;
-(BOOL)directlyContainsLeafIconWithIdentifier:(id)arg0 ;
-(BOOL)getIconGridRange:(struct SBHIconGridRange *)arg0 forGridCellIndex:(NSUInteger)arg1 gridCellInfo:(id)arg2 ;
-(BOOL)isAllowedToContainIcon:(id)arg0 ;
-(BOOL)isAllowedToContainIcons:(id)arg0 ;
-(BOOL)isEmpty;
-(BOOL)isEmptyIgnoringPlaceholders;
-(BOOL)isFull;
-(BOOL)isFullIncludingPlaceholders;
-(BOOL)isGridLayoutValid;
-(BOOL)isIconStateDirty;
-(NSInteger)_moveIcon:(id)arg0 byClusteringForSizeClass:(NSUInteger)arg1 toGridCellIndex:(NSUInteger)arg2 gridCellInfoOptions:(NSUInteger)arg3 ;
-(NSUInteger)_iconIndexForMovingIcon:(id)arg0 toGridCellIndex:(NSUInteger)arg1 gridCellInfo:(id)arg2 ;
-(NSUInteger)bestGridCellIndexForInsertingIcon:(id)arg0 atGridCellIndex:(NSUInteger)arg1 ;
// -(NSUInteger)countByEnumeratingWithState:(struct ? *)arg0 objects:(*id)arg1 count:(NSUInteger)arg2 ;
-(NSUInteger)firstFreeSlotIndex;
-(NSUInteger)indexForIcon:(id)arg0 ;
-(NSUInteger)numberOfFreeSlots;
-(NSUInteger)removeIconFromOtherPositionsInHierarchy:(id)arg0 forInsertingAtIndex:(NSUInteger)arg1 ;
-(NSUInteger)willAddIcon:(id)arg0 atIndex:(NSUInteger)arg1 ;
-(id)_checkAndRemoveBouncedIconsAvoidingIcons:(id)arg0 ignoringTrailingIconCheck:(BOOL)arg1 ;
-(id)_clusterIconsForSizeClass:(NSUInteger)arg0 gridCellInfoOptions:(NSUInteger)arg1 ;
-(id)_iconAtIndex:(NSUInteger)arg0 ;
-(id)_updateModelByRepairingGapsIfNecessary;
-(id)addIcons:(id)arg0 ;
-(id)allowedIconsForByReplacingContentsWithIcons:(id)arg0 ;
-(id)allowedIconsForIcons:(id)arg0 ;
-(id)allowedIconsForIcons:(id)arg0 ignoringPlaceholders:(BOOL)arg1 ;
-(id)changeGridSizeClassOfContainedIcon:(id)arg0 toGridSizeClass:(NSUInteger)arg1 gridCellInfo:(id)arg2 ;
-(id)containedNodeIdentifiers;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)directlyContainedIconPassingTest:(id)arg0 ;
-(id)directlyContainedIconWithIdentifier:(id)arg0 ;
-(id)gridCellInfoForGridSize:(struct SBHIconGridSize )arg0 options:(NSUInteger)arg1 ;
-(id)gridCellInfoWithOptions:(NSUInteger)arg0 ;
-(id)iconAtIndex:(NSUInteger)arg0 ;
// -(id)iconGridCellInfoBySimulatingInsertionOfIcons:(id)arg0 ignoringPlaceholders:(BOOL)arg1 iconOrder:(*id)arg2 ;
-(id)iconsAtGridCellIndexes:(id)arg0 gridCellInfo:(id)arg1 ;
-(id)iconsAtIndexes:(id)arg0 ;
-(id)iconsForGridRange:(struct SBHIconGridRange )arg0 gridCellInfo:(id)arg1 ;
-(id)iconsInGridColumn:(NSUInteger)arg0 gridCellInfo:(id)arg1 ;
-(id)iconsInGridColumnRange:(struct _NSRange )arg0 gridCellInfo:(id)arg1 ;
-(id)iconsInGridRow:(NSUInteger)arg0 gridCellInfo:(id)arg1 ;
-(id)iconsOfClass:(Class)arg0 ;
-(id)iconsThatAreAllowedToBeContainedInIcons:(id)arg0 ;
-(id)indexPathsForContainedNodeIdentifier:(id)arg0 prefixPath:(id)arg1 ;
-(id)init;
-(id)initWithFolder:(id)arg0 gridSize:(struct SBHIconGridSize )arg1 gridSizeClassSizes:(struct SBHIconGridSizeClassSizes )arg2 ;
-(id)initWithFolder:(id)arg0 maxIconCount:(NSUInteger)arg1 ;
-(id)initWithUniqueIdentifier:(id)arg0 folder:(id)arg1 gridSize:(struct SBHIconGridSize )arg2 gridSizeClassSizes:(struct SBHIconGridSizeClassSizes )arg3 ;
-(id)insertIcon:(id)arg0 atIndex:(NSUInteger)arg1 ;
-(id)insertIcon:(id)arg0 atIndex:(NSUInteger)arg1 options:(NSUInteger)arg2 ;
-(id)insertIcons:(id)arg0 atIndex:(NSUInteger)arg1 options:(NSUInteger)arg2 ;
-(id)layoutDescriptionWithOptions:(NSUInteger)arg0 ;
-(id)nodeDescriptionWithPrefix:(id)arg0 ;
-(id)nodeIdentifier;
-(id)nodesAlongIndexPath:(id)arg0 consumedIndexes:(NSUInteger)arg1 ;
-(id)objectWithUniqueIdentifier:(id)arg0 ;
-(id)placeIcon:(id)arg0 atIndex:(NSUInteger)arg1 ;
// -(id)placeIcon:(id)arg0 atIndex:(NSUInteger)arg1 options:(NSUInteger)arg2 bumpedIcons:(*id)arg3 ;
-(id)reversedOrderLayoutDescription;
-(id)succinctDescription;
-(id)succinctDescriptionBuilder;
-(void)_coalesceChangesWithRequestID:(id)arg0 changeBlock:(id)arg1 ;
-(void)_notifyListObservers:(id)arg0 ;
-(void)_unclusterIcons:(id)arg0 ofSizeClass:(NSUInteger)arg1 gridCellInfoOptions:(NSUInteger)arg2 ;
-(void)addIconsOfClass:(Class)arg0 toSet:(id)arg1 ;
// -(void)addIconsPassingTest:(id)arg0 toSet:(unk)arg1 ;
-(void)addListObserver:(id)arg0 ;
-(void)addNodeObserver:(id)arg0 ;
-(void)ancestryDidChange;
-(void)didAddIcon:(id)arg0 ;
-(void)didRemoveIcon:(id)arg0 ;
-(void)enumerateFolderIconsUsingBlock:(id)arg0 ;
-(void)enumerateIconsUsingBlock:(id)arg0 ;
-(void)list:(id)arg0 didAddContainedNodeIdentifiers:(id)arg1 ;
-(void)list:(id)arg0 didRemoveContainedNodeIdentifiers:(id)arg1 ;
-(void)listDidMoveNodes:(id)arg0 ;
-(void)markIconStateClean;
-(void)markIconStateDirty;
-(void)moveContainedIcon:(id)arg0 toGridCellIndex:(NSUInteger)arg1 gridCellInfoOptions:(NSUInteger)arg2 ;
-(void)performChangesByClusteringForSizeClass:(NSUInteger)arg0 withGridCellInfoOptions:(NSUInteger)arg1 block:(id)arg2 ;
-(void)performChangesByPreservingPositionsOfIconsLargerThanSizeClass:(NSUInteger)arg0 block:(id)arg1 ;
-(void)removeAllIcons;
-(void)removeIcon:(id)arg0 ;
-(void)removeIconAtIndex:(NSUInteger)arg0 ;
-(void)removeIconAtIndex:(NSUInteger)arg0 options:(NSUInteger)arg1 ;
-(void)removeIconFromOtherPositionsInHierarchy:(id)arg0 ;
-(void)removeIcons:(id)arg0 ;
-(void)removeLastIcon;
-(void)removeListObserver:(id)arg0 ;
-(void)removeNodeObserver:(id)arg0 ;
-(void)sortUsingComparator:(id)arg0 ;
-(void)sortUsingSelector:(SEL)arg0 ;


@end


#endif
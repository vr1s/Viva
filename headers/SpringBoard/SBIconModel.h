// Headers generated with ktool v0.19.3
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBICONMODEL_H
#define SBICONMODEL_H


#import "SBHIconModel.h"

@interface SBIconModel : SBHIconModel

@property (nonatomic) BOOL allowsWebClips; // ivar: _allowsWebClips
@property (readonly, nonatomic) id applicationDataSource; // ivar: _applicationDataSource


+(id)migratedIdentifierForLeafIdentifier:(id)arg0 ;
-(BOOL)_shouldSkipAddingIcon:(id)arg0 toRootFolder:(id)arg1 ;
-(BOOL)allowsWebClips;
-(BOOL)importState:(id)arg0 ;
-(BOOL)isIconVisible:(id)arg0 ;
-(BOOL)shouldAvoidCreatingIconForApplication:(id)arg0 ;
-(BOOL)shouldAvoidPlacingIconOnFirstPage:(id)arg0 ;
-(id)_applicationIcons;
-(id)addBookmarkIconForWebClip:(id)arg0 ;
-(id)addDownloadingIconForDownload:(id)arg0 ;
-(id)addIconForApplication:(id)arg0 ;
-(id)addIconForApplication:(id)arg0 force:(BOOL)arg1 ;
-(id)applicationIconForBundleIdentifier:(id)arg0 ;
-(id)applicationWithBundleIdentifier:(id)arg0 ;
-(id)bookmarkIconForWebClipIdentifier:(id)arg0 ;
-(id)description;
-(id)expectedIconForDisplayIdentifier:(id)arg0 ;
-(id)expectedIconForDisplayIdentifier:(id)arg0 createIfNecessary:(BOOL)arg1 ;
-(id)exportFlattenedState:(BOOL)arg0 includeMissingIcons:(BOOL)arg1 ;
-(id)exportPendingState:(BOOL)arg0 includeMissingIcons:(BOOL)arg1 ;
-(id)exportState:(BOOL)arg0 ;
-(id)forecastedLayoutForIconState:(id)arg0 includeMissingIcons:(BOOL)arg1 ;
-(id)indexPathForIconInPlatformState:(id)arg0 ;
-(id)initWithStore:(id)arg0 applicationDataSource:(id)arg1 ;
-(id)modernizeRootArchive:(id)arg0 ;
-(id)placeholdersByDisplayID;
-(void)_noteApplicationIconImageChanged:(id)arg0 ;
-(void)_replaceAppIconsWithDownloadingIcons;
-(void)_replaceAppIconsWithDownloadingIcons:(id)arg0 ;
-(void)adjustIconsToShow:(id)arg0 iconsToHide:(id)arg1 afterChangeToVisibleIconTags:(id)arg2 hiddenIconTags:(id)arg3 ;
-(void)dealloc;
-(void)loadAllIcons;
-(void)localeChanged;
-(void)willLayout;


@end


#endif
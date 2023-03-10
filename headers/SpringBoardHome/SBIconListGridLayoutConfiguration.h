// Headers generated with ktool v0.19.3
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBICONLISTGRIDLAYOUTCONFIGURATION_H
#define SBICONLISTGRIDLAYOUTCONFIGURATION_H

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBHAppLibraryVisualConfiguration;
@class SBHFloatyFolderVisualConfiguration;
@class SBHFolderIconVisualConfiguration;
@class SBHIconAccessoryVisualConfiguration;
@class SBHRootFolderVisualConfiguration;
@class SBHSidebarVisualConfiguration;

typedef struct SBHIconGridSize {
    unsigned short columns;
    unsigned short rows;
} SBHIconGridSize;

typedef struct SBHIconGridSizeClassSizes {
    SBHIconGridSize small;
    SBHIconGridSize medium;
    SBHIconGridSize large;
    SBHIconGridSize extraLarge;
} SBHIconGridSizeClassSizes;

typedef struct SBIconImageInfo {
    CGSize size;
    CGFloat scale;
    CGFloat continuousCornerRadius;
} SBIconImageInfo;

@interface SBIconListGridLayoutConfiguration : NSObject

@property (copy, nonatomic) SBHAppLibraryVisualConfiguration *appLibraryVisualConfiguration; // ivar: _appLibraryVisualConfiguration
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (copy, nonatomic) SBHFloatyFolderVisualConfiguration *floatyFolderVisualConfiguration; // ivar: _floatyFolderVisualConfiguration
@property (copy, nonatomic) SBHFolderIconVisualConfiguration *folderIconVisualConfiguration; // ivar: _folderIconVisualConfiguration
@property (readonly) NSUInteger hash;
@property (copy, nonatomic) SBHIconAccessoryVisualConfiguration *iconAccessoryVisualConfiguration; // ivar: _iconAccessoryVisualConfiguration
@property (nonatomic) SBHIconGridSizeClassSizes iconGridSizeClassSizes; // ivar: _iconGridSizeClassSizes
@property (nonatomic) SBIconImageInfo iconImageInfo;
@property (nonatomic) UIEdgeInsets landscapeLayoutInsets; // ivar: _landscapeLayoutInsets
@property (nonatomic) CGSize listSizeForIconSpacingCalculation; // ivar: _listSizeForIconSpacingCalculation
@property (nonatomic) NSUInteger numberOfLandscapeColumns; // ivar: _numberOfLandscapeColumns
@property (nonatomic) NSUInteger numberOfLandscapeRows; // ivar: _numberOfLandscapeRows
@property (nonatomic) NSUInteger numberOfPortraitColumns; // ivar: _numberOfPortraitColumns
@property (nonatomic) NSUInteger numberOfPortraitRows; // ivar: _numberOfPortraitRows
@property (nonatomic) UIEdgeInsets portraitLayoutInsets; // ivar: _portraitLayoutInsets
@property (readonly, copy, nonatomic) SBHRootFolderVisualConfiguration *rootFolderVisualConfiguration; // ivar: _rootFolderVisualConfiguration
@property (copy, nonatomic) SBHSidebarVisualConfiguration *sidebarVisualConfiguration; // ivar: _sidebarVisualConfiguration
@property (readonly) Class superclass;
@property (nonatomic) NSUInteger supportedIconGridSizeClasses; // ivar: _supportedIconGridSizeClasses


-(BOOL)isEqual:(id)arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)iconLabelVisualConfigurationForContentSizeCategory:(id)arg0 ;
-(id)init;
-(id)succinctDescription;
-(id)succinctDescriptionBuilder;
-(struct SBIconImageInfo )iconImageInfoForGridSizeClass:(NSUInteger)arg0 ;
-(void)setIconLabelVisualConfiguration:(id)arg0 forContentSizeCategory:(id)arg1 ;


@end


#endif
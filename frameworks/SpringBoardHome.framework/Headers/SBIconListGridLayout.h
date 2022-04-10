// Headers generated with ktool v0.19.3
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBICONLISTGRIDLAYOUT_H
#define SBICONLISTGRIDLAYOUT_H


#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <UIKit/UIKit.h>

#import "SBIconListGridLayoutConfiguration.h"

@interface SBIconListGridLayout : NSObject

@property (readonly, copy, nonatomic) SBHAppLibraryVisualConfiguration *appLibraryVisualConfiguration;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly, copy, nonatomic) SBHFloatyFolderVisualConfiguration *floatyFolderVisualConfiguration;
@property (readonly, copy, nonatomic) SBHFolderIconVisualConfiguration *folderIconVisualConfiguration;
@property (readonly) NSUInteger hash;
@property (readonly, copy, nonatomic) SBHIconAccessoryVisualConfiguration *iconAccessoryVisualConfiguration;
@property (readonly, nonatomic) SBHIconGridSizeClassSizes iconGridSizeClassSizes;
@property (readonly, nonatomic) SBIconImageInfo iconImageInfo;
@property (readonly, copy, nonatomic) SBIconListGridLayoutConfiguration *layoutConfiguration; // ivar: _layoutConfiguration
@property (readonly, copy, nonatomic) SBHRootFolderVisualConfiguration *rootFolderVisualConfiguration;
@property (readonly, copy, nonatomic) SBHSidebarVisualConfiguration *sidebarVisualConfiguration;
@property (readonly) Class superclass;
@property (readonly, nonatomic) NSUInteger supportedIconGridSizeClasses;
@property (readonly, nonatomic) BOOL usesAlternateLayout;


-(BOOL)isEqual:(id)arg0 ;
-(BOOL)usesAlternateLayout;
-(NSUInteger)numberOfColumnsForOrientation:(NSInteger)arg0 ;
-(NSUInteger)numberOfRowsForOrientation:(NSInteger)arg0 ;
-(id)accessoryBoldFont;
-(id)accessoryFont;
-(id)accessoryFontForContentSizeCategory:(id)arg0 options:(NSUInteger)arg1 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)init;
-(id)initWithLayoutConfiguration:(id)arg0 ;
-(id)labelFontForContentSizeCategory:(id)arg0 options:(NSUInteger)arg1 ;
-(id)labelVisualConfigurationForContentSizeCategory:(id)arg0 options:(NSUInteger)arg1 ;
-(id)succinctDescription;
-(id)succinctDescriptionBuilder;
-(struct SBIconImageInfo )iconImageInfoForGridSizeClass:(NSUInteger)arg0 ;
-(struct UIEdgeInsets )layoutInsetsForOrientation:(NSInteger)arg0 ;

@end


#endif
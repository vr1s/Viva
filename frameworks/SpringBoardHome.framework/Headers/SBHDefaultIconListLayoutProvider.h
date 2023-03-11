// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBHDEFAULTICONLISTLAYOUTPROVIDER_H
#define SBHDEFAULTICONLISTLAYOUTPROVIDER_H


#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

#include "SBIconListFlowLayout.h"

@protocol SBIconListLayoutProvider;
@protocol BSDescriptionProviding;

@interface SBHDefaultIconListLayoutProvider : NSObject <SBIconListLayoutProvider, BSDescriptionProviding>

{
NSMutableDictionary *_cachedListLayouts;
}


@property (readonly, nonatomic) NSUInteger screenType; // ivar: _screenType
@property (readonly, nonatomic) NSUInteger layoutOptions; // ivar: _layoutOptions
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;


-(struct UIEdgeInsets )homeScreenSearchOverlayInsetsForScreenType:(NSUInteger)arg0 layoutOptions:(NSUInteger)arg1 forAppLibrary:(BOOL)arg2 ;
-(void)configureRootFolderConfiguration:(id)arg0 forScreenType:(NSUInteger)arg1 layoutOptions:(NSUInteger)arg2 ;
-(void)configureAppLibraryConfiguration:(id)arg0 forScreenType:(NSUInteger)arg1 layoutOptions:(NSUInteger)arg2 ;
-(void)configureGridSizeClassSizes:(struct SBHIconGridSizeClassSizes *)arg0 forScreenType:(NSUInteger)arg1 numberOfColumns:(NSUInteger)arg2 ;
-(void)configureIconAccessoryConfiguration:(id)arg0 forScreenType:(NSUInteger)arg1 layoutOptions:(NSUInteger)arg2 ;
-(void)configureLabelConfigurations:(id)arg0 forScreenType:(NSUInteger)arg1 ;
-(id)succinctDescriptionBuilder;
-(id)initWithScreenType:(NSUInteger)arg0 layoutOptions:(NSUInteger)arg1 ;
-(SBIconListFlowLayout *)layoutForIconLocation:(id)arg0 ;
-(id)init;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)succinctDescription;
-(id)initWithScreenType:(NSUInteger)arg0 ;
-(void)configureFolderIconConfiguration:(id)arg0 forScreenType:(NSUInteger)arg1 numberOfRows:(NSUInteger)arg2 layoutOptions:(NSUInteger)arg3 ;
-(void)configureFloatyFolderConfiguration:(id)arg0 forScreenType:(NSUInteger)arg1 layoutOptions:(NSUInteger)arg2 ;
-(id)makeLayoutForIconLocation:(id)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)initWithLayoutOptions:(NSUInteger)arg0 ;
+(NSUInteger)currentDeviceScreenType;
+(SBHDefaultIconListLayoutProvider*)frameworkFallbackInstance;


@end


#endif


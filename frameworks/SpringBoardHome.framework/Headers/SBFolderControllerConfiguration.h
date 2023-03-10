

#ifndef SBFOLDERCONTROLLERCONFIGURATION_H
#define SBFOLDERCONTROLLERCONFIGURATION_H

@class NSString, UIView, _UILegibilitySettings;
@class SBFolderControllerAnimationContext, SBFolder, SBFolderIconImageCache, SBIconPageIndicatorImageSetCache;
@protocol NSCopying, BSDescriptionProviding, SBNestingViewControllerDelegate, SBFolderControllerDelegate, SBIconViewProviding, SBIconListLayoutProvider;

#import <Foundation/Foundation.h>

@interface SBFolderControllerConfiguration : NSObject


@property (nonatomic) BOOL addsFocusGuidesForWrapping; // ivar: _addsFocusGuidesForWrapping
@property (nonatomic) NSUInteger allowedOrientations; // ivar: _allowedOrientations
@property (retain, nonatomic) SBFolderControllerAnimationContext *animationContext; // ivar: _animationContext
@property (readonly, copy) NSString *debugDescription;
@property (weak, nonatomic) NSObject<SBNestingViewControllerDelegate> *delegate; // ivar: _delegate
@property (readonly, copy) NSString *description;
@property (retain, nonatomic) SBFolder *folder; // ivar: _folder
@property (weak, nonatomic) NSObject<SBFolderControllerDelegate> *folderDelegate; // ivar: _folderDelegate
@property (retain, nonatomic) SBFolderIconImageCache *folderIconImageCache; // ivar: _folderIconImageCache
@property (readonly) NSUInteger hash;
@property (nonatomic) CGFloat headerHeight; // ivar: _headerHeight
@property (retain, nonatomic) UIView *headerView; // ivar: _headerView
@property (retain, nonatomic) SBHIconImageCache *iconImageCache; // ivar: _iconImageCache
@property (retain, nonatomic) SBIconPageIndicatorImageSetCache *iconPageIndicatorImageSetCache; // ivar: _iconPageIndicatorImageSetCache
@property (weak, nonatomic) NSObject<SBIconViewProviding> *iconViewProvider; // ivar: _iconViewProvider
@property (nonatomic) CGRect initialViewFrame; // ivar: _initialViewFrame
@property (retain, nonatomic) _UILegibilitySettings *legibilitySettings; // ivar: _legibilitySettings
@property (retain, nonatomic) NSObject<SBIconListLayoutProvider> *listLayoutProvider; // ivar: _listLayoutProvider
@property (nonatomic) NSInteger orientation; // ivar: _orientation
@property (copy, nonatomic) NSString *originatingIconLocation; // ivar: _originatingIconLocation
@property (nonatomic) BOOL snapsToPageBoundariesAfterScrolling; // ivar: _snapsToPageBoundariesAfterScrolling
@property (readonly) Class superclass;
@property (nonatomic) NSUInteger userInterfaceLayoutDirectionHandling; // ivar: _userInterfaceLayoutDirectionHandling


-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)init;
-(id)initWithConfiguration:(id)arg0 ;
-(id)succinctDescription;
-(id)succinctDescriptionBuilder;


@end


#endif
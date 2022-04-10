// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBICON_H
#define SBICON_H

@class NSUserActivity;

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

@protocol SBHIconCollationSupport;
@protocol SBHUniquelyIdentifiable;
@protocol SBIconIndexNode;
@protocol BSDescriptionProviding;
@protocol NSCopying;
@protocol SBIconDelegate;

@interface SBIcon : NSObject <SBHIconCollationSupport, SBHUniquelyIdentifiable, SBIconIndexNode, BSDescriptionProviding, NSCopying>



@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
// @property (copy, nonatomic) id *overrideBadgeNumberOrString; // ivar: _overrideBadgeNumberOrString
@property (readonly, nonatomic) NSArray *iTunesCategoriesOrderedByRelevancy;
@property (weak, nonatomic) NSObject<SBIconDelegate> *delegate; // ivar: _delegate
@property (readonly, nonatomic) BOOL shouldWarmUp;
@property (readonly, copy, nonatomic) NSString *displayName;
@property (readonly, nonatomic) BOOL canTruncateLabel;
@property (readonly, nonatomic) BOOL canTightenLabel;
@property (readonly, copy, nonatomic) NSArray *tags;
@property (readonly, nonatomic) NSInteger badgeValue;
// @property (readonly, nonatomic) id *badgeNumberOrString;
@property (readonly, nonatomic) NSInteger labelAccessoryType;
@property (readonly, nonatomic) BOOL launchEnabled;
@property (readonly, nonatomic) BOOL launchDisabledForObscuredReason;
@property (readonly, nonatomic) BOOL supportsStackConfiguration;
@property (readonly, nonatomic) BOOL supportsRasterization;
@property (readonly, nonatomic) NSInteger progressState;
@property (readonly, nonatomic) CGFloat progressPercent;
@property (readonly, nonatomic) BOOL progressPaused;
@property (readonly, nonatomic) BOOL shouldAnimateProgress;
@property (readonly, nonatomic) BOOL uninstalled; // ivar: _uninstalled
@property (readonly, nonatomic) BOOL uninstallSupported;
@property (readonly, copy, nonatomic) NSString *uninstallAlertTitle;
@property (readonly, copy, nonatomic) NSString *uninstallAlertBody;
@property (readonly, copy, nonatomic) NSString *uninstallAlertConfirmTitle;
@property (readonly, copy, nonatomic) NSString *uninstallAlertCancelTitle;
@property (readonly, nonatomic) BOOL timedOut;
@property (readonly, copy, nonatomic) NSArray *folderTitleOptions;
@property (readonly, copy, nonatomic) NSString *folderFallbackTitle;
@property (readonly, nonatomic) BOOL canReceiveGrabbedIcon;
@property (readonly, nonatomic) BOOL canBeReceivedByIcon;
@property (readonly, nonatomic) BOOL canBeAddedToMultiItemDrag;
@property (readonly, copy, nonatomic) NSString *automationID;
@property (readonly, nonatomic) BOOL canBeAddedToSubfolder;
@property (nonatomic) NSUInteger gridSizeClass; // ivar: _gridSizeClass
@property (readonly, nonatomic) NSUInteger supportedGridSizeClasses;
@property (readonly, nonatomic) NSUserActivity *draggingUserActivity;
@property (readonly, copy, nonatomic) NSString *uniqueIdentifier;

-(id)applicationBundleID;
-(id)nodeDescriptionWithPrefix:(id)arg0 ;
-(Class)iconImageViewClassForLocation:(id)arg0 ;
-(id)generateIconImageWithInfo:(struct SBIconImageInfo )arg0 ;
-(id)displayNameForObscuredDisabledLaunchForLocation:(id)arg0 ;
-(void)localeChanged;
-(void)addObserver:(id)arg0 ;
-(BOOL)isWidgetIcon;
-(BOOL)isFolderIcon;
-(NSInteger)accessoryTypeForLocation:(id)arg0 ;
-(BOOL)isWidgetStackIcon;
-(BOOL)canBeReceivedByIcon;
-(BOOL)canReceiveGrabbedIcon;
-(void)launchFromLocation:(id)arg0 context:(id)arg1 ;
-(void)setBadge:(id)arg0 ;
-(BOOL)isPlaceholder;
-(id)nodesAlongIndexPath:(id)arg0 consumedIndexes:(NSUInteger)arg1 ;
-(id)displayNameForLocation:(id)arg0 ;
-(BOOL)shouldAnimateProgress;
-(id)folder;
-(id)descriptionForLocation:(id)arg0 ;
-(BOOL)isDownloadingIcon;
-(BOOL)assumesAppInstallFinishedForFolderProgress;
-(void)archivableStateDidChange;
-(void)_notifyAccessoriesDidUpdate;
-(void)addNodeObserver:(id)arg0 ;
-(void)setUninstalled;
-(void)completeUninstall;
-(id)succinctDescriptionBuilder;
-(void)possibleUserTapBeganWithAbsoluteTime:(NSUInteger)arg0 andContinuousTime:(NSUInteger)arg1 ;
-(id)nodeIdentifier;
-(void)removeObserver:(id)arg0 ;
-(void)_notifyLaunchEnabledDidChange;
-(void)reloadIconImage;
-(BOOL)canTruncateLabel;
-(BOOL)canTightenLabel;
-(id)indexPathsForContainedNodeIdentifier:(id)arg0 prefixPath:(id)arg1 ;
-(BOOL)supportsRasterization;
-(id)iconImageWithInfo:(struct SBIconImageInfo )arg0 ;
-(BOOL)isGrabbedIconPlaceholder;
-(id)containedNodeIdentifiers;
-(BOOL)hasObserver:(id)arg0 ;
-(id)iconLibraryQueryingFilterStrings;
-(id)iconLibraryQueryingAlphaSortString;
-(BOOL)canBeAddedToSubfolder;
-(BOOL)isAdditionalItemsIndicatorIcon;
-(BOOL)isCategoryIcon;
-(id)downloadingIconDataSource;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)_sbhIconLibraryCollationString;
-(BOOL)isLeafIcon;
-(id)succinctDescription;
-(void)possibleUserTapDidCancel;
-(id)genericIconImageWithInfo:(struct SBIconImageInfo )arg0 ;
-(BOOL)containsNodeIdentifier:(id)arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)accessoryTextForLocation:(id)arg0 ;
-(id)representedSceneIdentifier;
-(BOOL)supportsStackConfiguration;
-(BOOL)canBeAddedToMultiItemDrag;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(NSInteger)localizedCompareDisplayNames:(id)arg0 ;
-(id)leafIdentifier;
-(id)unmaskedIconImageWithInfo:(struct SBIconImageInfo )arg0 ;
-(id)_sbhIconLibraryOverrideCollationSectionTitle;
-(id)parentFolderIcon;
-(void)removeNodeObserver:(id)arg0 ;
-(void)enumerateObserversUsingBlock:(id)arg0 ;
-(void)_notifyImageDidUpdate;
-(void)noteBadgeDidChange;
-(BOOL)isGridSizeClassAllowed:(NSUInteger)arg0 ;
-(BOOL)shouldWarmUp;
+(Class)downloadingIconClass;
+(BOOL)canGenerateIconsInBackground;
+(id)genericIconImageWithInfo:(struct SBIconImageInfo )arg0 ;
+(id)iconImageFromUnmaskedImage:(id)arg0 info:(struct SBIconImageInfo )arg1 ;
+(BOOL)hasIconImage;
+(BOOL)forcesBackgroundIconGeneration;


@end


#endif


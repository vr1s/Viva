//
// Created by vrisk/a on 6/27/21.
//

#import "../EditorUI/VIVAUIManager.h"
#include "VIVAManager.h"
#import "VIVALayoutManager.h"
#include "Viva.h"
#import "VIVAConfigurationManager.h"
#import "VIVAPageConfiguration.h"
#import <SpringBoardHome/SBIconListGridLayoutConfiguration.h>

#include <SpringBoard/SBIconController.h>
#include <SpringBoardHome/SBRootFolderView.h>
#include <SpringBoardHome/SBIconListGridLayout.h>
#include <SpringBoardHome/SBHIconManager.h>
#include <SpringBoardHome/SBIconView.h>
#include <SpringBoardHome/SBDockIconListView.h>
#include <SpringBoardHome/SBDockView.h>

typedef struct SBHIconGridSizeClassIconImageInfos {
    SBIconImageInfo icon;
    SBIconImageInfo small;
    SBIconImageInfo medium;
    SBIconImageInfo large;
    SBIconImageInfo newsLargeTall;
    SBIconImageInfo extraLarge;
} SBHIconGridSizeClassIconImageInfos;

#define kListLayoutProvider [[[objc_getClass("SBIconController") sharedInstance] iconManager] listLayoutProvider]
#define ConfigForLocation(location) [(SBIconListGridLayout *)[kListLayoutProvider layoutForIconLocation:location] \
layoutConfiguration]
#define kAppLibraryIconListView [[[[objc_getClass("SBIconController") sharedInstance] _libraryViewController] _podFolderViewController] currentIconListView]


@interface SBIconListGridLayoutConfiguration (fourteen)
-(void)setIconGridSizeClassSizes:(SBHIconGridSizeClassSizes)sizes;
@end

@interface i15SBIconListGridLayoutConfiguration : NSObject
-(void)setIconGridSizeClassSizes:(SBHIconGridSizeClassSizes *)sizes;
@end



NSInteger widgetWidth(NSInteger size, NSInteger cols)
{
    CGFloat colf = (CGFloat) cols;
    if (size <= 2)
        return (NSInteger) (ceil(0.5f * colf)); // floor when widget resizing logic is implemented.
    if (size == 3)
        return (NSInteger) (floor(0.75f * colf));
    if (size >= 4)
        return cols;
    return size;
}
@implementation VIVALayoutManager
{

}
+ (instancetype)sharedInstance
{
    static id _sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        _sharedInstance = [[self alloc] init];
    });

    return _sharedInstance;
}
- (instancetype)init
{
    self = [super init];
    if (self)
    {
        self.defaultProvider = [[objc_getClass("SBHDefaultIconListLayoutProvider") alloc] initWithScreenType:[[objc_getClass("SBHDefaultIconListLayoutProvider") class] frameworkFallbackInstance].screenType];
        self.readyForIconModelSwap = NO;
    }

    return self;
}

+ (void)updateConfigItem:(NSString *)key forLocation:(NSString *)location withValue:(NSInteger)value
{
    [[VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][location] setConfigItem:key toValue:value];
    [VIVALayoutManager updateCacheForLocation:location];
    [[VIVALayoutManager sharedInstance] layoutIconViews];
    // thinking
    // destroying root folder on rebuild sucks. maybe we can find a way to *just* trigger a rebuild of icon views.  
    if ([key isEqualToString:@"HideLabels"] || [key isEqualToString:@"IconScale"])
    {
        [[VIVALayoutManager sharedInstance] layoutIndividualIcons];
        // [kRootFolderView _resetIconListViews];
        // [kIconManager _finishResetRootIconListsReusingPreviousControllers:NO];
    }

    if (@available(iOS 15, *)){}
    else // iOS 14 ONLY! this is unstable on higher versions
         // thankfully, iOS 15 gives us a very nice call we use elsewhere to bump icons :)))
    {
        if ([key isEqualToString:@"Rows"] || [key isEqualToString:@"Columns"])
        {
            [kIconModel layout];
        }
    }
}

+ (SBIconListGridLayoutConfiguration *)defaultConfigurationForIconLocation:(NSString *)iconLocation 
{
    if (!VIVALayoutManager.sharedInstance.originalConfigs)
        VIVALayoutManager.sharedInstance.originalConfigs = [NSMutableDictionary new];
    if (!VIVALayoutManager.sharedInstance.overlayConfigs)
        VIVALayoutManager.sharedInstance.overlayConfigs = [NSMutableDictionary new];
    if (!VIVALayoutManager.sharedInstance.originalConfigs[iconLocation])
    {
        // Store a copy, we're going to change the original object.
        VIVALayoutManager.sharedInstance.originalConfigs[iconLocation] = [VIVALayoutManager.sharedInstance.defaultProvider makeLayoutForIconLocation:iconLocation];
        VIVALayoutManager.sharedInstance.overlayConfigs[iconLocation] = [VIVALayoutManager.sharedInstance.defaultProvider makeLayoutForIconLocation:iconLocation];
    }

    return [(SBIconListGridLayout*)VIVALayoutManager.sharedInstance.originalConfigs[iconLocation] layoutConfiguration];
}


+ (void)updateCacheForLocation:(NSString *)iconLocation
{
    SBIconListFlowLayout *layout = VIVALayoutManager.sharedInstance.overlayConfigs[iconLocation];

    SBIconListGridLayoutConfiguration *og = [VIVALayoutManager defaultConfigurationForIconLocation:iconLocation];

    // NSLog(@"%@", [layout description]);
    SBIconListGridLayoutConfiguration *config = [layout layoutConfiguration];
    SBIconListGridLayoutConfiguration *mgrConfig = ConfigForLocation(iconLocation);

    // Set columns and rows here.
    VIVAPageConfiguration *pageConfig = [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][iconLocation];

    NSInteger loadoutValueColumns = pageConfig.layoutConfiguration.iconGridSize.columns;
    if (loadoutValueColumns < 1)
    {
        // Something went *VERY* wrong with config loading, this should never happen
        return;
    }
    [config setNumberOfPortraitColumns:pageConfig.layoutConfiguration.iconGridSize.columns];
    [config setNumberOfPortraitRows:pageConfig.layoutConfiguration.iconGridSize.rows];
    [mgrConfig setNumberOfPortraitColumns:pageConfig.layoutConfiguration.iconGridSize.columns];
    [mgrConfig setNumberOfPortraitRows:pageConfig.layoutConfiguration.iconGridSize.rows];

    // This set of code is iOS 14 Widget/Applist specific
    if (@available(iOS 14, *))
    {
        // These defaults may be screwed up. Do check them.
        SBHIconGridSizeClassSizes sizes = { .small = { .columns = (short)widgetWidth(2, loadoutValueColumns), .rows = 2 },
                                    .medium = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 2 },
                                    .large = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 6 },
                                    .extraLarge = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 6
        } };

        if (@available(iOS 15, *))
        {
            [(i15SBIconListGridLayoutConfiguration *)config setIconGridSizeClassSizes:&sizes];
            [(i15SBIconListGridLayoutConfiguration *)mgrConfig setIconGridSizeClassSizes:&sizes];
        }
        else{
            [config setIconGridSizeClassSizes:sizes];
            [mgrConfig setIconGridSizeClassSizes:sizes];
            }
    }

    // set top/bottom/left/right insets (for portrait).
    UIEdgeInsets originalInsets = [[VIVALayoutManager defaultConfigurationForIconLocation:iconLocation] portraitLayoutInsets];
    UIEdgeInsets calculatedInsets;

    CGFloat calculatedLeftInset = pageConfig.layoutConfiguration.pageInsets.horizontal?:0;
    CGFloat additionalHorizontalSpacing = pageConfig.layoutConfiguration.pageSpacing.horizontal;
    CGFloat additionalTopInset = pageConfig.layoutConfiguration.pageInsets.vertical?:0;

    if (calculatedLeftInset == 0) // this is viva specific left-inset behavior that feels more intuitive
                              // if left-inset is 0, it'll center the icons like it naturally does.
        calculatedLeftInset = (originalInsets.left) + (additionalHorizontalSpacing)*-2;

    calculatedInsets = UIEdgeInsetsMake(
        originalInsets.top + additionalTopInset,
        calculatedLeftInset,
        // *2 is because regularly it was too slow.
        // negative on the others bc vertical spacing is created by Top and Bottom inset.
        //     we dont actually give the user 'bottom inset' config, just 'top' and 'vertical spacing'.
        //     increasing vertical spacing increases how far we want to move it "down" from the top inset
        //     so, -2 is what we multiply vertical spacing by
        originalInsets.bottom - (additionalTopInset) + (pageConfig.layoutConfiguration.pageSpacing.vertical?:0) *-2,
        originalInsets.right - (pageConfig.layoutConfiguration.pageInsets.horizontal?:0) + (additionalHorizontalSpacing) *-2
    );

    config.portraitLayoutInsets = calculatedInsets;
    mgrConfig.portraitLayoutInsets = calculatedInsets;

    /*
    SBIconImageInfo info = {
        .size = pageConfig.layoutConfiguration.iconImageInfo.size,
        .scale = {3},
        .continuousCornerRadius = {13.5}
    };
    config.iconImageInfo = info;
    mgrConfig.iconImageInfo = info;


    if (@available(iOS 15, *))
    {
        struct SBHIconGridSizeClassIconImageInfos sizes;

        NSValue* szValue = [config valueForKey:@"_iconGridSizeClassIconImageInfos"];
        [szValue getValue:&sizes];

        sizes.icon = info;

        // _iconGridSizeClassIconImageInfos
        [config setValue:[NSValue value:&sizes withObjCType:@encode(struct SBHIconGridSizeClassIconImageInfos)] forKey:@"_iconGridSizeClassIconImageInfos"];
        [mgrConfig setValue:[NSValue value:&sizes withObjCType:@encode(struct SBHIconGridSizeClassIconImageInfos)] forKey:@"_iconGridSizeClassIconImageInfos"];
    }
    */
    
}

-(SBIconListFlowLayout *)layoutForIconLocation:(NSString* )iconLocation
{
    if ([iconLocation isEqualToString:@"SBIconLocationRootWithWidgets"])
    {
        iconLocation = @"SBIconLocationRoot";
    }
    if (!VIVALayoutManager.sharedInstance.overlayConfigs[iconLocation])
    {
        [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationRoot"];
        [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationDock"];
        [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationFolder"];
        [VIVALayoutManager updateCacheForLocation:iconLocation];
    }
    return VIVALayoutManager.sharedInstance.overlayConfigs[iconLocation];
}

-(void)initializeCacheOverride
{
    // Make sure we save defaults before we get started
    [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationRoot"];
    [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationDock"];
    [VIVALayoutManager defaultConfigurationForIconLocation:@"SBIconLocationFolder"];

    [VIVALayoutManager updateCacheForLocation:@"SBIconLocationRoot"];
    [VIVALayoutManager updateCacheForLocation:@"SBIconLocationDock"];
    [self layoutIconViews];
    [self layoutIndividualIcons];
    self.readyForIconModelSwap = YES;
}

- (void)doSharedEditorClosedTasks
{
    [self layoutIconViews];
    [self layoutIndividualIcons];

    // Destroys dock: [kRootFolderView _resetIconListViews];
    // Breaks widgets: [kIconManager _finishResetRootIconListsReusingPreviousControllers:NO];
    // 
}

-(void)layoutIconViews
{
    for (SBIconListView *list in [kRootFolderController iconListViews])
    {
        [list layoutIconsNow];
        SBIconListModel* model = [list model];

        NSUInteger loadoutValueRows = [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconGridSize.rows;
        NSUInteger loadoutValueColumns = [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconGridSize.columns;

        struct SBHIconGridSize size;
        size.rows = loadoutValueRows;
        size.columns = loadoutValueColumns;

        if (@available(iOS 15, *)) {
            [model changeGridSize:size options:0];
        }
        else {
            [model setValue:[NSValue value:&size withObjCType:@encode(struct SBHIconGridSize)] forKey:@"_gridSize"];
        }

        SBHIconGridSizeClassSizes sizes = { .small = { .columns = (short)widgetWidth(2, loadoutValueColumns), .rows = 2 },
                                            .medium = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 2 },
                                            .large = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 6 },
                                            .extraLarge = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 6 } };

        [model setValue:[NSValue value:&sizes withObjCType:@encode(struct SBHIconGridSizeClassSizes)] forKey:@"_gridSizeClassSizes"];
    }
    [[(SBRootFolderView *)[kRootFolderController contentView] dockListView] layoutIconsNow];
    [[(SBRootFolderView *)[kRootFolderController contentView] dockView] layoutSubviews];
    [(SBRootFolderView *)[kRootFolderController contentView] setPageControlHidden:
                                     [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hidePageControl];
}

-(void)layoutIconViewsAnimated
{
    for (SBIconListView *list in [kRootFolderController iconListViews])
    {
        [UIView animateWithDuration:(0.15) delay:0.0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
            [list layoutIconsNow];
        } completion:NULL];
    }
}

-(void)layoutIndividualIcons
{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"VIVAUpdateIconScale" object:nil];
    BOOL hideLabels = (BOOL)[VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideLabels;
    NSUInteger loadoutValueColumns = [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconGridSize.columns;
    
    for (SBIconListView *list in [kRootFolderController iconListViews])
    {
        BOOL reshow = NO;
        if (list.visibleColumnRange.length > 0)
        {
            [list hideAllIcons];
            reshow = YES;
        }
        for (SBIconView *icon in [list subviews])
        {
            if (![icon isMemberOfClass:objc_getClass("SBIconView")])
                continue;
            [icon setNeedsLayout];
            [icon layoutSubviews];
            [icon configureForLabelAllowed:!hideLabels];
        }
        if (reshow)
            [list showAllIcons];
    }
}
@end
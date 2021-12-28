//
// Created by Kritanta on 6/27/21.
//

#import "../EditorUI/HPUIManager.h"
#include "HPManager.h"
#import "HPLayoutManager.h"
#include "HomePlus.h"
#import "HPConfigurationManager.h"
#import "HPPageConfiguration.h"

#define kListLayoutProvider [[[objc_getClass("SBIconController") sharedInstance] iconManager] listLayoutProvider]
#define ConfigForLocation(location) [[kListLayoutProvider layoutForIconLocation:location] layoutConfiguration]
#define kAppLibraryIconListView [[[[objc_getClass("SBIconController") sharedInstance] _libraryViewController] _podFolderViewController] currentIconListView]


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
@implementation HPLayoutManager
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

    }

    return self;
}

+ (void)updateConfigItem:(NSString *)key forLocation:(NSString *)location withValue:(NSInteger)value
{
    [[HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][location] setConfigItem:key toValue:value];
    [HPLayoutManager updateCacheForLocation:location];
    [[HPLayoutManager sharedInstance] layoutIconViews];
    if ([key isEqualToString:@"IconScale"])
    {
        [[HPLayoutManager sharedInstance] layoutIndividualIcons];
    }
}

static NSMutableDictionary *originalConfigs = nil;

+ (SBIconListGridLayoutConfiguration *)defaultConfigurationForIconLocation:(NSString *)iconLocation 
{
    if (!ConfigForLocation(iconLocation))
        return nil;
    if (!originalConfigs)
        originalConfigs = [NSMutableDictionary new];
    if (!originalConfigs[iconLocation])
        // Store a copy, we're going to change the original object.
        originalConfigs[iconLocation] = [ConfigForLocation(iconLocation) copy];

    return originalConfigs[iconLocation];
}

+ (void)updateCacheForLocation:(NSString *)iconLocation
{
    SBIconListGridLayoutConfiguration *config = ConfigForLocation(iconLocation);

    // Set columns and rows here.
    HPPageConfiguration *pageConfig = [HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][iconLocation];

    NSInteger loadoutValueColumns = pageConfig.layoutConfiguration.iconGridSize.columns;
    if (loadoutValueColumns < 1)
    {
        // Something went *VERY* wrong with config loading, this should never happen
        return;
    }
    [config setNumberOfPortraitColumns:pageConfig.layoutConfiguration.iconGridSize.columns];
    [config setNumberOfPortraitRows:pageConfig.layoutConfiguration.iconGridSize.rows];

    // This set of code is iOS 14 Widget/Applist specific
    if (@available(iOS 14, *))
    {
        // These defaults may be screwed up. Do check them.
        SBHIconGridSizeClassSizes sizes = { .small = { .columns = (short)widgetWidth(2, loadoutValueColumns), .rows = 2 },
                                    .medium = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 2 },
                                    .large = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 6 },
                                    .extralarge = { .columns = (short)widgetWidth(4, loadoutValueColumns), .rows = 6 } };

        if (@available(iOS 15, *))
            [(i15SBIconListGridLayoutConfiguration *)config setIconGridSizeClassSizes:&sizes];
        else
            [config setIconGridSizeClassSizes:sizes];
    }

    // set top/bottom/left/right insets (for portrait).
    UIEdgeInsets originalInsets = [[HPLayoutManager defaultConfigurationForIconLocation:iconLocation] portraitLayoutInsets];
    UIEdgeInsets calculatedInsets;

    CGFloat calculatedLeftInset = pageConfig.layoutConfiguration.pageInsets.horizontal?:0;
    CGFloat additionalHorizontalSpacing = pageConfig.layoutConfiguration.pageSpacing.horizontal;
    CGFloat additionalTopInset = pageConfig.layoutConfiguration.pageInsets.vertical?:0;

    if (calculatedLeftInset == 0) // this is homeplus specific left-inset behavior that feels more intuitive
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

    SBIconImageInfo info = {
        .size = pageConfig.layoutConfiguration.iconImageInfo.size,
        .scale = {3},
        .continuousCornerRadius = {13.5}
    };
    config.iconImageInfo = info;
}

-(void)initializeCacheOverride
{
    // Make sure we save defaults before we get started
    [HPLayoutManager defaultConfigurationForIconLocation:@"SBIconLocationRoot"];
    [HPLayoutManager defaultConfigurationForIconLocation:@"SBIconLocationDock"];
    [HPLayoutManager defaultConfigurationForIconLocation:@"SBIconLocationFolder"];

    [HPLayoutManager updateCacheForLocation:@"SBIconLocationRoot"];
    [HPLayoutManager updateCacheForLocation:@"SBIconLocationDock"];
    [self layoutIconViews];
    [self layoutIndividualIcons];

}

-(void)layoutIconViews
{
    for (SBIconListView *list in [kRootFolderController iconListViews])
    {
        [list layoutIconsNow];
    }
    [[(SBRootFolderView *)[kRootFolderController contentView] dockListView] layoutIconsNow];
    [[(SBRootFolderView *)[kRootFolderController contentView] dockView] layoutSubviews];
    [(SBRootFolderView *)[kRootFolderController contentView] setPageControlHidden:
                                     [HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hidePageControl];
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
    BOOL hideLabels = (BOOL)[HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideLabels;
    for (SBIconListView *list in [kRootFolderController iconListViews])
    {
        for (SBIconView *icon in [list subviews])
        {
            if (![icon isMemberOfClass:objc_getClass("SBIconView")])
                return;
            [icon layoutSubviews];
            [icon configureForLabelAllowed:!hideLabels];
        }
    }
}
@end
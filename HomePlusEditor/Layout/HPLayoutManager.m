//
// Created by Kritanta on 6/27/21.
//

#import "HPUIManager.h"
#include "HPManager.h"
#import "HPLayoutManager.h"
#include "HomePlus.h"

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

+(void)updateConfigItem:(NSString *)key forLocation:(NSString *)location withValue:(NSInteger)value
{
    NSString *loc = [location substringFromIndex:14];
    [[[HPDataManager sharedInstance] currentConfiguration] setInteger:value
                                                               forKey:[NSString stringWithFormat:@"HPData%@%@", loc, key]];
    [HPLayoutManager updateCacheForLocation:location];
    [[HPLayoutManager sharedInstance] layoutIconViews];
    if ([key isEqualToString:@"Scale"])
    {
        [[HPLayoutManager sharedInstance] layoutIndividualIcons];
    }
}

+(void)updateCacheForLocation:(NSString *)iconLocation
{
    // Remove "SBIconLocation" from the iconLocation variable,
    //      so we just get "Root" or "Dock"
    NSString *loc = [iconLocation substringFromIndex:14];

    // We're going to use a static dictionary to hold our original configs here, for referencing the 'default' values.
    static NSMutableDictionary *originalConfigs = nil;
    SBIconListGridLayoutConfiguration *config = ConfigForLocation(iconLocation);

    if (!originalConfigs)
        originalConfigs = [NSMutableDictionary new];
    if (!originalConfigs[iconLocation])
        // Store a copy, we're going to change the original object.
        originalConfigs[iconLocation] = [config copy];

    // Set columns and rows here.
    NSInteger loadoutValueColumns = GetLoadoutValue(loc, @"Columns");
    [config setNumberOfPortraitColumns:GetLoadoutValue(loc, @"Columns")];
    [config setNumberOfPortraitRows:GetLoadoutValue(loc, @"Rows")];

    // This set of code is iOS 14 Widget/Applist specific
    if (@available(iOS 14, *))
    {
        // These defaults may be screwed up. Do check them.
        SBHIconGridSizeClassSizes sizes = { .small = { .width = (short)widgetWidth(2, loadoutValueColumns), .height = 2 },
                                    .medium = { .width = (short)widgetWidth(4, loadoutValueColumns), .height = 2 },
                                    .large = { .width = (short)widgetWidth(4, loadoutValueColumns), .height = 6 },
                                    .extralarge = { .width = (short)widgetWidth(4, loadoutValueColumns), .height = 6 } };
        [config setIconGridSizeClassSizes:sizes];
        // Applist does something weird regarding Root Location columns and grid settings
        // This appears to fix it. It still looks, off.
        if ([loc isEqualToString:@"Root"])
        {
        }
    }

    // set top/bottom/left/right insets (for portrait).
    UIEdgeInsets originalInsets = [originalConfigs[iconLocation] portraitLayoutInsets];
    UIEdgeInsets calculatedInsets;

    CGFloat calculatedLeftInset = GetLoadoutValue(loc, @"LeftInset")?:0;
    CGFloat additionalHorizontalSpacing = GetLoadoutValue(loc, @"HorizontalSpacing");
    CGFloat additionalTopInset = GetLoadoutValue(loc, @"TopInset")?:0;

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
        originalInsets.bottom - (additionalTopInset) + (GetLoadoutValue(loc, @"VerticalSpacing")?:0) *-2,
        originalInsets.right - (GetLoadoutValue(loc, @"LeftInset")?:0) + (additionalHorizontalSpacing) *-2
    );

    config.portraitLayoutInsets = calculatedInsets;

    SBIconImageInfo info = {
        .size = {.width = 60*(CGFloat)GetLoadoutValue(loc, @"Scale")/100, .height = 60*(CGFloat)GetLoadoutValue(loc, @"Scale")/100},
        .scale = {3},
        .continuousCornerRadius = {(CGFloat)GetLoadoutValue(loc, @"IconCorner")}
    };
    config.iconImageInfo = info;
}

-(void)initializeCacheOverride
{
    [HPLayoutManager updateCacheForLocation:@"SBIconLocationRoot"];
    [HPLayoutManager updateCacheForLocation:@"SBIconLocationDock"];
    [self layoutIconViews];
}

-(void)layoutIconViews
{
    for (SBIconListView *list in [kRootFolderController iconListViews])
    {
        [list layoutIconsNow];
    }
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
    for (SBIconListView *list in [kRootFolderController iconListViews])
    {
        for (UIView *icon in [list subviews])
        {
            [icon layoutSubviews];
        }
    }
}
@end
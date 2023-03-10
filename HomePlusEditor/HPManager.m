//
// HPManager.m
// HomePlus
//
// Generic Manager
//
// Created Oct 2019
// Author: Kritanta
//

#include "HPManager.h"
#import "HPUIManager.h"

#define kListLayoutProvider [[[objc_getClass("SBIconController") sharedInstance] iconManager] listLayoutProvider]
#define ConfigForLocation(location) [[kListLayoutProvider layoutForIconLocation:location] layoutConfiguration]
#define kAppLibraryIconListView [[[[objc_getClass("SBIconController") sharedInstance] _libraryViewController] _podFolderViewController] currentIconListView]
#define kIconModelDidLayoutNotification @"SBIconModelWillLayoutIconStateNotification"

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

@implementation HPManager

+ (instancetype)sharedInstance
{
    static HPManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = (HPManager *)[[[self class] alloc] init];
    });
    return sharedInstance;
}
- (instancetype)init
{
    self = [super init];

    if (self) {

        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(initializeCacheOverride) name:kIconModelDidLayoutNotification object:nil];
        //[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(performInitialConfiguration) name:@"SBHomescreenDisplayChangedNotification" object:nil];

        // Preference globals
        self._pfTweakEnabled = YES;
        // self._pfBatterySaver = NO; // Planned LPM Reduced Animation State
        self._pfGestureDisabled = YES;
        self._pfActivationGesture = 1;
        //static CGFloat _pfEditingScale = 0.7;

        // Values we use everywhere during runtime. 
        // These should be *avoided* wherever possible
        // We can likely interface managers to handle these without too much overhead
        self._rtEditingEnabled = NO;
        self._rtConfigured = NO;
        self._rtKickedUp = NO;
        self._rtIconSupportInjected = NO;
        // On <iOS 13 we need to reload the icon view initially several times to update our changes :)
        self._rtIconViewInitialReloadCount = 0;

        // Tweak compatability stuff. 
        // See the %ctor at the bottom of the file for more info
        self._tcDockyInstalled = NO;

        // Views to shrink with pan gesture
        self.wallpaperView = nil;
        self.homeWindow = nil;
        self.floatingDockWindow = nil;
        self.mockBackgroundView = nil;

        // Gesture recognizer to enable whenever kDisableEditingMode is hit.
        self._rtGestureRecognizer = nil;
        self._rtHitboxWindow = nil;
        //[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(updateCacheFor) name:@"HPUpdateLayoutCache" object:nil];
    }

    return self;
}

-(void)performInitialConfiguration
{
    [[[UIApplication sharedApplication] keyWindow] addSubview:[[HPUIManager sharedInstance] editorView]];
    [HPManager updateCacheForLocation:@"SBIconLocationRoot"];
    [HPManager updateCacheForLocation:@"SBIconLocationDock"];
    [kIconModel layout];
}

-(void)initializeCacheOverride
{
    [HPManager updateCacheForLocation:@"SBIconLocationRoot"];
    [HPManager updateCacheForLocation:@"SBIconLocationDock"];
    [self layoutIconViews];
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
        SBHIconGridSizeClassSizes sizes = { .small = { .width = widgetWidth(2, loadoutValueColumns), .height = 2 }, 
                                    .medium = { .width = widgetWidth(4, loadoutValueColumns), .height = 2 }, 
                                    .large = { .width = widgetWidth(4, loadoutValueColumns), .height = 6 }, 
                                    .extralarge = { .width = widgetWidth(4, loadoutValueColumns), .height = 6 } };
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
        .size = {.width = GetLoadoutValue(loc, @"Scale"), .height = GetLoadoutValue(loc, @"Scale")},
        .scale = {3},
        .continuousCornerRadius = {GetLoadoutValue(loc, @"IconCorner")}
    };
    config.iconImageInfo = info;
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

@end


static __attribute__((constructor)) void HomePlusConstructor (int __unused argc, char __unused **argv, char __unused **envp)
{
    [HPManager sharedInstance];
}
//
// Created by vrisk/a on 7/8/21.
//

#import "VIVAPageConfiguration.h"

@implementation VIVAPageConfiguration
{

@private
    VIVALayoutConfiguration _layoutConfiguration;
    VIVALayoutOptions _layoutOptions;
    NSString *name;
}
@synthesize name = _name;
@synthesize layoutConfiguration = _layoutConfiguration;
@synthesize layoutOptions = _layoutOptions;

- (void)setConfigItem:(NSString *)item toValue:(NSInteger)value
{
    // TODO: this feels like a cop-out
    if ([item isEqualToString:@"TopInset"])
        _layoutConfiguration.pageInsets.vertical = value;
    else if ([item isEqualToString:@"SideInset"])
        _layoutConfiguration.pageInsets.horizontal = value;
    else if ([item isEqualToString:@"vSpacing"])
        _layoutConfiguration.pageSpacing.vertical = value;
    else if ([item isEqualToString:@"hSpacing"])
        _layoutConfiguration.pageSpacing.horizontal = value;
    else if ([item isEqualToString:@"Rows"])
        _layoutConfiguration.iconGridSize.rows = value;
    else if ([item isEqualToString:@"Columns"])
        _layoutConfiguration.iconGridSize.columns = value;
    else if ([item isEqualToString:@"IconScale"])
        _layoutConfiguration.iconImageInfo.size = CGSizeMake(60.0*(value/100.0), 60.0*(value/100.0));
}

- (NSInteger)valueForItem:(NSString *)item
{
    if ([item isEqualToString:@"TopInset"])
        return _layoutConfiguration.pageInsets.vertical;
    else if ([item isEqualToString:@"SideInset"])
        return _layoutConfiguration.pageInsets.horizontal;
    else if ([item isEqualToString:@"vSpacing"])
        return _layoutConfiguration.pageSpacing.vertical;
    else if ([item isEqualToString:@"hSpacing"])
        return _layoutConfiguration.pageSpacing.horizontal;
    else if ([item isEqualToString:@"Rows"])
        return _layoutConfiguration.iconGridSize.rows ?: 1;
    else if ([item isEqualToString:@"Columns"])
        return _layoutConfiguration.iconGridSize.columns ?: 1;
    else if ([item isEqualToString:@"IconScale"])
        return _layoutConfiguration.iconImageInfo.size.width/60.0*100.0 ?: 60.0;
    return 0;
}

- (BOOL)boolForOption:(NSString *)option
{
    if ([option isEqualToString:@"HideLabels"])
        return _layoutOptions.hideLabels;
    if ([option isEqualToString:@"HideBadges"])
        return _layoutOptions.hideBadges;
    if ([option isEqualToString:@"HidePageControl"])
        return _layoutOptions.hidePageControl;
    return NO;
}

- (void)setBool:(BOOL)value forOption:(NSString *)option
{
    if ([option isEqualToString:@"HideLabels"])
        _layoutOptions.hideLabels=value;
    if ([option isEqualToString:@"HideBadges"])
        _layoutOptions.hideBadges=value;
    if ([option isEqualToString:@"HidePageControl"])
        _layoutOptions.hidePageControl=value;
}

- (instancetype)initWithLayoutConfiguration:(VIVALayoutConfiguration)layoutConfiguration layoutOptions:(VIVALayoutOptions)layoutOptions
{
    self = [super init];
    if (self)
    {
        _layoutConfiguration = layoutConfiguration;
        _layoutOptions = layoutOptions;
    }

    return self;
}

+ (instancetype)configurationWithLayoutConfiguration:(VIVALayoutConfiguration)layoutConfiguration layoutOptions:(VIVALayoutOptions)layoutOptions
{
    return [[self alloc] initWithLayoutConfiguration:layoutConfiguration layoutOptions:layoutOptions];
}

- (VIVAPageConfiguration *)initWithCoder:(NSCoder *)coder
{
    self = [super init];
    if (self)
    {
        CGVector gridSize = [coder decodeCGVectorForKey:@"IconGridSize"];
        UIOffset pageInsets = [coder decodeUIOffsetForKey:@"PageInsets"];
        UIOffset pageSpacing = [coder decodeUIOffsetForKey:@"PageSpacing"];
        CGRect imageInfo = [coder decodeCGRectForKey:@"IconImageInfo"];
        NSLog(@"imageInfo: %@", NSStringFromCGRect(imageInfo));

        BOOL hideBadges = [coder decodeBoolForKey:@"HideBadges"];
        BOOL hideLabels = [coder decodeBoolForKey:@"HideLabels"];
        BOOL hidePageControl = [coder decodeBoolForKey:@"HidePageControls"];

        SBHIconGridSize iconGridSize = {.rows = (unsigned short) gridSize.dy, .columns = (unsigned short) gridSize.dx};
        SBIconImageInfo iconImageInfo = {.scale = imageInfo.origin.x, .continuousCornerRadius = imageInfo.origin.y, .size = imageInfo.size};

        VIVALayoutConfiguration config = {.pageInsets = pageInsets, .pageSpacing = pageSpacing, .iconGridSize = iconGridSize, .iconImageInfo = iconImageInfo};
        VIVALayoutOptions opts = {.hideBadges=hideBadges, .hideLabels = hideLabels, .hidePageControl = hidePageControl};
        self = [self initWithLayoutConfiguration:config layoutOptions:opts];
        self.name = [coder decodeObjectForKey:@"Name"];
    }

    return self;
}

- (void) encodeWithCoder:(NSCoder *)aCoder
{
    [aCoder encodeObject:_name forKey:@"Name"];
    [aCoder encodeCGVector:CGVectorMake(_layoutConfiguration.iconGridSize.columns, _layoutConfiguration.iconGridSize.rows) forKey:@"IconGridSize"];
    [aCoder encodeUIOffset:_layoutConfiguration.pageInsets forKey:@"PageInsets"];
    [aCoder encodeUIOffset:_layoutConfiguration.pageSpacing forKey:@"PageSpacing"];
    [aCoder encodeCGRect:CGRectMake(_layoutConfiguration.iconImageInfo.scale,_layoutConfiguration.iconImageInfo.continuousCornerRadius, _layoutConfiguration.iconImageInfo.size.width, _layoutConfiguration.iconImageInfo.size.height) forKey:@"IconImageInfo"];

    [aCoder encodeBool:_layoutOptions.hideBadges forKey:@"HideBadges"];
    [aCoder encodeBool:_layoutOptions.hideLabels forKey:@"HideLabels"];
    [aCoder encodeBool:_layoutOptions.hidePageControl forKey:@"HidePageControls"];
}

@end
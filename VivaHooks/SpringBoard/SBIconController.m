#include <UIKit/UIKit.h>

#include "VIVAConfigurationManager.h"

@hook SBIconController

-(BOOL)iconManager:(id)arg1 allowsBadgingForIconLocation:(NSString *)location
{
    if ([location isEqualToString:@"SBIconLocationRoot"] || [location isEqualToString:@"SBIconLocationRootWithWidgets"])
    {
        if ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideBadges)
        {
            return NO;
        }
    }
    if ([location isEqualToString:@"SBIconLocationDock"])
    {
        if ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationDock"].layoutOptions.hideBadges)
        {
            return NO;
        }
    }
    return @orig(arg1, location);
}

@end
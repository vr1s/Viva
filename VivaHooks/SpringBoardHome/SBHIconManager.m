#include <UIKit/UIKit.h>
#include <SpringBoardHome/SBIconView.h>

#include "VivaConfigurationManager.h"

@hook SBHIconManager

-(BOOL)iconViewDisplaysLabel:(SBIconView*)icon 
{
    NSString* location = [icon location];

    if ([location isEqualToString:@"SBIconLocationRoot"] || [location isEqualToString:@"SBIconLocationRootWithWidgets"])
    {
        if ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideLabels)
        {
            return NO;
        }
    }
    if ([location isEqualToString:@"SBIconLocationDock"])
    {
        if ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationDock"].layoutOptions.hideLabels)
        {
            return NO;
        }
    }

    return @orig(icon);
}

-(NSUInteger)iconModel:(id)arg0 maxRowCountForListInRootFolderWithInterfaceOrientation:(NSInteger)arg1
{
    return [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconGridSize.rows;
}

@end
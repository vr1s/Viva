#include "VIVAConfigurationManager.h"

%hook SBIconModel 

-(NSUInteger)maxIconCountForDock
{
    return ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationDock"].layoutConfiguration.iconGridSize.columns);
}

%end


#include "VIVAConfigurationManager.h"

%hook SBIconListView

-(BOOL)automaticallyAdjustsLayoutMetricsToFit
{
    return NO;
}

%end

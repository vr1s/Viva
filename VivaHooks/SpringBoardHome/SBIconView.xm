#include <UIKit/UIKit.h>
#include <SpringBoardHome/SBIconView.h>

#include "VivaConfigurationManager.h"

%hook SBIconView

-(void)configureForLabelAllowed:(BOOL)allowed
{
    if ([self.location isEqualToString:@"SBIconLocationRoot"])
    {
        if ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideLabels)
        {
            %orig(NO);
            return;
        }
    }
    %orig;
}

%end
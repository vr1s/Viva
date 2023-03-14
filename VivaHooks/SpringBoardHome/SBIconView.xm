#include <UIKit/UIKit.h>
#include <SpringBoardHome/SBIconView.h>

#include "VivaConfigurationManager.h"

@interface SBIconView (VIVA)
-(void)__VIVA_ADDED_rescale; 
@end

%hook SBIconView


%new 
-(void)__VIVA_ADDED_rescale 
{
    //if ([self isFolderIcon])
    {
        NSString* location = self.location;
        if ([location isEqualToString:@"SBIconLocationRootWithWidgets"])
            location = @"SBIconLocationRoot";
        else if ([location isEqualToString:@"SBIconLocationFolder"])
        {
            self.layer.sublayerTransform = CATransform3DIdentity;
            return;
        }
        CGFloat scaleFactor = [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][location].layoutConfiguration.iconImageInfo.size.width / 60.0;
        // scaleFactor = (scaleFactor + 1.0) / 2.0;
        self.layer.sublayerTransform = CATransform3DMakeScale(scaleFactor, scaleFactor, 1);
    }
}

- (void)_updateIconImageViewAnimated:(BOOL)arg0 {
	%orig;
	[self __VIVA_ADDED_rescale];
}

- (void)setIconContentScale:(CGFloat)arg0 {
	%orig;
	[self __VIVA_ADDED_rescale];
}

-(id)initWithConfigurationOptions:(NSUInteger)arg0 
{
    id original = %orig;
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(__VIVA_ADDED_rescale) name:@"VIVAUpdateIconScale" object:nil];
    return original;
}
-(id)initWithConfigurationOptions:(NSUInteger)arg0 listLayoutProvider:(id)arg1 
{
    id original = %orig;
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(__VIVA_ADDED_rescale) name:@"VIVAUpdateIconScale" object:nil];
    return original;
}
-(id)initWithFrame:(struct CGRect )arg0 
{
    id original = %orig;
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(__VIVA_ADDED_rescale) name:@"VIVAUpdateIconScale" object:nil];
    return original;
}

-(void)configureForLabelAllowed:(BOOL)allowed
{
    // It's important to note that all SBIconViews by default are located in Root.
    // Account for any that might have this only checked once (e.g. app library crap)

    if ([self isKindOfClass:[objc_getClass("_SBHLibraryPodIconView") class]] )
    {
        %orig(allowed);
        return;
    }

    if ([self.location isEqualToString:@"SBIconLocationRoot"])
    {
        if ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideLabels)
        {
            %orig(NO);
            return;
        }
    }
    %orig(allowed);
}

%end


#include "VIVAConfigurationManager.h"

@interface SBFolderIconImageView : UIView
-(void)__VIVA_ADDED_rescale; 
@end

%hook SBFolderIconImageView 

%new 
-(void)__VIVA_ADDED_rescale 
{
    CGFloat scaleFactor = [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconImageInfo.size.width / 60.0;
    self.layer.sublayerTransform = CATransform3DMakeScale(scaleFactor*2, scaleFactor*2, 1);
}

-(id)initWithFrame:(struct CGRect )arg0 
{
    id original = %orig(arg0);

    //[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(__VIVA_ADDED_rescale) name:@"VIVAUpdateIconScale" object:nil];
    //[self __VIVA_ADDED_rescale];

    return original;
}

%end


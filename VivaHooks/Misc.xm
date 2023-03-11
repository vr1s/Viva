#include "Viva.h"

#ifndef NDEBUG
#define DEBUGGER_OVERLAY
#endif

#include "VivaEditor.h"
#define KEY @"VIVAModifiedIconState"
#pragma mark Dock BG Handling

#include <SpringBoard/SpringBoard.h>

#include <SpringBoardHome/SBIconView.h>

%hook SBDockView

// This is what we need to hook to hide the dock background cleanly
// This tidbit works across versions, so we can call it in the base group (%init)

- (id)initWithDockListView:(id)arg1 forSnapshot:(BOOL)arg2 
{
    id x = %orig;

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(layoutSubviews) name:@"VIVALayoutDockView" object:nil];

    return x;
}
%end

#pragma mark Editor Exit Listeners

%hook SBCoverSheetWindow

// This is the lock screen // drag down thing
// Pulling it down will disable the editor view

- (BOOL)becomeFirstResponder 
{
    BOOL x = %orig;

    if ([(SpringBoard*)[UIApplication sharedApplication] isShowingHomescreen] && [VIVAManager sharedInstance]._rtEditingEnabled)
    {
        [[VIVAUIManager sharedInstance] hideEditorView];
        [VIVAManager sharedInstance]._rtEditingEnabled = NO;
    }

    return x;
}

%end
@interface _SBIconGridWrapperView : UIView
@end
%hook _SBIconGridWrapperView
-(void)layoutSubviews
{
    %orig;
    CGSize size = [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconImageInfo.size;
    self.transform = CGAffineTransformMakeScale(size.width/60, size.height/60);
}
%end


%hook SBFStaticWallpaperImageView

// Whenever a wallpaper image is created for the homescreen, pass it to the manager
// We then use this FB/UIRootWindow in the tweak to give the awesome blurred bg UI feel

- (void)setImage:(UIImage *)img 
{
    %orig(img);
    [[VIVAUIManager sharedInstance] loadUpImagesFromWallpaper:img];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CreateBackgroundObject" object:nil];
}

%end

@interface PBUIPosterViewController : UIViewController
@end

%hook PBUIPosterViewController 

-(void)scene:(id)arg1 clientDidConnect:(id)arg2
{
    %orig;

    UIGraphicsBeginImageContext([self view].frame.size);
    [[self view].layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *viewImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();

    [[VIVAUIManager sharedInstance] loadUpImagesFromWallpaper:viewImage];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CreateBackgroundObject" object:nil];
}

%end

%hook SBIconController

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
    return %orig(arg1, location);
}

%end

%hook SBIconModel 

-(NSUInteger)maxIconCountForDock
{
    return ([VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationDock"].layoutConfiguration.iconGridSize.columns);
}

%end

%hook SBHIconManager

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

    return %orig(icon);
}

-(NSUInteger)iconModel:(id)arg0 maxRowCountForListInRootFolderWithInterfaceOrientation:(NSInteger)arg1
{
    return [VIVAConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconGridSize.rows;
}

%end
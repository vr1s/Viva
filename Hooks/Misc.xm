#include "HomePlus.h"
#include "HomePlusEditor.h"
#define KEY @"HPModifiedIconState"
#pragma mark Dock BG Handling

#include <SpringBoard/SpringBoard.h>

#include <SpringBoardHome/SBIconView.h>

%hook SBDockView

// This is what we need to hook to hide the dock background cleanly
// This tidbit works across versions, so we can call it in the base group (%init)

- (id)initWithDockListView:(id)arg1 forSnapshot:(BOOL)arg2 
{
    id x = %orig;

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(layoutSubviews) name:@"HPLayoutDockView" object:nil];

    return x;
}

- (void)layoutSubviews
{
    %orig;
    /*
    UIView *bgView = MSHookIvar<UIView *>(self, "_backgroundView"); 

    if ([[[HPDataManager sharedInstance] currentConfiguration] integerForKey:@"HPDataDockBG"])
    {
        bgView.alpha = 0;
        bgView.hidden = YES;
    }
    else
{
bgView.alpha = 1;
bgView.hidden = NO;
}*/
}

%end

#pragma mark Editor Exit Listeners

%hook SBCoverSheetWindow

// This is the lock screen // drag down thing
// Pulling it down will disable the editor view

- (BOOL)becomeFirstResponder 
{
    BOOL x = %orig;

    if ([(SpringBoard*)[UIApplication sharedApplication] isShowingHomescreen] && [HPManager sharedInstance]._rtEditingEnabled)
    {
        [[HPUIManager sharedInstance] hideEditorView];
        [HPManager sharedInstance]._rtEditingEnabled = NO;
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
    CGSize size = [HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutConfiguration.iconImageInfo.size;
    self.transform = CGAffineTransformMakeScale(size.width/60, size.height/60);
}
%end

# pragma mark Floating Dock Background

%hook SBFloatingDockView

-(void)layoutSubviews
{
    %orig;
    /*
    if ([[[HPDataManager sharedInstance] currentConfiguration] integerForKey:@"HPDataHideDockBG"])
    {
        self.backgroundView.alpha = 0;
        self.backgroundView.hidden = YES;
    }*/
}

%end



%hook SBFStaticWallpaperImageView

// Whenever a wallpaper image is created for the homescreen, pass it to the manager
// We then use this FB/UIRootWindow in the tweak to give the awesome blurred bg UI feel

- (void)setImage:(UIImage *)img 
{
    %orig(img);
    [[HPUIManager sharedInstance] loadUpImagesFromWallpaper:img];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CreateBackgroundObject" object:nil];
}

%end


%hook SBIconView

-(void)configureForLabelAllowed:(BOOL)allowed
{
    if ([self.location isEqualToString:@"SBIconLocationRoot"])
    {
        if ([HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideLabels)
        {
            %orig(NO);
            //[self setIconLabelAlpha:0];
            return;
        }
    }
    %orig;
}

%end

%hook SBIconController

-(BOOL)iconManager:(id)arg1 allowsBadgingForIconLocation:(NSString *)location
{
    if ([location isEqualToString:@"SBIconLocationRoot"])
    {
        if ([HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationRoot"].layoutOptions.hideBadges)
        {
            return NO;
        }
    }
    if ([location isEqualToString:@"SBIconLocationDock"])
    {
        if ([HPConfigurationManager.sharedInstance.currentConfiguration pageConfigurations][@"SBIconLocationDock"].layoutOptions.hideBadges)
        {
            return NO;
        }
    }
    return %orig(arg1, location);
}

%end
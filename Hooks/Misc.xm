#include "HomePlus.h"
#include "HomePlusEditor.h"
#define KEY @"HPModifiedIconState"
#pragma mark Dock BG Handling



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

    UIView *bgView = MSHookIvar<UIView *>(self, "_backgroundView"); 

    // Dont use UserDefaults like this. Use the bool api. I am lazy. 
    if ([[[HPDataManager sharedInstance] currentConfiguration] integerForKey:@"HPDataHideDockBG"])
    {
        bgView.alpha = 0;
        bgView.hidden = YES;
    }
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

# pragma mark Floating Dock Background

%hook SBFloatingDockView

-(void)layoutSubviews
{
    %orig;

    if ([[[HPDataManager sharedInstance] currentConfiguration] integerForKey:@"HPDataHideDockBG"])
    {
        self.backgroundView.alpha = 0;
        self.backgroundView.hidden = YES;
    }
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


%hook SpringBoard

- (NSUInteger)homeScreenRotationStyle
{
    BOOL x = [[[HPDataManager sharedInstance] currentConfiguration] objectForKey:@"HPDataForceRotation"]
                ? [[[HPDataManager sharedInstance] currentConfiguration] boolForKey:@"HPDataForceRotation"]
                : NO;
    return x ? 2 : %orig;
}

- (BOOL)homeScreenSupportsRotation
{
    return [[[HPDataManager sharedInstance] currentConfiguration] objectForKey:@"HPDataForceRotation"]
                ? [[[HPDataManager sharedInstance] currentConfiguration] boolForKey:@"HPDataForceRotation"]
                : NO;
}

%end

%hook SBWallpaperController

-(BOOL)_isAcceptingOrientationChangesFromSource:(NSInteger)arg
{
    return NO;
}

%end

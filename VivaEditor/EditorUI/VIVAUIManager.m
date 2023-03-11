//
// VIVAUIManager.h
// Viva
//
// Global manager for the Editor (and tutorial) views.
//
// Authors: vriska
// Created  Oct 2019
//

#include "spawn.h"

#include "VIVAUIManager.h"
#include "VivaEditor/EditorUI/MainEditorView/VIVAEditorViewController.h"
#include "../Utility/VIVAUtility.h"
#include "../Utility/VIVAResources.h"
#include "../../Viva.h"
#import "VIVAConfigurationManager.h"

#include <SpringBoard/SBIconController.h>
#include <SpringBoard/SBIconModel.h>

@interface VIVAEditorViewController () 

@property (nonatomic, readwrite, strong) VIVAControllerView *offsetControlView;
@property (nonatomic, readwrite, strong) VIVAControllerView *spacingControlView;
@property (nonatomic, readwrite, strong) VIVAControllerView *iconCountControlView;
@property (nonatomic, readwrite, strong) VIVAControllerView *settingsView;
@property (nonatomic, readwrite, strong) VIVAEditorViewNavigationTabBar *tabBar;

@property (nonatomic, readwrite, strong) VIVASettingsTableViewController *tableViewController;

@property (nonatomic, readwrite, strong) UIView *tapBackView;

@property (nonatomic, retain) VIVAControllerView *activeView;
@property (nonatomic, retain) UIButton *activeButton;

@property (nonatomic, retain) UIButton *offsetButton;
@property (nonatomic, retain) UIButton *spacerButton;
@property (nonatomic, retain) UIButton *iconCountButton;
@property (nonatomic, retain) UIButton *settingsButton;
@property (nonatomic, retain) UIButton *settingsDoneButton;

@end

static BOOL hasEnabledOnce = NO;

@interface VIVAUIManager () <VIVAEditorViewControllerDelegate>

@property (nonatomic, readwrite, strong) VIVAEditorViewController *editorViewController;


@end

@implementation VIVAUIManager

+ (instancetype)sharedInstance
{
    static VIVAUIManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = (VIVAUIManager *) [[[self class] alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init
{
    self = [super init];

    if (self) {
        self.editingLocation = @"SBIconLocationRoot";

    }

    return self;
}

- (void)loadUpImagesFromWallpaper:(UIImage *)image 
{
    self.wallpaper = image;
    self.blurredAndDarkenedWallpaper = [self bdBackgroundImage];
    self.blurredMoreBackgroundImage = [self blurredMoreBGImage];

    UIImage *a = [VIVAUtility isCurrentDeviceNotched] ? [VIVAResources inAppBannerNotchedToggled:NO] : [VIVAResources inAppBannerToggled:NO];
    UIImage *b = [[VIVAUIManager sharedInstance] blurredMoreBGImage];

    self.dynamicallyGeneratedSettingsHeaderImage = [VIVAUtility imageByCombiningImage:b withImage:a];
}
- (UIImage *)bdBackgroundImage
{   
    UIImage *sourceImage = self.wallpaper;

    //  Create our blurred image
    CIContext *context = [CIContext contextWithOptions:nil];
    CIImage *inputImage = [CIImage imageWithCGImage:sourceImage.CGImage];


    CIFilter* blackGenerator = [CIFilter filterWithName:@"CIConstantColorGenerator"];
    CIColor* black = [CIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:.5];
    [blackGenerator setValue:black forKey:@"inputColor"];
    CIImage* blackImage = [blackGenerator valueForKey:@"outputImage"];

    //Second, apply that black
    CIFilter *compositeFilter = [CIFilter filterWithName:@"CIMultiplyBlendMode"];
    [compositeFilter setValue:blackImage forKey:@"inputImage"];
    [compositeFilter setValue:inputImage forKey:@"inputBackgroundImage"];
    CIImage *darkenedImage = [compositeFilter outputImage];

    //Third, blur the image
    CIFilter *blurFilter = [CIFilter filterWithName:@"CIGaussianBlur"];
    [blurFilter setDefaults];
    [blurFilter setValue:@(15.0) forKey:@"inputRadius"];
    [blurFilter setValue:darkenedImage forKey:kCIInputImageKey];
    CIImage *blurredImage = [blurFilter outputImage];

    CGImageRef cgimg = [context createCGImage:blurredImage fromRect:inputImage.extent];
    UIImage *blurredAndDarkenedImage = [UIImage imageWithCGImage:cgimg];
    CGImageRelease(cgimg);

    return blurredAndDarkenedImage;
}
- (UIImage *)blurredMoreBGImage
{
    if (!self.wallpaper)
        return nil;
    UIImage *sourceImage = self.wallpaper;

    //  Create our blurred image
    CIContext *context = [CIContext contextWithOptions:nil];
    CIImage *inputImage = [CIImage imageWithCGImage:sourceImage.CGImage];


    CIFilter* blackGenerator = [CIFilter filterWithName:@"CIConstantColorGenerator"];
    CIColor* black = [CIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:.8];
    [blackGenerator setValue:black forKey:@"inputColor"];
    CIImage* blackImage = [blackGenerator valueForKey:@"outputImage"];

    //Second, apply that black
    CIFilter *compositeFilter = [CIFilter filterWithName:@"CIMultiplyBlendMode"];
    [compositeFilter setValue:blackImage forKey:@"inputImage"];
    [compositeFilter setValue:inputImage forKey:@"inputBackgroundImage"];
    CIImage *darkenedImage = [compositeFilter outputImage];

    //Third, blur the image
    CIFilter *blurFilter = [CIFilter filterWithName:@"CIGaussianBlur"];
    [blurFilter setDefaults];
    [blurFilter setValue:@(30.0) forKey:@"inputRadius"];
    [blurFilter setValue:darkenedImage forKey:kCIInputImageKey];
    CIImage *blurredImage = [blurFilter outputImage];

    CGImageRef cgimg = [context createCGImage:blurredImage fromRect:inputImage.extent];
    UIImage *blurredAndDarkenedImage = [UIImage imageWithCGImage:cgimg];
    CGImageRelease(cgimg);
    

    return blurredAndDarkenedImage;
}

- (VIVAEditorViewController *)editorViewController 
{
    if (!_editorViewController) 
    {
        _editorViewController = [[VIVAEditorViewController alloc] init];
        _editorViewController.delegate = self;
    }


    return _editorViewController;
}

- (void)showEditorView 
{
    [[NSNotificationCenter defaultCenter] postNotificationName:kEditingModeEnabledNotificationName object:nil];
    [[[VIVAUIManager sharedInstance] editorViewController] reload];

    [_editorViewController view].hidden = NO;
    [_editorViewController view].alpha = 1;
    [UIView animateWithDuration:.2
        animations:
        ^{
            [[_editorViewController view] setAlpha:1];
        }
    ];

    if (!hasEnabledOnce)
    {
        hasEnabledOnce = YES;
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(hideEditorView) name:@"SBCoverSheetWillPresentNotification" object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(hideEditorView) name:@"SBUIAppSwitcherWillRevealNotification" object:nil];
    }
}
- (void)hideEditorView
{
    if ([_editorViewController view].hidden)
        return;
    [[NSNotificationCenter defaultCenter] postNotificationName:kEditingModeDisabledNotificationName object:nil];
    [VIVAConfigurationManager.sharedInstance save];
    [_editorViewController handleDoneSettingsButtonPress:_editorViewController.settingsDoneButton];
    [_editorViewController view].hidden = YES;
    self.editingLocation = @"SBIconLocationRoot";
    [[self editorViewController] reload];
}

- (void)toggleEditorView
{
    [[NSNotificationCenter defaultCenter] postNotificationName:kShowFloatingDockNotificationName object:nil];
    if ([_editorViewController view].hidden) 
    {
        [self showEditorView];
    } 
    else 
    {
        [self hideEditorView];
    }
}

- (void)resetAllValuesToDefaults 
{
    [_editorViewController resetAllValuesToDefaults];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"VivaEditingModeDisabled" object:nil];
    [self hideEditorView];
    _editorViewController = nil;
    _editorViewController = [[VIVAEditorViewController alloc] init];
    _editorViewController.delegate = self;

    [kIconModel layout];

	pid_t pid;
    const char* args[] = {"killall", "backboardd", NULL};
    posix_spawn(&pid, "/usr/bin/killall", NULL, NULL, (char* const*)args, NULL);
}

- (void)editorViewControllerDidFinish:(VIVAEditorViewController *)editorViewController 
{

}

@end

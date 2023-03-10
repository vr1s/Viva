//
// HPUIManager.h
// HomePlus
//
// Global manager for the Editor (and tutorial) views.
//
// Authors: Kritanta
// Created  Oct 2019
//

#include "spawn.h"

#include "HPUIManager.h"
#include "HomePlusEditor/EditorUI/MainEditorView/HPEditorViewController.h"
#include "../Utility/HPUtility.h"
#include "../Utility/HPResources.h"
#include "../../HomePlus.h"
#import "HPConfigurationManager.h"

@interface HPEditorViewController () 

@property (nonatomic, readwrite, strong) HPControllerView *offsetControlView;
@property (nonatomic, readwrite, strong) HPControllerView *spacingControlView;
@property (nonatomic, readwrite, strong) HPControllerView *iconCountControlView;
@property (nonatomic, readwrite, strong) HPControllerView *settingsView;
@property (nonatomic, readwrite, strong) HPEditorViewNavigationTabBar *tabBar;

@property (nonatomic, readwrite, strong) HPSettingsTableViewController *tableViewController;

@property (nonatomic, readwrite, strong) UIView *tapBackView;

@property (nonatomic, retain) HPControllerView *activeView;
@property (nonatomic, retain) UIButton *activeButton;

@property (nonatomic, retain) UIButton *offsetButton;
@property (nonatomic, retain) UIButton *spacerButton;
@property (nonatomic, retain) UIButton *iconCountButton;
@property (nonatomic, retain) UIButton *settingsButton;
@property (nonatomic, retain) UIButton *settingsDoneButton;

@end

static BOOL hasEnabledOnce = NO;

@interface HPUIManager () <HPEditorViewControllerDelegate>

@property (nonatomic, readwrite, strong) HPEditorViewController *editorViewController;
@property (nonatomic, readwrite, strong) HPEditorWindow *editorView;


@end

@implementation HPUIManager

+ (instancetype)sharedInstance
{
    static HPUIManager *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = (HPUIManager *) [[[self class] alloc] init];
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

    UIImage *a = [HPUtility isCurrentDeviceNotched] ? [HPResources inAppBannerNotchedToggled:NO] : [HPResources inAppBannerToggled:NO];
    UIImage *b = [[HPUIManager sharedInstance] blurredMoreBGImage];

    self.dynamicallyGeneratedSettingsHeaderImage = [HPUtility imageByCombiningImage:b withImage:a];
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


- (HPEditorWindow *)editorView 
{
    if (!_editorView) 
    {
        _editorView = [[HPEditorWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        _editorView.rootViewController = self.editorViewController;
    }
    return _editorView;
}

- (HPEditorViewController *)editorViewController 
{
    if (!_editorViewController) 
    {
        _editorViewController = [[HPEditorViewController alloc] init];
        _editorViewController.delegate = self;
    }

    return _editorViewController;
}

- (void)showEditorView 
{
    [[NSNotificationCenter defaultCenter] postNotificationName:kEditingModeEnabledNotificationName object:nil];
    [[[HPUIManager sharedInstance] editorViewController] reload];
    [self editorViewController];
    [self editorView];
    _editorView.hidden = NO;
    _editorView.alpha = 0;
    [UIView animateWithDuration:.2
        animations:
        ^{
            _editorView.alpha = 1;
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
    if (_editorView.hidden == YES)
        return;
    [[NSNotificationCenter defaultCenter] postNotificationName:kEditingModeDisabledNotificationName object:nil];
    [HPConfigurationManager.sharedInstance save];
    [_editorViewController handleDoneSettingsButtonPress:_editorViewController.settingsDoneButton];
    _editorView.hidden = YES;
    self.editingLocation = @"SBIconLocationRoot";
    [[self editorViewController] unloadExtensionPanes];
    [[self editorViewController] reload];
}

- (void)toggleEditorView
{
    [[NSNotificationCenter defaultCenter] postNotificationName:kShowFloatingDockNotificationName object:nil];
    if (_editorView.hidden) 
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
    [[NSNotificationCenter defaultCenter] postNotificationName:@"HomePlusEditingModeDisabled" object:nil];
    [self hideEditorView];
    _editorView = nil;
    _editorViewController = nil;
    _editorViewController = [[HPEditorViewController alloc] init];
    _editorViewController.delegate = self;
    _editorView = [[HPEditorWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    _editorView.rootViewController = self.editorViewController;

    [kIconModel layout];

	pid_t pid;
    const char* args[] = {"killall", "backboardd", NULL};
    posix_spawn(&pid, "/usr/bin/killall", NULL, NULL, (char* const*)args, NULL);
}

- (void)editorViewControllerDidFinish:(HPEditorViewController *)editorViewController 
{

}

@end

//
// Created by vrisk/a on 6/25/21.
//

#import "VIVASystemUIManager.h"
#import "Viva.h"
#import "../EditorUI/VIVAUIManager.h"
#import "VIVAUtility.h"

#include <SpringBoard/SBWallpaperController.h>
#include <SpringBoard/SBIconController.h>
#include <SpringBoard/SBFloatingDockController.h>

#include <SpringBoardHome/SBHIconManager.h>


@implementation VIVASystemUIManager
{

}

+ (instancetype)sharedInstance
{
    static id _sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^
    {
        _sharedInstance = [[self alloc] init];
    });

    return _sharedInstance;
}

- (instancetype)init
{
    self = [super init];
    if (self)
    {

        self.homeWindow = [[kIconController parentViewController] view];
        self.wallpaperWindow = [[objc_getClass("SBWallpaperController") sharedInstance] _window];
        //self.floatingDockWindow = [[kIconController floatingDockController] floatingDockWindow];

        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(editorStateChanged:) name:kEditingModeEnabledNotificationName object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(editorStateChanged:) name:kEditingModeDisabledNotificationName object:nil];

        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(kickupStateChanged:) name:kEditorKickViewsUp object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(kickupStateChanged:) name:kEditorKickViewsBack object:nil];


    }

    return self;
}

-(void)editorStateChanged:(NSNotification *)notification
{
    BOOL enabled = ([[notification name] isEqualToString:kEditingModeEnabledNotificationName]);

    [VIVAManager sharedInstance]._rtEditingEnabled = enabled;
    BOOL notched = [VIVAUtility isCurrentDeviceNotched];
    CGFloat cR = notched ? 35 : 0;
    self.wallpaperWindow.layer.cornerRadius = enabled ? cR : 0;
}

-(void)hideFloatingDockView:(BOOL)shouldHide
{
    [[[kIconController iconManager] floatingDockViewController] setDockOffscreenProgress:shouldHide];
}

-(void)kickupStateChanged:(NSNotification *)notification
{
    [VIVASystemUIManager animateView:self.homeWindow
                    forKickupState:[[notification name] isEqualToString:kEditorKickViewsUp]];
    [VIVASystemUIManager animateView:self.wallpaperWindow
                    forKickupState:[[notification name] isEqualToString:kEditorKickViewsUp]];
}

+(void)animateView:(UIView *)view forKickupState:(BOOL)state
{
    CGAffineTransform transform = view.transform;
    [UIView animateWithDuration:0.4f
                     animations:
                             ^{
                                 view.transform = (state)
                                                  ? CGAffineTransformTranslate(transform, 0,
                                                      0 - ([[UIScreen mainScreen] bounds].size.height * 0.7f))
                                                  : CGAffineTransformTranslate(transform, 0,
                                                          ([[UIScreen mainScreen] bounds].size.height * 0.7f)
                                                 );
                             }];
}


@end
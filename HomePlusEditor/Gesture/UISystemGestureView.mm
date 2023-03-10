//
// Created by Kritanta on 6/24/21.
//
//

#import "UISystemGestureView.h"
#import "HPGestureManager.h"
#include "HPManager.h"
#include "HPUIManager.h"
#include "HomePlusEditor/Debug/KDBManager.h"

// TODO: this doesn't add overhead but its still a hack. need RE to find a better way.
#define NSLog(...) [KDBManager.sharedInstance logString:[NSString stringWithFormat:__VA_ARGS__] file:__FILE__ line:__LINE__]
static BOOL hasInjectedView = NO;

static void (*orig_layoutSubviews) (UISystemGestureView *, SEL);
static void hooked_layoutSubviews (UISystemGestureView *, SEL);

static void hooked_layoutSubviews (UISystemGestureView *self, SEL _cmd)
{
    orig_layoutSubviews(self, _cmd);

    if (!hasInjectedView)
    {
        hasInjectedView = YES;
        [[HPGestureManager sharedInstance] insertGestureRecognizers:self];
        [[self superview] addSubview:[[KDBManager sharedInstance] overlayView]];
        [KDBManager.sharedInstance setupOverlayView];
        // [self addSubview:[[[HPUIManager sharedInstance] editorViewController] view]];
        NSLog(@"Log Overlay Initialized");

        NSLog(@"HomePlus: inited");
    }
}

#include "substrate.h"

static __attribute__((constructor)) void GestureHookConstructor (int __unused argc, char __unused **argv, char __unused **envp)
{
    MSHookMessageEx(objc_getClass("UISystemGestureView"),
            @selector(layoutSubviews),
            (IMP) &hooked_layoutSubviews,
            (IMP *) &orig_layoutSubviews);
}
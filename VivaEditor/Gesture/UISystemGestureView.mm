//
// Created by vrisk/a on 6/24/21.
//
//

#import "UISystemGestureView.h"
#import "VIVAGestureManager.h"
#include "VIVAManager.h"
#include "VIVAUIManager.h"

// TODO: this doesn't add overhead but its still a hack. need RE to find a better way.
static BOOL hasInjectedView = NO;

static void (*orig_layoutSubviews) (UISystemGestureView *, SEL);
static void hooked_layoutSubviews (UISystemGestureView *, SEL);

static void hooked_layoutSubviews (UISystemGestureView *self, SEL _cmd)
{
    orig_layoutSubviews(self, _cmd);

    if (!hasInjectedView)
    {
        hasInjectedView = YES;
        [[VIVAGestureManager sharedInstance] insertGestureRecognizers:self];

        NSLog(@"Viva: inited");
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
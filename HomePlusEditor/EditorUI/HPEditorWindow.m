//
// HPEditorWindow.m
// HomePlus
//
// This is a Editor Window. We add a subview to it, and that thing holds our sliders
// TODO: do we really need this?
// 
// Created Oct 2019 
// Authors: Kritanta
//

#include "HPEditorWindow.h"
#include <objc/runtime.h>

@implementation HPEditorWindow

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];

    //objc_msgSend(super, "initWithFrame:", frame);

    return self;
}

@end

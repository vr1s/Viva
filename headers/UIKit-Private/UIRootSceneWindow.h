// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef UIROOTSCENEWINDOW_H
#define UIROOTSCENEWINDOW_H

#import <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

#include "headers/UIKit-Private/UIMutableTransformer.h"

@class FBSDisplayConfiguration;
@protocol UIMutableTransformerDelegate;

@interface UIRootSceneWindow : UIWindow <UIMutableTransformerDelegate>

@property (readonly, nonatomic) UIView *_sceneContainerView; // ivar: _sceneContainerView
@property (readonly, nonatomic) FBSDisplayConfiguration *displayConfiguration; // ivar: _displayConfiguration
@property (readonly, nonatomic) UIMutableTransformer *sceneTransformer; // ivar: _sceneTransformer
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;


-(BOOL)_usesWindowServerHitTesting;
-(BOOL)_canBecomeKeyWindow;
-(void)setFrame:(struct CGRect )arg0 ;
-(BOOL)_shouldPrepareScreenForWindow;
-(id)_focusResponder;
-(void)_updateTransforms;
-(id)hitTest:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(id)initWithDisplay:(id)arg0 ;
-(void)transformsDidChange:(id)arg0 ;
-(id)initWithDisplayConfiguration:(id)arg0 ;
-(id)initWithScreen:(id)arg0 ;
-(BOOL)_appearsInLoupe;
-(void)dealloc;


@end


#endif


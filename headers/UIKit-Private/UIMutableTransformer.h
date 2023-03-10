// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef UIMUTABLETRANSFORMER_H
#define UIMUTABLETRANSFORMER_H



#include <UIKit/UIKit.h>

#include "UITransformer.h"

@protocol UIMutableTransformerDelegate

-(void)transformsDidChange:(id)arg0 ;

@end


@interface UIMutableTransformer : UITransformer

@property (weak, nonatomic) NSObject<UIMutableTransformerDelegate> *_delegate; // ivar: _delegate


-(void)removeAll;
-(void)_updateTransform;
-(void)addTransform:(id)arg0 reason:(id)arg1 ;
-(void)replaceTransform:(id)arg0 withTransform:(id)arg1 reason:(id)arg2 ;
-(void)removeTransform:(id)arg0 ;
-(void)_setDelegate:(id)arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;


@end


#endif


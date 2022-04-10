// Headers generated with ktool v0.19.3
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef UITRANSFORMER_H
#define UITRANSFORMER_H


#include <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#include <UIKit/UIKit.h>

#include "UITransform.h"

@protocol BSDescriptionProviding;

@interface UITransformer : UITransform <BSDescriptionProviding, NSMutableCopying>

{
NSMutableArray *_transformReasonAssociations;
}


@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy, nonatomic) NSArray *transforms; // ivar: _transforms


-(BOOL)isEqual:(id)arg0 ;
-(id)_initWithTransformer:(id)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)mutableCopyWithZone:(struct _NSZone *)arg0 ;


@end


#endif
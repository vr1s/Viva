// Headers generated with ktool v0.19.3
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef UITRANSFORM_H
#define UITRANSFORM_H


#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@protocol BSDescriptionProviding;

@interface UITransform : NSObject <BSDescriptionProviding, NSCopying>

@property (readonly, copy) NSString *debugDescription;
@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, nonatomic) CGAffineTransform transform; // ivar: _transform


+(id)identity;
+(id)rotationWithDegrees:(NSInteger)arg0 ;
+(id)rotationWithRadians:(CGFloat)arg0 ;
+(id)scale:(CGFloat)arg0 ;
+(id)scaleX:(CGFloat)arg0 scaleY:(CGFloat)arg1 ;
+(id)transformWithCGAffineTransform:(struct CGAffineTransform )arg0 ;
+(id)translation:(struct CGPoint )arg0 ;
-(BOOL)isEqual:(id)arg0 ;
-(id)_initWithTransform:(struct CGAffineTransform )arg0 ;
-(id)copyWithZone:(struct _NSZone *)arg0 ;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)init;
-(id)succinctDescription;
-(id)succinctDescriptionBuilder;


@end


#endif
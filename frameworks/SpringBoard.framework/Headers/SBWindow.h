// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBWINDOW_H
#define SBWINDOW_H


#include <SpringBoardFoundation/SBFWindow.h>
@class SBUICoronaAnimationController;
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class SBRecycledViewsContainer;
@protocol SBMainDisplayInterfaceOrientationSource;
@protocol SBRecycledViewsContainerProviding;
@protocol SBWindowLayoutStrategyObserving;
@protocol SBWindowLayoutStrategy;

@interface SBWindow : SBFWindow <SBMainDisplayInterfaceOrientationSource, SBRecycledViewsContainerProviding, SBWindowLayoutStrategyObserving>

{
SBUICoronaAnimationController *_coronaAnimationController;
SBRecycledViewsContainer *_recycledViewsContainerView;
BOOL _requestedHiddenValue;
NSMutableSet *_additionalHiddenReasons;
}


@property (readonly, nonatomic) NSObject<SBWindowLayoutStrategy> *layoutStrategy; // ivar: _layoutStrategy
@property (readonly, nonatomic) NSInteger activeInterfaceOrientation;
@property (readonly, nonatomic) BOOL active;
@property (readonly, nonatomic) CGFloat orientationSourceLevel;
@property (readonly, copy, nonatomic) NSString *orientationSourceDescription;
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) UIView *recycledViewsContainer;


-(void)handleStatusBarChangeFromHeight:(CGFloat)arg0 toHeight:(CGFloat)arg1 ;
-(BOOL)_shouldResizeWithScene;
-(id)sb_coronaAnimationController;
-(id)initWithFrame:(struct CGRect )arg0 ;
-(void)setHidden:(BOOL)arg0 ;
-(id)_initWithScreen:(id)arg0 layoutStrategy:(id)arg1 debugName:(id)arg2 rootViewController:(id)arg3 scene:(id)arg4 ;
-(void)makeKeyAndVisible;
-(void)setAutorotates:(BOOL)arg0 forceUpdateInterfaceOrientation:(BOOL)arg1 ;
-(void)traitCollectionDidChange:(id)arg0 ;
-(void)dealloc;
-(id)initWithScreen:(id)arg0 debugName:(id)arg1 ;
-(id)initWithScreen:(id)arg0 debugName:(id)arg1 rootViewController:(id)arg2 ;
-(id)initWithScreen:(id)arg0 layoutStrategy:(id)arg1 debugName:(id)arg2 scene:(id)arg3 ;
-(id)initWithScreen:(id)arg0 layoutStrategy:(id)arg1 debugName:(id)arg2 ;
-(void)_willEnableSecureRendering:(id)arg0 ;
-(void)_didDisableSecureRendering:(id)arg0 ;
-(void)_updateHidingForSecureRendering:(BOOL)arg0 ;
-(void)_updateRealIsHidden;
-(void)_addHiddenReason:(id)arg0 ;
-(void)_removeHiddenReason:(id)arg0 ;
-(void)layoutStrategyFrameOnScreenDidChange:(id)arg0 ;
-(void)setAlphaAndObeyBecauseIAmTheWindowManager:(CGFloat)arg0 ;
+(BOOL)sb_autorotates;
+(id)defaultLayoutStrategy;
+(BOOL)sb_disableStatusBarHeightChanges;


@end


#endif


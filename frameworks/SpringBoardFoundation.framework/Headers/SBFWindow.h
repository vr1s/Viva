// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBFWINDOW_H
#define SBFWINDOW_H


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class _SBFKeyWindowStack;

@interface SBFWindow : UIWindow {
NSNumber *_isHiddenOverride;
}


@property (retain, nonatomic) _SBFKeyWindowStack *_keyWindowStack; // ivar: _keyWindowStack


-(BOOL)_canBecomeKeyWindow;
-(void)setHidden:(BOOL)arg0 ;
-(void)makeKeyWindow;
-(void)dealloc;
-(void)resignAsKeyWindow;
-(BOOL)_isEffectivelyHiddenForKeyWindowStack;
-(void)_makeKeyFromKeyWindowStack;
-(void)_resignKeyFromKeyWindowStack;
-(void)_setKeyWindowStack:(id)arg0 ;


@end


#endif


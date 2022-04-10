// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBFLOATINGDOCKVIEW_H
#define SBFLOATINGDOCKVIEW_H


#import <UIKit/UIKit.h>

#include <SpringBoardFoundation/SBFTouchPassThroughView.h>

@class SBFloatingDockPlatterView;
@class SBDockIconListView;
@protocol SBFloatingDockViewDelegate;

@interface SBFloatingDockView : SBFTouchPassThroughView

@property (retain, nonatomic) SBFloatingDockPlatterView *mainPlatterView; // ivar: _mainPlatterView
@property (retain, nonatomic) UIView *dividerView; // ivar: _dividerView
@property (retain, nonatomic) UIView *touchReceivingView; // ivar: _touchReceivingView
@property (nonatomic) CGFloat iconContentScale; // ivar: _iconContentScale
@property (weak, nonatomic) NSObject<SBFloatingDockViewDelegate> *delegate; // ivar: _delegate
@property (readonly, nonatomic) CGFloat maximumDockContinuousCornerRadius;
@property (readonly, nonatomic) CGSize maximumIconSize;
@property (readonly, nonatomic) CGFloat maximumPlatterHeight;
@property (readonly, nonatomic) CGFloat maximumInterIconSpacing;
@property (retain, nonatomic) SBDockIconListView *userIconListView; // ivar: _userIconListView
@property (retain, nonatomic) SBDockIconListView *recentIconListView; // ivar: _recentIconListView
@property (retain, nonatomic) UIView *backgroundView;
@property (nonatomic) UIEdgeInsets paddingEdgeInsets; // ivar: _paddingEdgeInsets
@property (nonatomic) CGFloat platterVerticalMargin; // ivar: _platterVerticalMargin
@property (nonatomic) NSUInteger minimumUserIconSpaces; // ivar: _minimumUserIconSpaces
@property (readonly, nonatomic) CGFloat contentHeight;
@property (readonly, nonatomic) CGFloat interIconSpacing;
@property (readonly, nonatomic) CGRect platterFrame;
@property (nonatomic) BOOL hasPlatterShadow;
@property (readonly, nonatomic) UIEdgeInsets platterShadowOutsets;


-(void)bounce;
-(CGFloat)contentHeightForBounds:(struct CGRect )arg0 ;
-(id)initWithFrame:(struct CGRect )arg0 ;
-(struct UIEdgeInsets )platterShadowOutsetsForBounds:(struct CGRect )arg0 ;
-(void)layoutSubviews;
-(struct SBIconImageInfo )_iconImageInfo;
-(void)_dynamicUserInterfaceTraitDidChange;
-(BOOL)pointInside:(struct CGPoint )arg0 withEvent:(id)arg1 ;
-(void)updateDividerVisualStyling;
-(struct CGSize )_referenceIconSize;
-(CGFloat)_referenceInterIconSpacing;
-(CGFloat)iconContentScaleForNumberOfUserIcons:(NSUInteger)arg0 ;
+(CGFloat)_referenceInterIconSpacingWithIconImageInfo:(struct SBIconImageInfo )arg0 ;
+(CGFloat)maximumInterIconSpacingWithIconImageInfo:(struct SBIconImageInfo )arg0 ;
+(CGFloat)maximumDockContinuousCornerRadiusWithIconImageInfo:(struct SBIconImageInfo )arg0 ;
+(struct CGSize )maximumIconSizeWithIconImageInfo:(struct SBIconImageInfo )arg0 ;
+(CGFloat)maximumPlatterHeightWithIconImageInfo:(struct SBIconImageInfo )arg0 ;
+(CGFloat)contentHeightForBounds:(struct CGRect )arg0 mainPlatterViewFrame:(struct CGRect )arg1 ;
+(CGFloat)minimumPlatterMargin;


@end


#endif


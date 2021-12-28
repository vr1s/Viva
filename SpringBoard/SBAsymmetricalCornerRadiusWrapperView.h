//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <UIKit/UIView.h>

@class BSCornerRadiusConfiguration;

@interface SBAsymmetricalCornerRadiusWrapperView : UIView
{
    BSCornerRadiusConfiguration *_cornerRadiusConfiguration;
    NSUInteger _maskedCorners;
    UIView *_trailingCornersMaskingView;
}

@property(retain, nonatomic) UIView *trailingCornersMaskingView; // @synthesize trailingCornersMaskingView=_trailingCornersMaskingView;
@property(nonatomic) NSUInteger maskedCorners; // @synthesize maskedCorners=_maskedCorners;
@property(retain, nonatomic) BSCornerRadiusConfiguration *cornerRadiusConfiguration; // @synthesize cornerRadiusConfiguration=_cornerRadiusConfiguration;
// - (void).cxx_destruct;
- (void)_updateMaskedCorners;
- (void)_updateCornerRadius;
- (void)sendContentViewToBack:(id)arg1;
- (void)bringContentViewToFront:(id)arg1;
- (void)addContentView:(id)arg1;
- (void)setClipsToBounds:(BOOL)arg1;
- (id)initWithFrame:(CGRect)arg1;

@end


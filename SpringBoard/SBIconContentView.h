//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <UIKit/UIView.h>

@interface SBIconContentView : UIView
{
    long long _orientation;
    UIView *_contentView;
}

@property(retain, nonatomic) UIView *contentView; // @synthesize contentView=_contentView;
@property(nonatomic) long long orientation; // @synthesize orientation=_orientation;
// - (void).cxx_destruct;
- (void)layoutSubviews;
- (id)initWithOrientation:(long long)arg1;

@end


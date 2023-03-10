//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <SpringBoard/SBDataPlanAlertItem.h>

#import <SpringBoard/SBDataPlanAlertActions-Protocol.h>

@class NSURL;

@interface SBDataPlanAccountAlertItem : SBDataPlanAlertItem <SBDataPlanAlertActions>
{
    NSURL *_accountURL;
}

+ (id)nowButtonTitle;
+ (id)laterButtonTitle;
@property(copy, nonatomic) NSURL *accountURL; // @synthesize accountURL=_accountURL;
// - (void).cxx_destruct;
- (void)takeAction;
- (void)notNow;
- (void)configure:(BOOL)arg1 requirePasscodeForActions:(BOOL)arg2;
- (id)initWithAccountURL:(id)arg1;

@end


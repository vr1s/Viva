//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <SpringBoard/SBTransaction.h>

@class NSMutableSet, NSSet, STTelephonyStatusDomain;

@interface SBAppRepairTransaction : SBTransaction
{
    NSSet *_appInfos;
    NSMutableSet *_repairRequests;
    STTelephonyStatusDomain *_telephonyDomain;
}

@property(readonly, copy, nonatomic) NSSet *appInfos; // @synthesize appInfos=_appInfos;
// - (void).cxx_destruct;
- (void)_startAppRepairs;
- (void)_completeRequest:(id)arg1 success:(BOOL)arg2 error:(id)arg3;
- (void)_evaluateCompletion;
- (BOOL)_canBeInterrupted;
- (void)_didComplete;
- (void)_begin;
- (id)initWithApplicationInfos:(id)arg1;

@end


//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <SpringBoard/_SBIdleTimerGlobalSettingMonitor.h>

@class NSNumber;

@interface _SBIdleTimerGlobalNumericSettingMonitor : _SBIdleTimerGlobalSettingMonitor
{
    NSNumber *_settingCache;
    id /* CDUnknownBlockType */ _fetchSettingFromSource;
}

// - (void).cxx_destruct;
- (id)formattedValue;
@property(readonly, nonatomic) NSNumber *numericValue;
- (void)_settingChanged:(id)arg1;
- (BOOL)_updateCache;
- (void)dealloc;
- (id)initWithLabel:(id)arg1 delegate:(id)arg2 updatingForNotification:(id)arg3 fetchingWith:(id /* CDUnknownBlockType */)arg4;

@end


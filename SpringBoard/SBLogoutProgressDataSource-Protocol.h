//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//


@class NSArray, NSDictionary, SBLogoutProgressTransientOverlayViewController;

@protocol SBLogoutProgressDataSource <NSObject>
- (NSArray *)pendingApplicationsForLogoutProgressTransientOverlayViewController:(SBLogoutProgressTransientOverlayViewController *)arg1;

@optional
- (NSDictionary *)debugBlockingTasksForLogoutProgressTransientOverlayViewController:(SBLogoutProgressTransientOverlayViewController *)arg1;
@end


//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//


@class NSSet, UABestAppSuggestion;

@protocol UABestAppSuggestionManagerDelegate <NSObject>

@optional
- (void)connectionInterrupted;
- (void)bestAppSuggestionChanged:(UABestAppSuggestion *)arg1 withAdditionalSuggestions:(NSSet *)arg2;
- (void)bestAppSuggestionChanged:(UABestAppSuggestion *)arg1;
- (void)bestAppSuggestionMayHaveChanged;
@end


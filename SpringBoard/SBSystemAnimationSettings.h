//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <PrototypeTools/PTSettings.h>

@class SBEntityRemovalAnimationSettings, SBFAnimationSettings, SBFWakeAnimationSettings;

@interface SBSystemAnimationSettings : PTSettings
{
    float _assistantAnimationDuration;
    float _assistantDismissAnimationDurationOverApp;
    float _spotlightNoninteractiveAnimationDuration;
    SBFAnimationSettings *_slideoverDosidoAnimationSettings;
    SBEntityRemovalAnimationSettings *_entityRemovalAnimationSettings;
    SBFWakeAnimationSettings *_wakeAnimationSettings;
}

+ (id)settingsControllerModule;
@property(retain, nonatomic) SBFWakeAnimationSettings *wakeAnimationSettings; // @synthesize wakeAnimationSettings=_wakeAnimationSettings;
@property(retain, nonatomic) SBEntityRemovalAnimationSettings *entityRemovalAnimationSettings; // @synthesize entityRemovalAnimationSettings=_entityRemovalAnimationSettings;
@property(retain, nonatomic) SBFAnimationSettings *slideoverDosidoAnimationSettings; // @synthesize slideoverDosidoAnimationSettings=_slideoverDosidoAnimationSettings;
@property(nonatomic) float spotlightNoninteractiveAnimationDuration; // @synthesize spotlightNoninteractiveAnimationDuration=_spotlightNoninteractiveAnimationDuration;
@property(nonatomic) float assistantDismissAnimationDurationOverApp; // @synthesize assistantDismissAnimationDurationOverApp=_assistantDismissAnimationDurationOverApp;
@property(nonatomic) float assistantAnimationDuration; // @synthesize assistantAnimationDuration=_assistantAnimationDuration;
// - (void).cxx_destruct;
- (void)setDefaultValues;

@end


//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <SpringBoard/SBHardwareButtonGestureParametersProviderBase.h>

#import <SpringBoard/SBHardwareButtonInteraction-Protocol.h>

@class SBSiriHardwareButtonInteraction;

@interface SBSiriHardwareButtonEventsOnlyButtonInteraction : SBHardwareButtonGestureParametersProviderBase <SBHardwareButtonInteraction>
{
    long long _siriButtonIdentifier;
    SBSiriHardwareButtonInteraction *_parentSiriInteraction;
}

+ (id)hardwareButtonInteractionForHomeButtonForwardingToInteraction:(id)arg1;
@property(nonatomic) __weak SBSiriHardwareButtonInteraction *parentSiriInteraction; // @synthesize parentSiriInteraction=_parentSiriInteraction;
@property(nonatomic) long long siriButtonIdentifier; // @synthesize siriButtonIdentifier=_siriButtonIdentifier;
// - (void).cxx_destruct;
- (BOOL)consumeSinglePressUp;

@end


//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <SpringBoard/SBSwitcherModifier.h>

@class NSArray, SBAppLayout;

@interface SBInsertionSwitcherModifier : SBSwitcherModifier
{
    SBAppLayout *_appLayout;
    BOOL _keepAppLayoutsBeforeInsertionInHierarchy;
    NSUInteger _indexToScrollToAfterInsertion;
    CGPoint _contentOffsetBeforeInsertion;
    NSArray *_appLayoutsVisibleBeforeInsertion;
    NSUInteger _phase;
}

@property(readonly, nonatomic) NSUInteger phase; // @synthesize phase=_phase;
// - (void).cxx_destruct;
- (id)appLayoutsForInsertionOrRemoval;
- (double)opacityForIndex:(NSUInteger)arg1;
- (BOOL)clipsToUnobscuredMarginAtIndex:(NSUInteger)arg1;
- (long long)layoutUpdateMode;
- (BOOL)isIndexVisible:(NSUInteger)arg1;
- (CGPoint)scrollViewContentOffset;
- (id)appLayouts;
- (id)handleInsertionEvent:(id)arg1;
- (id)initWithAppLayout:(id)arg1;

@end


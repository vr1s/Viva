// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBDOCKICONLISTVIEW_H
#define SBDOCKICONLISTVIEW_H

#include "SBIconListView.h"

@interface SBDockIconListView : SBIconListView

-(BOOL)_shouldAnimatePropertyWithKey:(id)arg0 ;
-(BOOL)isVertical;
-(BOOL)adaptsOrientationToTraitCollection;
-(id)initWithModel:(id)arg0 layoutProvider:(id)arg1 iconLocation:(id)arg2 orientation:(NSInteger)arg3 iconViewProvider:(id)arg4 ;
+(struct CGRect )defaultFrameForOrientation:(NSInteger)arg0 ;
+(NSUInteger)defaultIconViewConfigurationOptions;
+(CGFloat)defaultHeight;


@end


#endif


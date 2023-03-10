#include "HPEditorViewNavigationTabBar.h"

// TODO: move logic from HPEditorViewController to here, regarding what these buttons actually do.

#define kButtonSize 40
#define kButtonSpacing 10

#define possibleMaxIndex floor((self.frame.size.height / 50))-1

@implementation HPEditorViewNavigationTabBar

- (void)addSubview:(UIView*)subview toTabBarIndex:(NSUInteger)index 
{
    subview.frame = CGRectMake(0, 0 + (kButtonSpacing+kButtonSize) * index, kButtonSize, kButtonSize);
    [self addSubview:subview];
}

- (void)addSubview:(UIView*)subview toBackwardsTabBarIndex:(NSUInteger)index 
{
    subview.frame = CGRectMake(0, 0 + (kButtonSpacing+kButtonSize) * (possibleMaxIndex - index), kButtonSize, kButtonSize);
    [self addSubview:subview];
}

@end
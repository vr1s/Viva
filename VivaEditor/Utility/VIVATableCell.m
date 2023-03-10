#include "VIVATableCell.h"

@implementation VIVATableCell

- (void)setFrame:(CGRect)frame 
{
    frame.origin.x += 10;
    frame.size.width -= 2 * 10;
    [super setFrame:frame];
}

@end
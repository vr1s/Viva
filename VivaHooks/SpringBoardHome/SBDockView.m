#include <Foundation/Foundation.h>


@hook SBDockView

// This is what we need to hook to hide the dock background cleanly
// This tidbit works across versions, so we can call it in the base group (%init)

- (id)initWithDockListView:(id)arg1 forSnapshot:(BOOL)arg2 
{
    id x = @orig(arg1, arg2);

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(layoutSubviews) name:@"VIVALayoutDockView" object:nil];

    return x;
}
@end
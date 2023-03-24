#include <UIKit/UIKit.h>

#include <SpringBoard/SpringBoard.h>

#include "VIVAUIManager.h"
#include "VIVAManager.h"


@hook SBCoverSheetWindow

// This is the lock screen // drag down thing
// Pulling it down will disable the editor view

- (BOOL)becomeFirstResponder 
{
    BOOL x = @orig();

    if ([(SpringBoard*)[UIApplication sharedApplication] isShowingHomescreen] && [VIVAManager sharedInstance]._rtEditingEnabled)
    {
        [[VIVAUIManager sharedInstance] hideEditorView];
        [VIVAManager sharedInstance]._rtEditingEnabled = NO;
    }

    return x;
}

@end
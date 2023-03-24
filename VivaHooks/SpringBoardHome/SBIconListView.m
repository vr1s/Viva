#include <SpringBoardHome/SBIcon.h>
#include "VIVAConfigurationManager.h"

typedef struct SBIconCoordinate {
    NSInteger column;
    NSInteger row;
} SBIconCoordinate;

@hook SBIconListView


-(BOOL)automaticallyAdjustsLayoutMetricsToFit
{
    return NO;
}

@end

#include "HomePlus.h"

%hook SBIconListModel

- (SBIconListModel *)initWithUniqueIdentifier:(id)uid
        folder:(SBFolder *)folder
        gridSize:(SBHIconGridSize)gridSize
        gridSizeClassSizes:(SBHIconGridSizeClassSizes)sizes

{
if (gridSize.height == -1)
{
SBHIconGridSizeClassSizes fixedSizes = { .small = { .width = 2, .height = 2 }, .medium = { .width = 4, .height = 2 },
        .large = { .width = 4, .height = 4 }, .extralarge = { .width = 4, .height = 6 } };
return %orig(uid, folder, gridSize, fixedSizes);
}
return %orig(uid, folder, gridSize, sizes);
}
%end


// idk why we're forced to do this
%hook SBHLibraryCategoriesRootFolder

-(SBHLibraryCategoriesRootFolder *)initWithUniqueIdentifier:(id)arg1
        displayName:(id)arg2
        maxListCount:(NSUInteger)arg3
        listGridSize:(SBHIconGridSize)arg4
        iconGridSizeClassSizes:(SBHIconGridSizeClassSizes)arg5
{

SBHIconGridSizeClassSizes sizes = { .small = { .width = 2, .height = 2 }, .medium = { .width = 4, .height = 2 },
        .large = { .width = 4, .height = 4 }, .extralarge = { .width = 4, .height = 6 } };

return %orig(arg1, arg2, arg3, arg4, sizes);
}

%end

%hook SBIconListView
-(BOOL)automaticallyAdjustsLayoutMetricsToFit
{return NO;}
%end

%hook _SBHLibraryPodIconListView
-(CGSize)iconSpacing
{
return CGSizeMake(27, 35);
}
%end
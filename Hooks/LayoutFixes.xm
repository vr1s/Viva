#include "HomePlus.h"

%group iOS14

// idk why we're forced to do this
%hook SBHLibraryCategoriesRootFolder

-(SBHLibraryCategoriesRootFolder *)initWithUniqueIdentifier:(id)arg1
        displayName:(id)arg2
        maxListCount:(NSUInteger)arg3
        listGridSize:(SBHIconGridSize)arg4
        iconGridSizeClassSizes:(SBHIconGridSizeClassSizes)arg5
{

SBHIconGridSizeClassSizes sizes = { .small = { .columns = 2, .rows = 2 }, .medium = { .columns = 4, .rows = 2 },
        .large = { .columns = 4, .rows = 4 }, .extralarge = { .columns = 4, .rows = 6 } };
return %orig(arg1, arg2, arg3, arg4, sizes);
}

%end
%end

%group iOS15

// idk why we're forced to do this
%hook SBHLibraryCategoriesRootFolder

-(SBHLibraryCategoriesRootFolder *)initWithUniqueIdentifier:(id)arg1
        displayName:(id)arg2
        maxListCount:(NSUInteger)arg3
        listGridSize:(SBHIconGridSize)arg4
        iconGridSizeClassSizes:(SBHIconGridSizeClassSizes *)arg5
{

SBHIconGridSizeClassSizes sizes = { .small = { .columns = 2, .rows = 2 }, .medium = { .columns = 4, .rows = 2 },
        .large = { .columns = 4, .rows = 4 }, .extralarge = { .columns = 4, .rows = 6 } };
    return %orig(arg1, arg2, arg3, arg4, &sizes);
}

%end
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

%ctor {
    if (@available(iOS 15, *))
        %init(iOS15);
    else
        %init(iOS14);
    %init()
};
SBIconListModel
+(void)layOutIcons:(id)arg0 atIndexes:(id)arg1 inGridCellInfo:(id)arg2 startingAtGridCellIndex:(NSUInteger)arg3 gridSize:(struct SBHIconGridSize )arg4 gridSizeClassSizes:(struct SBHIconGridSizeClassSizes )arg5 iconLayoutBehavior:(NSUInteger)arg6 referenceIconOrder:(id)arg7 options:(NSUInteger)arg8 ;


1c3195618  void _SBHIconGridSizeClassIconImageInfosUpdateImageInfo(
1c3195618      int64_t* arg1, int64_t arg2, int64_t arg3, int64_t arg4, 
1c3195618      int64_t arg5, int64_t arg6)

1c319561c      if (arg2 u<= 5)
1c319562c          void* x8_1
1c319562c          switch (arg2)
1c3195638              case 0
1c3195638                  *arg1 = arg3
1c3195638                  arg1[1] = arg4
1c319563c                  x8_1 = &arg1[3]
1c3195640                  arg1[2] = arg5
1c3195648              case 1
1c3195648                  arg1[4] = arg3
1c3195648                  arg1[5] = arg4
1c319564c                  x8_1 = &arg1[7]
1c3195650                  arg1[6] = arg5
1c3195658              case 2
1c3195658                  arg1[8] = arg3
1c3195658                  arg1[9] = arg4
1c319565c                  x8_1 = &arg1[0xb]
1c3195660                  arg1[0xa] = arg5
1c3195668              case 3
1c3195668                  arg1[0xc] = arg3
1c3195668                  arg1[0xd] = arg4
1c319566c                  x8_1 = &arg1[0xf]
1c3195670                  arg1[0xe] = arg5
1c3195678              case 4
1c3195678                  arg1[0x14] = arg3
1c3195678                  arg1[0x15] = arg4
1c319567c                  x8_1 = &arg1[0x17]
1c3195680                  arg1[0x16] = arg5
1c3195688              case 5
1c3195688                  arg1[0x10] = arg3
1c3195688                  arg1[0x11] = arg4
1c319568c                  x8_1 = &arg1[0x13]
1c3195690                  arg1[0x12] = arg5
1c3195694          *x8_1 = arg6

typedef struct SBHIconGridSizeClassIconImageInfos {
    SBIconImageInfo icon;
    SBIconImageInfo small;
    SBIconImageInfo medium;
    SBIconImageInfo large;
    SBIconImageInfo newsLargeTall;
    SBIconImageInfo extraLarge;
} SBHIconGridSizeClassIconImageInfos;

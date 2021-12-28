//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <SpringBoardHome/BSDescriptionProviding-Protocol.h>

typedef struct {
	double value;
	BOOL inclusive;
} SCD_Struct_SB4;

typedef struct {
	SCD_Struct_SB4 start;
	SCD_Struct_SB4 end;
} SCD_Struct_SB5;

typedef struct SBIconImageInfo {
	CGSize size;
	double scale;
	double continuousCornerRadius;
} SBIconImageInfo;

typedef struct {
	unsigned long long field1;
	id field2;
	unsigned long long field3;
	unsigned long long field4[5];
} SCD_Struct_SB12;

typedef struct SBVisibleColumnRange {
	unsigned long long iconListIndex;
	NSRange columnRange;
} SBVisibleColumnRange;

typedef struct SBIconListPredictedVisibleColumn {
	unsigned long long column;
	double confidence;
} SBIconListPredictedVisibleColumn;

typedef struct SBFolderPredictedVisibleColumn {
	unsigned long long iconListIndex;
	SBIconListPredictedVisibleColumn predictedVisibleColumn;
} SBFolderPredictedVisibleColumn;

typedef struct {
	CGRect field1;
	CGRect field2;
	CGRect field3;
	CGRect field4;
	CGRect field5;
} SCD_Struct_SB17;

typedef struct SBIconCoordinate {
	long long row;
	long long col;
} SBIconCoordinate;

typedef struct {
	UIEdgeInsets field1;
	CGRect field2;
	CGRect field3;
	CGRect field4;
	CGRect field5;
	double field6;
} SCD_Struct_SB19;

@class NSMutableDictionary, NSString, SBHClockIconVisualConfiguration, SBHFloatyFolderVisualConfiguration, SBHFolderIconVisualConfiguration, SBHIconAccessoryVisualConfiguration, SBHSidebarVisualConfiguration;

@interface SBIconListGridLayoutConfiguration : NSObject <NSCopying, BSDescriptionProviding>
{
    NSMutableDictionary *_iconLabelVisualConfigurations;
    NSUInteger _numberOfPortraitColumns;
    NSUInteger _numberOfPortraitRows;
    NSUInteger _numberOfLandscapeColumns;
    NSUInteger _numberOfLandscapeRows;
    SBHIconAccessoryVisualConfiguration *_iconAccessoryVisualConfiguration;
    SBHFolderIconVisualConfiguration *_folderIconVisualConfiguration;
    SBHClockIconVisualConfiguration *_clockIconVisualConfiguration;
    SBHFloatyFolderVisualConfiguration *_floatyFolderVisualConfiguration;
    SBHSidebarVisualConfiguration *_sidebarVisualConfiguration;
    UIEdgeInsets _portraitLayoutInsets;
    UIEdgeInsets _landscapeLayoutInsets;
    struct SBIconImageInfo _iconImageInfo;
}

@property(copy, nonatomic) SBHSidebarVisualConfiguration *sidebarVisualConfiguration; // @synthesize sidebarVisualConfiguration=_sidebarVisualConfiguration;
@property(copy, nonatomic) SBHFloatyFolderVisualConfiguration *floatyFolderVisualConfiguration; // @synthesize floatyFolderVisualConfiguration=_floatyFolderVisualConfiguration;
@property(copy, nonatomic) SBHClockIconVisualConfiguration *clockIconVisualConfiguration; // @synthesize clockIconVisualConfiguration=_clockIconVisualConfiguration;
@property(copy, nonatomic) SBHFolderIconVisualConfiguration *folderIconVisualConfiguration; // @synthesize folderIconVisualConfiguration=_folderIconVisualConfiguration;
@property(copy, nonatomic) SBHIconAccessoryVisualConfiguration *iconAccessoryVisualConfiguration; // @synthesize iconAccessoryVisualConfiguration=_iconAccessoryVisualConfiguration;
@property(nonatomic) struct SBIconImageInfo iconImageInfo; // @synthesize iconImageInfo=_iconImageInfo;
@property(nonatomic) UIEdgeInsets landscapeLayoutInsets; // @synthesize landscapeLayoutInsets=_landscapeLayoutInsets;
@property(nonatomic) UIEdgeInsets portraitLayoutInsets; // @synthesize portraitLayoutInsets=_portraitLayoutInsets;
@property(nonatomic) NSUInteger numberOfLandscapeRows; // @synthesize numberOfLandscapeRows=_numberOfLandscapeRows;
@property(nonatomic) NSUInteger numberOfLandscapeColumns; // @synthesize numberOfLandscapeColumns=_numberOfLandscapeColumns;
@property(nonatomic) NSUInteger numberOfPortraitRows; // @synthesize numberOfPortraitRows=_numberOfPortraitRows;
@property(nonatomic) NSUInteger numberOfPortraitColumns; // @synthesize numberOfPortraitColumns=_numberOfPortraitColumns;
// - (void).cxx_destruct;
- (id)descriptionBuilderWithMultilinePrefix:(id)arg1;
- (id)descriptionWithMultilinePrefix:(id)arg1;
- (id)succinctDescriptionBuilder;
- (id)succinctDescription;
@property(readonly, copy) NSString *description;
// - (id)copyWithZone:(_NSZone )arg1;
- (void)setIconLabelVisualConfiguration:(id)arg1 forContentSizeCategory:(id)arg2;
- (id)iconLabelVisualConfigurationForContentSizeCategory:(id)arg1;
- (id)init;

@end


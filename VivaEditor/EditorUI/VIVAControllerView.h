//
// VIVAControllerView.h
// Viva
//
// Authors: vriska
// Created  Oct 2019
//

#include "../Utility/OBSlider.h"
#include <UIKit/UIKit.h>

#ifndef VIVACONTROLLERVIEW_H
#define VIVACONTROLLERVIEW_H

#include "../../VIVAManager.h"
#define kLeftScreenBuffer 0.146
#define kTopContainerTopAnchor 0.7697
#define kContainerHeight 0.123
#define kResetButtonSize 25.0

typedef enum VIVAControllerItemType : NSUInteger {
    kVIVAControllerItemTypeSlider,
    kVIVAControllerItemTypeCounter,
    kVIVAControllerItemTypeSwitch,
    kVIVAControllerItemTypeNone
} VIVAControllerItemType;

typedef struct VIVAControllerItemInfo {
    NSString *label;
    NSString *configKey;
    NSInteger min;
    NSInteger max;
    NSInteger defaultValue;
} VIVAControllerItemInfo;

typedef struct VIVAControllerViewItem {
    VIVAControllerItemType itemType;
    VIVAControllerItemInfo itemInfo;
} VIVAControllerViewItem;

typedef struct VIVAControllerViewConfiguration {
    VIVAControllerViewItem topControl;
    VIVAControllerViewItem bottomControl;
} VIVAControllerViewConfiguration;

@interface VIVAControllerView : UIView

@property (nonatomic, retain) UIView *topView;
@property (nonatomic, retain) UIView *bottomView;

@property (nonatomic, retain) UILabel *topLabel;
@property (nonatomic, retain) OBSlider *topControl;
@property (nonatomic, retain) UITextField *topTextField;

@property (nonatomic, retain) UILabel *bottomLabel;
@property (nonatomic, retain) OBSlider *bottomControl;
@property (nonatomic, retain) UITextField *bottomTextField;

@property (nonatomic, retain) UIButton *topResetButton;
@property (nonatomic, retain) UIButton *bottomResetButton;

@property (nonatomic, assign) VIVAControllerViewConfiguration config;

- (instancetype)initWithFrame:(CGRect)frame config:(VIVAControllerViewConfiguration)config;

- (void)layoutControllerView;

- (void)topSliderUpdated:(UISlider *)slider;
- (void)bottomSliderUpdated:(UISlider *)slider;

- (void)topTextFieldBeganEditing:(UITextField *)textField;
- (void)topTextFieldEndedEditing:(UITextField *)textField;
- (void)topTextFieldUpdated:(UITextField *)textField;
- (void)invertTopTextField;

- (void)bottomTextFieldBeganEditing:(UITextField *)textField;
- (void)bottomTextFieldEndedEditing:(UITextField *)textField;
- (void)bottomTextFieldUpdated:(UITextField *)textField;

- (void)invertBottomTextField;

- (void)handleTopResetButtonPress:(UIButton*)sender;
- (void)handleBottomResetButtonPress:(UIButton*)sender;

@end


@interface VIVAOffsetControllerView : VIVAControllerView

@property (nonatomic, retain) UILabel *leftOffsetLabel;

@end

@interface VIVAIconCountControllerView : VIVAControllerView

@end

@interface VIVAScaleControllerView : VIVAControllerView

@end

@interface VIVASpacingControllerView : VIVAControllerView

@end

#endif
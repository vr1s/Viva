//
// HPControllerView.h
// HomePlus
//
// Authors: Kritanta
// Created  Oct 2019
//

#include "../Utility/OBSlider.h"
#include <UIKit/UIKit.h>

#ifndef HPCONTROLLERVIEW_H
#define HPCONTROLLERVIEW_H

#include "../../HPManager.h"
#define kLeftScreenBuffer 0.146
#define kTopContainerTopAnchor 0.7697
#define kContainerHeight 0.123
#define kResetButtonSize 25.0

typedef enum HPControllerItemType : NSUInteger {
    kHPControllerItemTypeSlider,
    kHPControllerItemTypeCounter,
    kHPControllerItemTypeSwitch,
    kHPControllerItemTypeNone
} HPControllerItemType;

typedef struct HPControllerItemInfo {
    NSString *label;
    NSString *configKey;
    NSInteger min;
    NSInteger max;
    NSInteger defaultValue;
} HPControllerItemInfo;

typedef struct HPControllerViewItem {
    HPControllerItemType itemType;
    HPControllerItemInfo itemInfo;
} HPControllerViewItem;

typedef struct HPControllerViewConfiguration {
    HPControllerViewItem topControl;
    HPControllerViewItem bottomControl;
} HPControllerViewConfiguration;

@interface HPControllerView : UIView

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

@property (nonatomic, assign) HPControllerViewConfiguration config;

- (instancetype)initWithFrame:(CGRect)frame config:(HPControllerViewConfiguration)config;

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


@interface HPOffsetControllerView : HPControllerView

@property (nonatomic, retain) UILabel *leftOffsetLabel;

@end

@interface HPIconCountControllerView : HPControllerView

@end

@interface HPScaleControllerView : HPControllerView

@end

@interface HPSpacingControllerView : HPControllerView

@end

#endif
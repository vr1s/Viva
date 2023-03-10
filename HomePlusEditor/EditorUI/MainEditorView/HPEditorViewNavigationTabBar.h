//
// HPEditorViewNavigationTabBar.h
// HomePlus
//
// Little class stub for the vertical tab bars in the tweak
// I have no idea if .buttons is even used, but I don't think so
// Eventually this can be expanded to offload certain functions here,
//      although currently most of the stuff is handled manually by the ViewController
//
// Authors: Kritanta
// Created  Dec 2019
//

#include <UIKit/UIKit.h>

#ifndef HPEDITORVIEWNAVIGATIONTABBAR_H
#define HPEDITORVIEWNAVIGATIONTABBAR_H
@interface HPEditorViewNavigationTabBar : UIView

@property (nonatomic, retain) NSMutableArray *buttons;

- (void)addSubview:(UIView*)subview toTabBarIndex:(NSUInteger)index ;
- (void)addSubview:(UIView*)subview toBackwardsTabBarIndex:(NSUInteger)index ;

@end

#endif
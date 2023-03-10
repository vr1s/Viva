//
// VIVAEditorViewNavigationTabBar.h
// Viva
//
// Little class stub for the vertical tab bars in the tweak
// I have no idea if .buttons is even used, but I don't think so
// Eventually this can be expanded to offload certain functions here,
//      although currently most of the stuff is handled manually by the ViewController
//
// Authors: vriska
// Created  Dec 2019
//

#include <UIKit/UIKit.h>

#ifndef VIVAEDITORVIEWNAVIGATIONTABBAR_H
#define VIVAEDITORVIEWNAVIGATIONTABBAR_H
@interface VIVAEditorViewNavigationTabBar : UIView

@property (nonatomic, retain) NSMutableArray *buttons;

- (void)addSubview:(UIView*)subview toTabBarIndex:(NSUInteger)index ;
- (void)addSubview:(UIView*)subview toBackwardsTabBarIndex:(NSUInteger)index ;

@end

#endif
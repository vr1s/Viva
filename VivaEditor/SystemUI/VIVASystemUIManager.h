//
// Created by vrisk/a on 6/25/21.
//

@import Foundation;
@import UIKit;

#ifndef VIVA_VIVASYSTEMUIMANAGER_H
#define VIVA_VIVASYSTEMUIMANAGER_H

#define KICKED_UP YES
#define NORMAL NO
#define KickupState BOOL

@interface VIVASystemUIManager : NSObject
+ (instancetype)sharedInstance;

@property (nonatomic, retain)  UIView *wallpaperWindow;
@property (nonatomic, retain)  UIView *homeWindow;
@property (nonatomic, retain)  UIView *floatingDockWindow;
@property (nonatomic, retain)  UIView *mockBackgroundView;

-(void)hideFloatingDockView:(BOOL)shouldHide;
@end

#endif //VIVA_VIVASYSTEMUIMANAGER_H
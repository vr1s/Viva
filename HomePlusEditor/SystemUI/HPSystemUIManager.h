//
// Created by Kritanta on 6/25/21.
//

@import Foundation;
@import UIKit;

#ifndef HOMEPLUS_HPSYSTEMUIMANAGER_H
#define HOMEPLUS_HPSYSTEMUIMANAGER_H

#define KICKED_UP YES
#define NORMAL NO
#define KickupState BOOL

@interface HPSystemUIManager : NSObject
+ (instancetype)sharedInstance;

@property (nonatomic, retain)  UIView *wallpaperWindow;
@property (nonatomic, retain)  UIView *homeWindow;
@property (nonatomic, retain)  UIView *floatingDockWindow;
@property (nonatomic, retain)  UIView *mockBackgroundView;
@end

#endif //HOMEPLUS_HPSYSTEMUIMANAGER_H
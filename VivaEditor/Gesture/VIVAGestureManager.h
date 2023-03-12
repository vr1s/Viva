//
// Created by vrisk/a on 6/24/21.
//

@import Foundation;
@import UIKit;
#import <objc/NSObject.h>

@class VIVAHitboxView;
@class VIVAHitboxWindow;

#ifndef VIVA_VIVAGESTURERECOGNIZERVIEW_H
#define VIVA_VIVAGESTURERECOGNIZERVIEW_H


@interface UISystemGestureView : UIView 
@end

@interface SBMainDisplaySystemGestureRecognizer : NSObject
+(SBMainDisplaySystemGestureRecognizer *)mainDisplayManager;
-(void)addGestureRecognizer:(UIGestureRecognizer *)recognizer withType:(NSUInteger)type;
@end
// _UISystemGestureManager addGestureRecognizer:toDisplayWithIdentity:
@class FBSDisplayIdentity;
@interface FBSDisplayConfiguration : NSObject
@property (nonatomic, retain) FBSDisplayIdentity *identity;
@end
@interface UIScreen (priv)
@property (nonatomic, retain) FBSDisplayConfiguration *displayConfiguration;
@end
@interface _UISystemGestureManager : NSObject
+(_UISystemGestureManager *)sharedInstance;
-(void)addGestureRecognizer:(UIGestureRecognizer *)recognizer toDisplayWithIdentity:(FBSDisplayIdentity *)identity;
@end


@interface VIVAGestureManager : NSObject

@property (nonatomic, assign) BOOL editorOpened;
@property (nonatomic, assign) CGFloat panAmount;
@property (nonatomic, assign) BOOL editorActivated;
@property (nonatomic, assign) BOOL hitboxMaxed;
@property (nonatomic, retain) VIVAHitboxView *hp_larger_hitbox;
@property (nonatomic, retain) VIVAHitboxWindow *hp_larger_window;
@property (nonatomic, retain) VIVAHitboxView *hp_hitbox;
@property (nonatomic, retain) VIVAHitboxWindow *hp_hitbox_window;

@property (nonatomic, retain) UISystemGestureView *systemGestureView;

@property (nonatomic, strong) UIPinchGestureRecognizer *activeGestureRecognizer;
@property (nonatomic, strong) UIPinchGestureRecognizer *inactiveGestureRecognizer;

+ (instancetype)sharedInstance;

- (void)insertGestureRecognizers:(_UISystemGestureManager *)gestureManager;
- (void)setSystemGestureView:(UISystemGestureView *)systemGestureView;

- (void)handlePinchGesture:(UIPinchGestureRecognizer *)gestureRecognizer;
@end

// can we do both of these differently?

#define kMaxAmt 80

static CGFloat lastAmount = 1;

#endif //VIVA_VIVAGESTURERECOGNIZERVIEW_H
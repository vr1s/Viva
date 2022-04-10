// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBDOCKVIEW_H
#define SBDOCKVIEW_H


#import <UIKit/UIKit.h>

@class SBHighlightView;
@class SBDockIconListView;
@protocol SBDockViewDelegate;

@interface SBDockView : UIView {
SBHighlightView *_highlightView;
UIImageView *_backgroundImageView;
UIView *_accessibilityBackgroundView;
BOOL _forSnapshot;
}


@property (readonly, nonatomic) UIColor *accessibilityBackgroundColor;
@property (retain, nonatomic) UIView *backgroundView; // ivar: _backgroundView
@property (nonatomic) NSUInteger dockEdge; // ivar: _dockEdge
@property (readonly, nonatomic) CGFloat dockHeight;
@property (readonly, nonatomic) CGFloat dockHeightPadding;
@property (readonly, nonatomic) CGRect dockListViewFrame;
@property (readonly, nonatomic) SBDockIconListView *dockListView; // ivar: _iconListView
@property (nonatomic) CGFloat dockListOffset; // ivar: _dockListOffset
@property (weak, nonatomic) NSObject<SBDockViewDelegate> *delegate; // ivar: _delegate
@property (readonly, nonatomic) BOOL dockInset;


-(void)minimumHomeScreenScaleDidChange;
-(id)traitCollection;
-(void)_updateCornerRadii;
-(struct UIEdgeInsets )_dockOverhangInsets;
-(void)_backgroundContrastDidChange:(id)arg0 ;
-(void)setBackgroundAlpha:(CGFloat)arg0 ;
-(CGFloat)_minimumHomeScreenScale;
-(void)updateAccessibilityTintColor;
-(CGFloat)_layoutScale;
-(void)traitCollectionDidChange:(id)arg0 ;
-(id)_visualConfiguration;
-(void)layoutSubviews;
-(id)initWithDockListView:(id)arg0 forSnapshot:(BOOL)arg1 ;
-(void)didMoveToWindow;
-(id)_listLayout;
-(void)dealloc;


@end


#endif


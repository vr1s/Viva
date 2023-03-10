// Headers generated with ktool v1.2.0
// https://github.com/cxnder/ktool | pip3 install k2l
// Platform: IOS | Minimum OS: 14.8.0 | SDK: 14.8.0


#ifndef SBWALLPAPERCONTROLLER_H
#define SBWALLPAPERCONTROLLER_H

@protocol SBFIrisWallpaperView;
@protocol SBUIWallpaperOverlay;

@class PTSingleTestRecipe;
@class SBFWallpaperConfigurationManager;
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>

@class SBWallpaperViewController;
@class SBWallpaperAggdLogger;
@protocol SBFLegibilitySettingsProviderDelegate;
@protocol SBFWallpaperViewInternalObserver;
@protocol SBUIActiveOrientationObserver;
@protocol _UISettingsKeyObserver;
@protocol SBWallpaperPresentingDelegate;
@protocol SBWallpaperReachabilityCoordinating;
@protocol BSDescriptionProviding;
@protocol SBWallpaperServerDelegate;
@protocol SBFWallpaperViewDelegate;
@protocol UIWindowDelegate;
@protocol CSWallpaperOverlayHosting;
@protocol SBWallpaperPresenting;
@protocol SBWallpaperLegibilityProviding;
@protocol BSInvalidatable;
@protocol BSInvalidatable;
@protocol SBWallpaperPresenting;
@protocol SBWallpaperLegibilityProviding;
@protocol SBWallpaperPresentingDelegate;

@interface SBWallpaperController : NSObject <SBFLegibilitySettingsProviderDelegate, SBFWallpaperViewInternalObserver, SBUIActiveOrientationObserver, _UISettingsKeyObserver, SBWallpaperPresentingDelegate, SBWallpaperReachabilityCoordinating, BSDescriptionProviding, SBWallpaperServerDelegate, SBFWallpaperViewDelegate, UIWindowDelegate, CSWallpaperOverlayHosting, SBWallpaperPresenting, SBWallpaperLegibilityProviding>

{
UIWindow *_wallpaperWindow;
UIView *_wallpaperContainerView;
UIView *_wallpaperOverlayContainerView;
NSInteger _displayedVariant;
UIView<SBUIWallpaperOverlay> *_wallpaperOverlay;
NSMutableSet *_activeOrientationSources;
NSMapTable *_orientationProviders;
PTSingleTestRecipe *_migrationTestRecipe;
PTSingleTestRecipe *_reloadTestRecipe;
SBWallpaperViewController *_wallpaperViewController;
}


@property (retain, nonatomic) SBWallpaperAggdLogger *wallpaperAggdLogger; // ivar: _wallpaperAggdLogger
@property (readonly, nonatomic) NSInteger _orientation; // ivar: _orientation
@property (retain, nonatomic) UITraitCollection *fakeBlurViewOverrideTraitCollection; // ivar: _fakeBlurViewOverrideTraitCollection
@property (retain, nonatomic) NSObject<BSInvalidatable> *batterySaverAnimationAssertion; // ivar: _batterySaverAnimationAssertion
@property (retain, nonatomic) NSObject<BSInvalidatable> *wallpaperStyleAnimationAssertion; // ivar: _wallpaperStyleAnimationAssertion
@property (readonly, nonatomic) UIScreen *screen; // ivar: _screen
@property (readonly, copy, nonatomic) NSString *cachingIdentifier; // ivar: _cachingIdentifier
@property (readonly, nonatomic) NSObject<SBWallpaperPresenting> *presenter; // ivar: _wallpaperPresenter
@property (readonly, nonatomic) NSObject<SBWallpaperLegibilityProviding> *legibilityProvider; // ivar: _wallpaperLegibilityProvider
@property (nonatomic) CGFloat windowLevel;
@property (readonly, nonatomic) UIGestureRecognizer *wallpaperGestureRecognizer;
@property (readonly, nonatomic) NSInteger activeOrientationSource;
@property (readonly, nonatomic) SBFWallpaperConfigurationManager *wallpaperConfigurationManager; // ivar: _wallpaperConfigurationManager
@property (readonly) NSUInteger hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) CGFloat effectiveReachabilityYOffset;
@property (weak, nonatomic) NSObject<SBWallpaperPresentingDelegate> *wallpaperPresentingDelegate; // ivar: _wallpaperPresentingDelegate
@property (nonatomic) NSInteger variant;
@property (readonly, nonatomic) CGFloat homescreenWallpaperScale;
@property (readonly, nonatomic) CGFloat minimumHomescreenWallpaperScale;
@property (nonatomic) CGFloat lockscreenWallpaperScale;
@property (readonly, nonatomic) CGFloat minimumLockscreenWallpaperScale;
@property (readonly, nonatomic) NSObject<SBFIrisWallpaperView> *irisWallpaperView;

-(id)_window;
-(void)willAnimateRotationToInterfaceOrientation:(NSInteger)arg0 duration:(CGFloat)arg1 ;
-(void)cancelInProcessAnimations;
-(void)wallpaperView:(id)arg0 didChangeZoomFactor:(CGFloat)arg1 ;
-(void)activeInterfaceOrientationDidChangeToOrientation:(NSInteger)arg0 willAnimateWithDuration:(CGFloat)arg1 fromOrientation:(NSInteger)arg2 ;
-(void)addObserver:(id)arg0 forVariant:(NSInteger)arg1 ;
-(id)legibilitySettingsForVariant:(NSInteger)arg0 ;
-(id)averageColorForVariant:(NSInteger)arg0 ;
-(void)wallpaperServer:(id)arg0 setWallpaperVideoWithWallpaperMode:(id)arg1 cropRect:(struct CGRect )arg2 wallpaperMode:(NSInteger)arg3 completionHandler:(id)arg4 ;
-(void)_updateWallpaperForLocations:(NSInteger)arg0 options:(NSUInteger)arg1 wallpaperMode:(NSInteger)arg2 withCompletion:(id)arg3 ;
-(void)updateOrientationAfterSourceChange;
-(id)activeInterfaceOrientationSourcesDescriptions;
-(void)wallpaperViewDidChangeWantsRasterization:(id)arg0 ;
-(void)providerLegibilitySettingsChanged:(id)arg0 ;
-(void)preheatWallpaperForVariant:(NSInteger)arg0 ;
-(id)_wallpaperViewForVariant:(NSInteger)arg0 ;
-(CGFloat)contrastForVariant:(NSInteger)arg0 ;
-(id)suspendColorSamplingForReason:(id)arg0 ;
-(void)addReachabilityObserver:(id)arg0 ;
-(void)setAlpha:(CGFloat)arg0 forWallpaperVariant:(NSInteger)arg1 ;
-(void)updateWallpaperForLocations:(NSInteger)arg0 withCompletion:(id)arg1 ;
-(void)setDisallowsRasterization:(BOOL)arg0 forVariant:(NSInteger)arg1 withReason:(id)arg2 ;
-(id)averageColorInRect:(struct CGRect )arg0 forVariant:(NSInteger)arg1 ;
-(id)initWithWallpaperConfigurationManager:(id)arg0 cachingIdentifier:(id)arg1 ;
-(void)_batterySaverModeChanged:(id)arg0 ;
-(void)settings:(id)arg0 changedValueForKey:(id)arg1 ;
-(BOOL)updateIrisWallpaperForStaticMode;
-(void)updateIrisWallpaperForInteractiveMode;
-(void)setWallpaperHidden:(BOOL)arg0 variant:(NSInteger)arg1 reason:(id)arg2 ;
-(id)setHomescreenWallpaperScale:(CGFloat)arg0 withAnimationFactory:(id)arg1 ;
-(BOOL)_isAcceptingOrientationChangesFromSource:(NSInteger)arg0 ;
-(void)wallpaperPresenter:(id)arg0 didChangeWallpaperForLocations:(NSInteger)arg1 withConfiguration:(id)arg2 ;
-(BOOL)removeWallpaperStyleForPriority:(NSInteger)arg0 forVariant:(NSInteger)arg1 withAnimationFactory:(id)arg2 ;
-(void)wallpaperViewDidInvalidateBlurs:(id)arg0 ;
-(void)removeObserver:(id)arg0 forVariant:(NSInteger)arg1 ;
-(void)wallpaperServer:(id)arg0 fetchOriginalVideoURLDataForVariant:(NSInteger)arg1 completionHandler:(id)arg2 ;
-(BOOL)setWallpaperStyle:(NSInteger)arg0 forPriority:(NSInteger)arg1 forVariant:(NSInteger)arg2 withAnimationFactory:(id)arg3 ;
-(CGFloat)contrastInRect:(struct CGRect )arg0 forVariant:(NSInteger)arg1 ;
-(id)averageColorInRect:(struct CGRect )arg0 forVariant:(NSInteger)arg1 withSmudgeRadius:(CGFloat)arg2 ;
-(id)newFakeBlurViewForVariant:(NSInteger)arg0 style:(NSInteger)arg1 transformOptions:(NSUInteger)arg2 ;
-(void)removeReachabilityObserver:(id)arg0 ;
-(id)relinquishHostingOfWallpaperOverlay;
-(void)activeInterfaceOrientationWillChangeToOrientation:(NSInteger)arg0 ;
-(void)setLockscreenOnlyWallpaperAlpha:(CGFloat)arg0 ;
-(void)endDelayingHomescreenStyleChangesForReason:(id)arg0 animationFactory:(id)arg1 ;
-(void)updateWallpaperForLocations:(NSInteger)arg0 wallpaperMode:(NSInteger)arg1 withCompletion:(id)arg2 ;
-(id)beginRequiringWithReason:(id)arg0 ;
-(void)startHostingWallpaperOverlay:(id)arg0 ;
-(void)orientationSource:(NSInteger)arg0 willAnimateRotationToInterfaceOrientation:(NSInteger)arg1 duration:(CGFloat)arg2 ;
-(void)deactivateOrientationSource:(NSInteger)arg0 ;
-(NSInteger)defaultInterfaceOrientationForSource:(NSInteger)arg0 ;
-(void)_motionEffectsChanged;
-(void)orientationSource:(NSInteger)arg0 willRotateToInterfaceOrientation:(NSInteger)arg1 duration:(CGFloat)arg2 ;
-(void)wallpaperServer:(id)arg0 fetchOriginalImageDataForVariant:(NSInteger)arg1 completionHandler:(id)arg2 ;
-(void)wallpaperServer:(id)arg0 setWallpaperColor:(id)arg1 darkColor:(id)arg2 forVariants:(NSInteger)arg3 completionHandler:(id)arg4 ;
-(void)_noteSignificantTimeChanged:(id)arg0 ;
-(void)wallpaperServer:(id)arg0 setWallpaperGradient:(id)arg1 forVariants:(NSInteger)arg2 completionHandler:(id)arg3 ;
-(void)_reloadWallpaperAndFlushCaches:(BOOL)arg0 completionHandler:(id)arg1 ;
-(id)wallpaperView:(id)arg0 wallpaperConfigurationIncludingValueTypes:(NSUInteger)arg1 ;
-(id)succinctDescriptionBuilder;
-(void)wallpaperServer:(id)arg0 fetchContentCutoutBoundsForVariant:(NSInteger)arg1 orientation:(NSInteger)arg2 completionHandler:(id)arg3 ;
-(id)suspendWallpaperAnimationForReason:(id)arg0 ;
-(BOOL)isWindowIgnoredForReachability:(id)arg0 ;
-(id)init;
-(id)initWithWallpaperConfigurationManager:(id)arg0 ;
-(void)_forceUpdateToSpringBoardInterfaceOrientationWithAnimationDuration:(CGFloat)arg0 ;
-(void)_updateWallpaperForLocations:(NSInteger)arg0 options:(NSUInteger)arg1 withCompletion:(id)arg2 ;
-(id)descriptionWithMultilinePrefix:(id)arg0 ;
-(id)succinctDescription;
-(void)setOrientationProvider:(id)arg0 forSource:(NSInteger)arg1 ;
-(void)wallpaperServer:(id)arg0 setWallpaperColorName:(id)arg1 forVariants:(NSInteger)arg2 completionHandler:(id)arg3 ;
-(void)setLockscreenWallpaperContentsRect:(struct CGRect )arg0 ;
-(void)wallpaperServer:(id)arg0 restoreDefaultWallpaperWithCompletionHandler:(id)arg1 ;
-(void)_updateScreenBlanked;
-(id)descriptionBuilderWithMultilinePrefix:(id)arg0 ;
-(void)beginDelayingHomescreenStyleChangesForReason:(id)arg0 ;
-(NSInteger)wallpaperPresenter:(id)arg0 requestsOrientationWithRefresh:(BOOL)arg1 ;
-(void)wallpaperServer:(id)arg0 fetchThumbnailDataForVariant:(NSInteger)arg1 completionHandler:(id)arg2 ;
-(void)orientationSource:(NSInteger)arg0 didRotateFromInterfaceOrientation:(NSInteger)arg1 ;
-(void)dealloc;
-(void)activateOrientationSource:(NSInteger)arg0 ;
+(id)accessAuthenticator;
+(id)sharedInstance;


@end


#endif


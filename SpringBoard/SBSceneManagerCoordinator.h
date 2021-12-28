//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

#import <SpringBoard/FBProcessManagerObserver-Protocol.h>
#import <SpringBoard/FBSDisplayObserving-Protocol.h>
#import <SpringBoard/FBSceneDelegate-Protocol.h>
#import <SpringBoard/FBSceneManagerDelegate_Private-Protocol.h>
#import <SpringBoard/FBSceneManagerObserver-Protocol.h>
#import <SpringBoard/FBWorkspaceDelegate-Protocol.h>
#import <SpringBoard/SBSceneManagerReferenceDelegate-Protocol.h>

@class FBSceneManager, NSMutableDictionary, NSMutableSet, NSString, UIApplicationSceneDeactivationManager;

@interface SBSceneManagerCoordinator : NSObject <FBSceneManagerDelegate_Private, FBSceneManagerObserver, FBSceneDelegate, FBProcessManagerObserver, FBWorkspaceDelegate, FBSDisplayObserving, SBSceneManagerReferenceDelegate>
{
    FBSceneManager *_sceneManager;
    NSMutableDictionary *_displayIdentityToReferenceMap;
    NSMutableSet *_workspaceIdentifiersToIgnore;
    UIApplicationSceneDeactivationManager *_sceneDeactivationManager;
}

+ (id)secureMainDisplaySceneManager;
+ (id)mainDisplaySceneManager;
+ (id)sharedInstance;
@property(readonly, nonatomic) UIApplicationSceneDeactivationManager *sceneDeactivationManager; // @synthesize sceneDeactivationManager=_sceneDeactivationManager;
// - (void).cxx_destruct;
- (void)sceneManagerDidInvalidateForReference:(id)arg1;
- (void)displayMonitor:(id)arg1 willDisconnectIdentity:(id)arg2;
- (void)displayMonitor:(id)arg1 didConnectIdentity:(id)arg2 withConfiguration:(id)arg3;
- (void)workspace:(id)arg1 didReceiveSceneRequestWithOptions:(id)arg2 completion:(id /* CDUnknownBlockType */)arg3;
- (void)processManager:(id)arg1 didRemoveProcess:(id)arg2;
- (void)processManager:(id)arg1 didAddProcess:(id)arg2;
- (void)scene:(id)arg1 didReceiveActions:(id)arg2;
- (void)scene:(id)arg1 didUpdateClientSettingsWithDiff:(id)arg2 oldClientSettings:(id)arg3 transitionContext:(id)arg4;
- (void)scene:(id)arg1 didCompleteUpdateWithContext:(id)arg2 error:(id)arg3;
- (void)scene:(id)arg1 didApplyUpdateWithContext:(id)arg2;
- (void)scene:(id)arg1 didPrepareUpdateWithContext:(id)arg2;
- (void)sceneManager:(id)arg1 scene:(id)arg2 didReceiveActions:(id)arg3;
- (void)sceneManager:(id)arg1 didDestroyScene:(id)arg2;
- (void)sceneManager:(id)arg1 willDestroyScene:(id)arg2;
- (void)sceneManager:(id)arg1 didCreateScene:(id)arg2;
- (void)sceneManager:(id)arg1 interceptUpdateForScene:(id)arg2 withNewSettings:(id)arg3;
- (id)sceneManager:(id)arg1 createDefaultTransitionContextForScene:(id)arg2;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
- (void)registerSceneWorkspaceIdentifierToIgnore:(id)arg1;
- (void)enumerateSceneManagersWithBlock:(id /* CDUnknownBlockType */)arg1;
- (id)sceneManagerForDisplayIdentity:(id)arg1;
- (id)_sceneManagerForDisplayIdentity:(id)arg1 creatingIfNecessary:(BOOL)arg2;
- (id)_referenceForDisplayIdentity:(id)arg1 creatingIfNecessary:(BOOL)arg2;
- (void)dealloc;
- (id)init;

@end


//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <UIKit/UITableViewController.h>

#import <SpringBoardHome/SBHIconRootViewProviding-Protocol.h>

@class NSSet, SBFolder, SBFolderIconImageCache, SBHIconImageCache, UIView, UIViewController, _UILegibilitySettings;

@interface SBHIconRootTableViewController : UITableViewController <SBHIconRootViewProviding>
{
    SBFolder *_folder;
    _UILegibilitySettings *_legibilitySettings;
    SBFolderIconImageCache *_folderIconImageCache;
    SBHIconImageCache *_iconImageCache;
}

@property(retain, nonatomic) SBHIconImageCache *iconImageCache; // @synthesize iconImageCache=_iconImageCache;
@property(retain, nonatomic) SBFolderIconImageCache *folderIconImageCache; // @synthesize folderIconImageCache=_folderIconImageCache;
@property(retain, nonatomic) _UILegibilitySettings *legibilitySettings; // @synthesize legibilitySettings=_legibilitySettings;
@property(retain, nonatomic) SBFolder *folder; // @synthesize folder=_folder;
// - (void).cxx_destruct;
- (void)tableView:(id)arg1 didSelectRowAtIndexPath:(id)arg2;
- (id)tableView:(id)arg1 cellForRowAtIndexPath:(id)arg2;
- (long long)tableView:(id)arg1 numberOfRowsInSection:(long long)arg2;
- (long long)numberOfSectionsInTableView:(id)arg1;
- (void)enumerateDisplayedIconViewsUsingBlock:(id /* CDUnknownBlockType */)arg1;
- (BOOL)isDisplayingIconView:(id)arg1 inLocation:(id)arg2;
- (BOOL)isDisplayingIcon:(id)arg1 inLocations:(id)arg2;
- (BOOL)isDisplayingIconView:(id)arg1;
- (BOOL)isDisplayingIcon:(id)arg1;
- (BOOL)isDisplayingIcon:(id)arg1 inLocation:(id)arg2;
- (id)firstIconViewForIcon:(id)arg1 excludingLocations:(id)arg2;
- (id)firstIconViewForIcon:(id)arg1;
- (id)firstIconViewForIcon:(id)arg1 inLocations:(id)arg2;
- (id)iconViewForIcon:(id)arg1 location:(id)arg2;
@property(readonly, copy, nonatomic) NSSet *presentedIconLocations;
- (BOOL)isPresentingIconLocation:(id)arg1;
- (void)setIdleText:(id)arg1;
- (void)revealIcon:(id)arg1 animated:(BOOL)arg2 completionHandler:(id /* CDUnknownBlockType */)arg3;
- (BOOL)setCurrentPageIndex:(long long)arg1 animated:(BOOL)arg2 completion:(id /* CDUnknownBlockType */)arg3;
@property(nonatomic) long long currentPageIndex;
- (void)noteUserIsInteractingWithIcons;
- (void)enumerateDisplayedIconViewsForIcon:(id)arg1 usingBlock:(id /* CDUnknownBlockType */)arg2;
- (void)cancelScrolling;
@property(readonly, nonatomic, getter=isScrollTracking) BOOL scrollTracking;
@property(readonly, nonatomic, getter=isScrolling) BOOL scrolling;
- (void)setEditing:(BOOL)arg1 animated:(BOOL)arg2;
@property(nonatomic, getter=isEditing) BOOL editing;
@property(readonly, nonatomic) UIViewController *deepestFolderController;
@property(readonly, nonatomic) UIView *contentView;
- (void)viewDidLoad;

@end

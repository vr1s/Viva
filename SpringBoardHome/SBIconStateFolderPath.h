//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Mar 22 2020 01:47:48).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableArray;

@interface SBIconStateFolderPath : NSObject
{
    NSMutableArray *_folderNames;
    NSMutableArray *_folderDefaultNames;
    NSMutableArray *_folderPaths;
}

// - (void).cxx_destruct;
- (void)enumerateFoldersUsingBlock:(id /* CDUnknownBlockType */)arg1;
- (void)addFolderWithName:(id)arg1 defaultName:(id)arg2 indexPath:(id)arg3;
- (id)folderIndexPathAtIndex:(NSUInteger)arg1;
- (id)folderDefaultNameAtIndex:(NSUInteger)arg1;
- (id)folderNameAtIndex:(NSUInteger)arg1;
@property(readonly, nonatomic) NSUInteger count;
- (id)init;

@end



#ifndef PREFIX
#define PREFIX

// TODO: do we actually need this here still?
#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

#import <objc/runtime.h>
// Macros for values we use
#define GetLoadoutValue(location, item) [[[HPDataManager sharedInstance] currentConfiguration] integerForKey:[NSString stringWithFormat:@"%@%@%@", @"HPData", location, item]]

#define GetLoadoutBool(location, item) [[[HPDataManager sharedInstance] currentConfiguration] boolForKey:[NSString stringWithFormat:@"%@%@%@", @"HPData", location, item]]

// TODO: why is this not dynamic?
#define kDeviceCornerRadius 39

// bad
#define fakeCopy(what) [NSKeyedUnarchiver unarchiveObjectWithData:[NSKeyedArchiver archivedDataWithRootObject:what]]

#define kIconController [objc_getClass("SBIconController") sharedInstance]
#define kRootFolderController [kIconController _rootFolderController]
#define kIconModel [(SBIconController *)kIconController model]

#define kIdentifier @"me.kritanta.homeplusprefs"
#define kSettingsChangedNotification (CFStringRef)@"me.kritanta.homeplusprefs/settingschanged"
#define kSettingsPath @"/var/mobile/Library/Preferences/me.kritanta.homeplusprefs.plist"
#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

@interface KDBManager : NSObject

@property (readonly) UIView *overlayView;
@property (readonly) UITextView *textView;
@property (readonly) NSString *textQueue;
@property BOOL open;

+(instancetype)sharedInstance;


- (void)setupOverlayView;

-(void)logString:(NSString *)string file:(char *)file line:(int)line;

@end

#define NSLog(...) [KDBManager.sharedInstance logString:[NSString stringWithFormat:__VA_ARGS__] file:__FILE__ line:__LINE__]

//#define
#endif

#ifndef PREFIX
#define PREFIX

// TODO: do we actually need this here still?
#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>
#include <SpringBoard/SBIconModel.h>
#include <SpringBoard/SBIconController.h>

#import <objc/runtime.h>
// Macros for values we use
#define GetLoadoutValue(location, item) [[[VIVADataManager sharedInstance] currentConfiguration] integerForKey:[NSString stringWithFormat:@"%@%@%@", @"VIVAData", location, item]]

#define GetLoadoutBool(location, item) [[[VIVADataManager sharedInstance] currentConfiguration] boolForKey:[NSString stringWithFormat:@"%@%@%@", @"VIVAData", location, item]]

// TODO: why is this not dynamic?
#define kDeviceCornerRadius 39

// bad
#define fakeCopy(what) [NSKeyedUnarchiver unarchiveObjectWithData:[NSKeyedArchiver archivedDataWithRootObject:what]]

#define kIconController [objc_getClass("SBIconController") sharedInstance]
#define kRootFolderController [kIconController _rootFolderController]
#define kIconModel [(SBIconController *)kIconController model]

#define kIdentifier @"sk.vri.vivaprefs"
#define kSettingsChangedNotification (CFStringRef)@"sk.vri.vivaprefs/settingschanged"
#define kSettingsPath @"/var/mobile/Library/Preferences/sk.vri.vivaprefs.plist"

#ifndef DEBUGGER_OVERLAY
#define DEBUGGER_OVERLAY
#ifndef NDEBUG
#include "DebuggerOverlay.h"
#endif
#endif
#ifndef NDEBUG
#define NSLog(...) [KDBManager.sharedInstance logString:[NSString stringWithFormat:__VA_ARGS__] file:__FILE__ line:__LINE__]
#endif

//#define
#endif
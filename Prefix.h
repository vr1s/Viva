
#ifndef PREFIX
#define PREFIX

// TODO: do we actually need this here still?
#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>
#include <SpringBoard/SBIconModel.h>
#include <SpringBoard/SBIconController.h>
#include <SpringBoardHome/SBRootFolderView.h>
#include <SpringBoardHome/SBRootFolderController.h>

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
#define kRootFolderView [(SBRootFolderController *)kRootFolderController rootFolderView]
#define kIconModel [(SBIconController *)kIconController model]
#define kIconManager [(SBIconController *)kIconController iconManager]

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

#ifndef NDEBUG
#ifndef INSPC
#define INSPC

#ifdef __cplusplus
extern "C" {
#endif

void watchObject(id obj);
void unwatchObject(id obj);
void watchSelectorOnObject(id obj, SEL _cmd);
void unwatchSelectorOnObject(id obj, SEL _cmd);

void watchClass(Class clazz);
void unwatchClass(Class clazz);
void watchSelectorOnClass(Class clazz, SEL _cmd);
void unwatchSelectorOnClass(Class clazz, SEL _cmd);
void watchSelector(SEL _cmd);
void unwatchSelector(SEL _cmd);
void enableLogging();
void disableLogging();

void enableCompleteLogging();
void disableCompleteLogging();

void flushLogFile();

#ifdef __cplusplus
}
#endif


#endif // INSPC
#endif // NDEBUG
//#define
#endif
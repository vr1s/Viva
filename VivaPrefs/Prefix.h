
#ifndef PREFIX
#define PREFIX
#include <Foundation/Foundation.h>
#include <UIKit/UIKit.h>

// Macros for values we use
#define GetLoadoutValue(location, item) [[[VIVADataManager sharedInstance] currentConfiguration] integerForKey:[NSString stringWithFormat:@"%@%@%@", @"VIVAData", location, item]]
#define kDeviceCornerRadius 39
#define fakeCopy(what) [NSKeyedUnarchiver unarchiveObjectWithData:[NSKeyedArchiver archivedDataWithRootObject:what]]

#define kSerialKey "JAJFIWEPOFJAWPI"
#define kECIDKey "JAIWEFJAPWOIFJAP"
#define kWifiMacKey "JAFIEWPFJIJF"
#define kBTMacKey "JAFIOWPEJFIPOAW"

//#define
#endif
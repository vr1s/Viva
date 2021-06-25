#include <UIKit/UIKit.h>


#ifndef HPCONFIGURATION_H
#define HPCONFIGURATION_H

@interface HPConfiguration : NSObject

@property (nonatomic, retain) NSString *configurationName;
@property (nonatomic, retain) NSString *readableName;
@property (nonatomic, retain) NSMutableDictionary *values;

- (instancetype)initWithConfigurationName:(NSString *)name;

- (void)saveConfigurationToFile;
- (void)loadConfigurationFromFile;
-(void)delete;

- (void)writeDefaults;

- (id)valueForKey:(NSString *)key;
- (id)objectForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;
- (CGFloat)floatForKey:(NSString *)key;

- (void)setValue:(id)value forKey:(NSString *)key;
- (void)setObject:(id)value forKey:(NSString *)key;
- (void)setInteger:(NSInteger)value forKey:(NSString *)key;
- (void)setBool:(BOOL)value forKey:(NSString *)key;
- (void)setFloat:(CGFloat)value forKey:(NSString *)key;

@end

#endif
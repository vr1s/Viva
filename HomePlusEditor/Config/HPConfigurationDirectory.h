//
// Created by Kritanta on 7/8/21.
//

#import <Foundation/Foundation.h>

#ifndef HOMEPLUS_HPCONFIGURATIONDIRECTORY_H
#define HOMEPLUS_HPCONFIGURATIONDIRECTORY_H

@interface HPConfigurationDirectory : NSObject <NSCoding>
@property NSMutableDictionary *configurations;
@property NSString *selectedConfigurationName;

- (instancetype)initWithCoder:(NSCoder *)coder;

- (void)encodeWithCoder:(NSCoder *)coder;
@end

#endif //HOMEPLUS_HPCONFIGURATIONDIRECTORY_H
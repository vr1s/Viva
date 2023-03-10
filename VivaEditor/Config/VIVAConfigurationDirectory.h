//
// Created by vrisk/a on 7/8/21.
//

#import <Foundation/Foundation.h>

#ifndef VIVA_VIVACONFIGURATIONDIRECTORY_H
#define VIVA_VIVACONFIGURATIONDIRECTORY_H

@interface VIVAConfigurationDirectory : NSObject <NSCoding>
@property NSMutableDictionary *configurations;
@property NSString *selectedConfigurationName;

- (instancetype)initWithCoder:(NSCoder *)coder;

- (void)encodeWithCoder:(NSCoder *)coder;
@end

#endif //VIVA_VIVACONFIGURATIONDIRECTORY_H
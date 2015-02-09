//
//  AllWeatherRadial.m
//  objc-study
//
//  Created by Wang Da on 13-11-3.
//  Copyright (c) 2013年 Wang Da. All rights reserved.
//

#import "AllWeatherRadial.h"

@implementation AllWeatherRadial
@synthesize rainHandling;
@synthesize snowHandling;

- (NSString *) description
{
    NSString *desc;
    desc = [[NSString alloc] initWithFormat:
            @"AllWeatherRadial: %.1f / %.1f / %.1f / %.1f",
            [self pressure], [self treadDepth],
            [self rainHandling], [self snowHandling]];
    
    return desc;
}

- (id) initWithPressure:(float)p treadDepth:(float)td
{
    if (self = [super initWithPressure:p treadDepth:td])
    {
        rainHandling = 23.7;
        snowHandling = 42.5;
    }
    return self;
}


@end

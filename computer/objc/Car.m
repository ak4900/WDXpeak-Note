//
//  Car.m
//  objc-study
//
//  Created by Wang Da on 13-11-3.
//  Copyright (c) 2013年 Wang Da. All rights reserved.
//

#import "Car.h"
#import "Engine.h"
#import "Tire.h"

@implementation Car

@synthesize name;
@synthesize engine;

// 初始化函数
- (id) init
{
    if (self = [super init])
    {
        name = @"Car" ;
        engine = [Engine new];
        tires = [[NSMutableArray alloc] init];
        for (int i = 0; i < 4; i++) {
            [tires addObject: [NSNull null]];
        }
    }
    return (self);
} // init

- (void) setName:(NSString *)newName
{
    name = [newName copy];
}

- (NSString *) name
{
    return name;
}


- (Engine *) engine
{
    return engine;
} // engine

- (void) setEngine:(Engine *)newEngine
{
    engine = newEngine;
} // setEngine

- (void) setTire:(Tire *)tire atIndex:(int)index
{
    [tires replaceObjectAtIndex: index withObject:tire];
} // setTire:atIndex:

- (Tire *) tireAtIndex:(int)index
{
    Tire *tire;
    tire = [tires objectAtIndex:index];
    return tire;
} // tireAtIndex:

- (void) print
{
    NSLog(@"%@ has:", name);
    NSLog(@"%@",engine);
    for (int i = 0; i < 4; i++)
    {
        NSLog(@"%@", [self tireAtIndex:i]);
    }
    NSLog(@"%@", engine);
}

@end

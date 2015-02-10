//
//  Tire.m
//  objc-study
//
//  Created by Wang Da on 13-11-3.
//  Copyright (c) 2013年 Wang Da. All rights reserved.
//

#import "Tire.h"

/*
 类中的某个初始化方法被指派为制定初始化函数。该类的所有处事方法都使用指定初始化函数执行初始化操作，
 而子类使用其超类的指定初始化函数进行超类的初始化。
 
 通常，接收参数最多的初始化方法是最终的指定初始化函数
 
 */


@implementation Tire
- (id) init
{
    if (self = [self initWithPressure:34 treadDepth:20])
    {
        //pressure = 34.0;
        //treadDepth = 20.0;
    }
    return (self);
}

- (id) initWithPressure:(float)p
{
    if (self = [self initWithPressure:p treadDepth:20.0])
    {
        //pressure = p;
        //treadDepth = 20.0;
    }
    return self;
}

- (id) initWIthTreadDepth:(float)td
{
    if (self = [self initWithPressure:34.0 treadDepth:td])
    {
        //pressure = 34.0;
        //treadDepth = td;
    }
    return self;
}

- (id) initWithPressure:(float)p treadDepth:(float)td
{
    if (self = [super init])
    {
        pressure = p;
        treadDepth = td;
    }
    return self;
}

- (void) setPressure:(float)p
{
    pressure = p;
}

- (float) pressure
{
    return pressure;
}

- (void) setTreadDepth:(float)td
{
    treadDepth = td;
}

- (float) treadDepth
{
    return treadDepth;
}

- (NSString *) description
{
    NSString *desc;
    desc = [NSString stringWithFormat:@"Tire: Pressure: %.1f TreadDepth: %.1f", pressure, treadDepth];
    return  desc;
}


@end // Tire

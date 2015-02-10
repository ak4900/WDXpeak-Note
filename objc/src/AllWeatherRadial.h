//
//  AllWeatherRadial.h
//  objc-study
//
//  Created by Wang Da on 13-11-3.
//  Copyright (c) 2013年 Wang Da. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Tire.h"

@interface AllWeatherRadial : Tire
{
    float rainHandling;
    float snowHandling;
}
@property float rainHandling;
@property float snowHandling;

@end

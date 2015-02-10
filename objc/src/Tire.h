//
//  Tire.h
//  objc-study
//
//  Created by Wang Da on 13-11-3.
//  Copyright (c) 2013年 Wang Da. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Tire : NSObject
{
    float pressure;
    float treadDepth;
}
- (id) initWithPressure: (float) pressure;
- (id) initWIthTreadDepth: (float) treadDepth;
- (id) initWithPressure: (float) pressure treadDepth: (float) treadDepth;
- (void) setPressure: (float) pressure;
- (float) pressure;
- (void) setTreadDepth: (float) treadDepth;
- (float) treadDepth;
@end

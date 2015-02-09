//
//  Car.h
//  objc-study
//
//  Created by Wang Da on 13-11-3.
//  Copyright (c) 2013年 Wang Da. All rights reserved.
//

#import <Foundation/Foundation.h>

/*

 @class告诉编译器，这是一个类，所以我只会通过指针来引用，而无需知道这个类的细节。
 
 */
@class Tire;
@class Engine;

@interface Car : NSObject
{
    NSString *name;
    Engine *engine;
    NSMutableArray *tires;
}
@property (copy) NSString *name;
@property (retain) Engine *engine;
- (Tire *) tireAtIndex: (int) index;
- (void) setTire: (Tire *) tire atIndex:(int) index;
- (void) print;
@end // Car


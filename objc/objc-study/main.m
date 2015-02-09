//
//  main.m
//  objc-study
//
//  Created by Wang Da on 13-9-11.
//  Copyright (c) 2013年 Wang Da. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Tire.h"
#import "Engine.h"
#import "Car.h"
#import "Slant6.h"
#import "AllWeatherRadial.h"

/*
        关于Objecitve-C的一些碎碎念
 框架是一种把头文件、库、图片、声音等内容聚集在一个独立单元中的集合体

 
        关于Xcode的一些碎碎念
 Control + I 自动整理好代码的缩进
 Command + [/] 将代码左移/右移
 Control + F 光标前移/方向键右
 Control + B 光标后移/方向键左
 Control + P 光标上移/方向键上
 Control + N 光标下移/方向键下
 Control + A 光标移动到行首
 Control + E 光标移动到行尾
 Control + T 交换光标两边的字符
 Control + D 删除光标右边的字符
 Control + K 将当前行光标以后的所有字符全部删除
 Control + L 将光标置于窗口正中央
 */




struct iPoint {
    float x;
    float y;
};

typedef struct
{
    float x;
    float y;
} PointType;

/*
 * 在Objective-C中，参数和返回值通过“传值”的方式传递。但是如果你传递了一个指针，对指针变量的任何改动
 * 都会影响到调用函数中的原变量。同样，必须注意不要返回指向在函数退出是超出了作用域的变量的指针或者引用
 */

// 使用指针
void myFunction(int a, int *b)
{
    NSLog(@"反引用指针以访问原始值并改动");
    a = 20;
    *b = 20; // 反引用指针以访问原始值
}

// 函数的调用
long int calculateFactorial(int value)
{
    NSLog(@"进入函数calculateFactorial");
    long int result = 1;
    for (int i = 1; i <= value; ++i)
    {
        result = result * i;
    }
    NSLog(@"返回函数calculateFactorial结果");
    return result;
}

// 测试条件语句
void checkValue(int value)
{
    NSLog(@"Value = %1d",value);
    if (value > 75)
    {
        NSLog(@"%1d is greater than 75!",value);
    }
    else if (value < 25)
    {
        NSLog(@"%1d is greater than 25!",value);
    }
    else
    {
        NSLog(@"%1d is between 24 and 76", value);
    }
}

// 测试switch语句
void switchValue(int value)
{
    NSLog(@"Value = %1d",value);
    switch (value) {
        case 1:
            NSLog(@"This is case 1 for switch function!");
            break;
        case 2:
            NSLog(@"This is case 2 for switch function!");
            break;
        case 3:
            NSLog(@"This is case 3 for switch function!");
            break;
        case 4:
            NSLog(@"This is case 4 for switch function!");
            break;
        default:
            NSLog(@"This is default case for switch function!");
            break;
    }
}

// 头文件扩展
extern long int calculateFactorialoutside(int value);


// OOP部分
/*
 # 类：表示对象类型的结构体。对象通过它的类来获取自身的各种信息，尤其是执行每个操作需要运行的代码。建议首字母大写。
 # 对象：包含值和指向其类的隐藏指针的结构体。
 # 实例：是「对象」的另一种称呼
 # 消息：是对象可以执行的操作，用于通知对象去做什么
 # 方法：为响应消息而运行的代码。
 # 方法调度：Objective-C使用的一种机制，用于推测执行什么方法以响应某个特定的消息。
 # 接口：类为对象提供的特性描述
 # 实现：使接口能正常工作的代码
 */
typedef enum
{
    kCircle,
    Krectangle,
    kEgg
} ShapeType;

typedef enum
{
    kRedColor,
    kGreenColor,
    kBlueColor
} ShapeColor;

typedef struct
{
    int x, y, width, height;
} ShapeRect;


NSString *colorName (ShapeColor colorName)
{
    switch (colorName)
    {
        case kRedColor:
            return @"red";
            break;
        case kGreenColor:
            return @"green";
            break;
        case kBlueColor:
            return @"blue";
            break;
        default:
            break;
    }
    return @"no clue";
} // colorName

@interface Shape : NSObject
{
    ShapeColor fillColor;
    ShapeRect bounds;
}

- (void) setFillColor: (ShapeColor) fillColor;

- (void) setBounds: (ShapeRect) bounds;

- (void) draw;

@end // Shape

@implementation Shape

- (void) setFillColor:(ShapeColor)c
{
    fillColor = c;
} // setFillColor

- (void) setBounds:(ShapeRect)b
{
    bounds = b;
} // setBounds

- (void) draw
{
}

@end


@interface Circle : Shape
@end // Circle

@interface Rectangle : Shape
@end // Rectangle

@implementation Circle
- (void) setFillColor:(ShapeColor)c
{
    if (c == kRedColor)
    {
        c = kGreenColor;
    }
    
    // 利用这种方式调用父类的实现
    [super setFillColor: c];
}

- (void) draw
{
    NSLog(@"drawing a circle at (%d %d %d %d) in %@",
          bounds.x, bounds.y, bounds.width, bounds.height, colorName(fillColor));
} // draw
@end

@implementation Rectangle
- (void) draw
{
    NSLog(@"drawing rect at (%d %d %d %d) in %@",
          bounds.x, bounds.y, bounds.width, bounds.height, colorName(fillColor));
} // draw
@end

// 复合
/*
 复合是通过包含作为实例变量的对象指针实现的。
 */



/*
 
 如果你在生命方法时添加了加号，就是把这个方法定义为类方法。这个方法属于类对象，通常用于创建新的实例。
 我们称这种用来创建新对象的类方法为工厂方法。
 
 NSString是不可变的，指的是一旦被创建，便不能改变。
 你可以对它执行各种各样的操作，例如用它生成新的字符串、超找字符或者将它与其他字符串进行比较。
 但是你不能以删除字符或者添加字符的方式来改变它。
 如果想改变字符串，请使用NSMutableString
 
 */







int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        NSLog(@"Hello, 这是Objective-C语法测试代码");
        /*
        NSLog(@"##测试输出变量");
        int i = 5555;
        NSLog(@"变量i:%1d\n\n",i);
        
        // 结构体
        struct iPoint p;
        p.x = 20.0;
        p.y = 50.0;
        NSLog(@"##测试结构体iPoint");
        NSLog(@"x=%.2f, y=%.2f\n\n", p.x, p.y);
        
        // 类型定义
        PointType pt;
        pt.x = 25.0;
        pt.y = 30.0;
        NSLog(@"##测试类型定义");
        NSLog(@"x=%.1f, y=%.1f\n\n", pt.x, pt.y);
        
        // enum类型
        enum MyEnumType {
            value1 = 15,
            value2 = 30,
            value3 = 45
        };
        typedef enum MyEnumType MyEnum;
        
        MyEnum foo;
        foo = value1;
        NSLog(@"##测试enum类型");
        NSLog(@"value1=%1d",foo);
        foo = value2;
        NSLog(@"value2=%1d",foo);
        foo = value3;
        NSLog(@"value3=%1d\n\n",foo);
        
        // 指针
        int x = 5;
        int *y = &x;
        NSLog(@"##测试指针");
        NSLog(@"这里的Y显示的是内存中的地址");
        NSLog(@"X:%1d - Y:%1d", x, y);
        NSLog(@"这里的Y显示的是内存中指向的地址中的内容");
        NSLog(@"X:%1d - Y:%1d\n\n", x, *y);
        
        // 使用运算符
        NSLog(@"##使用运算符测试");
        int a = 10;
        NSLog(@"a=%1d", a);
        int b = 3;
        NSLog(@"b=%1d", b);
        int c = a + b;
        NSLog(@"c=a+b=%1d", c);
        int d = a - b;
        NSLog(@"d=a-b=%1d", d);
        int e = a * b;
        NSLog(@"e=a*b=%1d", e);
        int f = a / b;
        NSLog(@"f=a/b=%1d", f);
        int g = a % b;
        NSLog(@"g=a%%b=%1d\n\n", g);
        
        // 使用函数
        NSLog(@"##测试函数使用");
        a = 5;
        NSLog(@"a=%1d,计算其阶乘", a);
        long int result =  calculateFactorial(a);
        NSLog(@"%1d!=%ld", a, result);
        a = 10;
        NSLog(@"a=%1d,计算其阶乘", a);
        result =  calculateFactorial(a);
        NSLog(@"%1d!=%ld\n\n", a, result);
    
        // 使用指针
        NSLog(@"##测试传入指针");
        a = 10;
        b = 10;
        NSLog(@"a=%1d, b=%1d", a, b);
        myFunction(a, &b);
        NSLog(@"a=%1d, b=%1d\n\n", a, b);
        
        // 条件语句
        NSLog(@"##测试条件语句");
        int n = 55;
        checkValue(n);
        n = 78;
        checkValue(n);
        n = 22;
        checkValue(n);
        NSLog(@"\n\n");
        
        // switch语句
        NSLog(@"##测试switch语句");
        n = 1;
        switchValue(n);
        n = 2;
        switchValue(n);
        n = 3;
        switchValue(n);
        n = 4;
        switchValue(n);
        n = 5;
        switchValue(n);
        NSLog(@"\n\n");
        
        // 循环语句
        NSLog(@"##测试循环语句");
        for (int i = 0; i < 10; i++) {
            NSLog(@"循环%1d, i=%1d",i+1,i);
        }
        */
        
        // 复合测试
        /*
        Car *car = [Car new];
        Engine *engine = [Engine new];
        [car setEngine: engine];
        for (int i = 0; i < 4; i++)
        {
            Tire *tire = [Tire new];
            [car setTire:tire atIndex:i];
        }
        [car print];
        */
        
        // 常规枚举方法
        /*
        NSFileManager *manager;
        manager = [NSFileManager defaultManager];
        
        NSString *home;
        home = [@"~" stringByExpandingTildeInPath];
        
        NSDirectoryEnumerator *direnum;
        direnum = [manager enumeratorAtPath:home];
        
        NSMutableArray *files;
        files = [NSMutableArray arrayWithCapacity:42];
        
        NSString *filename;
        while (filename = [direnum nextObject])
        {
            if ([[filename pathExtension] isEqualTo: @"jpg"])
            {
                [files addObject: filename];
            }
        }
                           
        NSEnumerator *fileenum;
        fileenum = [files objectEnumerator];
        
        while (filename = [fileenum nextObject])
        {
            NSLog(@"%@", filename);
        }
         */
        
        // 快速遍历
        /*
        NSFileManager *manager;
        manager = [NSFileManager defaultManager];
        NSString *home;
        home = [@"~" stringByExpandingTildeInPath];
        
        NSMutableArray *files;
        files = [NSMutableArray arrayWithCapacity:42];
        
        for (NSString *filename in [manager enumeratorAtPath:home])
        {
            if ([[filename pathExtension] isEqualTo: @"jpg"])
            {
                [files addObject: filename];
            }
        }
        
        for (NSString *filename in files)
        {
            NSLog(@"%@", filename);
        }
        */
        
        Car *car = [[Car alloc] init];
        
        for (int i= 0; i < 4; i++)
        {
            /*
            Tire *tire;
            tire = [[Tire alloc] initWithPressure:23 + i  treadDepth:33-i];
            [car setTire:tire atIndex:i];
            */
            
            AllWeatherRadial *tire;
            tire = [[AllWeatherRadial alloc] init];
            tire.rainHandling = 20+i;
            tire.snowHandling = 28+i;
            NSLog(@"tire %d's handling is %.f %.f", i, tire.rainHandling, tire.snowHandling);
            [car setTire:tire atIndex:i];
        }
        Engine *engine = [[Slant6 alloc] init];
        car.name = @"Herbie";
        car.engine = engine;
        [car print];
        
        
            
    }
    
    // 内存管理部分，现在iOS有了ARC，不必手动管理了
    
    /*
     
     分配（allocation）是一个新对象诞生的过程。向某个类发送alloc消息，就能为类分配一块足够大的内存，
     以存放该类的全部实例变量。同时alloc方法还顺便将这块内存区域全部初始化为0.
     
     初始化函数的一般规则是，假如你的对象必须要用某些信息进行初始化，那么你应该将这些信息
     作为init方法的一部分添加进来。这些都是典型的不可变对象。
     
     */
    
    
    return 0;
}




**1.   Object－c的类可以多重继承么？可以实现多个接口么？Category是什么？重写一个类的方式用继承好还是分类好？为什么？**

  

Object-c的类不可以多重继承；可以实现多个接口，通过实现多个接口可以完成C++的多重继承；Category是类别，一般情况用分类好，用Category
去重写类的方法，仅对本Category有效，不会影响到其他类与原有类的关系。

  

**2.#import 跟#include 又什么区别，@class呢, ＃import<> 跟 #import”"又什么区别？**

  

#import是Objective-C导入头文件的关键字，#include是C/C++导入头文件的关键字,使用#import头文件会自动只导入一次，不会重复
导入，相当于#include和#pragma once；@class告诉编译器某个类的声明，当执行时，才去查看类的实现文件，可以解决头文件的相互包含；#im
port<>用来包含系统的头文件，#import””用来包含用户头文件。

  

**3\. 属性readwrite，readonly，assign，retain，copy，nonatomic 各是什么作用，在那种情况下用？**

  

readwrite 是可读可写特性；需要生成getter方法和setter方法时

  

readonly 是只读特性  只会生成getter方法 不会生成setter方法 ;不希望属性在类外改变

  

assign 是赋值特性，setter方法将传入参数赋值给实例变量；仅设置变量时；

  

retain 表示持有特性，setter方法将传入参数先保留，再赋值，传入参数的retaincount会+1;

  

copy 表示赋值特性，setter方法将传入对象复制一份；需要完全一份新的变量时。

  

nonatomic 非原子操作，决定编译器生成的setter getter是否是原子操作，atomic表示多线程安全，一般使用nonatomic

  

**4.写一个setter方法用于完成@property （nonatomic,retain）NSString *name,写一个setter方法用于完成@property（nonatomic，copy）NSString *name**

  1. \- (**void**) setName:(NSString*) str
  2. {
  3. [str retain];
  4. [name release];
  5. name = str;
  6. }
  7. \- (**void**)setName:(NSString *)str
  8. {
  9. id t = [str copy];
  10. [name release];
  11. name = t;
  12. }

  

**5.对于语句NSString*obj = [[NSData alloc] init]; obj在编译时和运行时分别时什么类型的对象？**

  

编译时是NSString的类型；运行时是NSData类型的对象

  

  

**6.常见的object-c的数据类型有那些， 和C的基本数据类型有什么区别？如：NSInteger和int**

  

object-c的数据类型有NSString，NSNumber，NSArray，NSMutableArray，NSData等等，这些都是class，创建后便
是对象，而C语言的基本数据类型int，只是一定字节的内存空间，用于存放数值；NSInteger是基本数据类型，并不是NSNumber的子类，当然也不是NSO
bject的子类。NSInteger是基本数据类型Int或者Long的别名（NSInteger的定义typedef long
NSInteger），它的区别在于，NSInteger会根据系统是32位还是64位来决定是本身是int还是Long。

  

**[7\. id](http://7.id/) 声明的对象有什么特性？**

  

Id 声明的对象具有运行时的特性，即可以指向任意类型的objcetive-c的对象；

  

**8.Objective-C如何对内存管理的,说说你的看法和解决方法?**

  

Objective-C的内存管理主要有三种方式ARC（自动内存计数）、手动内存计数、内存池。

  

**9.内存管理的几条原则时什么？按照默认法则.那些关键字生成的对象**

  

需要手动释放？在和property结合的时候怎样有效的避免内存泄露？

  

谁申请，谁释放

  

遵循Cocoa Touch的使用原则；

  

内存管理主要要避免“过早释放”和“内存泄漏”，对于“过早释放”需要注意@property设置特性时，一定要用对特性关键字，对于“内存泄漏”，一定要申请了要负
责释放，要细心。

  

关键字alloc 或new 生成的对象需要手动释放；

  

设置正确的property属性，对于retain需要在合适的地方释放，

  

**10.如何对iOS设备进行性能测试?**

  

Profile-> Instruments ->Time Profiler

  

**11.看下面的程序,第一个NSLog会输出什么？这时str的retainCount是多少？第二个和第三个呢？ 为什么？**

  

  1. =======================================================
  2. NSMutableArray* ary = [[NSMutableArray array] retain];
  3. NSString *str = [NSString stringWithFormat:@"test"];
  4. [strretain];
  5. [aryaddObject:str];
  6. NSLog(@"%@%d",str,[str retainCount]);
  7. [strretain];
  8. [strrelease];
  9. [strrelease];
  10. NSLog(@"%@%d",str,[str retainCount]);
  11. [aryremoveAllObjects];
  12. NSLog(@"%@%d",str,[str retainCount]);
  13. =======================================================

str的retainCount创建+1，retain+1，加入数组自动+1

  

3

  

retain+1，release-1，release-1

  

2

  

数组删除所有对象，所有数组内的对象自动-1

  

1

  

**12\. Object C中创建线程的方法是什么？如果在主线程中执行代码，方法是什么？如果想延时执行代码、方法又是什么？**

  

线程创建有三种方法：使用NSThread创建、使用GCD的dispatch、使用子类化的NSOperation,然后将其加入NSOperationQueue
;在主线程执行代码，方法是performSelectorOnMainThread，如果想延时执行代码可以用performSelector:onThread:
withObject:waitUntilDone:

  

**13.描述一下iOS SDK中如何实现MVC的开发模式**

  

MVC是模型、试图、控制开发模式，对于iOS SDK，所有的View都是视图层的，它应该独立于模型层，由视图控制层来控制。所有的用户数据都是模型层，它应该独
立于视图。所有的ViewController都是控制层，由它负责控制视图，访问模型数据。

  

**1.Difference between shallow copy and deep copy?**

  

浅复制和深复制的区别？

  

答案：浅层复制：只复制指向对象的指针，而不复制引用对象本身。

  

深层复制：复制引用对象本身。

  

意思就是说我有个A对象，复制一份后得到A_copy对象后，对于浅复制来说，A和A_copy指向的是同一个内存资源，复制的只不过是是一个指针，对象本身资源

  

还是只有一份，那如果我们对A_copy执行了修改操作,那么发现A引用的对象同样被修改，这其实违背了我们复制拷贝的一个思想。深复制就好理解了,内存中存在了

  

两份独立对象本身。

  

用网上一哥们通俗的话将就是：

  

浅复制好比你和你的影子，你完蛋，你的影子也完蛋

  

深复制好比你和你的克隆人，你完蛋，你的克隆人还活着。

  

**2.What is advantage of categories? What is difference between implementing a category and inheritance?**

  

类别的作用？继承和类别在实现中有何区别？

  

答案：category 可以在不获悉，不改变原来代码的情况下往里面添加新的方法，只能添加，不能删除修改。

  

并且如果类别和原来类中的方法产生名称冲突，则类别将覆盖原来的方法，因为类别具有更高的优先级。

  

类别主要有3个作用：

  

(1)将类的实现分散到多个不同文件或多个不同框架中。

  

(2)创建对私有方法的前向引用。

  

(3)向对象添加非正式协议。

  

 继承可以增加，修改或者删除方法，并且可以增加属性。

  

**3.Difference between categories and extensions?**

  

类别和类扩展的区别。

  

 答案：category和extensions的不同在于 后者可以添加属性。另外后者添加的方法是必须要实现的。

  

extensions可以认为是一个私有的Category。

  

**4.Difference between protocol in objective c and interfaces in java?**

  

oc中的协议和java中的接口概念有何不同？

  

答案：OC中的代理有2层含义，官方定义为 formal和informal protocol。前者和Java接口一样。

  

informal protocol中的方法属于设计模式考虑范畴，不是必须实现的，但是如果有实现，就会改变类的属性。

  

其实关于正式协议，类别和非正式协议我很早前学习的时候大致看过，也写在了学习教程里

  

“非正式协议概念其实就是类别的另一种表达方式“这里有一些你可能希望实现的方法，你可以使用他们更好的完成工作”。

  

这个意思是，这些是可选的。比如我门要一个更好的方法，我们就会申明一个这样的类别去实现。然后你在后期可以直接使用这些更好的方法。

  

这么看，总觉得类别这玩意儿有点像协议的可选协议。"

  

现在来看，其实protocal已经开始对两者都统一和规范起来操作，因为资料中说“非正式协议使用interface修饰“，

  

现在我们看到协议中两个修饰词：“必须实现(@requied)”和“可选实现(@optional)”。

  

**5.What are KVO and KVC?**

  

答案：kvc:键 - 值编码是一种间接访问对象的属性使用字符串来标识属性，而不是通过调用存取方法，直接或通过实例变量访问的机制。

  

很多情况下可以简化程序代码。apple文档其实给了一个很好的例子。

  

kvo:键值观察机制，他提供了观察某一属性变化的方法，极大的简化了代码。

  

具体用看到嗯哼用到过的一个地方是对于按钮点击变化状态的的监控。

  

对于kvc机制如何通过key寻找到value：

  

“当通过KVC调用对象时，比如：[self
valueForKey:@”someKey”]时，程序会自动试图通过几种不同的方式解析这个调用。首先查找对象是否带有 someKey
这个方法，如果没找到，会继续查找对象是否带有someKey这个实例变量（iVar），如果还没有找到，程序会继续试图调用 -(id)
valueForUndefinedKey:这个方法。如果这个方法还是没有被实现的话，程序会抛出一个NSUndefinedKeyException异常错误。

  

(cocoachina.com注：Key-Value Coding查找方法的时候，不仅仅会查找someKey这个方法，还会查找getsomeKey这个方法，
前面加一个get，或者_someKey以及_getsomeKey这几种形式。同时，查找实例变量的时候也会不仅仅查找someKey这个变量，也会查找_some
Key这个变量是否存在。）

  

设计valueForUndefinedKey:方法的主要目的是当你使用-(id)valueForKey方法从对象中请求值时，对象能够在错误发生前，有最后的机
会响应这个请求。这样做有很多好处，下面的两个例子说明了这样做的好处。“

  

来至cocoa，这个说法应该挺有道理。

  

因为我们知道button却是存在一个highlighted实例变量.因此为何上面我们只是add一个相关的keypath就行了，

  

可以按照kvc查找的逻辑理解，就说的过去了。

  

**6.What is purpose of delegates?**

  

代理的作用？

  

答案：代理的目的是改变或传递控制链。允许一个类在某些特定时刻通知到其他类，而不需要获取到那些类的指针。可以减少框架复杂度。

  

另外一点，代理可以理解为java中的回调监听机制的一种类似。

  

**7.What are mutable and immutable types in Objective C?**

  

oc中可修改和不可以修改类型。

  

答案：可修改不可修改的集合类。这个我个人简单理解就是可动态添加修改和不可动态添加修改一样。

  

比如NSArray和NSMutableArray。前者在初始化后的内存控件就是固定不可变的，后者可以添加等，可以动态申请新的内存空间。

  

**8.When we call objective c is runtime language what does it mean?**

  

我们说的oc是动态运行时语言是什么意思？

  

答案：多态。 主要是将数据类型的确定由编译时，推迟到了运行时。

  

这个问题其实浅涉及到两个概念，运行时和多态。

  

简单来说，运行时机制使我们直到运行时才去决定一个对象的类别，以及调用该类别对象指定方法。

  

多态：不同对象以自己的方式响应相同的消息的能力叫做多态。意思就是假设生物类（life）都用有一个相同的方法-eat;

  

那人类属于生物，猪也属于生物，都继承了life后，实现各自的eat，但是调用是我们只需调用各自的eat方法。

  

也就是不同的对象以自己的方式响应了相同的消息（响应了eat这个选择器）。

  

因此也可以说，运行时机制是多态的基础？

  

**9.what is difference between NSNotification and protocol?**

  

通知和协议的不同之处？

  

答案：协议有控制链(has-a)的关系，通知没有。

  

首先我一开始也不太明白，什么叫控制链（专业术语了~）。但是简单分析下通知和代理的行为模式，我们大致可以有自己的理解

  

简单来说，通知的话，它可以一对多，一条消息可以发送给多个消息接受者。

  

代理按我们的理解，到不是直接说不能一对多，比如我们知道的明星经济代理人，很多时候一个经济人负责好几个明星的事务。

  

只是对于不同明星间，代理的事物对象都是不一样的，一一对应，不可能说明天要处理A明星要一个发布会，代理人发出处理发布会的消息后，别称B的发布会了。但是通知就不
一样，他只关心发出通知，而不关心多少接收到感兴趣要处理。

  

因此控制链（has-a从英语单词大致可以看出，单一拥有和可控制的对应关系。

  

**10.What is push notification?**

  

什么是推送消息？

  

答案：太简单，不作答~~~~~~~~~~

  

这是cocoa上的答案。

  

其实到不是说太简单，只是太泛泛的一个概念的东西。就好比说，什么是人。

  

推送通知更是一种技术。

  

简单点就是客户端获取资源的一种手段。

  

普通情况下，都是客户端主动的pull。

  

推送则是服务器端主动push。

  

**11.Polymorphism？**

  

关于多态性

  

答案：多态，子类指针可以赋值给父类。

  

这个题目其实可以出到一切面向对象语言中，

  

因此关于多态，继承和封装基本最好都有个自我意识的理解，也并非一定要把书上资料上写的能背出来。

  

最重要的是转化成自我理解。

  

**12.Singleton?**

  

对于单例的理解

  

答案：11，12题目其实出的有点泛泛的感觉了，可能说是[编程](http://www.2cto.com/kf)语言需要或是必备的基础。

  

基本能用熟悉的语言写出一个单例，以及可以运用到的场景或是你编程中碰到过运用的此种模式的框架类等。

  

进一步点，考虑下如何在多线程访问单例时的安全性。

  

**13.What is responder chain?**

  

说说响应链

  

答案： 事件响应链。包括点击事件，画面刷新事件等。在视图栈内从上至下，或者从下之上传播。

  

可以说点事件的分发，传递以及处理。具体可以去看下touch事件这块。因为问的太抽象化了

  

严重怀疑题目出到越后面就越笼统。

  

**14.Difference between frame and bounds?**

  

frame和bounds有什么不同？

  

答案:frame指的是：该view在父view坐标系统中的位置和大小。（参照点是父亲的坐标系统）

  

bounds指的是：该view在本身坐标系统中 的位置和大小。（参照点是本身坐标系统）

  

**15.Difference between method and selector?**

  

方法和选择器有何不同？

  

答案：selector是一个方法的名字，method是一个组合体，包含了名字和实现.

  

可以理解 @selector()就是取类方法的编号,他的行为基本可以等同C语言的中函数指针,只不过C语言中，可以把函数名直接赋给一个函数指针
，而Object-C的类不能直接应用函数指针，这样只能做一个@selector语法来取.

  

它的结果是一个SEL类型。这个类型本质是类方法的编号(函数地址)

  

**[16.Is](http://16.is/) there any garbage collection mechanism in Objective C.?**

  

OC的垃圾回收机制？

  

答案： OC2.0有Garbage collection，但是iOS平台不提供。

  

一般我们了解的objective-c对于内存管理都是手动操作的，但是也有自动释放池。

  

但是差了大部分资料，貌似不要和arc机制搞混就好了。

  

**17.NSOperation queue?**

  

答案：存放NSOperation的集合类。

  

操作和操作队列，基本可以看成java中的线程和线程池的概念。用于处理ios多线程开发的问题。

  

网上部分资料提到一点是，虽然是queue，但是却并不是带有队列的概念，放入的操作并非是按照严格的先进现出。

  

这边又有个疑点是，对于队列来说，先进先出的概念是Afunc添加进队列，Bfunc紧跟着也进入队列，Afunc先执行这个是必然的，

  

但是Bfunc是等Afunc完全操作完以后，B才开始启动并且执行，因此队列的概念离乱上有点违背了多线程处理这个概念。

  

但是转念一想其实可以参考银行的取票和叫号系统。

  

因此对于A比B先排队取票但是B率先执行完操作，我们亦然可以感性认为这还是一个队列。

  

但是后来看到一票关于这操作队列话题的文章，其中有一句提到

  

“因为两个操作提交的时间间隔很近，线程池中的线程，谁先启动是不定的。”

  

瞬间觉得这个queue名字有点忽悠人了，还不如pool~

  

综合一点，我们知道他可以比较大的用处在于可以帮组多线程编程就好了。

  

**18.What is lazy loading?**

  

答案：懒汉模式，只在用到的时候才去初始化。

  

也可以理解成延时加载。

  

我觉得最好也最简单的一个列子就是tableView中图片的加载显示了。

  

一个延时载，避免内存过高，一个异步加载，避免线程堵塞。

  

**19.Can we use two tableview controllers on one viewcontroller?**

  

是否在一个视图控制器中嵌入两个tableview控制器？

  

答案：一个视图控制只提供了一个View视图，理论上一个tableViewController也不能放吧，

  

只能说可以嵌入一个tableview视图。当然，题目本身也有歧义，如果不是我们定性思维认为的UIViewController，

  

而是宏观的表示视图控制者，那我们倒是可以把其看成一个视图控制者，它可以控制多个视图控制器，比如TabbarController那样的感觉。

  

**20.Can we use one tableview with two different datasources? How you will achieve this?**

  

一个tableView是否可以关联两个不同的数据源？你会怎么处理？

  

答案：首先我们从代码来看，数据源如何关联上的，其实是在数据源关联的代理方法里实现的。

  

因此我们并不关心如何去关联他，他怎么关联上，方法只是让我返回根据自己的需要去设置如相关的数据源。

  

因此，我觉得可以设置多个数据源啊，但是有个问题是，你这是想干嘛呢？想让列表如何显示，不同的数据源分区块显示？

  

**1.When to use NSMutableArray and when to use NSArray?**

  

什么时候使用NSMutableArray，什么时候使用NSArray？

  

答案：当数组在程序运行时，需要不断变化的，使用NSMutableArray，当数组在初始化后，便不再改变的，使用NSArray。需要指出的是，使用NSArr
ay只表明的是该数组在运行时不发生改变，即不能往NSAarry的数组里新增和删除元素，但不表明其数组內的元素的内容不能发生改变。NSArray是线程安全的，
NSMutableArray不是线程安全的，多线程使用到NSMutableArray需要注意。

  

**2.Give us example of what are delegate methods and what are data source methods of uitableview.**

  

给出委托方法的实例，并且说出UITableVIew的Data Source方法

  

答案：CocoaTouch框架中用到了大量委托，其中UITableViewDelegate就是委托机制的典型应用，是一个典型的使用委托来实现适配器模式，其中
UITableViewDelegate协议是目标，tableview是适配器，实现UITableViewDelegate协议，并将自身设置为talbevie
w的delegate的对象，是被适配器，一般情况下该对象是UITableViewController。

  

UITableVIew的Data Source方法有- (NSInteger)tableView:(UITableView *)tableView
numberOfRowsInSection:(NSInteger)section;

  

\- (UITableViewCell *)tableView:(UITableView *)tableView
cellForRowAtIndexPath:(NSIndexPath *)indexPath;

  

**3.How many autorelease you can create in your application? Is there any limit?**

  

在应用中可以创建多少autorelease对象，是否有限制？

  

答案：无

  

**4.If we don’t create any autorelease pool in our application then is there any autorelease pool already provided to us?**

  

如果我们不创建内存池，是否有内存池提供给我们？

  

答案:界面线程维护着自己的内存池，用户自己创建的数据线程，则需要创建该线程的内存池

  

**5.When you will create an autorelease pool in your application?**

  

什么时候需要在程序中创建内存池？

  

答案：用户自己创建的数据线程，则需要创建该线程的内存池

  

**7.What are commonly used NSObject class methods?**

  

类NSObject的那些方法经常被使用？

  

答案：NSObject是Objetive-C的基类，其由NSObject类及一系列协议构成。

  

其中类方法alloc、class、 description 对象方法init、dealloc、–
performSelector:withObject:afterDelay:等经常被使用

  

**8.What is convenience constructor?**

  

什么是简便构造方法？

  

答案：简便构造方法一般由CocoaTouch框架提供，如NSNumber的 + numberWithBool:  + numberWithChar:  +
numberWithDouble:  + numberWithFloat:  + numberWithInt:

  

Foundation下大部分类均有简便构造方法，我们可以通过简便构造方法，获得系统给我们创建好的对象，并且不需要手动释放。

  

**9.How to design universal application in Xcode?**

  

如何使用Xcode设计通用应用？

  

答案：使用MVC模式设计应用，其中Model层完成脱离界面，即在Model层，其是可运行在任何设备上，在controller层，根据iPhone与iPad（
独有UISplitViewController）的不同特点选择不同的viewController对象。在View层，可根据现实要求，来设计，其中以xib文件
设计时，其设置其为universal。

  

**11.What are UIView animations?**

  

UIView的动画效果有那些？

  

答案：有很多，如  UIViewAnimationOptionCurveEaseInOut
UIViewAnimationOptionCurveEaseIn     UIViewAnimationOptionCurveEaseOut
UIViewAnimationOptionTransitionFlipFromLeft
UIViewAnimationOptionTransitionFlipFromRight
UIViewAnimationOptionTransitionCurlUpUIViewAnimationOptionTransitionCurlDown

  

**12.How can you store data in iPhone applications?**

  

在iPhone应用中如何保存数据？

  

答案：有以下几种保存机制：

  

1.通过web服务，保存在服务器上

  

2.通过NSCoder固化机制，将对象保存在文件中

  

3.通过SQlite或CoreData保存在文件数据库中

  

**13.What is coredata?**

  

什么是coredata？

  

答案：coredata是苹果提供一套数据保存框架，其基于SQlite

  

**14.What is NSManagedObject model?**

  

什么是NSManagedObject模型？

  

答案：NSManagedObject是NSObject的子类 ，也是coredata的重要组成部分，它是一个通用的类,实现了core data
模型层所需的基本功能，用户可通过子类化NSManagedObject，建立自己的数据模型。

  

**15.What is NSManagedobjectContext?**

  

什么是NSManagedobjectContext？

  

答案：NSManagedobjectContext对象负责应用和数据库之间的交互。

  

**16.What is predicate?**

  

什么是谓词？

  

答案：谓词是通过NSPredicate，是通过给定的逻辑条件作为约束条件，完成对数据的筛选。

  

    predicate = [NSPredicate predicateWithFormat:@"customerID == %d",n];

  

    a = [customers filteredArrayUsingPredicate:predicate];

  

**17.What kind of persistence store we can use with coredata?**

  

使用coredata有哪几种持久化存储机制？

  

答案：无

**  
**

**1 谈谈对Block 的理解？并写出一个使用Block执行UIVew动画？**

  

答案：Block是可以获取其他函数局部变量的匿名函数，其不但方便开发，并且可以大幅提高应用的执行效率（多核心CPU可直接处理Block指令）

  

  1. [UIView transitionWithView:self.view
  2. duration:0.2
  3. options:UIViewAnimationOptionTransitionFlipFromLeft
  4. animations:^{ [[blueViewController view] removeFromSuperview]; [[self view] insertSubview:yellowViewController.view atIndex:0]; }
  5. completion:NULL];

**3 做过的项目是否涉及网络访问功能，使用什么对象完成网络功能？**

  

答案：ASIHTTPRequest与NSURLConnection

  

**4 简单介绍下NSURLConnection类及+ sendSynchronousRequest:returningResponse:error:与– initWithRequest:delegate:两个方法的区别？**

  

答案:  NSURLConnection主要用于网络访问，其中+ sendSynchronousRequest:returningResponse:erro
r:是同步访问数据，即当前线程会阻塞，并等待request的返回的response，而–
initWithRequest:delegate:使用的是异步加载，当其完成网络访问后，会通过delegate回到主线程，并其委托的对象。

  

**1 多线程是什么**

**  
**

多线程是个复杂的概念，按字面意思是同步完成多项任务，提高了资源的使用效率，从硬件、操作系统、应用软件不同的角度去看，多线程被赋予不同的内涵，对于硬件，现在市
面上多数的CPU都是多核的，多核的CPU运算多线程更为出色；从操作系统角度，是多任务，现在用的主流操作系统都是多任务的，可以一边听歌、一边写博客；对于应用来
说，多线程可以让应用有更快的回应，可以在网络下载时，同时响应用户的触摸操作。在iOS应用中，对多线程最初的理解，就是并发，它的含义是原来先做烧水，再摘菜，再
炒菜的工作，会变成烧水的同时去摘菜，最后去炒菜。

  

**2 iOS 中的多线程**

  

iOS中的多线程，是Cocoa框架下的多线程，通过Cocoa的封装，可以让我们更为方便的使用线程，做过C++的同学可能会对线程有更多的理解，比如线程的创立，
信号量、共享变量有认识，Cocoa框架下会方便很多，它对线程做了封装，有些封装，可以让我们创建的对象，本身便拥有线程，也就是线程的对象化抽象，从而减少我们的
工程，提供程序的健壮性。

  

GCD是（Grand Central Dispatch）的缩写 ，从系统级别提供的一个易用地多线程类库，具有运行时的特点，能充分利用多核心硬件。GCD的AP
I接口为C语言的函数，函数参数中多数有Block，[关于Block的使用参看这里](http://blog.csdn.net/xunyn/article/d
etails/11658261)，为我们提供强大的“接口”，[对于GCD的使用参见本文](http://blog.csdn.net/xunyn/articl
e/details/8682223)

  

NSOperation与Queue

NSOperation是一个抽象类，它封装了线程的细节实现，我们可以通过子类化该对象，加上NSQueue来同面向对象的思维，管理多线程程序。具体可参看这里：
[一个基于NSOperation的多线程网络访问的项目。](http://blog.csdn.net/xunyn/article/details/12583
545)

  

NSThread

NSThread是一个控制线程执行的对象，它不如NSOperation抽象，通过它我们可以方便的得到一个线程，并控制它。但NSThread的线程之间的并发控
制，是需要我们自己来控制的，可以通过NSCondition实现。

  

** iOS多线程常见面试题**

**  
**

在项目什么时候选择使用GCD，什么时候选择NSOperation？

项目中使用NSOperation的优点是NSOperation是对线程的高度抽象，在项目中使用它，会使项目的程序结构更好，子类化NSOperation的设计
思路，是具有面向对象的优点（复用、封装），使得实现是多线程支持，而接口简单，建议在复杂项目中使用。

项目中使用GCD的优点是GCD本身非常简单、易用，对于不复杂的多线程操作，会节省代码量，而Block参数的使用，会是代码更为易读，建议在简单项目中使用。

  

**1\. 你使用过Objective-C的运行时编程（Runtime Programming）么？如果使用过，你用它做了什么？你还能记得你所使用的相关的头文件或者某些方法的名称吗？**

  

Objecitve-C的重要特性是Runtime（运行时）,在#import <objc/runtime.h>
下能看到相关的方法，用过objc_getClass()和class_copyMethodList()获取过私有API;使用

```objective-c

Method method1 = class_getInstanceMethod(cls, sel1);

Method method2 = class_getInstanceMethod(cls, sel2);

method_exchangeImplementations(method1, method2);

```

代码交换两个方法，在写unit test时使用到。

  

**2\. 你实现过多线程的Core Data么？NSPersistentStoreCoordinator，NSManagedObjectContext和NSManagedObject中的哪些需要在线程中创建或者传递？你是用什么样的策略来实现的？**

  

没实现过多线程的CoreData(待实践)

<!--more—>

  

**3\. Core开头的系列的内容。是否使用过CoreAnimation和CoreGraphics。UI框架和CA，CG框架的联系是什么？分别用CA和CG做过些什么动画或者图像上的内容。（有需要的话还可以涉及Quartz的一些内容）**

**  
**

UI框架的底层有CoreAnimation，CoreAnimation的底层有CoreGraphics。

UIKit |

\------------ |

Core Animation |

Core Graphics |

Graphics Hardware|

使用CA做过menu菜单的展开收起（太逊了）

  

**4\. 是否使用过CoreText或者CoreImage等？如果使用过，请谈谈你使用CoreText或者CoreImage的体验。**

  

CoreText可以解决复杂文字内容排版问题。CoreImage可以处理图片，为其添加各种效果。体验是很强大，挺复杂的。

  

**5\. NSNotification和KVO的区别和用法是什么？什么时候应该使用通知，什么时候应该使用KVO，它们的实现上有什么区别吗？如果用protocol和delegate（或者delegate的Array）来实现类似的功能可能吗？如果可能，会有什么潜在的问题？如果不能，为什么？（虽然protocol和delegate这种东西面试已经面烂了…）**

  

NSNotification是通知模式在iOS的实现，KVO的全称是键值观察(Key-value observing),其是基于KVC（key-value 
coding）的，KVC是一个通过属性名访问属性变量的机制。例如将Module层的变化，通知到多个Controller对象时，可以使用NSNotificat
ion；如果是只需要观察某个对象的某个属性，可以使用KVO。

  

对于委托模式，在设计模式中是对象适配器模式，其是delegate是指向某个对象的，这是一对一的关系，而在通知模式中，往往是一对多的关系。委托模式，从技术上可
以现在改变delegate指向的对象，但不建议这样做，会让人迷惑，如果一个delegate对象不断改变，指向不同的对象。

  

**6\. 你用过NSOperationQueue么？如果用过或者了解的话，你为什么要使用NSOperationQueue，实现了什么？请描述它和GCD的区别和类似的地方（提示：可以从两者的实现机制和适用范围来描述）。**

  

使用NSOperationQueue用来管理子类化的NSOperation对象，控制其线程并发数目。GCD和NSOperation都可以实现对线程的管理，区
别是 NSOperation和NSOperationQueue是多线程的面向对象抽象。项目中使用NSOperation的优点是NSOperation是对线程
的高度抽象，在项目中使用它，会使项目的程序结构更好，子类化NSOperation的设计思路，是具有面向对象的优点（复用、封装），使得实现是多线程支持，而接口
简单，建议在复杂项目中使用。

  

项目中使用GCD的优点是GCD本身非常简单、易用，对于不复杂的多线程操作，会节省代码量，而Block参数的使用，会是代码更为易读，建议在简单项目中使用。

[更详细的答案见我的这篇文章](http://blog.csdn.net/xunyn/article/details/14525243)

  

**7\. 既然提到GCD，那么问一下在使用GCD以及block时要注意些什么？它们两是一回事儿么？block在ARC中和传统的MRC中的行为和用法有没有什么区别，需要注意些什么？**

**  
**

使用block是要注意，若将block做函数参数时，需要把它放到最后，GCD是Grand Central Dispatch，是一个对线程开源类库，而Bloc
k是闭包，是能够读取其他函数内部变量的函数。[更详细的答案见我的这篇文章](http://blog.csdn.net/xunyn/article/detai
ls/11658261)

  

**8\. 您是否做过异步的网络处理和通讯方面的工作？如果有，能具体介绍一些实现策略么？**

  

使用NSOperation发送异步网络请求，使用NSOperationQueue管理线程数目及优先级，底层是用NSURLConnetion，详细可见开源框架
[LWConnetion](https://github.com/xunyn/LWConnetionDemo)。

  

**9\. 对于Objective-C，你认为它最大的优点和最大的不足是什么？对于不足之处，现在有没有可用的方法绕过这些不足来实现需求。如果可以的话，你有没有考虑或者实践过重新实现OC的一些功能，如果有，具体会如何做？**

  

最大的优点是它的运行时特性，不足是没有命名空间，对于命名冲突，可以使用长命名法或特殊前缀解决，如果是引入的第三方库之间的命名冲突，可以使用link命令及fl
ag解决冲突。

  

**10\. 你实现过一个框架或者库以供别人使用么？如果有，请谈一谈构建框架或者库时候的经验；如果没有，请设想和设计框架的public的API，并指出大概需要如何做、需要注意一些什么方面，来使别人容易地使用你的框架。**

  

抽象和封装，方便使用。首先是对问题有充分的了解，比如构建一个文件解压压缩框架，从使用者的角度出发，只需关注发送给框架一个解压请求，框架完成复杂文件的解压操作
，并且在适当的时候通知给是哦难过者，如解压完成、解压出错等。在框架内部去构建对象的关系，通过抽象让其更为健壮、便于更改。其次是API的说明文档。

  

**3、Object-C有私有方法吗？私有变量呢？**

  

objective-c – 类里面的方法只有两种, 静态方法和实例方法. 这似乎就不是完整的面向对象了,按照OO的原则就是一个对象只暴露有用的东西.
如果没有了私有方法的话, 对于一些小范围的代码重用就不那么顺手了. 在类里面声名一个私有方法

  

@interface Controller : NSObject { NSString *something; }

  

+ (void)thisIsAStaticMethod;

  

– (void)thisIsAnInstanceMethod;

  

@end

  

@interface Controller (private) -

  

(void)thisIsAPrivateMethod;

  

@end

  

@private可以用来修饰私有变量

  

在Objective‐C中，所有实例变量默认都是私有的，所有实例方法默认都是公有的

  

**4、Object-C有多继承吗？没有的话用什么代替？cocoa 中所有的类都是NSObject 的子类**

  

多继承在这里是用protocol 委托代理 来实现的

  

你不用去考虑繁琐的多继承 ,虚基类的概念.

  

ood的多态特性 在 obj-c 中通过委托来实现.

  

**5、内存管理 Autorelease、retain、copy、assign的set方法和含义？**

  

1，你初始化(alloc/init)的对象，你需要释放(release)它。例如：

  

NSMutableArray aArray = [[NSArray alloc] init]; 后，需要 [aArray release];

  

2，你retain或copy的，你需要释放它。例如：

  

[aArray retain] 后，需要 [aArray release];

  

3，被传递(assign)的对象，你需要斟酌的retain和release。例如：

  

obj2 = [[obj1 someMethod] autorelease];

  

对象2接收对象1的一个自动释放的值，或传递一个基本数据类型(NSInteger，NSString)时：你或希望将对象2进行retain，以防止它在被使用之前
就被自动释放掉。但是在retain后，一定要在适当的时候进行释放。

  

关于索引计数(Reference Counting)的问题

  

retain值 = 索引计数(Reference Counting)

  

NSArray对象会retain(retain值加一)任何数组中的对象。当NSArray被卸载(dealloc)的时候，所有数组中的对象会 被
执行一次释放(retain值减一)。不仅仅是NSArray，任何收集类(Collection Classes)都执行类似操作。例如
NSDictionary，甚至UINavigationController。

  

Alloc/init建立的对象，索引计数为1。无需将其再次retain。

  

[NSArray array]和[NSDate date]等“方法”建立一个索引计数为1的对象，但是也是一个自动释放对象。所以是本地临时对象，那么无所谓了。
如果是打算在全Class中使用的变量(iVar)，则必须retain它。

  

缺省的类方法返回值都被执行了“自动释放”方法。(*如上中的NSArray)

  

在类中的卸载方法“dealloc”中，release所有未被平衡的NS对象。(*所有未被autorelease，而retain值为1的)

  

**10、Objective-C堆和栈的区别？**

  

管理方式：对于栈来讲，是由编译器自动管理，无需我们手工控制；对于堆来说，释放工作由程序员控制，容易产生memory leak。

  

申请大小：

  

栈：在Windows下,栈是向低地址扩展的数据结构，是一块连续的内存的区域。这句话的意思是栈顶的地址和栈的最大容量是系统预先规定好的，在
WINDOWS下，栈的大小是2M（也有的说是1M，总之是一个编译时就确定的常数），如果申请的空间超过栈的剩余空间时，将提示overflow。因
此，能从栈获得的空间较小。

  

堆：堆是向高地址扩展的数据结构，是不连续的内存区域。这是由于系统是用链表来存储的空闲内存地址的，自然是不连续的，而链表的遍历方向是由低地址向高地址。堆的大小
受限于计算机系统中有效的虚拟内存。由此可见，堆获得的空间比较灵活，也比较大。

  

碎片问题：对于堆来讲，频繁的new/delete势必会造成内存空间的不连续，从而造成大量的碎片，使程序效率降低。对于栈来讲，则不会存在这个问题，因为栈是先进
后出的队列，他们是如此的一一对应，以至于永远都不可能有一个内存块从栈中间弹出

  

分配方式：堆都是动态分配的，没有静态分配的堆。栈有2种分配方式：静态分配和动态分配。静态分配是编译器完成的，比如局部变量的分配。动态分配由alloca函数进
行分配，但是栈的动态分配和堆是不同的，他的动态分配是由编译器进行释放，无需我们手工实现。

  

分配效率：栈是机器系统提供的数据结构，计算机会在底层对栈提供支持：分配专门的寄存器存放栈的地址，压栈出栈都有专门的指令执行，这就决定了栈的效率比较高。堆则是
C/C++函数库提供的，它的机制是很复杂的。

  

**循环引用**

**  
**

所有的引用计数系统，都存在循环应用的问题。例如下面的引用关系：

    •    对象a创建并引用到了对象b.

    •    对象b创建并引用到了对象c.

    •    对象c创建并引用到了对象b.

这时候b和c的引用计数分别是2和1。当a不再使用b，调用release释放对b的所有权，因为c还引用了b，所以b的引用计数为1，b不会被释放。b不释放，c的
引用计数就是1，c也不会被释放。从此，b和c永远留在内存中。

这种情况，必须打断循环引用，通过其他规则来维护引用关系。比如，我们常见的delegate往往是assign方式的属性而不是retain方式 的属性，赋值不会
增加引用计数，就是为了防止delegation两端产生不必要的循环引用。如果一个UITableViewController对象a通过retain获取了UIT
ableView对象b的所有权，这个UITableView对象b的delegate又是a，
如果这个delegate是retain方式的，那基本上就没有机会释放这两个对象了。自己在设计使用delegate模式时，也要注意这点。

  

**tableView的重用机制？**

  

　查看UITableView头文件，会找到NSMutableArray*  visiableCells，和NSMutableDictnery* reusab
leTableCells两个结构。visiableCells内保存当前显示的cells，reusableTableCells保存可重用的cells。

  

　　TableView显示之初，reusableTableCells为空，那么tableViewdequeueReusableCellWithIdentif
ier:CellIdentifier返回nil。开始的cell都是通过[[UITableViewCell
alloc]initWithStyle:UITableViewCellStyleDefault
reuseIdentifier:CellIdentifier]来创建，而且cellForRowAtIndexPath只是调用最大显示cell数的次数。

  

　　比如：有100条数据，iPhone一屏最多显示10个cell。程序最开始显示TableView的情况是：

  

　　1. 用[[UITableViewCell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier]创建10次cell，并给cell指定同样的重用标识(当然，可以为不同显示类型的cell指定不同的标识)。并且10个cell全部都加入到visiableCells数组，reusableTableCells为空。

  

　　2. 向下拖动tableView，当cell1完全移出屏幕，并且cell11(它也是alloc出来的，原因同上)完全显示出来的时候。cell11加入到visiableCells，cell1移出visiableCells，cell1加入到reusableTableCells。

  

3\. 接着向下拖动tableView，因为reusableTableCells中已经有值，所以，当需要显示新的cell，cellForRowAtIndex
Path再次被调用的时候，tableViewdequeueReusableCellWithIdentifier:CellIdentifier，返回cell1
。cell1加入到visiableCells，cell1移出reusableTableCells；cell2移出visiableCells，cell2加入到
reusableTableCells。之后再需要显示的Cell就可以正常重用了。

  

**ViewController 的loadView、viewDidLoad、viewDidUnload分别是什么时候调用的，在自定义ViewCointroller时在这几个函数中应该做什么工作？**

  

由init、loadView、viewDidLoad、viewDidUnload、dealloc的关系说起

init方法

在init方法中实例化必要的对象（遵从LazyLoad思想）

init方法中初始化ViewController本身

  

loadView方法

当view需要被展示而它却是nil时，viewController会调用该方法。不要直接调用该方法。

如果手工维护views，必须重载重写该方法

如果使用IB维护views，必须不能重载重写该方法

  

loadView和IB构建view

你在控制器中实现了loadView方法，那么你可能会在应用运行的某个时候被内存管理控制调用。 如果设备内存不足的时候， view
控制器会收到didReceiveMemoryWarning的消息。 默认的实现是检查当前控制器的view是否在使用。
如果它的view不在当前正在使用的view hierarchy里面，且你的控制器实现了loadView方法，那么这个view将被release,
loadView方法将被再次调用来创建一个新的view。

  

viewDidLoad方法

viewDidLoad 此方法只有当view从nib文件初始化的时候才被调用。

重载重写该方法以进一步定制view

在iPhone OS 3.0及之后的版本中，还应该重载重写viewDidUnload来释放对view的任何索引

viewDidLoad后调用数据Model

  

viewDidUnload方法

当系统内存吃紧的时候会调用该方法（注：viewController没有被dealloc）

内存吃紧时，在iPhone OS 3.0之前didReceiveMemoryWarning是释放无用内存的唯一方式，但是OS
3.0及以后viewDidUnload方法是更好的方式

在该方法中将所有IBOutlet（无论是property还是实例变量）置为nil（系统release view时已经将其release掉了）

  

在该方法中释放其他与view有关的对象、其他在运行时创建（但非系统必须）的对象、在viewDidLoad中被创建的对象、缓存数据等
release对象后，将对象置为nil（IBOutlet只需要将其置为nil，系统release view时已经将其release掉了）

  

一般认为viewDidUnload是viewDidLoad的镜像，因为当view被重新请求时，viewDidLoad还会重新被执行

  

viewDidUnload中被release的对象必须是很容易被重新创建的对象（比如在viewDidLoad或其他方法中创建的对象），不要release用户
数据或其他很难被重新创建的对象

  

dealloc方法

viewDidUnload和dealloc方法没有关联，dealloc还是继续做它该做的事情

  

**ViewController的didReceiveMemoryWarning是在什么时候调用的？默认的操作是什么？**

  

当程序接到内存警告时View Controller将会收到这个消息：didReceiveMemoryWarning

  

从iOS3.0开始，不需要重载这个函数，把释放内存的代码放到viewDidUnload中去。

  

这个函数的默认实现是:检查controller是否可以安全地释放它的**view**(这里加粗的**view**指的是controller的**view**
属性)，比如**view**本身没有superview并且可以被很容易地重建（从nib或者loadView函数）。

  

如果**view**可以被释放，那么这个函数释放**view**并调用viewDidUnload。

  

你可以重载这个函数来释放controller中使用的其他内存。但要记得调用这个函数的super实现来允许父类（一般是UIVIewController）释放*
*view**。

  

如果你的ViewController保存着**view**的子view的引用，那么，在早期的iOS版本中，你应该在这个函数中来释放这些引用。而在iOS3.0
或更高版本中，你应该在viewDidUnload中释放这些引用。

  

**delegate和notification区别，分别在什么情况下使用？**

  

KVC(Key-Value-Coding)

KVO（Key-Value-Observing）

  

**Key-Value Coding (KVC)**

  

KVC，即是指 NSKeyValueCoding，一个非正式的 Protocol，提供一种机制来间接访问对象的属性。KVO 就是基于 KVC
实现的关键技术之一。

  

一个对象拥有某些属性。比如说，一个 Person 对象有一个 name 和一个 address 属性。以 KVC 说法，Person 对象分别有一个
value 对应他的 name 和 address 的 key。 key 只是一个字符串，它对应的值可以是任意类型的对象。从最基础的层次上看，KVC
有两个方法：一个是设置 key 的值，另一个是获取 key 的值。如下面的例子：

  

**void** changeName(Person *p, NSString *newName)  

  

{

  

    // using the KVC accessor (getter) method

    NSString *originalName = [p valueForKey:@"name"];

  

    // using the KVC  accessor (setter) method.

    [p setValue:newName forKey:@"name"];

  

    NSLog(@"Changed %@'s name to: %@", originalName, newName);

  

}

  

现在，如果 Person 有另外一个 key 配偶（spouse），spouse 的 key 值是另一个 Person 对象，用 KVC 可以这样写：

  

**void** logMarriage(Person *p)  

  

{

  

    // just using the accessor again, same as example above

    NSString *personsName = [p valueForKey:@"name"];

  

    // this line is different, because it is using

    // a "key path" instead of a normal "key"

    NSString *spousesName = [p
valueForKeyPath:@"[spouse.name](http://spouse.name/)"];

  

    NSLog(@"%@ is happily married to %@", personsName, spousesName);

  

}

  

key 与 key pat 要区分开来，key 可以从一个对象中获取值，而 key path 可以将多个 key 用点号 “.” 分割连接起来，比如：

  

[p valueForKeyPath:@"[spouse.name](http://spouse.name/)"];

  

相当于这样……

  

[[p valueForKey:@"spouse"] valueForKey:@"name"];

  

好了，以上是 KVC 的基本知识，接着看看 KVO。

  

Key-Value Observing (KVO)

  

Key-Value Observing (KVO) 建立在 KVC 之上，它能够观察一个对象的 KVC key path 值的变化。举个例子，用代码观察一个
person 对象的 address 变化，以下是实现的三个方法：

  * watchPersonForChangeOfAddress: 实现观察
  * observeValueForKeyPath:ofObject:change:context: 在被观察的 key path 的值变化时调用。
  * dealloc 停止观察

**static** NSString ***const** KVO_CONTEXT_ADDRESS_CHANGED = @"KVO_CONTEXT_ADDRESS_CHANGED"  

  

  

@implementation PersonWatcher

  

-(**void**) watchPersonForChangeOfAddress:(Person *)p

{

  

    // this begins the observing

    [p addObserver:self

        forKeyPath:@"address"

          options:0

          context:KVO_CONTEXT_ADDRESS_CHANGED];

  

    // keep a record of all the people being observed,

    // because we need to stop observing them in dealloc

    [m_observedPeople addObject:p];

}

  

// whenever an observed key path changes, this method will be called

\- (**void**)observeValueForKeyPath:(NSString *)keyPath

                      ofObject:(id)object

                        change:(NSDictionary *)change

                      context:(**void** *)context  

  

  

{

    // use the context to make sure this is a change in the address,

    // because we may also be observing other things

    **if**(context == KVO_CONTEXT_ADDRESS_CHANGED) {

        NSString *name = [object valueForKey:@"name"];

        NSString *address = [object valueForKey:@"address"];

        NSLog(@"%@ has a new address: %@", name, address);

    }

}

  

-(**void**) dealloc;

{

  

    // must stop observing everything before this object is

    // deallocated, otherwise it will cause crashes

    **for**(Person *p in m_observedPeople){

        [p removeObserver:self forKeyPath:@"address"];

    }

  

    [m_observedPeople release];

    m_observedPeople = nil;

  

    [super dealloc];

  

}

  

-(id) init;

{

    **if**(self = [super init]){

        m_observedPeople = [NSMutableArray **new**];  

  

    }

  

    **return** self;  

  

}

  

@end

  

这就是 KVO 的作用，它通过 key path 观察对象的值，当值发生变化的时候会收到通知。

**  
**

**关键字const什么含义**

  

const意味着”只读”，下面的声明都是什么意思？

const int a;

int const a;

const int *a;

int * const a;

int const * a const;

  

前两个的作用是一样，a是一个常整型数。第三个意味着a是一个指向常整型数的指针（也就是，整型数是不可修改的，但指针可以）。第四个意思a是一个指向整型数的常指针
（也就是说，指针指向的整型数是可以修改的，但指针是不可修改的）。最后一个意味着a是一个指向常整型数的常指针（也就是说，指针指向的整型数是不可修改的，同时指针
也是不可修改的）。

  

结论：

•; 关键字const的作用是为给读你代码的人传达非常有用的信息，实际上，声明一个参数为常量是为了告诉了用户这个参数的应用目的。如果你曾花很多时间清理其它人
留下的垃圾，你就会很快学会感谢这点多余的信息。（当然，懂得用const的程序员很少会留下的垃圾让别人来清理的。）

•; 通过给优化器一些附加的信息，使用关键字const也许能产生更紧凑的代码。

•; 合理地使用关键字const可以使编译器很自然地保护那些不希望被改变的参数，防止其被无意的代码修改。简而言之，这样可以减少bug的出现。

  

欲阻止一个变量被改变，可以使用 const 关键字。在定义该 const 变量时，通常需要对它进行初

始化，因为以后就没有机会再去改变它了；

（2）对指针来说，可以指定指针本身为 const，也可以指定指针所指的数据为 const，或二者同时指

定为 const；

（3）在一个函数声明中，const 可以修饰形参，表明它是一个输入参数，在函数内部不能改变其值；

（4）对于类的成员函数，若指定其为 const 类型，则表明其是一个常函数，不能修改类的成员变量；

（5）对于类的成员函数，有时候必须指定其返回值为 const 类型，以使得其返回值不为“左值”。

  

**关键字volatile有什么含义？并给出三个不同例子？**

  

一个定义为volatile的变量是说这变量可能会被意想不到地改变，这样，编译器就不会去假设这个变量的值了。精确地说就是，优化器在用到这个变量时必须每次都小心
地重新读取这个变量的值，而不是使用保存在寄存器里的备份。下面是volatile变量的几个例子：

• 并行设备的硬件寄存器（如：状态寄存器）

• 一个中断服务子程序中会访问到的非自动变量(Non-automatic variables)

• 多线程应用中被几个任务共享的变量

  

• 一个参数既可以是const还可以是volatile吗？解释为什么。

• 一个指针可以是volatile 吗？解释为什么。

  

下面是答案：

• 是的。一个例子是只读的状态寄存器。它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。

• 是的。尽管这并不很常见。一个例子是当一个中服务子程序修该一个指向一个buffer的指针时。

  

**线程和进程的区别？**

  

进程和线程都是由操作系统所体会的程序运行的基本单元，系统利用该基本单元实现系统对应用的并发性。

进 程和线程的主要差别在于它们是不同的操作系统资源管理方式。进程有独立的地址空间，一个进程崩溃后，在保护模式下不会对其它进程产生影响，而线程只是一个
进程中的不同执行路径。线程有自己的堆栈和局部变量，但线程之间没有单独的地址空间，一个线程死掉就等于整个进程死掉，所以多进程的程序要比多线程的程序
健壮，但在进程切换时，耗费资源较大，效率要差一些。但对于一些要求同时进行并且又要共享某些变量的并发操作，只能用线程，不能用进程。

  

**当一个空指针（nil pointer）调用了一个方法会发生什么？**

**  
**

**什么都不做**

**  
**

**  
**

1\. 请解释下method swizzling，并说出你一般什么时候会用到它？

  

MethodSwizzling是一种在运行时修改方法名与方法实现映射关系的技术,常用于在系统内部方法的基础上增加新的处理流程。

  

2\. 假设有三个对象，一个父类的父类，一个父类和一个子类。父类的父类持有父类的引用（retain），父类持有子类的引用（retain），子类持有父类的引用
（retain）。父类的父类释放（release）父类，解释下会发生什么。

  

父类被父类的父类释放掉以后，父类的引用计数－1，而因为子类拥有父类的计数，父类并未销毁。

  

3\. 当一个空指针（nil pointer）调用了一个方法会发生什么？

  

安然无恙 —— 这是oc自带的消息机制，nil也能发送消息，而不会报错

  

4\. 为什么retainCount绝对不能用在发布的代码中？请给出两个相对独立的解释。

  

a,因为retainCount不靠谱，不能真实的反映一个对象的引用计数

  

b,使用 alloc release等东西，一一对应，不需要retainCount

c,app已然推荐ARC，连release都不用了，更何况retainCount

  

－retainCount受到时间和framework的影响太大，不能准确反映内存的引用计数

  

－retainCount很容易迷惑人，采取规范的内存管理才是王道

  

5\. 请说明一下你查找或者解决内存泄露的处理过程。

  

利用Xcode的工具，

  

Analyze来看各种提示信息 (你可以在building setting里面开启各种烦人的提示)

Profile跟进一些具体的内存的点

  

跟进具体的代码，来看一些关键的点 block、delegate等

  

使用instruments作为动态分析的手段，还有Xcode的静态内存分析

  

6\. 解释下自动回收池(autorelease pool)在程序运行时是如何运作的。

  

xcode为开发者写的代码外层包了一层NSAutoreleasePool。建立一个回收池堆栈(Stack)每次对象发送autorelease消息时，对象的引
用计数并不真正变化，而是向pool中添加一条记录，记下对象的这种要求。最后当pool发送drain或release消息时，池中的所有对象的这种要求一一被执行
。顺便说下使用场景：－应用不是基于"Application Kit",像"Command-line tool",因为它并没有内置的"autorelease
pools"的支持。－创建线程，你必需在线程开始时创建一个'"Autorelease
Pool"实例。反之，会造成内存池泄漏。一个循环内创建了太多的临时对象，你应该为他们创建一个"Autorelease
Pool"对象，并在下次循环之前销毁它们。

  

7\. 当处理属性申明的时候，原子（atomic）跟 非原子（non-atomic）属性有什么区别？

  

是否线程安全

  

atomic是原子的，多线程的时候，可以防止写操作完毕前被读取

  

事关多线程，原子(atomic)可以说是线程安全的，也就是在读取这个属性的变量的时候，会进行一些额外的操作（比如锁），所以说，atomic会比较安全电视比较
耗时。

  

8\. 在C语言中，你如何能用尽可能短的时间来倒转一个字符串？

  

char *revstr(char *str, size_t len)

{

    char    *start = str;

    char    *end = str + len - 1;

    char    ch;

    if (str != NULL)

    {

       while (start < end)

        {

            ch = *start;

            *start++ = *end;

            *end-- = ch;

        }

    }

    return str;

}  

  

9\. 遍历一个NSArray和一个NSSet，哪一个更快？

  

其实意思是问，遍历一个链表和哈希表，哪个更快？

  

如果你只需要保存和遍历一些数据，就选择NSArray,或者元素个数比较小，那么及时需要查找的功能，也不要用NSSet.

  

只有在元素个数很大，或者需要保证数据唯一性的情况下，使用NSSet.

  

10\. 解释代码签名（code signing）是如何运作的。

  

**代码签名的原理**

  

其实代码签名是一个比较通用的技术，而底层实现都是使用RSA不对称加密的原理，数学原理就不在此赘述，RSA密钥体系中，有一个公钥和一个私钥，公钥是公开出去的，
私钥自己保存。数字签名一般是这样的，先对文件做摘要如MD5的散列，然后使用你自己的私钥对这个散列码进行加密，并和文件合并在一起。

这样当其他人获得这个文件的时候，使用签名者的公钥对报文进行解密，然后和文件的MD5散列进行比较，这样既保证了来源的可靠性也保证了数据的完整性。

  

用过诺基亚的高端智能手机的人也许知道“给软件签名”这个说法，否则设备不会接受这个软件，代码签名主要是为了保证代码的安全性，没有恶意或不安全的代码。

代码签名确保代码的真实以及明确识别代码的来源。在代码运行在一个开发系统以前，以及在代码提交到Apple发布以前，Apple要求所有的的应用程序都必须进行数字
签名。另外，Apple在发布每一个应用程序之前都要添加他自己的数字签名。

  

11\. Objective-C中的posing指的是什么？

  

 Posing，顾名思义，意思是“冒充”，它跟categories类似，但本质上不一样，Posing存在的目的在于子类可以冒充父类，使得后续的代码无需把父类
修改为子类，就可以很方便的让父类表现成子类的行为，从而实现非常方便的冒充，这在一般的语言中是难以想象的。

       它允许你扩展一个class，并且全面的冒充这个super class，比如：你有一个扩展NSArray的NSArrayChild对象，如果你让
NSArrayChild冒充NSArray，则你程序代码所在的NSArray都会自动替换为NSArrayChild。注意，这里不是指代码替换，而是NSArr
ay所在地方的行为都跟NSArrayChild一样了。

  

12\. 列举标准Xcode版本中的6个工具。

  

13\. copy跟retain有什么区别？

  

一个是复制内容，一个引用计数+1，（NSString比较特殊，两个的功能几乎一样）需要注意的是，自定义的类需要重写一个方法以实现自己的深复制：

  

    －(id)copyWithZone:(NSZone *)Zone{

  

               grandSuper *scCopy;

  

              scCopy = [[[self class] allocWithZone:Zone]init];

  

              return scCopy;

  

    }

  

14\. frames跟bounds有哪些区别？

  

frame相对于superView而言

bounds相对于自身的origin而言，一般是(0,0)，设备朝向变化，bounds会变

  

15\. 执行如下的代码会发生什么情况？

  

Ball *ball = [[[[Ball alloc] init] autorelease] autorelease];

  

崩溃，因为重复释放，在自动回收池下一次进行回收时崩溃

  

16\. 列举5个iOS app的状态。

  

程序开始，程序暂停（挂起），程序进入后台，程序进入前台，程序重新激活，程序意外暂停

  

1.首次启动应用程序：程序开始，程序再次激活

  

2.按home键退出：程序暂停，程序进入后台

  

3.再次进入程序：程序进入前台，程序再次激活

  


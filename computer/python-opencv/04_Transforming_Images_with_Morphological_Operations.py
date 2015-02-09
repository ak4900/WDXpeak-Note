# -*- coding: utf-8 -*-
import cv2
import numpy

# 定义结构元素
# 形态学处理的核心就是定义结构元素，在OpenCV-Python中，可以使用其自带的getStructuringElement函数，
# 也可以直接使用NumPy的ndarray来定义一个结构元素。首先来看用getStructuringElement函数定义一个结构元素：
# element = cv2.getStructuringElement(cv2.MORPH_CROSS,(5,5))
# 这就定义了一个5×5的十字形结构元素
# 也可以用NumPy来定义结构元素，如下
# NpKernel = np.uint8(np.zeros((5,5)))  
# for i in range(5):  
#     NpKernel[2, i] = 1 #感谢chenpingjun1990的提醒，现在是正确的  
#     NpKernel[i, 2] = 1
# 这里可以看出，用OpenCV-Python内置的常量定义椭圆（MORPH_ELLIPSE）和十字形结构（MORPH_CROSS）元素要简单一些，
# 如果定义矩形（MORPH_RECT）和自定义结构元素，则两者差不多。

# 腐蚀和膨胀
# 下面先以腐蚀图像为例子介绍如何使用结构元素
img = cv2.imread('pics/scene.png',0)
#OpenCV定义的结构元素
kernel = cv2.getStructuringElement(cv2.MORPH_RECT,(3, 3))
#腐蚀图像
eroded = cv2.erode(img,kernel)
#显示腐蚀后的图像
cv2.imshow("Eroded Image",eroded);

#膨胀图像
dilated = cv2.dilate(img,kernel)
#显示膨胀后的图像
cv2.imshow("Dilated Image",dilated);
#原图像
cv2.imshow("Origin", img)

#NumPy定义的结构元素
NpKernel = numpy.uint8(numpy.ones((3,3)))
Nperoded = cv2.erode(img,NpKernel)
#显示腐蚀后的图像
cv2.imshow("Eroded by NumPy kernel",Nperoded);

# 如上所示，腐蚀和膨胀的处理很简单，只需设置好结构元素，然后分别调用cv2.erode(...)和cv2.dilate(...)函数即可，
# 其中第一个参数是需要处理的图像，第二个是结构元素。返回处理好的图像。


# 开运算和闭运算
# 了解形态学基本处理的同学都知道，开运算和闭运算就是将腐蚀和膨胀按照一定的次序进行处理。
# 但这两者并不是可逆的，即先开后闭并不能得到原先的图像。代码示例如下：

# 定义结构元素
kernel = cv2.getStructuringElement(cv2.MORPH_RECT,(5, 5))
# 闭运算
closed = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)
# 显示腐蚀后的图像
cv2.imshow("Close",closed);
# 开运算
opened = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernel)
# 显示腐蚀后的图像
cv2.imshow("Open", opened);

# 闭运算用来连接被误分为许多小块的对象，而开运算用于移除由图像噪音形成的斑点。
# 因此，某些情况下可以连续运用这两种运算。如对一副二值图连续使用闭运算和开运算，将获得图像中的主要对象。
# 同样，如果想消除图像中的噪声（即图像中的“小点”），也可以对图像先用开运算后用闭运算，
# 不过这样也会消除一些破碎的对象。

# 用形态学运算检测边和角点
# 这里通过一个较复杂的例子介绍如何用形态学算子检测图像中的边缘和拐角（这里只是作为介绍形态学处理例子，
# 实际使用时请用Canny或Harris等算法）。

# 检测边缘
# 形态学检测边缘的原理很简单，在膨胀时，图像中的物体会想周围“扩张”；腐蚀时，图像中的物体会“收缩”。
# 比较这两幅图像，由于其变化的区域只发生在边缘。所以这时将两幅图像相减，得到的就是图像中物体的边缘。

image = cv2.imread("pics/face1.jpg",0);
#构造一个3×3的结构元素   
element = cv2.getStructuringElement(cv2.MORPH_RECT,(3, 3))
dilate = cv2.dilate(image, element)
erode = cv2.erode(image, element)
  
#将两幅图像相减获得边，第一个参数是膨胀后的图像，第二个参数是腐蚀后的图像  
result = cv2.absdiff(dilate,erode);
  
#上面得到的结果是灰度图，将其二值化以便更清楚的观察结果  
retval, result = cv2.threshold(result, 40, 255, cv2.THRESH_BINARY);
#反色，即对二值图每个像素取反  
result = cv2.bitwise_not(result);
#显示图像  
cv2.imshow("result",result);

# 检测拐角
# 与边缘检测不同，拐角的检测的过程稍稍有些复杂。但原理相同，所不同的是先用十字形的结构元素膨胀像素，
# 这种情况下只会在边缘处“扩张”，角点不发生变化。接着用菱形的结构元素腐蚀原图像，导致只有在拐角处才会“收缩”，
# 而直线边缘都未发生变化。
# 第二步是用X形膨胀原图像，角点膨胀的比边要多。这样第二次用方块腐蚀时，角点恢复原状，而边要腐蚀的更多。
# 所以当两幅图像相减时，只保留了拐角处。

image = cv2.imread("pics/square.png", 0)
origin = cv2.imread("pics/square.png")
#构造5×5的结构元素，分别为十字形、菱形、方形和X型  
cross = cv2.getStructuringElement(cv2.MORPH_CROSS,(5, 5))
#菱形结构元素的定义稍麻烦一些  
diamond = cv2.getStructuringElement(cv2.MORPH_RECT,(5, 5))
diamond[0, 0] = 0
diamond[0, 1] = 0
diamond[1, 0] = 0
diamond[4, 4] = 0
diamond[4, 3] = 0
diamond[3, 4] = 0
diamond[4, 0] = 0
diamond[4, 1] = 0
diamond[3, 0] = 0
diamond[0, 3] = 0
diamond[0, 4] = 0
diamond[1, 4] = 0
square = cv2.getStructuringElement(cv2.MORPH_RECT,(5, 5))
x = cv2.getStructuringElement(cv2.MORPH_CROSS,(5, 5))
#使用cross膨胀图像
result1 = cv2.dilate(image,cross)
#使用菱形腐蚀图像  
result1 = cv2.erode(result1, diamond)

#使用X膨胀原图像   
result2 = cv2.dilate(image, x)
#使用方形腐蚀图像   
result2 = cv2.erode(result2,square)
  
#result = result1.copy()  
#将两幅闭运算的图像相减获得角   
result = cv2.absdiff(result2, result1)
#使用阈值获得二值图  
retval, result = cv2.threshold(result, 40, 255, cv2.THRESH_BINARY)
  
#在原图上用半径为5的圆圈将点标出。  
for j in range(result.size):
    y = j / result.shape[0]
    x = j % result.shape[0]

    if result[x, y] == 255:
    	cv2.circle(image, (y, x), 5, (255,0,0))

cv2.imshow("Result", image) 

cv2.waitKey(0)
cv2.destroyAllWindows()





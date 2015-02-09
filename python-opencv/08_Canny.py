# -*- coding: utf-8 -*-
import cv2
import numpy

# OpenCV-Python中Canny函数的原型为：
# edge = cv2.Canny(image, threshold1, threshold2[, edges[, apertureSize[, L2gradient ]]])
# 必要参数：
# 第一个参数是需要处理的原图像，该图像必须为单通道的灰度图；
# 第二个参数是阈值1；
# 第三个参数是阈值2。
# 其中较大的阈值2用于检测图像中明显的边缘，但一般情况下检测的效果不会那么完美，边缘检测出来是断断续续的。
# 所以这时候用较小的第一个阈值用于将这些间断的边缘连接起来。
# 可选参数中apertureSize就是Sobel算子的大小。而L2gradient参数是一个布尔值，如果为真，
# 则使用更精确的L2范数进行计算（即两个方向的倒数的平方和再开放），否则使用L1范数（直接将两个方向导数的绝对值相加）。

# 具体的算法可参见清华大学出版社的《图像处理与计算机视觉算法及应用(第2版) 》第二章，其中有Canny算法的详细描述及实现。
# 函数返回一副二值图，其中包含检测出的边缘。

# Canny函数的使用很简单，只需指定最大和最小阈值即可。如下：

img = cv2.imread("pics/face.png", 0)

img = cv2.GaussianBlur(img,(3,3),0)
canny = cv2.Canny(img, 50, 100)
  
# 首先，由于Canny只能处理灰度图，所以将读取的图像转成灰度图。
# 用高斯平滑处理原图像降噪。
# 调用Canny函数，指定最大和最小阈值，其中apertureSize默认为3。

cv2.imshow('Canny', canny)
cv2.waitKey(0)
cv2.destroyAllWindows()
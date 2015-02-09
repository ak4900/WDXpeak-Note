# -*- coding: utf-8 -*-
import cv2
import numpy

# Laplacian算子
# 图像中的边缘区域，像素值会发生“跳跃”，对这些像素求导，在其一阶导数在边缘位置为极值，
# 这就是Sobel算子使用的原理——极值处就是边缘。
# 如果对像素值求二阶导数，会发现边缘处的导数值为0。
# Laplace函数实现的方法是先用Sobel 算子计算二阶x和y导数，再求和

# 函数原型
# 在OpenCV-Python中，Laplace算子的函数原型如下：
# dst = cv2.Laplacian(src, ddepth[, dst[, ksize[, scale[, delta[, borderType]]]]])

# 如果看了上一篇Sobel算子的介绍，这里的参数应该不难理解。
# 前两个是必须的参数：
# 第一个参数是需要处理的图像；
# 第二个参数是图像的深度，-1表示采用的是与原图像相同的深度。目标图像的深度必须大于等于原图像的深度；
# 其后是可选的参数：

# dst不用解释了；
# ksize是算子的大小，必须为1、3、5、7。默认为1。
# scale是缩放导数的比例常数，默认情况下没有伸缩系数；
# delta是一个可选的增量，将会加到最终的dst中，同样，默认情况下没有额外的值加到dst中；
# borderType是判断图像边界的模式。这个参数默认值为cv2.BORDER_DEFAULT。

img = cv2.imread("pics/face.png", 0)
gray_lap = cv2.Laplacian(img,cv2.CV_16S,ksize = 3)
dst = cv2.convertScaleAbs(gray_lap)

# 有点像粉笔画，是吧。这是因为原图像未经过去噪就直接处理了。
# 可以通过滤波一文中，使用低通滤波一节中高斯模糊来先处理一下再用拉普拉斯函数。
# 下面是先低通之后，可以感受一下

result = cv2.blur(img, (3,3))
gray_lap_blur = cv2.Laplacian(result, cv2.CV_16S, ksize = 3)
dst_blur = cv2.convertScaleAbs(gray_lap_blur)

cv2.imshow('laplacian',dst)
cv2.imshow('laplacian with blur',dst_blur)
cv2.waitKey(0)
cv2.destroyAllWindows()
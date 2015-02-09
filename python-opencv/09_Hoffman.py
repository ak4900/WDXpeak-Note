# -*- coding: utf-8 -*-
import cv2
import numpy

# 霍夫变换
# Hough变换是经典的检测直线的算法。其最初用来检测图像中的直线，同时也可以将其扩展，
# 以用来检测图像中简单的结构。
# OpenCV提供了两种用于直线检测的Hough变换形式。其中基本的版本是cv2.HoughLines。
# 其输入一幅含有点集的二值图（由非0像素表示），其中一些点互相联系组成直线。
# 通常这是通过如Canny算子获得的一幅边缘图像。cv2.HoughLines函数输出的是[float, float]形式的ndarray，
# 其中每个值表示检测到的线(ρ , θ)中浮点点值的参数。下面的例子首先使用Canny算子获得图像边缘，
# 然后使用Hough变换检测直线。其中HoughLines函数的参数3和4对应直线搜索的步长。
# 在本例中，函数将通过步长为1的半径和步长为π/180的角来搜索所有可能的直线。
# 最后一个参数是经过某一点曲线的数量的阈值，超过这个阈值，就表示这个交点所代表的参数对(rho, theta)在
# 原图像中为一条直线。
# http://blog.csdn.net/sunny2038/article/details/9253823

img = cv2.imread("pics/face1.jpg", 0)

img = cv2.GaussianBlur(img,(3,3),0)
edges = cv2.Canny(img, 50, 150, apertureSize = 3)
lines = cv2.HoughLines(edges,1,numpy.pi/180,118) #这里对最后一个参数使用了经验型的值  
result = img.copy()
  
#经验参数  
minLineLength = 200  
maxLineGap = 15  
lines = cv2.HoughLinesP(edges,1,numpy.pi/180,80,minLineLength,maxLineGap)  
for x1,y1,x2,y2 in lines[0]:  
    cv2.line(img,(x1,y1),(x2,y2),(0,255,0),2)

cv2.imshow('Canny', edges)
cv2.imshow('Result', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
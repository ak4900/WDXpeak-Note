# -*- coding: utf-8 -*-
import cv2
import numpy

# 计算并显示直方图
# 与C++中一样，在Python中调用的OpenCV直方图计算函数为cv2.calcHist。
# cv2.calcHist的原型为：
# cv2.calcHist(images, channels, mask, histSize, ranges[, hist[, accumulate ]]) #返回hist

"""
通过一个例子来了解其中的各个参数：
#coding=utf-8
import cv2
import numpy as np

image = cv2.imread("D:/histTest.jpg", 0)
hist = cv2.calcHist([image],
    [0], #使用的通道
    None, #没有使用mask
    [256], #HistSize
    [0.0,255.0]) #直方图柱的范围
其中第一个参数必须用方括号括起来。
第二个参数是用于计算直方图的通道，这里使用灰度图计算直方图，所以就直接使用第一个通道；
第三个参数是Mask，这里没有使用，所以用None。
第四个参数是histSize，表示这个直方图分成多少份（即多少个直方柱）。第二个例子将绘出直方图，到时候会清楚一点。
第五个参数是表示直方图中各个像素的值，[0.0, 256.0]表示直方图能表示像素值从0.0到256的像素。
最后是两个可选参数，由于直方图作为函数结果返回了，所以第六个hist就没有意义了（待确定）
最后一个accumulate是一个布尔值，用来表示直方图是否叠加。
"""

# 彩色图像不同通道的直方图

def calcAndDrawHist(image, color):
	hist = cv2.calcHist([image], [0], None, [256], [0.0, 255.0])
	minVal, maxVal, minLoc, maxLoc = cv2.minMaxLoc(hist)
	histImg = numpy.zeros([256, 256, 3], numpy.uint8)
	hpt = int(0.9 * 256)

	for h in range(256):
		intensity = int(hist[h] * hpt / maxVal)
		cv2.line(histImg, (h, 256), (h, 256 - intensity), color)

	return histImg

if __name__ == '__main__':
	img = cv2.imread("pics/face1.jpg")
	b, g, r = cv2.split(img)

	histImgB = calcAndDrawHist(b, [255, 0, 0])
	histImgG = calcAndDrawHist(g, [0, 255, 0])
	histImgR = calcAndDrawHist(r, [0, 0, 255])

	cv2.imshow("histImgB", histImgB)
	cv2.imshow("histImgG", histImgG)
	cv2.imshow("histImgR", histImgR)
	cv2.imshow("Img", img)
	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

	# 均衡化只能均衡灰度
	img = cv2.imread("pics/face1.jpg",0)
	result = cv2.equalizeHist(img)

	cv2.imshow("Result", result)
	cv2.imshow("Gray", gray)

	cv2.waitKey(0)
	cv2.destroyAllWindows()

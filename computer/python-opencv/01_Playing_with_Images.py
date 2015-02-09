# -*- coding: utf-8 -*-
# 导入OpenCV包
import cv2
import numpy

# 读取并显示图像
# 在Python中不需要声明变量，所以也就不需要C++中的cv::Mat xxxxx了。只需这样:
img = cv2.imread("pics/face.png")
# OpenCV目前支持读取bmp、jpg、png、tiff等常用格式。更详细的请参考OpenCV的参考文档。

# 接着创建一个窗口,然后在窗口中显示图像
cv2.namedWindow("Image")
cv2.imshow("Image", img)

# 保存图像
# 保存图像很简单，直接用cv2.imwrite即可。
# cv2.imwrite("D:\\cat2.jpg", img)
# 第一个参数是保存的路径及文件名，第二个是图像矩阵。其中，imwrite()有个可选的第三个参数，如下：
# cv2.imwrite("D:\\cat2.jpg", img，[int(cv2.IMWRITE_JPEG_QUALITY), 5])
# 第三个参数针对特定的格式： 对于JPEG，其表示的是图像的质量，用0-100的整数表示，默认为95。 
# 注意，cv2.IMWRITE_JPEG_QUALITY类型为Long，必须转换成int。
# 对于PNG，第三个参数表示的是压缩级别。cv2.IMWRITE_PNG_COMPRESSION，
# 从0到9,压缩级别越高，图像尺寸越小。默认级别为3
emptyImage = numpy.zeros(img.shape, numpy.uint8)

emptyImage2 = img.copy()

emptyImage3 = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

cv2.imshow("EmptyImage", emptyImage)  
cv2.imshow("Image", img)  
cv2.imshow("EmptyImage2", emptyImage2)  
cv2.imshow("EmptyImage3", emptyImage3)  
cv2.imwrite("pics/face.jpg", img, [int(cv2.IMWRITE_JPEG_QUALITY), 5])  
cv2.imwrite("pics/face1.jpg", img, [int(cv2.IMWRITE_JPEG_QUALITY), 100])  
cv2.imwrite("pics/face1.png", img, [int(cv2.IMWRITE_PNG_COMPRESSION), 0])  
cv2.imwrite("pics/face2.png", img, [int(cv2.IMWRITE_PNG_COMPRESSION), 9]) 


# 最后还要添上一句：
cv2.waitKey(0)

# 如果不添最后一句，在IDLE中执行窗口直接无响应。在命令行中执行的话，则是一闪而过。
# 最后释放窗口是个好习惯！
cv2.destroyAllWindows()


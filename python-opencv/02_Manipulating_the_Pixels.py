# -*- coding: utf-8 -*-
import cv2
import numpy

# 像素的访问和访问numpy中ndarray的方法完全一样，灰度图为：
# img[j,i] = 255 
# 其中j，i分别表示图像的行和列。对于BGR图像，为：
# img[j,i,0]= 255  
# img[j,i,1]= 255  
# img[j,i,2]= 255 
# 第三个数表示通道。

# void salt(cv::Mat &image, int n)
def salt(img, n):
	for k in range(n):
		# int i = rand() % image.cols;
		i = int(numpy.random.random() * img.shape[1])
		# int j = rand() % image.rows;
		j = int(numpy.random.random() * img.shape[0])

		""" C++ Code
        if (image.channels() == 1) // gray-level image
        {
        	image.at<uchar>(j,i) = 255;
        }
        else if (image.channels() == 3)
        {
        	image.at<cv::Vec3b>(j,i)[0] = 255;
        	image.at<cv::Vec3b>(j,i)[1] = 255;
        	image.at<cv::Vec3b>(j,i)[2] = 255;
        }
        """

		if img.ndim == 2:   
			img[j,i] = 255
		elif img.ndim == 3:
			img[j,i,0]= 255
			img[j,i,1]= 255
			img[j,i,2]= 255
	return img

	"""
    上面的代码需要注意几点：
	1、与C++不同，在Python中灰度图的img.ndim = 2，而C++中灰度图图像的通道数img.channel() =1
	2、为什么使用np.random.random()？
		这里使用了numpy的随机数，Python自身也有一个随机数生成函数。
		这里只是一种习惯，np.random模块中拥有更多的方法，而Python自带的random只是一个轻量级的模块。
		不过需要注意的是np.random.seed()不是线程安全的，而Python自带的random.seed()是线程安全的。
		如果使用随机数时需要用到多线程，建议使用Python自带的random()和random.seed()，
		或者构建一个本地的np.random.Random类的实例。
    """

# 分离、合并通道
# 由于OpenCV Python和NumPy结合的很紧，所以即可以使用OpenCV自带的split函数，也可以直接操作numpy数组来分离通道。
# 直接法为:
# img = cv2.imread("D:/cat.jpg")
# b, g, r = cv2.split(img)
# 其中split返回RGB三个通道，如果只想返回其中一个通道，可以这样：
# b = cv2.split(img)[0]  
# g = cv2.split(img)[1]  
# r = cv2.split(img)[2]

# 通道合并
# 同样，通道合并也有两种方法。第一种是OpenCV自带的merge函数，如下：
# merged = cv2.merge([b,g,r]) #前面分离出来的三个通道
# 接着是NumPy的方法：
# mergedByNp = np.dstack([b,g,r]) 



if __name__ == '__main__':  
    img = cv2.imread("pics/face1.jpg")
    b, g, r = cv2.split(img)
    cv2.imshow("Blue",r)
    cv2.imshow("Red",b)
    cv2.imshow("Green",g)
    merged = cv2.merge([b,g,r])
    cv2.imshow("Merge", merged)
    saltImage = salt(img, 500)  
    cv2.imshow("Salt", saltImage)  
    cv2.waitKey(0)  
    cv2.destroyAllWindows()
    """ C++ Code
	cv::Mat image = cv::imread("pics/face.png");
	salt(image, 3000);
	cv::nameWindow("Image");
	cv::imshow("Image", image);
	"""

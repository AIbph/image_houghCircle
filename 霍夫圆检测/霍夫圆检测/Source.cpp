#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
	// 霍夫圆检测

	// 读取图像
	Mat src = imread("D:/OpenCVProject/day1218/霍夫圆检测/霍夫圆检测/test.jpg");
	if (!src.data)
	{
		printf("could not load image......");
	}
	imshow("origin iamge", src);

	// 中值滤波，转灰度图
	Mat m_img, gray_img;
	medianBlur(src, m_img, 3);
	cvtColor(m_img, gray_img, CV_BGR2GRAY);
	imshow("gray image", gray_img);

	// 霍夫圆检测
	/*		
		HoughCircles();
		src_gray: 输入图像 (灰度图)
		circles: 存储下面三个参数: x_{c}, y_{c}, r 集合的容器来表示每个检测到的圆.
		CV_HOUGH_GRADIENT: 指定检测方法. 现在OpenCV中只有霍夫梯度法
		dp = 1: 累加器图像的反比分辨率
		min_dist = src_gray.rows/8: 检测到圆心之间的最小距离
		param_1 = 200: Canny边缘函数的高阈值
		param_2 = 100: 圆心检测阈值.
		min_radius = 0: 能检测到的最小圆半径, 默认为0.
		max_radius = 0: 能检测到的最大圆半径, 默认为0
	*/
	Mat dst;
	vector<Vec3f>pcircles;
	HoughCircles(gray_img, pcircles, CV_HOUGH_GRADIENT, 1, 40, 150, 30, 35, 40);
	src.copyTo(dst);
	for (int i = 0; i < pcircles.size(); i++)
	{
		Vec3f cc = pcircles[i];
		circle(dst, Point(cc[0], cc[1]), cc[2], Scalar(0, 255, 255), 2, LINE_AA);
		circle(dst, Point(cc[0], cc[1]), 2, Scalar(255, 0, 255), 2, LINE_AA);
	}

	// 展示最终图像效果
	imshow("final image", dst);

	waitKey(0);
	return 0;
}
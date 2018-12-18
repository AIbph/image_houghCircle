#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
	// ����Բ���

	// ��ȡͼ��
	Mat src = imread("D:/OpenCVProject/day1218/����Բ���/����Բ���/test.jpg");
	if (!src.data)
	{
		printf("could not load image......");
	}
	imshow("origin iamge", src);

	// ��ֵ�˲���ת�Ҷ�ͼ
	Mat m_img, gray_img;
	medianBlur(src, m_img, 3);
	cvtColor(m_img, gray_img, CV_BGR2GRAY);
	imshow("gray image", gray_img);

	// ����Բ���
	/*		
		HoughCircles();
		src_gray: ����ͼ�� (�Ҷ�ͼ)
		circles: �洢������������: x_{c}, y_{c}, r ���ϵ���������ʾÿ����⵽��Բ.
		CV_HOUGH_GRADIENT: ָ����ⷽ��. ����OpenCV��ֻ�л����ݶȷ�
		dp = 1: �ۼ���ͼ��ķ��ȷֱ���
		min_dist = src_gray.rows/8: ��⵽Բ��֮�����С����
		param_1 = 200: Canny��Ե�����ĸ���ֵ
		param_2 = 100: Բ�ļ����ֵ.
		min_radius = 0: �ܼ�⵽����СԲ�뾶, Ĭ��Ϊ0.
		max_radius = 0: �ܼ�⵽�����Բ�뾶, Ĭ��Ϊ0
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

	// չʾ����ͼ��Ч��
	imshow("final image", dst);

	waitKey(0);
	return 0;
}
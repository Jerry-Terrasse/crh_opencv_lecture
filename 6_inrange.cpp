#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img = cv::imread("../imgs/dont_forget.jpg"); // 从文件读取图片到内存
	if(img.empty()) // 判断图片是否读取成功
	{
		std::cerr << "读取图片失败！" << std::endl;
		return -1;
	}

	cv::Mat mask; // 用于存储inrange操作得到的掩模
	cv::inRange(img, cv::Scalar(0, 0, 0), cv::Scalar(110, 45, 140), mask); // 三通道inrange操作，当像素值的三个bgr分量都在指定范围内时，掩模对应位置为255，否则为0
	// 随便给的一个范围，效果不好，可以自己调整

	cv::imshow("mask", mask); // 显示掩模
	cv::waitKey(0); // 等待按键

	// 换成灰度图再inrange试试
	cv::Mat gray; // 用于存储转换后的图片
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY); // 转换为灰度图
	cv::inRange(gray, 19, 114, mask); // 单通道inrange操作，当像素值在指定范围内时，掩模对应位置为255，否则为0
	// 随便给的一个范围，可以看到效果好一些，不过噪点很多，可以自己调整

	cv::imshow("mask", mask); // 显示掩模
	cv::waitKey(0); // 等待按键
}
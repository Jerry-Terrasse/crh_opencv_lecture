#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img = cv::imread("../imgs/lena.jpg"); // 从文件读取图片到内存
	if(img.empty()) // 判断图片是否读取成功
	{
		std::cerr << "读取图片失败！" << std::endl;
		return -1;
	}

	cv::Mat converted; // 用于存储转换后的图片
	cv::cvtColor(img, converted, cv::COLOR_BGR2GRAY); // 转换为灰度图

	cv::imshow("converted", converted); // 显示转换后的图片
	cv::waitKey(0); // 等待按键
}
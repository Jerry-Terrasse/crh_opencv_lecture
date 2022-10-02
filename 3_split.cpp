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

	cv::imshow("original", img); // 显示原始图片
	cv::waitKey(0); // 等待按键

	std::vector<cv::Mat> channels; // 定义一个Mat类型的vector，用于存放三个图像通道
	cv::split(img, channels); // 将图像分割成三个通道
	
	cv::imshow("B", channels[0]); // 显示蓝色通道
	cv::imshow("G", channels[1]); // 显示绿色通道
	cv::imshow("R", channels[2]); // 显示红色通道
	cv::waitKey(0); // 同时显示三个通道，等待按键

	cv::Mat merged; // 定义一个Mat类型的变量，用于存放合并后的图像
	cv::merge(channels, merged); // 将三个通道合并成一个图像

	cv::imshow("merged", merged); // 显示合并而来的图片，理论上和原始图片一样
	cv::waitKey(0); // 等待按键
}
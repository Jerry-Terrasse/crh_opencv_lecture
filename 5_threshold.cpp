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

	cv::imshow("original", img); // 显示原图片

	// 要用threshold需要先转换成灰度图
	cv::Mat gray; // 用于存储转换后的图片
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY); // 转换为灰度图

	cv::Mat mask; // 用于存储threshold操作得到的掩模
	cv::threshold(gray, mask, 114, 255, cv::THRESH_BINARY); // 二值化，当像素值大于114时，对应位置为纯白(255)，否则为纯黑(0)
	// 随便给的一个范围，可以看到噪点很多，可以自己调整
	cv::imshow("mask", mask); // 显示掩模
	cv::waitKey(0); // 等待按键

	cv::threshold(gray, mask, 114, 255, cv::THRESH_BINARY_INV); // 这一次反过来，当像素值大于114时，对应位置为纯黑，否则为纯白
	cv::imshow("mask", mask); // 显示掩模（在同一个窗口上显示）
	cv::waitKey(0); // 等待按键
}
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img = cv::imread("../imgs/lena_noise.jpg"); // 从文件读取图片到内存
	if(img.empty()) // 判断图片是否读取成功
	{
		std::cerr << "读取图片失败！" << std::endl;
		return -1;
	}

	cv::imshow("original", img); // 显示原图

	cv::Mat blured; // 用于存储模糊后的图片
	cv::GaussianBlur(img, blured, cv::Size(5, 5), 3); // 高斯滤波，第三个参数为模糊核的大小，第四个参数为标准差，可以自己调整

	// cv::medianBlur(img, blured, 5); // 中值滤波，第三个参数为模糊核的大小，必须为奇数，可以自己调整

	cv::imshow("blured", blured); // 显示灰度图
	cv::waitKey(0); // 等待按键
}
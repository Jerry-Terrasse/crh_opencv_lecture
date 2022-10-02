#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img = cv::imread("../imgs/geometry_with_gap.jpg", cv::IMREAD_GRAYSCALE); // 从文件读取图片到内存，灰度图
	if(img.empty()) // 判断图片是否读取成功
	{
		std::cerr << "读取图片失败！" << std::endl;
		return -1;
	}

	cv::imshow("original", img); // 显示原图

	cv::Mat structure_element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)); // 定义结构元素，矩形，大小为3x3
	cv::Mat result; // 用于存储形态学操作后的图片

	// 闭操作，先膨胀后腐蚀
	cv::dilate(img, result, structure_element); // 膨胀
	cv::erode(result, result, structure_element); // 腐蚀

	cv::imshow("result", result); // 显示灰度图
	cv::waitKey(0); // 等待按键
}
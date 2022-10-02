#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img = cv::imread("../imgs/dont_forget.jpg"); // 从文件读取图片到内存
	if(img.empty()) // 判断图片是否读取成功
	{
		std::cerr << "读取图片失败！" << std::endl;
		return -1;
	}

	std::cout << "Channels: " << img.channels() << std::endl; // 图像通道数
	std::cout << "Depth: " << img.depth() << std::endl; // 图像深度
	std::cout << (img.depth()==CV_8U ? "It is " : "It is not ") << "CV_8U" << std::endl; // 判断图像深度是否为CV_8U
	std::cout << "Empty: " << img.empty() << std::endl; // 图像是否为空
	std::cout << "Width: " << img.cols << "  " << "Height: " << img.rows << std::endl; // 图像宽度
	// 注意：cols和rows的顺序是反的，cols是宽度，rows是高度
	std::cout << "Size: " << img.size() << std::endl; // 图片的尺寸，返回的是cv::Size类型

	cv::imshow("img", img); // 显示图片
	cv::waitKey(0); // 等待按键
}
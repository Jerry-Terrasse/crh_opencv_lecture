#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img = cv::imread("../imgs/lena.jpg"); // 从文件读取图片到内存
	if(img.empty()) {// 判断图片是否读取成功
		std::cerr << "读取图片失败！" << std::endl;
		return -1;
	}

	/* 可以对图像进行任意的处理 */

	cv::imshow("img", img); // 显示图片
	cv::waitKey(0); // 等待按键

	bool res = cv::imwrite("../my_image.png", img); // 将图片写入文件
	if(res) {
		std::cout << "写入图片成功" << std::endl;
		return -1;
	} else {
		std::cerr << "写入图片失败！" << std::endl;
		return -1;
	}
}
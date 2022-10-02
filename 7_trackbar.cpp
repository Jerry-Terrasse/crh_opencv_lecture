#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	cv::Mat img = cv::imread("../imgs/dont_forget.jpg"); // 从文件读取图片到内存
	if(img.empty()) // 判断图片是否读取成功
	{
		std::cerr << "读取图片失败！" << std::endl;
		return -1;
	}

	// 要用threshold需要先转换成灰度图
	cv::Mat gray; // 用于存储转换后的图片
	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY); // 转换为灰度图
	cv::imshow("show", gray); // 显示灰度图

	cv::createTrackbar("threshold", "show", nullptr, 255, [](int pos, void *gray_ptr) { // 定义回调函数
		cv::Mat &gray = *(cv::Mat *)gray_ptr; // 解引用得到Mat
		cv::Mat mask; // 用于存储threshold操作得到的掩模
		cv::threshold(gray, mask, pos, 255, cv::THRESH_BINARY); // 二值化，当像素值大于pos时，对应位置为纯白(255)，否则为纯黑(0)
		cv::imshow("show", mask); // 显示掩模
		std::cout << mask.channels() << std::endl;
	}, &gray); // 创建一个滑动条，滑动条的名字为threshold，滑动条的范围为0-255，滑动条的回调函数为上面定义的lambda表达式，回调函数的第一个参数为滑动条的位置，回调函数的第二个参数为传递给回调函数的参数，这里传递的是灰度图的地址

	cv::waitKey(0); // 等待按键
}
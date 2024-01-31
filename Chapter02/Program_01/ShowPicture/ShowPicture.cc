#include <opencv2/opencv.hpp>

constexpr auto WINDOW_NAME = "Example1";

int main(int argc, char* argv[]) {
	cv::Mat img = cv::imread(argv[1], cv::IMREAD_UNCHANGED);
	if (img.empty()) return -1;

	cv::namedWindow(WINDOW_NAME, cv::WINDOW_AUTOSIZE);
	cv::imshow(WINDOW_NAME, img);
	cv::waitKey(0);
	cv::destroyWindow(WINDOW_NAME);
	return 0;
}
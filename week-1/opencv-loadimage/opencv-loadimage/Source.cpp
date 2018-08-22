#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty())
		return -1;
	cv::namedWindow("Window1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Window1", img);
	cv::waitKey(0);
	cv::destroyWindow("Window1");
}
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
	cv::Mat imgA = cv::imread(argv[1], 0);
	cv::Mat imgB = cv::imread(argv[2], 0);

	cv::namedWindow("Image1", CV_WINDOW_AUTOSIZE);
	cv::imshow("Image1", imgA);

	if (imgA.empty()) {
		return -1;
	}

	cv::namedWindow("Image2", CV_WINDOW_AUTOSIZE);
	cv::imshow("Image2", imgB);

	if (imgB.empty()) {
		return -1;
	}

	cv::Mat imgDiff;

	cv::absdiff(imgA, imgB, imgDiff);

	cv::namedWindow("ImageDiff", CV_WINDOW_AUTOSIZE);
	cv::imshow("ImageDiff", imgDiff);

	cv::waitKey(0);
}
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty()) {
		printf("Image not found!");
		cv::waitKey(0);
		return -1;
	}

	cv::namedWindow("Window1", CV_WINDOW_AUTOSIZE);
	cv::imshow("Window1", img);

	cv::Mat colorPlane[3];
	split(img, colorPlane);

	cv::namedWindow("Red", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("Green", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("Blue", CV_WINDOW_AUTOSIZE);

	cv::imshow("Red", colorPlane[0]);
	cv::imshow("Green", colorPlane[1]);
	cv::imshow("Blue", colorPlane[2]);

	cv::waitKey(0);

	cv::destroyAllWindows();
}
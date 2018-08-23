#include <opencv2/opencv.hpp>

int main(int argc,char** argv) {
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty()) {
		printf("Image not found!");
		cv::waitKey(0);
	}

	cv::namedWindow("Window1", CV_WINDOW_AUTOSIZE);
	cv::imshow("Window1", img);

	printf("Image Data:\nHeight: %d\nWidth: %d", img.rows, img.cols);
	
	//Cropping using cv::Rect
	cv::Rect roi;
	roi.x = 100;
	roi.y = 100;
	roi.width = 200;
	roi.height = 200;

	cv::Mat sliceImg = img(roi);

	cv::namedWindow("Window2", CV_WINDOW_AUTOSIZE);
	cv::imshow("Window2", sliceImg);

	//Cropping using two cv::Range
	cv::namedWindow("Window3", CV_WINDOW_AUTOSIZE);
	cv::imshow("Window3", img(cv::Range(50,350), cv::Range(50,350)));

	cv::waitKey(0);
	cv::destroyAllWindows();
}
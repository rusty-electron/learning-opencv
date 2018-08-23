#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
	cv::Mat img1 = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	if (img1.empty()) {
		printf("Image 1 not found!");
		cv::waitKey(0);
	    return -1;
	}

	cv::Mat img2 = cv::imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
	if (img2.empty()) {
		printf("Image 2 not found!");
		cv::waitKey(0);
		return -1;
	}

	cv::namedWindow("Image1", CV_WINDOW_AUTOSIZE);
	cv::imshow("Image1", img1);

	cv::namedWindow("Image2", CV_WINDOW_AUTOSIZE);
	cv::imshow("Image2", img2);
	
	cv::Mat sum;
	cv::add(img1, img2, sum);

	cv::namedWindow("Result", CV_WINDOW_AUTOSIZE);
	cv::imshow("Result", sum);

	cv::waitKey(0);
	cv::destroyAllWindows();
}
#include <opencv2/opencv.hpp>
void imgSubtract(cv::Mat a, cv::Mat b, cv::Mat& c) {

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			c.at<uchar>(i, j) = cv::saturate_cast<uchar>(a.at<uchar>(i, j) - b.at<uchar>(i, j));
		}
	}
}

void imgSubtractPreserve(cv::Mat a, cv::Mat b, cv::Mat& c) {

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			c.at<uchar>(i, j) = cv::saturate_cast<uchar>(a.at<uchar>(i, j) - b.at<uchar>(i, j))
				+ cv::saturate_cast<uchar>(b.at<uchar>(i,j) - a.at<uchar>(i,j));
		}
	}
}

int main(int argc, char** argv) {
	cv::Mat imgA = cv::imread(argv[1], 0);
	cv::Mat imgB = cv::imread(argv[2], 0);

	if (imgA.empty()) {
		return -1;
	}

	if (imgB.empty()) {
		return -1;
	}

	cv::Mat imgDiff= cv::Mat::zeros(imgA.size(), imgA.type());
	imgSubtract(imgA,imgB,imgDiff);

	cv::namedWindow("A - B", CV_WINDOW_AUTOSIZE);
	cv::imshow("A - B", imgDiff);

	imgSubtract(imgB, imgA, imgDiff);

	cv::namedWindow("B - A", CV_WINDOW_AUTOSIZE);
	cv::imshow("B - A", imgDiff);

	imgSubtractPreserve(imgB, imgA, imgDiff);

	cv::namedWindow("Abs", CV_WINDOW_AUTOSIZE);
	cv::imshow("Abs", imgDiff);

	cv::waitKey(0);
	cv::destroyAllWindows();
	
}
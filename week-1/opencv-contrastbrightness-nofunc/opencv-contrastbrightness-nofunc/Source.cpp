#include <opencv2/opencv.hpp>

cv::Mat img;
cv::Mat previewImg;
int beta;
int alpha;

//Syntax: image.convertTo(new_image, -1, alpha, beta);
void onContrastTrackbar(int, void*) {
	
	//
	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			for (int c = 0; c < 3; c++) {
				previewImg.at<cv::Vec3b>(x, y)[c] = cv::saturate_cast<uchar>(((alpha / 50.0)*img.at<cv::Vec3b>(x, y)[c]) + (beta - 50));
			}
		}
	}
	//
	cv::imshow("Adjust", previewImg);
}

void onBrightTrackbar(int, void*) {
	//
	for (int x = 0; x < previewImg.rows; x++) {
		for (int y = 0; y < previewImg.cols; y++) {
			for (int c = 0; c < 3; c++) {
				previewImg.at<cv::Vec3b>(x, y)[c] = 
					cv::saturate_cast<uchar>(((alpha / 50.0)*img.at<cv::Vec3b>(x, y)[c]) + (beta - 50));
			}
		}
	}
	//
	cv::imshow("Adjust", previewImg);
}

int main(int argc, char** argv) {
	alpha = 50;
	beta = 50;

	img = cv::imread(argv[1]);
	previewImg = cv::Mat::zeros(img.size(), img.type());

	if (img.empty()) {
		std::cout << "Image not found!" << std::endl;
		std::cin.get();
		return -1;
	}

	cv::namedWindow("Original", CV_WINDOW_AUTOSIZE);
	cv::imshow("Original", img);

	cv::namedWindow("Adjust", CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("Contrast", "Adjust", &alpha, 100, onContrastTrackbar);
	onContrastTrackbar(alpha, 0);

	cv::createTrackbar("Brightness", "Adjust", &beta, 100, onBrightTrackbar);
	onBrightTrackbar(beta, 0);

	cv::waitKey(0);
	cv::destroyAllWindows();
}
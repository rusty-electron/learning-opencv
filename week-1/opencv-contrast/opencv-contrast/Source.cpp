#include <opencv2/opencv.hpp>
cv::Mat img;
cv::Mat previewImg;
int beta;
int alpha;

//Syntax: image.convertTo(new_image, -1, alpha, beta);
void onContrastTrackbar(int, void*) {
	img.convertTo(previewImg, -1, alpha/50.0, beta - 50);
	cv::imshow("Adjust", previewImg);
}

void onBrightTrackbar(int, void*) {
	img.convertTo(previewImg, -1, alpha / 50.0, beta - 50);
	cv::imshow("Adjust", previewImg);
}

int main(int argc, char** argv) {
	alpha = 50;
	beta = 50;

	img = cv::imread(argv[1], 1);
	
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
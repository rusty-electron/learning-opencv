#include <opencv2/opencv.hpp>
double alpha, beta;
int alphaSlider;
cv::Mat img1;
cv::Mat img2;
cv::Mat sum;

void onTrackbar(int, void*) {
	alpha = (double)alphaSlider / 100;
	beta = 1.0 - alpha;
	cv::addWeighted(img1, alpha, img2, beta, 0.0, sum);
	cv::imshow("Alpha Blending", sum);
}

int main(int argc, char** argv) {
	alphaSlider = 50;

	img1 = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	if (img1.empty()) {
		printf("Image 1 not found!");
		cv::waitKey(0);
		return -1;
	}

	img2 = cv::imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
	if (img2.empty()) {
		printf("Image 2 not found!");
		cv::waitKey(0);
		return -1;
	}

	cv::namedWindow("Alpha Blending", CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("Blend:", "Alpha Blending", &alphaSlider, 100, onTrackbar);
	onTrackbar(alphaSlider, 0);

	cv::waitKey(0);
	cv::destroyAllWindows();
}
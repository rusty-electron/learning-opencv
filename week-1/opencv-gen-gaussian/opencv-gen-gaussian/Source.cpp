#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {

	cv::Mat img = cv::imread(argv[1], 0);
	if (img.empty()) {
		std::cout << "Image not found!" << std::endl;
		cv::waitKey(0);
		return -1;
	}
	//Convert the Image range of (0, 255) to (0,1.0)
	normalize(img, img, 0.0, 1.0, CV_MINMAX, CV_64F);
	cv::Mat noise = cv::Mat(512, 512, CV_64F);

	cv::namedWindow("NoiseA", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("NoiseB", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("NoiseC", CV_WINDOW_AUTOSIZE);

	//Noise A
	cv::Mat tmp = img.clone();
	cv::randn(noise, 0, 0.1);
	tmp += noise;
	normalize(tmp, tmp, 0.0, 1.0, CV_MINMAX, CV_64F);
	cv::imshow("NoiseA", tmp);

	//Noise B
	tmp = img.clone();
	cv::randn(noise, 0, 0.15);
	tmp += noise;
	normalize(tmp, tmp, 0.0, 1.0, CV_MINMAX, CV_64F);
	cv::imshow("NoiseB", tmp);

	//Noise C
	tmp = img.clone();
	cv::randn(noise, 0, 0.25);
	tmp += noise;
	normalize(tmp, tmp, 0.0, 1.0, CV_MINMAX, CV_64F);
	cv::imshow("NoiseC", tmp);

	cv::waitKey(0);
	cv::destroyAllWindows();
}
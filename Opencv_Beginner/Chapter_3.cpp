/*

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgcrop;

	resize(img, imgResize, Size(), 0.5, 0.5);

	Rect roi(0, 100, 250, 250);
	imgcrop = img(roi);

	imshow("image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgcrop);

	waitKey(0);

}

*/
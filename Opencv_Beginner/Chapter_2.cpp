/*

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgcanny, imgBlur, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	GaussianBlur(img, imgBlur,Size(3, 3), 3, 0);

	Canny(img, imgcanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));

	dilate(imgcanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);




	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image canny", imgcanny);
	imshow("Image Blur", imgBlur);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);

}
*/

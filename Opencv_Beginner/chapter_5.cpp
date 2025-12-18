/*

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  warp Images  //////////////////////

void main() {

	string path = "Resources/Cards.jpg";
	Mat img = imread(path);
	Mat matrix, imgwarp;
	float w = 250, h= 350;

	Point2f src[4] = { {528,144}, {769,190}, {406,392}, {673,456} };
	Point2f dest[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h } };

	matrix = getPerspectiveTransform(src, dest);
	warpPerspective(img, imgwarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, Point(src[i]), 10, Scalar(255, 0, 255), FILLED);
	}
	imshow("Image", img);
	imshow("Image Warp", imgwarp);
	waitKey(0);

}

*/
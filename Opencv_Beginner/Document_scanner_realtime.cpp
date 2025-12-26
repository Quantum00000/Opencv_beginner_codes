/*

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Mat imgGray, imgcanny, imgBlur, imgDil, img;
vector<Point> points;

void preprocessing(Mat img) {

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgcanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgcanny, imgDil, kernel);

	//imshow("Dilimage", imgDil);

}

vector<Point> orderedpoints(vector<Point> points) {
	vector<int> sum, diff;
	vector<Point> ordered(4);
	for (Point p : points) {
		sum.push_back(p.x + p.y);
		diff.push_back(p.x - p.y);
	}
	ordered[0] = points[min_element(sum.begin(), sum.end()) - sum.begin()];// top-left
	ordered[3] = points[max_element(sum.begin(), sum.end()) - sum.begin()];//bottom-right
	ordered[1] = points[min_element(diff.begin(), diff.end()) - diff.begin()]; //top-right
	ordered[2] = points[ max_element(diff.begin(),diff.end()) - diff.begin()];//bottom-left

	// Ensure clockwise order
	if (ordered[1].y > ordered[2].y) {
		swap(ordered[1], ordered[2]);
	}

	return ordered;
}


void wrap(vector<Point> points,Mat img) {
	Mat matrix, imgwarp;
	float w = 250, h = 350;

	//To convert points into Point2f form

		Point2f src[4];
		vector<Point> ordered = orderedpoints(points);
		for (int i = 0; i < ordered.size(); i++) {
			src[i] = ordered[i];
		}

	Point2f dest[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h } };
	matrix = getPerspectiveTransform(src, dest);
	warpPerspective(img, imgwarp, matrix, Point(w, h));
	imshow("Imagewrap", imgwarp);

}


vector<Point> getContours(Mat imgDil) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	vector<Point> biggest;
	int maxarea=0;

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);

		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			if (area > maxarea && conPoly[i].size() == 4) {
				maxarea = area;
				biggest = { conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3] };
				}
			

			drawContours(img, contours, i, Scalar(255, 0, 255), 2);

				//boundRect[i]=boundingRect(contours[i]);
				//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 2);

		}
	}
	

		return biggest;

}

void main() {

	VideoCapture cap(0);


	while (true) {
		cap.read(img);
		flip(img, img, 1); // horizontal flip
		//resize(img, img, Size(), 0.5, 0.5);
		preprocessing(img);
		points = getContours(imgDil);
		if (points.size() == 4) {
			wrap(points, img);
		}
		imshow("Image", img);
		waitKey(1);
	}
	

}

*/



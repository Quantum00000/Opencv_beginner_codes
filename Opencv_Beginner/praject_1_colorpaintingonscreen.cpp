/*

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
vector<vector<int>> newpoints;

//mycolor store the hsv color range
vector<vector<int>> mycolor{
	{152,179,97,255,62,255},
	{27,82,57,241,16,111}
};

//newcolor store the bgr color
vector<Scalar> mycolorvalues{
	{255,0,255},
	{255,255,0}
};


//function to get the contour and draw bounding box
Point getContours(Mat imgDil) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	Point mypoint(0, 0);

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);

		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			mypoint.x = boundRect[i].x + boundRect[i].width / 2;
			mypoint.y = boundRect[i].y;

			//drawContours(img, contours, i, Scalar(255, 0, 255), 2);
		
			//boundRect[i]=boundingRect(contours[i]);
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 2);

		}
	}
	return mypoint;

}


//function to find the color
vector<vector<int>> findcolor(Mat img) {

	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < mycolor.size(); i++) {

		Scalar lower(mycolor[i][0], mycolor[i][2], mycolor[i][4]);
		Scalar upper(mycolor[i][1], mycolor[i][3], mycolor[i][5]);
		Mat  mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		Point mypoint = getContours(mask);

		if (mypoint.x != 0 && mypoint.y != 0) {
			newpoints.push_back({ mypoint.x,mypoint.y,i });
		}
	}

	return newpoints;

}

void drawoncanvas(vector<vector<int>> newpoints, vector<Scalar> mycolorvalues) {

	for (int i = 0; i < newpoints.size(); i++) {

		circle(img,Point(newpoints[i][0],newpoints[i][1]),10,mycolorvalues[newpoints[i][2]],FILLED);
	}
}

void main() {

	VideoCapture cap(0);
	

	while (true) {
		cap.read(img);

		newpoints=findcolor(img);
		drawoncanvas(newpoints, mycolorvalues);

		imshow("Image", img);
		waitKey(1);
	}
}

*/




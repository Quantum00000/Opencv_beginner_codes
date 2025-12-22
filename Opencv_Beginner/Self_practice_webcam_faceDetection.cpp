/*

////////////////////////// webcam Face Detection //////////////////////////

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {

	VideoCapture cap(1);
	Mat img,gray;

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) {
		cout << "XML file not loaded" << endl;
	}

	vector<Rect> faces;

	while (true) {

		cap.read(img);

		cvtColor(img, gray, COLOR_BGR2GRAY);
		faceCascade.detectMultiScale(gray, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++) {
			
			rectangle(img, faces[i], Scalar(255, 0, 255), 3);
		}

		imshow("Image", img);
		
		waitKey(1);
	}
}

*/
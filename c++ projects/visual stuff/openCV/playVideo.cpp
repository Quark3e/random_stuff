#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {

	VideoCapture cap("C:/Users/aa82637/Desktop/testVideo.mp4");

	if (cap.isOpened() == false) {
		cout << "Cannot open video file" << endl;
		cin.get();
		return -1;
	}
	
	cap.set(CAP_PROP_POS_MSEC, 300);

	double fps = cap.get(CAP_PROP_FPS);
	cout << "Frames per Second: " << fps << endl;

	String window_name = "This is the title of the video frame, box thingy";

	namedWindow(window_name, WINDOW_NORMAL);

	while (true) {
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cout << "This is the end of the video" << endl;
			break;
		}

		imshow(window_name, frame);

		if (waitKey(10) == 27) {
			cout << "The esc key thingy-majig has been pressed" << endl;
			break;
		}
	}

	return 0;
}
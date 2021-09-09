
#include "C:/OpenCV_folder/opencv/sources/include/opencv2/opencv.hpp"

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// Read the image file
	Mat image = imread("C:/Users/aa82637/Desktop/dabbing astronaut.jpg");
	//1280x720

	if (image.empty()) // Check for failure
	{
		cout << "Could not open or find the image" << endl;
		system("pause"); //wait for any key press
		return -1;
	}

	String windowName = "My HelloWorld Window"; //Name of the window

	//namedWindow(windowName); // Create a window
	//imshow(windowName, image); // Show our image inside the created window.

	int down_width = 400;
	int down_height = 224;
	Mat resized_down;
	resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);

	//int up_width = 600;
	//int up_height = 400;
	//Mat resized_up;
	//resize(image, resized_up, Size(up_width, up_height), INTER_LINEAR);

	imshow("Resized Down by defining height and width", resized_down);
	waitKey();
	//imshow("Resized Up image by defining height and width", resized_up);

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); //destroy the created window
	return 0;
}
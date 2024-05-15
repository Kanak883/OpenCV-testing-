#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    VideoCapture cap(0); 

    if (!cap.isOpened()) {
        cout << "Failed to open the camera." << endl;
        return -1; 
    }

    namedWindow("Camera Feed", WINDOW_NORMAL); 

    while (true) {
        Mat frame;
        cap.read(frame); 

        if (frame.empty()) {
            cout << "Failed to grab a frame." << endl;
            break; 
        }

        imshow("Camera Feed", frame); 

        char c = waitKey(30); 
        if (c == 27) { 
            cout << "Exiting..." << endl;
            break; 
        }
    }

    cap.release(); // Release the camera resource
    destroyAllWindows(); // Close all windows

    return 0;
}

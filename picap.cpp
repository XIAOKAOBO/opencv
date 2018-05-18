#include <iostream>
#include<opencv2/opencv.hpp>
#include <raspicam/raspicam_cv.h>


int main(int argc, char** argv)
{

        Mat image, output;
        //VideoCapture cap(CV_CAP_ANY);
    raspicam::RaspiCam_Cv cap;

        if( !cap.isOpened() )
        {
            cout << "Could not initialize capturing...\n";
            return 0;
        }

        while(1){
            cap.grab();
            cap.retrieve(output);

            imshow("webcam input", output);
            char c = (char)waitKey(10);
        if( c == 27 ) break;
        }
}
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <opencv2/opencv.hpp>

// Declare the matrices as extern to allow for initialization in a .cpp file
extern const cv::Mat P0;
extern const cv::Mat P1;

extern cv::Mat K0, R0, t0;
extern cv::Mat K1, R1, t1;

// Declare a function to initialize the above matrices
void initializeCalibrationConstants();

#endif // CONSTANTS_H
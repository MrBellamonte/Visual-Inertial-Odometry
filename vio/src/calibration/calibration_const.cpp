#include "calibration_const.h"
#include <iostream>


const cv::Mat P0 = (cv::Mat_<double>(3, 4) << 
    7.188560000000e+02, 0.000000000000e+00, 6.071928000000e+02, 0.000000000000e+00,
    0.000000000000e+00, 7.188560000000e+02, 1.852157000000e+02, 0.000000000000e+00,
    0.000000000000e+00, 0.000000000000e+00, 1.000000000000e+00, 0.000000000000e+00);

const cv::Mat P1 = (cv::Mat_<double>(3, 4) << 
    7.188560000000e+02, 0.000000000000e+00, 6.071928000000e+02, -3.861448000000e+02,
    0.000000000000e+00, 7.188560000000e+02, 1.852157000000e+02, 0.000000000000e+00,
    0.000000000000e+00, 0.000000000000e+00, 1.000000000000e+00, 0.000000000000e+00);

// const cv::Mat K0, R0, t0;
cv::Mat K0, R0, t0;
cv::Mat K1, R1, t1;


void initializeCalibrationConstants() {
    cv::Mat K, R, t;
    cv::decomposeProjectionMatrix(P0, K, R, t);
    t = t / t.at<double>(3);
    K0 = K.clone();
    R0 = R.clone();
    t0 = t.clone();

    cv::decomposeProjectionMatrix(P1, K, R, t);
    t = t / t.at<double>(3);
    K1 = K.clone();
    R1 = R.clone();
    t1 = t.clone();
    std::cout << "Calibration matrices initialized!  \n" << std::endl;
}
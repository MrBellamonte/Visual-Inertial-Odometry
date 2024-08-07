#include <opencv2/opencv.hpp>
#include <iostream>


#include "calibration/calibration_const.h"
#include "feature_extraction/feature_extraction.h"


int main() {
    initializeCalibrationConstants();

    // Concatenate the base path with the filename provided by the user
    std::string test_image ="/app/feature_extraction/images/P1180213.JPG";

    cv::Mat image;
    image = cv::imread(test_image, cv::IMREAD_GRAYSCALE);

    cv::Mat descriptors;
    std::vector<cv::KeyPoint> keypoints;

    extract_features(image, descriptors, keypoints, 1000, 25000);

    return 0;
}
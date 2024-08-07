#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * Extracts features from the given image.
 *
 * @param image The input image from which features will be extracted.
 * @return void
 */
void extract_features(cv::Mat &image,
                      cv::Mat &descriptors,
                      std::vector<cv::KeyPoint> &keypoints,
                      int num_keypoints_detected,
                      int num_keypoints_detected_to_detect);
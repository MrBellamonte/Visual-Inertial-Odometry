#include <anms.h>
#include <iostream>
#include <numeric> 
#include <opencv2/opencv.hpp>

void extract_features(cv::Mat &image,
                      cv::Mat &descriptors,
                      std::vector<cv::KeyPoint> &keypoints,
                      int num_keypoints_detected,
                      int num_keypoints_detected_to_detect) 
{

    std::vector<cv::KeyPoint> keypoints_detected;
    clock_t t_feature_extraction_start = clock();
    cv::Ptr<cv::ORB> orb = cv::ORB::create(num_keypoints_detected_to_detect);
    orb->detectAndCompute(image, cv::noArray(), keypoints_detected, descriptors);
    clock_t t_feature_extraction =
      double(clock() - t_feature_extraction_start) * 1000 / (double)CLOCKS_PER_SEC;


    clock_t t_ssc_start = clock();
     // Sorting keypoints_detected by deacreasing order of strength
    vector<float> responseVector;
    for (unsigned int i = 0; i < keypoints_detected.size(); i++)
        responseVector.push_back(keypoints_detected[i].response);
    vector<int> Indx(responseVector.size());
    std::iota(std::begin(Indx), std::end(Indx), 0);

    for (unsigned int i = 0; i < keypoints_detected.size(); i++)
        keypoints.push_back(keypoints_detected[Indx[i]]);

    float tolerance = 0.1;
    vector<cv::KeyPoint> sscKP =
      ssc(keypoints, num_keypoints_detected, tolerance, image.cols, image.rows);


    clock_t t_ssc =
      double(clock() - t_ssc_start) * 1000 / (double)CLOCKS_PER_SEC;

    cout << "Features extracted in " << t_feature_extraction << " ms." << endl;
    cout << "Features selected in " << t_ssc << " ms." << endl;
}
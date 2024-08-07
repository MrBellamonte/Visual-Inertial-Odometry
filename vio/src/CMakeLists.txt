# Create a library from the source files
add_library(vio main.cc calibration/calibration_const.cpp feature_extraction/feature_extraction.cpp)

# Include header files from the include directory
target_include_directories(vio PUBLIC ../include)

# add_executable(vio main.cc calibration/calibration_const.cpp feature_extraction/feature_extraction.cpp) # Add other source files as needed
target_link_libraries(vio Ceres::ceres)
target_link_libraries(vio ${OpenCV_LIBS})


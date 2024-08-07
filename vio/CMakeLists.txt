cmake_minimum_required(VERSION 3.5)

# Project name and version
project(VIO VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the installation prefix of "Ceres" to CMAKE_PREFIX_PATH
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/Ceres")

find_package(Ceres REQUIRED)
find_package(OpenCV REQUIRED)

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/src/feature_extraction)
include_directories(${PROJECT_SOURCE_DIR}/src/calibration)

# Include the ANMS_Codes headers
include_directories(/usr/local/include)

add_subdirectory(src)

add_executable(feature_extractor_driver drivers/feature_extractor_driver.cpp)
target_include_directories(feature_extractor_driver PRIVATE include)
target_link_libraries(feature_extractor_driver vio)
# Link against libanms_library.a
target_link_libraries(feature_extractor_driver /usr/local/lib/libanms_library.a)
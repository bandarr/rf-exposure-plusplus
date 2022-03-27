# CMakeList.txt : CMake project for Yarg, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (rf-exposure-plusplus "rf-exposure-plusplus.cpp" "rf-exposure-plusplus.h" "FrequencyValues.cpp" "FrequencyValues.h" "CableValues.cpp" "CableValues.h" "ExposureCalculator.cpp" "ExposureCalculator.h")

# TODO: Add tests and install targets if needed.

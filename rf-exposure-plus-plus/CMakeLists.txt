# CMakeList.txt : CMake project for rf-exposure-plus-plus, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (rf-exposure-plus-plus "rf-exposure-plus-plus.cpp" "rf-exposure-plus-plus.h" "FrequencyValues.h" "FrequencyValues.cpp" "CableLossConstants.h" "CableLossConstants.cpp" "ExposureCalculator.h" "ExposureCalculator.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET rf-exposure-plus-plus PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

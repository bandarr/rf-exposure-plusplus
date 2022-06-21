#include "FrequencyValues.h"
#include <iostream>

using namespace std;
using namespace Exposure;

FrequencyValues::FrequencyValues( float frequency, float swr, float gaindbi ) : frequency( frequency ), swr( swr ), gaindbi( gaindbi ) {}

float Exposure::FrequencyValues::getFrequency()
{
  return frequency;
}

float Exposure::FrequencyValues::getSWR()
{
  return swr;
}

float Exposure::FrequencyValues::getGaindbi()
{
  return gaindbi;
}



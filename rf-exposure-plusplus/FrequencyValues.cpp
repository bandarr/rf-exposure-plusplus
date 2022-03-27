#include "FrequencyValues.h"
#include <iostream>

using namespace std;
using namespace Exposure;

FrequencyValues::FrequencyValues( float frequency, float swr, float gaindbi ) : frequency( frequency ), swr( swr ), gaindbi( gaindbi ) {}

float Exposure::FrequencyValues::GetFrequency()
{
  return frequency;
}

float Exposure::FrequencyValues::GetSWR()
{
  return swr;
}

float Exposure::FrequencyValues::GetGaindbi()
{
  return gaindbi;
}



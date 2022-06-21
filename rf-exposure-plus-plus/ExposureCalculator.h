#pragma once

#include "FrequencyValues.h"
#include "CableLossConstants.h"

namespace Exposure
{
  class ExposureCalculator
  {
  public:
    float calculateUncontrolledSafeDistance( FrequencyValues frequencyValues, CableLossConstants cableLossConstants, int transmitterPower, int feedLineLength, float dutyCycle, float uncontrolledPercentage30Minutes );

  private:
    float calculateReflectionCoefficient( float swr );
    float calculateFeedlineLossForMatchedLoadAtFrequency( int feedLineLength, float feedLineLossPer100ftAtFrequency );
    float calculateFeedlineLossForMatchedLoadAtFrequencyPercentage( float feedLineLossForMatchedLoad );
    float calculateFeedlineLossPer100ftAtFrequency( float frequency, CableLossConstants cableLossConstants );
    float calculateFeedlineLossForSWR( float feedLineLossForMatchedLoadPercentage, float gammaSquared );
    float calculateFeedlineLossForSWRPercentage( float feedLineLossForSwr );

  };
}
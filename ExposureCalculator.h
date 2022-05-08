#pragma once

#include "FrequencyValues.h"
#include "CableLossConstants.h"

namespace Exposure
{
  class ExposureCalculator
  {
  public:
    float CalculateUncontrolledSafeDistance( FrequencyValues freq_values, CableLossConstants cable_values, int transmitter_power, int feedline_length, float duty_cycle, float uncontrolled_percentage_30_minutes );

  private:
    float CalculateReflectionCoefficient( float swr );
    float CalculateFeedlineLossForMatchedLoadAtFrequency( int feedline_length, float feedline_loss_per_100ft_at_frequency );
    float CalculateFeedlineLossForMatchedLoadAtFrequencyPercentage( float feedline_loss_for_matched_load );
    float CalculateFeedlineLossPer100ftAtFrequency( float freq, CableLossConstants cable_values );
    float CalculateFeedlineLossForSWR( float feedline_loss_for_matched_load_percentage, float gamma_squared );
    float CalculateFeedlineLossForSWRPercentage( float feedline_loss_for_swr );

  };
}
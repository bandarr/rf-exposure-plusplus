#include "ExposureCalculator.h"
#include <cmath>

float Exposure::ExposureCalculator::CalculateUncontrolledSafeDistance( FrequencyValues freq_values, CableLossConstants cable_values, int transmitter_power, int feedline_length, float duty_cycle, float uncontrolled_percentage_30_minutes )
{
  float frequency = freq_values.GetFrequency();

  float feedline_loss_per_100ft_at_frequency = CalculateFeedlineLossPer100ftAtFrequency( frequency, cable_values );

  float feedline_loss_for_matched_load_at_frequency = CalculateFeedlineLossForMatchedLoadAtFrequency( feedline_length, feedline_loss_per_100ft_at_frequency );

  float feedline_loss_for_matched_load_at_frequency_percentage = CalculateFeedlineLossForMatchedLoadAtFrequencyPercentage( feedline_loss_for_matched_load_at_frequency );

  float gamma_squared = abs( pow( CalculateReflectionCoefficient( freq_values.GetSWR() ), 2.0f ) );

  float feedline_loss_for_swr_percentage = CalculateFeedlineLossForSWRPercentage( CalculateFeedlineLossForSWR( feedline_loss_for_matched_load_at_frequency_percentage, gamma_squared ) );

  float power_loss_at_swr = feedline_loss_for_swr_percentage * transmitter_power;

  float peak_envelope_power_at_antenna = transmitter_power - power_loss_at_swr;

  float uncontrolled_average_pep = peak_envelope_power_at_antenna * duty_cycle * uncontrolled_percentage_30_minutes;

  float mpe_s = 180.0f / ( pow( frequency, 2.0f ) );

  float gain_decimal = pow( 10.0f, ( freq_values.GetGaindbi() / 10.0f ) );

  return sqrt( ( 0.219f * uncontrolled_average_pep * gain_decimal ) / mpe_s );
}

float Exposure::ExposureCalculator::CalculateReflectionCoefficient( float swr )
{
  return abs( ( swr - 1 ) / ( swr + 1 ) );
}

float Exposure::ExposureCalculator::CalculateFeedlineLossForMatchedLoadAtFrequency( int feedline_length, float feedline_loss_per_100ft_at_frequency )
{
  return ( feedline_length / 100.0f ) * feedline_loss_per_100ft_at_frequency;
}

float Exposure::ExposureCalculator::CalculateFeedlineLossForMatchedLoadAtFrequencyPercentage( float feedline_loss_for_matched_load )
{
  return pow( 10.0f, ( ( feedline_loss_for_matched_load * -1.0f ) / 10.0f ) );
}

float Exposure::ExposureCalculator::CalculateFeedlineLossPer100ftAtFrequency( float frequency, CableLossConstants cable_values )
{
  return cable_values.GetK1() * sqrt( frequency + cable_values.GetK2() * frequency );
}

float Exposure::ExposureCalculator::CalculateFeedlineLossForSWR( float feedline_loss_for_matched_load_percentage, float gamma_squared )
{
  return -10.0f * log10( feedline_loss_for_matched_load_percentage * ( ( 1.0f - gamma_squared ) / ( 1.0f - pow( feedline_loss_for_matched_load_percentage, 2.0f ) * gamma_squared ) ) );
}

float Exposure::ExposureCalculator::CalculateFeedlineLossForSWRPercentage( float feedline_loss_for_swr )
{
  return ( 100.0f - 100.0f / ( pow( 10.0f, ( feedline_loss_for_swr / 10.0f ) ) ) ) / 100.0f;
}



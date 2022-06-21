#include "ExposureCalculator.h"
#include <cmath>

float Exposure::ExposureCalculator::calculateUncontrolledSafeDistance( FrequencyValues frequencyValues, CableLossConstants cableLossConstants, int transmitterPower, int feedLineLength, float dutyCycle, float transmitFactorPer30 )
{
  float frequency = frequencyValues.getFrequency();

  float feedLineLossPer100ftAtFrequency = calculateFeedlineLossPer100ftAtFrequency( frequency, cableLossConstants );

  float feedlineLossForMatchedLoadAtFrequency = calculateFeedlineLossForMatchedLoadAtFrequency( feedLineLength, feedLineLossPer100ftAtFrequency );

  float feedLineLossForMatchedLoadAtFrequencyPercentage = calculateFeedlineLossForMatchedLoadAtFrequencyPercentage( feedlineLossForMatchedLoadAtFrequency );

  float gammaSquared = abs( pow( calculateReflectionCoefficient( frequencyValues.getSWR() ), 2.0f ) );

  float feedlineLossForSwrPercentage = calculateFeedlineLossForSWRPercentage( calculateFeedlineLossForSWR( feedLineLossForMatchedLoadAtFrequencyPercentage, gammaSquared ) );

  float powerLossAtSwr = feedlineLossForSwrPercentage * transmitterPower;

  float peakEnvelopePowerAtAntenna = transmitterPower - powerLossAtSwr;

  float uncontrolledAveragePep = peakEnvelopePowerAtAntenna * dutyCycle * transmitFactorPer30;

  float mpeS = 180.0f / ( pow( frequency, 2.0f ) );

  float gainDecimal = pow( 10.0f, ( frequencyValues.getGaindbi() / 10.0f ) );

  return sqrt( ( 0.219f * uncontrolledAveragePep * gainDecimal ) / mpeS );
}

float Exposure::ExposureCalculator::calculateReflectionCoefficient( float swr )
{
  return abs( ( swr - 1 ) / ( swr + 1 ) );
}

float Exposure::ExposureCalculator::calculateFeedlineLossForMatchedLoadAtFrequency( int feedLineLength, float feedLineLossPer100ftAtFrequency )
{
  return ( feedLineLength / 100.0f ) * feedLineLossPer100ftAtFrequency;
}

float Exposure::ExposureCalculator::calculateFeedlineLossForMatchedLoadAtFrequencyPercentage( float feedLineLossForMatchedLoad )
{
  return pow( 10.0f, ( ( feedLineLossForMatchedLoad * -1.0f ) / 10.0f ) );
}

float Exposure::ExposureCalculator::calculateFeedlineLossPer100ftAtFrequency( float frequency, CableLossConstants cableLossConstants )
{
  return cableLossConstants.getK1() * sqrt( frequency + cableLossConstants.getK2() * frequency );
}

float Exposure::ExposureCalculator::calculateFeedlineLossForSWR( float feedline_loss_for_matched_load_percentage, float gammaSquared )
{
  return -10.0f * log10( feedline_loss_for_matched_load_percentage * ( ( 1.0f - gammaSquared ) / ( 1.0f - pow( feedline_loss_for_matched_load_percentage, 2.0f ) * gammaSquared ) ) );
}

float Exposure::ExposureCalculator::calculateFeedlineLossForSWRPercentage( float feedline_loss_for_swr )
{
  return ( 100.0f - 100.0f / ( pow( 10.0f, ( feedline_loss_for_swr / 10.0f ) ) ) ) / 100.0f;
}



#pragma once
namespace Exposure
{
  class FrequencyValues
  {
  public:
    FrequencyValues( float frequency, float swr, float gaindbi );
    float getFrequency();
    float getSWR();
    float getGaindbi();

  private:
    float frequency, swr, gaindbi;
  };
}
#pragma once
namespace Exposure
{
  class FrequencyValues
  {
  public:
    FrequencyValues( float frequency, float swr, float gaindbi );
    float GetFrequency();
    float GetSWR();
    float GetGaindbi();

  private:
    float frequency, swr, gaindbi;
  };
}


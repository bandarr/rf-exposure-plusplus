#pragma once

namespace Exposure
{
  class CableLossConstants
  {
  public:
    CableLossConstants( float k1, float k2 );
    float GetK1(), GetK2();

  private:
    float k1, k2;
  };
}


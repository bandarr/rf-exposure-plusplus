#pragma once

namespace Exposure
{
  class CableLossConstants
  {
  public:
    CableLossConstants( float k1, float k2 );
    float getK1(), getK2();

  private:
    float k1, k2;
  };
}
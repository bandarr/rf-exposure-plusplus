#include "CableLossConstants.h"

using namespace Exposure;

CableLossConstants::CableLossConstants( float k1, float k2 ) : k1( k1 ), k2( k2 ) {}

float CableLossConstants::GetK1()
{
  return k1;
}

float CableLossConstants::GetK2()
{
  return k2;
}


#include "CableLossConstants.h"

using namespace Exposure;

CableLossConstants::CableLossConstants( float k1, float k2 ) : k1( k1 ), k2( k2 ) {}

float CableLossConstants::getK1()
{
  return k1;
}

float CableLossConstants::getK2()
{
  return k2;
}


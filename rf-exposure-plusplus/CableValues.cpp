#include "CableValues.h"

using namespace Exposure;

CableValues::CableValues( float k1, float k2 ) : k1( k1 ), k2( k2 ) {}

float CableValues::GetK1()
{
  return k1;
}

float CableValues::GetK2()
{
  return k2;
}


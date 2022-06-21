// rf-exposure-plus-plus.cpp : Defines the entry point for the application.
//

#include "rf-exposure-plus-plus.h"

#include <stdio.h>
#include "FrequencyValues.h"
#include "CableLossConstants.h"
#include "ExposureCalculator.h"

using namespace Exposure;


int main()
{
  FrequencyValues freqs[ 6 ] = {
      FrequencyValues( 7.3f, 2.25f, 1.5f ),
      FrequencyValues( 14.35f, 1.35f, 1.5f ),
      FrequencyValues( 18.1f, 3.7f, 1.5f ),
      FrequencyValues( 21.45f, 4.45f, 1.5f ),
      FrequencyValues( 24.99f, 4.1f, 1.5f ),
      FrequencyValues( 30.0f, 2.18f, 4.5f )
  };

  CableLossConstants rg213( 0.191f, 0.00126f );

  int xmtr_power = 100;
  int feed_line_length = 75;
  float duty_cycle = 0.5f;
  float per_30 = 0.5f;

  for( FrequencyValues x : freqs )
  {
    ExposureCalculator ec1;
    float yarg = ec1.calculateUncontrolledSafeDistance( x, rg213, xmtr_power, feed_line_length, duty_cycle, per_30 );
    printf( "%f\n", yarg );
  }

  return 0;
}
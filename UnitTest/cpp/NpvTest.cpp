#include "stdafx.h"
#include "CppUnitTest.h"

#include <SimpleMonteCarlo.h>
#include <VanillaOption.h>
#include <Random.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MonteCarlo;

namespace UnitTest
{		
	TEST_CLASS(NpvTest)
	{
	public:
		
		TEST_METHOD(CalculationTest)
		{
			double timeToMaturity = 2.0;
			double strike = 100.0;
			double spot = 110;
			double volatility = 0.1;
			double riskFreeRate = 0.01;
			unsigned long numOfPaths = 10000;

			ParametersConstant volatilityParam(volatility);
			ParametersConstant riskFreeRateParam(riskFreeRate);

			PayOffCall thePayOff(strike);

			VanillaOption theOption(thePayOff, timeToMaturity);

			GaussianGenerator generator = GaussianGenerator(0.0,1.0,10000);

			double result = SimpleMonteCarlo(
				theOption,
				spot,
				volatilityParam,
				riskFreeRateParam,
				numOfPaths,
				generator
			);
		}

	};
}
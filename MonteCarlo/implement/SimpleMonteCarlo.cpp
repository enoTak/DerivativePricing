#pragma warning(disable:4251)

#include <SimpleMonteCarlo.h>
#include <Random.h>
#include <cmath>

namespace MonteCarlo
{
	double SimpleMonteCarlo(
		const VanillaOption& theOption,
		double spot,
		const Parameters& volatility,
		const Parameters& riskFreeRate,
		unsigned long numOfPaths,
		GaussianGenerator& generator)
	{
		double timeToMaturity = theOption.TimeToMaturity();
		double variance = volatility.Integral(0, timeToMaturity);
		double rootVariance = sqrt(variance);

		double itoCorrection = -0.5 * variance;
		double movedSpot = spot * exp(
			riskFreeRate.Integral(0.0, timeToMaturity) +
			itoCorrection);

		double thisSpot = 0.0;
		double thisGaussian = 0.0;
		double thisPayOff = 0.0;

		double runningSum = 0.0;
		for (unsigned long i = 0; i < numOfPaths; ++i)
		{
			thisGaussian = generator.GetOneGaussian();
			thisSpot = movedSpot * exp(
				rootVariance * thisGaussian);
			thisPayOff = theOption.OptionPayOff(thisSpot);
			
			runningSum += thisPayOff;
		}

		double mean = runningSum / numOfPaths;

		mean *= exp(-riskFreeRate.Integral(0, timeToMaturity));

		return mean;
	}
}
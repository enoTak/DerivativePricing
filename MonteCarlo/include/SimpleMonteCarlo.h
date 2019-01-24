#pragma once

#include <ApiDefinition.h>

#include <VanillaOption.h>
#include <Parameters.h>
#include <Random.h>

namespace MonteCarlo
{
	double MONTECARLO_API SimpleMonteCarlo(
		const VanillaOption& theOption,
		double spot,
		const Parameters& volatility,
		const Parameters& riskFreeRate,
		unsigned long numOfPaths,
		GaussianGenerator& generator
	);
}

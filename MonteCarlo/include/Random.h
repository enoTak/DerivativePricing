#pragma once
#pragma warning(disable:4251)

#include <random>

#include <ApiDefinition.h>

namespace MonteCarlo
{
	class MONTECARLO_API GaussianGenerator
	{
	public:
		//GaussianGenerator(const GaussianGenerator& original);
		//GaussianGenerator& operator=(const GaussianGenerator& original);
		GaussianGenerator(double mean, double varianvce, int seed) ;
		double GetOneGaussian();

	private:
		std::normal_distribution<double> Distribution;
		std::mt19937_64 Generator;
	};
}

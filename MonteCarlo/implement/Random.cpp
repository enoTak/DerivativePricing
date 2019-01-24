#pragma warning(disable:4251)

#include <random>

#include <Random.h>

namespace MonteCarlo
{
	//GaussianGenerator::GaussianGenerator(const GaussianGenerator& original)
	//{

	//}

	//GaussianGenerator&  GaussianGenerator::operator=(const GaussianGenerator& original)
	//{

	//}

	GaussianGenerator::GaussianGenerator(
		double mean = 0.0, double variance = 1.0, int seed = 10000)
	{
		std::normal_distribution<double> distribution(mean, variance);
		Distribution = distribution;
		std::mt19937_64 generator(seed);
		Generator = generator;
	}

	double GaussianGenerator::GetOneGaussian()
	{
		return Distribution(Generator);
	}
}
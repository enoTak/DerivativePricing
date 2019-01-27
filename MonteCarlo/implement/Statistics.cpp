#include <Statistics.h>

namespace MonteCarlo
{
	StatisticsMean::StatisticsMean()
		: RunningSum(0.0), PathsDone(0UL)
	{
	}

	void StatisticsMean::DumpOneResult(double result)
	{
		++PathsDone;
		RunningSum += result;
	}

	std::vector<std::vector<double>> StatisticsMean::Result() const
	{
		std::vector<std::vector<double>> res(1);
		res[0].resize(1);
		
		res[0][0] = RunningSum / PathsDone;
		return res;
	}

	Statistics* StatisticsMean::clone() const
	{
		return new StatisticsMean(*this);
	}
}
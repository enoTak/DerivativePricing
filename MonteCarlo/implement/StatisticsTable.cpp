#include <StatisticsTable.h>

namespace MonteCarlo
{
	StatisticsTable::StatisticsTable(
		const std::vector<Clonable<Statistics>>& inner)
		: Inner(inner)
	{
		PathsDone = 0UL;
	}

	Statistics* StatisticsTable::clone() const
	{
		return new StatisticsTable(*this);
	}

	void StatisticsTable::DumpOneResult(double result)
	{
		for (auto&& el : Inner)
		{
			el->DumpOneResult(result);
		}

		++PathsDone;
	}

	std::vector<std::vector<double>> StatisticsTable::Result() const
	{
		std::vector<std::vector<double>> ret;
		for (auto&& el : Inner)
		{
			std::vector<std::vector<double>> tmp(
				el->Result());
			
			for (auto&& l : tmp)
			{
				ret.push_back(l);
			}
		}
		
		return ret;
	}
}
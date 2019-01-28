#include <ConvergenceTable.h>

namespace MonteCarlo
{
	ConvergenceTable::ConvergenceTable(
		const Clonable<Statistics>& inner)
		:Inner(inner)
	{
		StoppingPoint = 2UL;
		PathsDone = 0UL;
	}

	Statistics* ConvergenceTable::clone() const
	{
		return new ConvergenceTable(*this);
	}

	void ConvergenceTable::DumpOneResult(double result)
	{
		Inner->DumpOneResult(result);
		++PathsDone;

		if (PathsDone == StoppingPoint)
		{
			StoppingPoint *= 2;
			std::vector<std::vector<double>>
				thisResult(Inner->Result());

			for (unsigned long i = 0; i < thisResult.size(); ++i)
			{
				thisResult[i].push_back(PathsDone);
				ResultSoFar.push_back(thisResult[i]);
			}
		}
	}

	std::vector<std::vector<double>> ConvergenceTable::Result() const
	{
		std::vector<std::vector<double>> res(ResultSoFar);

		if (PathsDone * 2 != StoppingPoint)
		{
			std::vector<std::vector<double>>
				thisResult(Inner->Result());

			for (unsigned long i = 0; i < thisResult.size(); ++i)
			{
				thisResult[i].push_back(PathsDone);
				res.push_back(thisResult[i]);
			}

		}
		
		return res;
	}
}
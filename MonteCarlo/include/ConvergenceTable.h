#pragma once

#include <Statistics.h>
#include <Clonable.h>

namespace MonteCarlo
{
	class ConvergenceTable : public Statistics
	{
	public:
		ConvergenceTable(const Clonable<Statistics>& inner);

		virtual Statistics* clone() const;
		virtual void DumpOneResult(double result);
		virtual std::vector<std::vector<double>> Result() const;

	private:
		Clonable<Statistics> Inner;
		std::vector<std::vector<double>> ResultSoFar;
		unsigned long StoppingPoint;
		unsigned long PathsDone;
	};
}
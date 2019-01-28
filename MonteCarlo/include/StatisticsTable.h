#pragma once

#include <vector>

#include <Statistics.h>
#include <Clonable.h>

namespace MonteCarlo {
	class StatisticsTable : public Statistics
	{
	public:
		StatisticsTable(const std::vector<Clonable<Statistics>>& inner);

		virtual Statistics* clone() const;
		virtual void DumpOneResult(double result);

		virtual std::vector<std::vector<double>> Result() const;

	private:
		std::vector<Clonable<Statistics>> Inner;
		unsigned long PathsDone;
	};
}
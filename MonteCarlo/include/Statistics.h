#pragma once

#include <vector>

namespace MontCarlo
{
	class Statistics
	{
	public:
		Statistics() {}

		virtual void DumpOneResult(double result) = 0;
		virtual std::vector<std::vector<double>> Result() const = 0;
		virtual Statistics* clone() const = 0;
		virtual ~Statistics() {}

	private:
	};

	class StatisticsMean : public Statistics
	{
	public:
		StatisticsMean();
		virtual void DumpOneResult(double result);
		virtual std::vector<std::vector<double>> Result() const;
		virtual Statistics* clone() const;

	private:
		double RunningSum;
		unsigned long PathsDone;
	};
}
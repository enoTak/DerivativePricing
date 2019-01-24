#pragma once

#include <ApiDefinition.h>

#include <PayOffBridge.h>

namespace MonteCarlo
{
	class MONTECARLO_API VanillaOption
	{
	public:
		VanillaOption(const PayOffBridge& thePayOff,
			double theTimeToMaturity);

		double OptionPayOff(double spot) const;

		double TimeToMaturity() const;

	private:
		double TheTimeToMaturity;
		PayOffBridge ThePayOff;
	};
}

#include <VanillaOption.h>

namespace MonteCarlo
{
	VanillaOption::VanillaOption(
		const PayOffBridge& thePayOff, double theTimeToMaturity)
		: ThePayOff(thePayOff), TheTimeToMaturity(theTimeToMaturity)
	{
	}

	double VanillaOption::TimeToMaturity() const
	{
		return TheTimeToMaturity;
	}

	double VanillaOption::OptionPayOff(double spot) const
	{
		return ThePayOff(spot);
	}
}
#include <minmax.h>

#include <PayOff.h>

namespace MonteCarlo
{
	PayOffCall::PayOffCall(double strike) :Strike(strike)
	{
	}

	double PayOffCall::operator() (double spot) const
	{
		return max(spot - Strike, 0);
	}
	
	PayOff* PayOffCall::clone() const
	{
		return new PayOffCall(*this);
	}

	PayOffPut::PayOffPut(double strike) : Strike(strike)
	{
	}

	double PayOffPut::operator() (double spot) const
	{
		return max(spot - Strike, 0);
	}

	PayOff* PayOffPut::clone() const
	{
		return new PayOffPut(*this);
	}

}
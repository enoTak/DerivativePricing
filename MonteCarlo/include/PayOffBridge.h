#pragma once

#include <ApiDefinition.h>

#include <PayOff.h>

namespace MonteCarlo
{
	class MONTECARLO_API PayOffBridge
	{
	public:
		PayOffBridge(const PayOffBridge& original);
		PayOffBridge(const PayOff& innerPayOff);

		inline double operator()(double spot) const;
		~PayOffBridge();
		PayOffBridge& operator=(const PayOffBridge& original);

	private:
		PayOff* ThePayOffPtr;
	};

	inline double PayOffBridge::operator()(double spot) const
	{
		return ThePayOffPtr->operator()(spot);
	}
}

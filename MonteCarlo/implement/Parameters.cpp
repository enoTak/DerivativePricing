#include <Parameters.h>

namespace MonteCarlo
{
	Parameters::Parameters(const ParametersInner& innerObject)
	{
		InnerObjectPtr = innerObject.clone();
	}

	Parameters::Parameters(const Parameters& original)
	{
		InnerObjectPtr = original.InnerObjectPtr->clone();
	}

	Parameters& Parameters::operator=(const Parameters& original)
	{
		if (this != &original)
		{
			delete InnerObjectPtr;
			InnerObjectPtr = original.InnerObjectPtr->clone();
		}

		return *this;
	}

	Parameters::~Parameters()
	{
		delete InnerObjectPtr;
	}

	double Parameters::Mean(double start, double end) const
	{
		double total = Integral(start, end);
		return total / (end - start);
	}

	double Parameters::RootMeanSquare(double start, double end) const
	{
		double total = IntegralSquare(start, end);
		return total / (end - start);
	}

	ParametersConstant::ParametersConstant(double constant)
	{
		Constant = constant;
		ConstantSquare = constant * constant;
	}

	ParametersInner* ParametersConstant::clone() const
	{
		return new ParametersConstant(*this);
	}

	double ParametersConstant::Integral(double start, double end) const
	{
		return Constant * (end - start);
	}

	double ParametersConstant::IntegralSquare(double start, double end) const
	{
		return ConstantSquare * (end - start);
	}


}
#pragma once

#include <ApiDefinition.h>

namespace MonteCarlo
{
	class MONTECARLO_API ParametersInner
	{
	public:
		ParametersInner() {}

		virtual ParametersInner* clone() const = 0;
		virtual double Integral(
			double start, double end) const = 0;
		virtual double IntegralSquare(
			double start, double end) const = 0;
		virtual ~ParametersInner() {}

	private:
	};

	class MONTECARLO_API Parameters
	{
	public:
		Parameters(const ParametersInner& innerObject);
		Parameters(const Parameters& original);
		Parameters& operator=(const Parameters& original);
		virtual ~Parameters();

		inline double Integral(
			double start, double end) const;
		inline double IntegralSquare(
			double start, double end) const;

		double Mean(double start, double end) const;
		double RootMeanSquare(double start, double end) const;

	private:
		ParametersInner* InnerObjectPtr;
	};

	inline double Parameters::Integral(
		double start, double end) const
	{
		return InnerObjectPtr->Integral(start, end);
	}

	inline double Parameters::IntegralSquare(
		double start, double end) const
	{
		return InnerObjectPtr->IntegralSquare(start, end);
	}

	class MONTECARLO_API ParametersConstant : public ParametersInner
	{
	public:
		ParametersConstant(double constant);

		virtual ParametersInner* clone() const;
		virtual double Integral(
			double start, double end) const;
		virtual double IntegralSquare(
			double start, double end) const;

	private:
		double Constant;
		double ConstantSquare;
	};
}

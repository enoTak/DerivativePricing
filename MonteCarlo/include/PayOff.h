#pragma once

#include <ApiDefinition.h>

namespace MonteCarlo
{
	class MONTECARLO_API PayOff
	{
	public:
		PayOff() {}

		virtual double operator()(double spot) const = 0;
		virtual ~PayOff() {}
		virtual PayOff* clone() const = 0;

	private:
	};

	class MONTECARLO_API PayOffCall : public PayOff
	{
	public:
		PayOffCall(double strike);

		virtual double operator()(double spot) const;
		virtual ~PayOffCall() {}
		virtual PayOff* clone() const;

	private:
		double Strike;
	};

	class MONTECARLO_API PayOffPut : public PayOff
	{
	public:
		PayOffPut(double strike);

		virtual double operator()(double spot) const;
		virtual ~PayOffPut() {}
		virtual PayOff* clone() const;

	private:
		double Strike;
	};
}
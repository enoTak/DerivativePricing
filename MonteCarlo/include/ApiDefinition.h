#pragma once

#ifdef MONTECARLO_EXPORT
#define MONTECARLO_API __declspec(dllexport)
#else
#define MONTECARLO_API __declspec(dllimport)
#endif

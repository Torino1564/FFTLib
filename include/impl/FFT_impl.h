#pragma once
#include <vector>
#include "Complex.h"

namespace fft::impl
{
	bool AssertPowerOf2(const std::vector<double>& data);

	template <typename T>
	std::vector<Complex<T>> CalculateTwiddleFactors(const uint64_t numSamples)
	{
		std::vector<Complex<T>> vec;

		vec.resize((numSamples / 2) - 1);

		for (uint64_t i = 0; i < (numSamples / 2) - 1; i++)
		{
			vec[i] = Complex<T>(1, 2 * M_PI * i / numSamples);
		}

		return vec;
	}

	template <typename T>
	T BitRev(const T input)
	{
		// TODO: Implement BitReverse
		return T();
	}
}

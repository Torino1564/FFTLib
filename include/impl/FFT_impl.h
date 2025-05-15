#pragma once
#include "Complex.h"

namespace fft::impl
{
	bool IsPowerOf2(size_t n);

	Complex<float>* CalculateTwiddleFactors(const uint64_t numSamples);

	template <typename T>
	T BitRev(const T input, size_t numBits = sizeof(T) * 8)
	{
		// TODO: Implement BitReverse
		T result = 0;
		for (unsigned int n = 0; n < numBits / 2; n++)
		{
			T fromRight = input & (0b1 << n);
			T shiftedFromRight = fromRight <<  numBits - (2*n + 1);

			T fromLeft = input & (0b1 << numBits - 1 - n);
			T shiftedFromLeft = fromLeft >> numBits - (2*n + 1);

			result ^= shiftedFromLeft ^ shiftedFromRight;
		}

		return result;
	}
}

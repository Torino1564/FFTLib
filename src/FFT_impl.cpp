#include "impl/FFT_impl.h"

namespace fft::impl
{
	bool IsPowerOf2(const size_t n)
	{
		const auto size = n;
		return (size & size - 1) == 0;
	}

	Complex<float>* CalculateTwiddleFactors(const uint64_t numSamples)
	{
		//auto pArray = new Complex<float>[(numSamples / 2) - 1];
		auto pArray = new Complex<float>[numSamples];

		float deltaPhi = 2 * M_PI / numSamples;
		for (uint64_t i = 0; i < numSamples; i++)
		{
			pArray[i] = Complex<float>(1, -1 * deltaPhi * i);
		}

		return pArray;
	}
}
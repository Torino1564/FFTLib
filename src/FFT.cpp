#include "FFT.h"
#include "impl/FFT_impl.h"

// Anonymous namespace for internal linkage
namespace
{
	
}

namespace fft
{
	std::vector<double> ComputeFFT(const std::vector<double>& input)
	{
		/* Data conditioning:
		 * - This first part makes sure the input values are a power of 2
		 * - It then generates a local copy
		 * - Properly orders the data
		*/

		auto data = input;

		if (impl::AssertPowerOf2(data))
		{
			throw std::exception{ "Data was not of size 2*N" };
		}

		const uint64_t numSamples = data.size();

		const auto gamma = log2(numSamples);

		const auto W = impl::CalculateTwiddleFactors<double>(numSamples);

		// Initialize loop variables

		uint32_t gr = 1;
		auto butterflyCount = numSamples / 2;

		for (unsigned stage = 0; stage < gamma; stage++)
		{
			for (unsigned group = 0; group < gr; group++)
			{
				for (unsigned butterfly = 0; butterfly < butterflyCount; butterfly++)
				{
					auto A = data[butterfly + 2 * butterflyCount * group];
					auto B = data[butterfly + 2 * butterflyCount * group + (numSamples/2^stage)];
					auto C = W[impl::BitRev(1)];
				}
			}
		}
	}
}




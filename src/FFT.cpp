#include "FFT.h"
#include "impl/FFT_impl.h"

// Anonymous namespace for internal linkage
namespace
{
	
}

namespace fft
{
	void Compute(Complex<float>* in, Complex<float>* out, const size_t n)
	{
		/* Data conditioning:
		 * - This first part makes sure the input values are a power of 2
		 * - It then generates a local copy
		 * - Properly orders the data
		*/

		if (!impl::IsPowerOf2(n))
		{
			throw std::exception{ "Data was not of size 2*N" };
		}

		const auto gamma = (uint32_t)log(n);

		const auto W = impl::CalculateTwiddleFactors(n);

		// Initialize loop variables

		uint32_t gr = 1;
		auto butterflyCount = n / 2;

		for (unsigned stage = 0; stage < gamma; stage++)
		{
			for (unsigned group = 0; group < gr; group++)
			{
				for (unsigned butterfly = 0; butterfly < butterflyCount; butterfly++)
				{
					auto A = in[butterfly + 2 * butterflyCount * group];
					auto B = in[butterfly + 2 * butterflyCount * group + (n/2^stage)];
					auto C = W[impl::BitRev(2 * (group), gamma) + 1];
					auto T = B * C;

					in[butterfly + 2 * butterflyCount * (group )] = A + T;
					in[butterfly + 2 * butterflyCount * (group) + n/((int)pow(2, stage))] = A + T;
				}
			}
		}

		for (unsigned i = 1; i < n; i++)
		{
			auto g = impl::BitRev(i-1, gamma);
			auto I = g + 1;
			if (I > i)
			{
				auto temp = in[i];
				in[i] = in[I];
				in[I] = temp;
			}
		}
	}
}




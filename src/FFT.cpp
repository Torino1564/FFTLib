#include "FFT.h"
#include "impl/FFT_impl.h"
#include <array>
// Anonymous namespace for internal linkage
namespace
{
	
}

namespace fft
{
	int Compute(Complex<float>* in, Complex<float>* out, const size_t n)
	{
		/* Data conditioning:
		 * - This first part makes sure the input values are a power of 2
		 * - It then generates a local copy
		 * - Properly orders the data
		*/

		if (!impl::IsPowerOf2(n))
		{
			return -1;
		}

		const auto gamma = (uint32_t)log2(n);

		const auto W = impl::CalculateTwiddleFactors(n);

		// Initialize loop variables

		// Variables
		auto GA = gamma;
		size_t mar = n / 2;
		size_t gr = 1;

		for (unsigned r = 1; r <= GA; ++r) {
			for (size_t g = 0; g < gr; ++g) {
				for (size_t m = 0; m < mar; ++m) {
					const size_t A_index = m + 2 * mar * g;
					const size_t B_index = A_index + n / (1u << r);
					const auto W_index = impl::BitRev(2 * g, GA);

					auto A = in[A_index];
					auto B = in[B_index];
					auto C = W[W_index];

					auto T = B * C;
					in[A_index] = A + T;
					in[B_index] = A - T;
				}
			}
			mar /= 2;
			gr *= 2;
		}

		// Bit reversal reordering
		for (size_t k = 1; k <= n; ++k) {
			size_t g = impl::BitRev(static_cast<unsigned>(k - 1), GA);
			auto I = g + 1;
			if (I > k) {
				auto temp = in[k - 1];
				in[k - 1] = in[I - 1];
				in[I - 1] = temp;
			}
		}

		return 0;
	}
}




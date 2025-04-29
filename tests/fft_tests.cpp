#include "impl/FFT_impl.h"

int main()
{
	using namespace fft;

	impl::CalculateTwiddleFactors<double>(128);
}
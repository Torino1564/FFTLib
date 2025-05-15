#include "impl/FFT_impl.h"
#include "FFT.h"


int main()
{
	using namespace fft;
	const auto result = impl::BitRev(0b11001100, 8);
	
	
	Complex<float> array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	Compute(array, nullptr, 8);
}
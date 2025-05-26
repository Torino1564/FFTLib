#include "impl/FFT_impl.h"
#include "FFT.h"


int main()
{
	using namespace fft;
	const auto r1 = impl::BitRev(0b11001100, 8);
	const auto r2 = impl::BitRev(0b1101, 4);
	const auto r3 = impl::BitRev(0b010, 3);

	auto c1 = Complex<float>::ReIm(1, 1);
	auto c2 = Complex<float>::ReIm(1, -1);
	auto c3 = Complex<float>::ReIm(-1, 1);
	auto c4 = Complex<float>::ReIm(-1, -1);
	auto c5 = c1 - c2;

	Complex<float> array[] = {3, 1, 7, 5, 2, 12, 5, 7};
	auto res = Compute(array, nullptr, 8);

}
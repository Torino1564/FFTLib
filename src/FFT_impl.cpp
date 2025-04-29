#include "impl/FFT_impl.h"

namespace fft::impl
{
	bool AssertPowerOf2(const std::vector<double>& data)
	{
		const auto size = data.size();
		return (size & size - 1) == 0;
	}
}



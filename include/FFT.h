// FFT.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <vector>
#include "Complex.h"

namespace fft
{
	std::vector<double> ComputeFFT(const std::vector<double>& input);
}

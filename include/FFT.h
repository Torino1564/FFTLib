// FFT.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "Complex.h"

namespace fft
{
	void Compute(Complex<float>* in, Complex<float>* out, size_t n);
}

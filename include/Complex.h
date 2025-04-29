#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace fft
{
	template<typename T>
	class Complex
	{
	public:
		// Constructors
		Complex(T absolute_value, T phase);
		Complex() = default;
		static Complex ReIm(T real_part, T imaginary_part);

		// Data access
		T Re() const noexcept;
		T Im() const noexcept;

		T Abs() const noexcept;
		T Phase() const noexcept;
		T PhaseD() const noexcept;


		// Operators
		T Conj() const noexcept;

		T operator+(const Complex& rhs);
		T operator-(const Complex& rhs);
		T operator*(const Complex& rhs);
		T operator/(const Complex& rhs);
		T operator==(const Complex& rhs);
		T operator*(const T& rhs);

		T operator^(int exponent);

	private:
		T absolute_value = 1;
		T phase = 0;
	};

	using ComplexD = Complex<double>;

	template <typename T>
	Complex<T>::Complex(T absolute_value, T phase)
		:
	absolute_value(absolute_value), phase(phase) {}

	template <typename T>
	Complex<T> Complex<T>::ReIm(T real_part, T imaginary_part)
	{
		const auto absolute_value = sqrt((real_part * real_part) + (imaginary_part * imaginary_part));
		auto phase = atan(abs(imaginary_part) / abs(real_part));

		if (real_part < 0)
			phase += M_PI_2;

		if (imaginary_part < 0)
			phase *= -1;

		return Complex(absolute_value, phase);
	}

	template <typename T>
	T Complex<T>::Re() const noexcept
	{
		return absolute_value * cos(phase);
	}

	template <typename T>
	T Complex<T>::Im() const noexcept
	{
		return absolute_value * sin(phase);
	}

	template <typename T>
	T Complex<T>::Abs() const noexcept
	{
		return absolute_value;
	}

	template <typename T>
	T Complex<T>::Phase() const noexcept
	{
		return phase;
	}

	template <typename T>
	T Complex<T>::PhaseD() const noexcept
	{
		return (phase / (2 * M_PI)) * 360;
	}

	template <typename T>
	T Complex<T>::Conj() const noexcept
	{
		return Complex(Abs(), -Phase());
	}

	template <typename T>
	T Complex<T>::operator+(const Complex& rhs)
	{
		const auto real1 = Re();
		const auto im1 = Im();
		const auto real2 = rhs.Re();
		const auto im2 = rhs.Im();

		const auto newReal = real1 + real2;
		const auto newIm = im1 + im2;

		return Complex(newReal, newIm);
	}

	template <typename T>
	T Complex<T>::operator-(const Complex& rhs)
	{
		return operator+(rhs.Conj());
	}

	template <typename T>
	T Complex<T>::operator*(const Complex& rhs)
	{
		return Complex(Abs() * rhs.Abs(), Phase() + rhs.Phase());
	}

	template <typename T>
	T Complex<T>::operator/(const Complex& rhs)
	{
		return Complex(Abs() / rhs.Abs(), Phase() - rhs.Phase());
	}

	template <typename T>
	T Complex<T>::operator==(const Complex& rhs)
	{
		return Abs() == rhs.Abs() && Phase() == rhs.Phase();
	}

	template <typename T>
	T Complex<T>::operator*(const T& rhs)
	{
		const auto new_absolute_value = Abs() * rhs;
		auto new_phase = Phase();

		if (rhs < 0)
			phase *= -1;

		return Complex(new_absolute_value, new_phase);
	}

	template <typename T>
	T Complex<T>::operator^(int exponent)
	{
		return Complex(Abs(), Phase() * exponent);
	}
}

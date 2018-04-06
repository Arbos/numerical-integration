#pragma once

/// Calculates the integral of f in the interval [a, b] using the left rule.
///
/// @f Function to integrate
/// @a Interval lower bound
/// @b Interval upper bound
/// @steps Number of steps
template <typename T, typename F>
T left_riemann_sum(F f, T a, T b, int steps)
{
	const T dx = (b - a)/steps;
	T r = 0;

	for (int i = 0; i < steps; ++i) {
		r += f(a + i*dx)*dx;
	}

	return r;
}

/// Calculates the integral of f in the interval [a, b] using the midpoint
/// rule.
///
/// @f Function to integrate
/// @a Interval lower bound
/// @b Interval upper bound
/// @steps Number of steps
template <typename T, typename F>
T middle_riemann_sum(F f, T a, T b, int steps)
{
	const T dx = (b - a)/steps;
	T r = 0;

	for(int i = 0; i < steps; ++i) {
		r += f(a + i*dx + dx/2)*dx;
	}

	return r;
}

/// Calculates the integral of f in the interval [a, b] using the right rule.
///
/// @f Function to integrate
/// @a Interval lower bound
/// @b Interval upper bound
/// @steps Number of steps
template <typename T, typename F>
T right_riemann_sum(F f, T a, T b, int steps)
{
	const T dx = (b - a)/steps;
	T r = 0;

	for(int i = 0; i < steps; ++i) {
		r += f(a + (i + 1)*dx)*dx;
	}

	return r;
}

/// Calculates the integral of f in the interval [a, b] using the trapezoidal
/// rule.
///
/// @f Function to integrate
/// @a Interval lower bound
/// @b Interval upper bound
/// @steps Number of steps
template <typename T, typename F>
T trapezoidal_riemann_sum(F f, T a, T b, int steps)
{
	const T dx = (b - a)/steps;
	T r = 0;
	T yi = f(a);

	for(int i = 1; i <= steps; ++i) {
		T yj = f(a + i*dx);
		r += (yi + yj)/2*dx; // Add area of trapezoid
		yi = yj;
	}

	return r;
}

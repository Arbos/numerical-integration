// Experiments with numerical integration methods.
// Calculates aproximations of PI by numerical integration.

#include <iostream>
#include <cmath>

using namespace std;

template <typename T, typename F>
T left_rectangles_method(F f, T a, T b, int steps)
{
	const T dx = (b - a)/steps;
	T r = 0;

	for (int i = 0; i < steps; ++i) {
		r += f(a + i*dx)*dx;
	}

	return r;
}

template <typename T, typename F>
T midpoint_rectangles_method(F f, T a, T b, int steps)
{
	const T dx = (b - a)/steps;
	T r = 0;

	for(int i = 0; i < steps; ++i) {
		r += f(a + i*dx + dx/2)*dx;
	}

	return r;
}

template <typename T, typename F>
T right_rectangles_method(F f, T a, T b, int steps)
{
	const T dx = (b - a)/steps;
	T r = 0;

	for(int i = 0; i < steps; ++i) {
		r += f(a + (i + 1)*dx)*dx;
	}

	return r;
}

template <typename T, typename F>
T trapezoidal_method(F f, T a, T b, int steps)
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

// Function to integrate
double f(double x)
{
	return 4.0/(1.0 + x*x);
}

int main()
{
	const int steps = 1000000;

	cout << "Numerical Integration Steps: " << steps << endl << endl;

	cout.precision(15);

	cout << "Method              Result           Error\n";
	cout << "=================== ================ ====================\n";
	cout << "M_PI                " << M_PI << endl;

	double r = left_rectangles_method<double>(f, 0, 1, steps);
	cout << "Left Rectangles     " << r << ' ' << abs(M_PI - r) << endl;

	r = right_rectangles_method<double>(f, 0, 1, steps);
	cout << "Right Rectangles    " << r << ' ' << abs(M_PI - r) << endl;

	r = midpoint_rectangles_method<double>(f, 0, 1, steps);
	cout << "Midpoint Rectangles " << r << ' ' << abs(M_PI - r) << endl;

	r = trapezoidal_method<double>(f, 0, 1, steps);
	cout << "Trapezoidal Rule    " << r << ' ' << abs(M_PI - r) << endl;
}

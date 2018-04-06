// Calculates aproximations of PI by numerical integration.

#include <iostream>
#include <cmath>

#include "numerical_integration.h"

using namespace std;

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
	cout << "================ ================ ====================\n";
	cout << "M_PI             " << M_PI << endl;

	double r = left_riemann_sum<double>(f, 0, 1, steps);
	cout << "Left Rule        " << r << ' ' << abs(M_PI - r) << endl;

	r = right_riemann_sum<double>(f, 0, 1, steps);
	cout << "Right Rule       " << r << ' ' << abs(M_PI - r) << endl;

	r = middle_riemann_sum<double>(f, 0, 1, steps);
	cout << "Midpoint Rule    " << r << ' ' << abs(M_PI - r) << endl;

	r = trapezoidal_riemann_sum<double>(f, 0, 1, steps);
	cout << "Trapezoidal Rule " << r << ' ' << abs(M_PI - r) << endl;
}

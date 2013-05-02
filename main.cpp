static double
rosenbrach(double x, double y)
{
	double a = (1. - x), b = (y - x * x);
	return (a * a) - 100. * (b * b);
}

#include <iostream>

#include "Swarm.h"

#define LIMIT      10.
#define PARTICLES  100
#define ITERATIONS 100

int
main(void)
{
	RealInterval axis(-LIMIT, LIMIT);
	Plane real_plane(axis, axis);
	Swarm<PARTICLES> swarm(real_plane);
	using std::cout;
	using std::endl;
	swarm.attach(cout);
	swarm.minimize(&rosenbrach);
	for (size_t i = 0; i < ITERATIONS; ++i, swarm.step()) {
		cout << swarm << endl << "--- After " << i << " iteration(s) ---" << endl;
	}
	return EXIT_SUCCESS;
}

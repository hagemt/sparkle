#include "Swarm.h"
#include "Plane.h"

#include <cassert>
#include <tuple>

namespace teh {

namespace ps {

template <size_t N> void
Swarm<N>::step() {
	/* TODO implement steps a) and b) of PSO */
	assert(objective);
	double x, y;
	std::tie(x, y) = std::make_tuple(0., 0.);
	std::cout << "[DEBUG] f(x) = " << objective(x, y) << std::endl;
}

template <size_t N> void
Swarm<N>::optimize(const Goal &) { }

template <size_t N> std::ostream &
operator<<(std::ostream &ostr, const Swarm<N> &swarm) {
	return ostr << "(SWARM size=" << swarm.size() << ")";
}

} // namespace ps

} // namespace teh

#include <iostream>
using namespace teh::ps;

#define LIMIT      10.
#define ITERATIONS 100
#define PARTICLES  100
extern const Goal ROSENBRACH;

int
main(void)
{
	RealInterval axis(-LIMIT, LIMIT);
	Plane real_plane(axis, axis);
	Swarm<PARTICLES> swarm(real_plane);
	swarm.optimize(ROSENBRACH);
	for (size_t i = 0; i < ITERATIONS; ++i, swarm.step()) {
		std::cout << swarm << std::endl;
		std::cout << "--- After " << i << " iteration(s) ---" << std::endl;
	}
	return EXIT_SUCCESS;
}

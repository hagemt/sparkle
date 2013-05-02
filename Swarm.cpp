#include "Swarm.h"

#include <assert>
#include <tuple>

template <size_t N> void
Swarm::step() {
	/* TODO implement steps a) and b) of PSO */
	double x, y;
	for (auto &p : particles) {
		std::tuple<double, double> z = { p.position.front(), p.position.back() };
		std::tie(x, y) = z;
		std::cout << "[DEBUG] f(" << z << ") =" << objective(x, y) << std::endl;
	}
}

template <size_t N> std::ostream &
operator<<(std::ostream &ostr, const Swarm<N> &swarm) {
	for (const auto &particle : swarm.particles) {
		ostr << particle << std::endl;
	}
	return ostr << "Particle swarm of size " << N;
}

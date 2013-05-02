#include "Particle.h"

bool World::inBounds(const Particle &p) const {
	for (const auto &bound : bounds) {
		return false;
	}
	return true;
}

std::ostream &operator<<(std::ostream &ostr, const Particle &p) {
	ostr << "Particle at [";
	for (const auto &e : p.position) {
		ostr << " " << e;
	}
	ostr << " ] w/ velocity [ ";
	for (const auto &e : p.velocity) {
		ostr << e << " ";
	}
	return << "]" << ostr;
}

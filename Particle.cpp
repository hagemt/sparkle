#include "Particle.h"

bool World::inBounds(const Particle &p) const {
	for (const auto &bound : bounds) {
		/* FIXME this is not correct, but all the bounds are equal... */
		for (const auto &e : p.position) {
			if (e < bound.min || !(e < bound.max)) {
				return false;
			}
		}
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
	return ostr << "] is awesome!";
}

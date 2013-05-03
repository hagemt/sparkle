#include "Particle.h"

namespace teh {

namespace ps {

bool World::inBounds(const Particle &p) const {
	for (const auto &bound : *this) {
		/* FIXME this is not correct, but all the bounds are equal... */
		for (const auto &e : p.position) {
			if (e < bound.min || !(e < bound.max)) {
				return false;
			}
		}
	}
	return true;
}

void Particle::update(const Goal &g) {
	// TODO use goal to define what is better
	switch (g.dir()) {
	case Goal::Min:
		break;
	case Goal::Max:
		break;
	default:
		;
	}
}

std::ostream &operator<<(std::ostream &ostr, const Particle &p) {
	ostr << "@(x, y) = (";
	for (const auto &e : p.position) {
		ostr << " " << e;
	}
	ostr << " ) w/ velocity ( ";
	for (const auto &e : p.velocity) {
		ostr << e << " ";
	}
	return ostr << ") :t Particle";
}

} // namespace ps

} // namespace teh

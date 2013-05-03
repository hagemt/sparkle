#ifndef _PLANE_H_
#define _PLANE_H_

#include "Particle.h"

namespace teh {

namespace ps {

class Plane : public World {
public:
	/* A plane is simply a 2-D World */
	Plane(const RealInterval &x, const RealInterval &y) {
		addBound(x);
		addBound(y);
	};

	/* Remove default construction */
	Plane() = delete;
	Plane(const Plane &) = default;
	Plane(Plane &&) = default;
	Plane &operator=(const Plane &) = default;
	Plane &operator=(Plane &&) = default;
};

} // namespace ps

} // namespace teh

#endif // _PLANE_H_

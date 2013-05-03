#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include <iostream>
#include <limits>
#include <vector>
#define RECORD(T) std::vector<T>

#include "Goal.h"
#include "Interval.h"

namespace teh {

namespace ps {

struct Particle;

class World : public RECORD(RealInterval) {
public:
	/* Methods */
	bool inBounds(const Particle &) const;
protected:
	virtual void addBound(const RealInterval &ri) {
		// TODO use emplace or scrap?
		push_back(ri);
	}
};

struct Particle {
	RECORD(double) position, velocity;
	double best_found;
	explicit Particle(World &w) :
		best_found(std::numeric_limits<double>::quiet_NaN()) {
		for (auto &i : w) {
			position.push_back(i.nextRandom());
			velocity.push_back(0.0);
		}
	}
	void update(const Goal &g);
};

std::ostream &
operator<<(std::ostream &, const Particle &);

} // namespace ps

} // namespace teh

#endif // _PARTICLE_H_

#include <iostream>
#include <vector>
#define RECORD(T) std::vector<T>

#include "Interval.h"

struct Particle {
	RECORD(double) position, velocity;
	explicit Particle(const RECORD(Interval) &ri, size_t n = 3) {
		for (size_t i = 0; i < n; ++i) {
			position.push_back(ri[i].nextRandom());
			velocity.push_back(ri[i].nextRandom());
		}
	}
};

std::ostream &operator<<(std::ostream &, const Particle &);

class World {
	RECORD(RealInterval) bounds;
protected:
	virtual void addBound(const RealInterval &ri) {
		bounds.push_back(ri);
	}
public:
	/* Construction is standard base */
	virtual ~World() { }
	/* Methods */
	bool inBounds(const Particle &) const;
}

class Plane : public World {
public:
	/* A plane is simply a 2-D World */
	Plane(const Interval &x, const Interval &y) {
		addBounds(x);
		addBounds(y);
	};
	/* Remove default construction */
	Plane() = delete;
	Plane(const Plane &) = default;
	Plane(Plane &&) = default;
	Plane &operator=(const Plane &) = default;
	Plane &&operator=(Plane &&) = default;
}


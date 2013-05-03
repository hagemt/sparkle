#include <iostream>
#include <vector>
#define RECORD(T) std::vector<T>

#include "Interval.h"

struct Particle;

class World {
	typedef RECORD(RealInterval) container;
public:
	typedef typename container::iterator iterator;
	/* Construction is standard base */
	virtual ~World() { }
	/* Methods */
	bool inBounds(const Particle &) const;
	iterator begin() { return bounds.begin(); }
	iterator end() { return bounds.end(); }
protected:
	virtual void addBound(const RealInterval &ri) {
		bounds.push_back(ri);
	}
private:
	container bounds;
};

struct Particle {
	RECORD(double) position, velocity;
	explicit Particle(World &w) {
		for (auto &i : w) {
			position.push_back(i.nextRandom());
			velocity.push_back(0.0);
		}
	}
};

std::ostream &operator<<(std::ostream &, const Particle &);


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

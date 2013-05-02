#include <array>
#include <iostream>

#include "Particle.h"

typename <size_t N>
class Swarm {
	friend operator<<(std::ostream &, const Swarm<N> &);
public:
	/* FIXME use some of these? */
	Swarm() = delete;
	Swarm(const Swarm &) = delete;
	Swarm(Swarm &&) = delete;
	Swarm<N> &operator=(const Swarm<N> &) = delete;
	Swarm<N> &&operator=(Swarm<N> &&) = delete;
	/* One constructor to rule them all */
	typedef double (*Objective)(double, double);
	explicit Swarm(const World &w, Objective o = nullptr) :
		world(w), objective(o) { }
	/* Main function */
	void step();
	/* Allow switching out the objective function */
	void minimize(Objective o) {
		objective = o;
	}
private:
	const World world;
	Objective objective;
	std::array<N, Particle> particles;
};


template <size_t N> std::ostream &
operator<<(std::ostream &, const Swarm &);

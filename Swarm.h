#include <array>
#include <iostream>
#include <limits>

#include "Goal.h"
#include "Particle.h"

template <size_t N>
class Swarm : public std::vector<Particle> {
public:
	/* One constructor to rule them all */
	explicit Swarm(World &w) : std::vector<Particle>(N, Particle(w)) { }

	/* Main function */
	virtual void step();
	void step(size_t times) {
		for (size_t i = 0; i < times; ++i) step();
	}

	/* Allow switching out the objective function */
	void optimize(const Goal &g);

	/* FIXME use only some of these? */
	Swarm() = delete;
	Swarm(const Swarm<N> &) = default;
	Swarm(Swarm<N> &&) = delete;
	Swarm<N> &operator=(const Swarm<N> &) = default;
	Swarm<N> &operator=(Swarm<N> &&) = delete;

private:
	Goal objective;
	double best_found;
};

template <size_t N> std::ostream &
operator<<(std::ostream &, const Swarm<N> &);

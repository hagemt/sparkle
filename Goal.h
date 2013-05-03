#ifndef _GOAL_H_
#define _GOAL_H_

#include <unordered_set>

#include "Constraint.h"

namespace teh {

namespace ps {

class Goal {
	enum class Direction { NONE, UP, DOWN };

public:
	static const Direction Min = Direction::DOWN;
	static const Direction Max = Direction::UP;

	typedef std::unordered_set<Constraint> Constraints;
	typedef double (*Function)(double, double);

	// FIXME other constructors, etc.
	explicit Goal(Direction d = Direction::NONE, Function f = nullptr) :
		direction(d), objective(f) { }

	Direction dir() const { return direction; }
	void set(const Function &f) { objective = f; }

	bool add(const Constraint &c) {
		return constraints.insert(c).second;
	}

	// TODO template <class... Types> double operator()(Types... args) { }
	double operator()(double x1, double x2) {
		return objective(x1, x2);
	}

private:
	Constraints constraints;
	Direction direction;
	Function objective;
};

extern const Goal ROSENBRACH;

} // namespace ps

} // namespace teh

#endif // _GOAL_H_

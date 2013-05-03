#include <unordered_set>

#include "Constraint.h"

class Goal {
	enum class Direction { NONE, UP, DOWN };

public:
	static const Direction Min = Direction::DOWN;
	static const Direction Max = Direction::UP;
	typedef double (*Function)(double, double);

	// FIXME other constructors, etc.
	explicit Goal(Direction d = Direction::NONE, Function f = nullptr) :
		objective(f), direction(d) { }

	Direction dir() const { return direction; }
	void set(const Function &f) { objective = f; }

	/*
	bool add(const Constraint &c) {
		return constraints.insert(c).second;
	}
	*/

	// TODO template <class... Types> double operator()(Types... args) { }
	double operator()(double x1, double x2) {
		return objective(x1, x2);
	}

private:
	Function objective;
	const Direction direction;
	std::unordered_set<Constraint> constraints;
};

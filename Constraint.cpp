#include "Constraint.h"

bool Constraint::operator==(const Constraint &) const {
	return true;
}

namespace std {

size_t hash<Constraint>::operator()(const Constraint &) const {
	return 0;
}

}

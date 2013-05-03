#include "Constraint.h"

namespace teh {

namespace ps {

bool Constraint::operator==(const Constraint &) const {
	return true;
}

} // namespace ps

} // namespace teh

namespace std {

using teh::ps::Constraint;

size_t hash<Constraint>::operator()(const Constraint &) const {
	return 0;
}

} // namespace std

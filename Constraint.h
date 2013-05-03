#ifndef _CONSTRAINT_H_
#define _CONSTRAINT_H_

#include <functional>

namespace teh {

namespace ps {

class Constraint {
	bool operator==(const Constraint &) const;
};

} // namespace ps

} // namespace teh

namespace std {

using teh::ps::Constraint;

template<> struct hash<Constraint> {
	size_t operator()(const Constraint &) const;
};

} // namespace std

#endif // _CONSTRAINT_H_

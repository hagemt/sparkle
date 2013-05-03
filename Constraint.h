#include <functional>

class Constraint {
	bool operator==(const Constraint &) const;
};

namespace std {
template<> struct hash<Constraint> {
	size_t operator()(const Constraint &) const;
};
}

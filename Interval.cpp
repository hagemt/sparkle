#include <iostream>
#include <sstream>

#include "Interval.h"
using namespace teh::ps;

// TODO isolate this in its own file
template <typename T> std::ostream &
operator<<(std::ostream &ostr, const Interval<T> &i) {
	return ostr << "[" << i.min << "," << i.max << ")";
}

int main(int argc, char *argv[]) {
	double number;
	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		if (ss >> number) {
			RealInterval interval(-number, number);
			std::cout << "A (uniform) random element of the real interval " <<
				interval << " is: " << interval.nextRandom() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}

#include <iostream>
#include <sstream>
#include <string>

#include "Interval.h"

template <typename T> std::ostream &
operator<<(std::ostream &ostr, const Interval<T> &i) {
	return ostr << "[" << i.min << "," << i.max << ")";
}

int main(int argc, char *argv[]) {
	for (int n, i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		if (ss >> n) {
			RealInterval interval(static_cast<double>(-n), static_cast<double>(n));
			std::cout << "A random element of the real interval " <<
				interval << " (uniform) is: " << interval.nextRandom() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}

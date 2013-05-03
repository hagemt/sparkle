#include "Goal.h"

static double
__rosenbrach(double x, double y)
{
	double a = (1. - x), b = (y - x * x);
	return (a * a) - 100. * (b * b);
}

const Goal ROSENBRACH(Goal::Min, &__rosenbrach);

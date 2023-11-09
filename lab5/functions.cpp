#include "functions.h"


double function_v5(const double& x) { return pow(sin(x), 2) / sqrt((1 + pow(x, 3))); }

double function_v30(const double& x, const double& y) { return 1 / pow(x + y, 2); }
#pragma once

#include <cmath>

using namespace std;

namespace simpson {
    double solve_integral(double (&fun) (const double&),
                          const double& a, const double& b,
                          const double& eps);
    double do_mid_calculations(double (&fun) (const double&),
                               const double& a, const double& b,
                               const int& n);
}
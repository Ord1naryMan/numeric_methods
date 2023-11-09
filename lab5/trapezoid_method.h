#pragma once

#include <cmath>

using namespace std;

namespace trapezoid {
    double do_mid_calculations(
            double (&fun)(const double&),
            const double& a, const double& b,
            const double& n);

    double solve_integral(
            double (&fun)(const double&),
          const double& a, const double& b,
          const int& eps);
}
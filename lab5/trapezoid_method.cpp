#include "trapezoid_method.h"

double trapezoid::do_mid_calculations(
        double (&fun)(const double&),
        const double& a, const double& b,
        const double& n) {
    double h = (b - a) / n;
    double mid_sum = 0;
    for (int i = 1; i < n - 1; i++) {
        mid_sum += fun(a + h * i);
    }

    return h * (fun(a) + 2 * mid_sum + fun(b)) / 2;
}

double trapezoid::solve_integral(double (&fun)(const double&),
                      const double& a, const double& b,
                      const int& eps) {
    int n = 10;
    double prev_integral_result = 0;
    double cur_integral_result = do_mid_calculations(fun, a, b, n);

    while (abs(prev_integral_result - cur_integral_result) > 3 * eps) {
        n *= 2;
        prev_integral_result = cur_integral_result;
        cur_integral_result = do_mid_calculations(fun, a, b, n);
    }

    return cur_integral_result;
}

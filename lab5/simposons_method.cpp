#include "simpsons_method.h"

double simpson::solve_integral(double (&fun) (const double&),
                               const double& a, const double& b,
                               const double& eps) {
    int n = 10;
    double prev_integral_result = 0;
    double cur_integral_result = simpson::do_mid_calculations(fun, a, b, n);

    while (abs(prev_integral_result - cur_integral_result) > 15 * eps) {
        n *= 2;
        prev_integral_result = cur_integral_result;
        cur_integral_result = simpson::do_mid_calculations(fun, a, b, n);
    }

    return cur_integral_result;
}

double simpson::do_mid_calculations(double (&fun)(const double &),
                                    const double &a, const double &b,
                                    const int &n) {

    int m = n / 2;
    double mid_sum1 = 0, mid_sum2 = 0;
    double h = (b - a) / n;

    for (int i = 1; i <= m; i++) {
        mid_sum1 += fun(a + h * double (2 * i - 1));
    }

    for (int i = 1; i <= m - 1; i++) {
        mid_sum2 += fun(a + h * double (2 * i));
    }

    return h * (fun(a) + 4 * mid_sum1 + 2 * mid_sum2 + fun(b)) / 3;
}
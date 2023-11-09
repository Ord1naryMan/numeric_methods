#include "cubic_simpsons_method.h"

double cubic_simpson::solve_integral(double (&fun) (const double&, const double&),
                               const double& a, const double& b,
                               const double& c, const double& d,
                               const double& eps) {
    int n = 10;
    double prev_integral_result = 0;
    double cur_integral_result = cubic_simpson::do_mid_calculations(fun, a, b, c, d, n);

    while (abs(prev_integral_result - cur_integral_result) > 15 * eps) {
        n *= 2;
        prev_integral_result = cur_integral_result;
        cur_integral_result = cubic_simpson::do_mid_calculations(fun, a, b, c, d, n);
    }

    return cur_integral_result;
}

double cubic_simpson::do_mid_calculations(double (&fun)(const double &, const double&),
                                    const double &a, const double &b,
                                    const double &c, const double &d,
                                    int n) {

    int m = n / 2;
    n = 2 * m;
    double hx = (b - a) / (2 * n), hy = (d - c) / (2 * m);
    double result = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            result += fun(a + double(2 * i) * hx, c + double(2 * j) * hy);
            result += 4 * fun(a + (double(2 * i - 1)) * hx, c + (double(2 * j)) * hy);
            result += fun(a + (double(2 * i + 2)) * hx, c + (double(2 * j)) * hy);
            result += 4 * fun(a + (double(2 * i)) * hx, c + (double(2 * j + 1)) * hy);
            result += 16 * fun(a + (double(2 * i + 1)) * hx, c + (double(2 * j + 1)) * hy);
            result += 4 * fun(a + (double(2 * i + 2)) * hx, c + (double(2 * j + 1)) * hy);
            result += fun(a + (double(2 * i)) * hx, c + (double(2 * j + 2)) * hy);
            result += 4 * fun(a + (double(2 * i + 1)) * hx, c + (double(2 * j + 2)) * hy);
            result += fun(a + (double(2 * i + 2)) * hx, c + (double(2 * j + 2)) * hy);
        }
    }

    return hx * hy * result / 9;
}
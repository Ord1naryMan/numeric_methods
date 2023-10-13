#include <iostream>
#include <cmath>
#include <vector>
#include "../lab1/functions.h"

using namespace std;

double f1(double x1, double x2) {
    return pow(x1, 3) + pow(x2, 3) - 6*x1 + 3;
}

double f2(double x1, double x2) {
    return pow(x1, 3) + pow(x2, 3) - 6*x2 + 2;
}

double df1_dx1(double x1) {
    return 3*pow(x1, 2) - 6;
}

double df1_dx2(double x2) {
    return 3*pow(x2, 2);
}

double df2_dx1(double x1) {
    return 3*pow(x1, 2);
}

double df2_dx2(double x2) {
    return 3*pow(x2, 2) - 6;
}

double mod_vec(vector<double> x) {
    double sum = 0;
    for (double xk : x) {
        sum += xk * xk;
    }
    return sqrt(sum);
}

//!!!! не общий вид т.к. нужно находить производные для матрицы якоби

vector<double> newtonMethod(double x1, double x2, double e1, double e2, int NIT) {
    vector<double> result;
    double x1k = x1;
    double x2k = x2;
    for (int k = 0; k < NIT; k++) {
        double res_f1k = f1(x1k, x2k);
        double res_f2k = f2(x1k, x2k);
        double J11k = df1_dx1(x1k);
        double J12k = df1_dx2(x2k);
        double J21k = df2_dx1(x1k);
        double J22k = df2_dx2(x2k);

        //J * dx = -F   we need to find dx
        //ветор невязки это по сути вектор решений F при xk
        vector<double> dx = solve({{J11k, J12k, -res_f1k}, {J21k, J22k, -res_f2k}});
        if (dx.empty()) {
            return result;
        }
        double dx1k = dx[0];
        double dx2k = dx[1];

        double new_x1k = x1k + dx1k;
        double new_x2k = x2k + dx2k;

        double d1 = max(abs(res_f1k), abs(res_f2k));
        double d2;

        if (mod_vec({new_x1k, new_x2k}) < 1) {
            d2 = max(abs(x1k - new_x1k), abs(x2k - new_x2k));
        } else {
            d2 = max(
                abs((x1k - new_x1k)/new_x1k),
                abs((x2k - new_x2k)/new_x2k)
            );
        }

        if (d1 <= e1 && d2 <= e2) {
            result.push_back(new_x1k);
            result.push_back(new_x2k);
            return result;
        }

        x1k = new_x1k;
        x2k = new_x2k;
    }
    cout << "Iteration quantity overflow" << endl;
    return result;
}

int main() {
    vector<double> result = newtonMethod(1, 1, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (1, 1): ("
        << result[0] << ", " << result[1] << ")"
        << endl;
    }
    result = newtonMethod(2, 1.5, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (2, 1.5): ("
             << result[0] << ", " << result[1] << ")"
             << endl;
    }
    result = newtonMethod(-3, -1.5, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (-3, -1.5): ("
             << result[0] << ", " << result[1] << ")"
             << endl;
    }
    result = newtonMethod(-3.5, -2, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (-3.5, -2): ("
             << result[0] << ", " << result[1] << ")"
             << endl;
    }
    result = newtonMethod(-2, -2, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (-2, -2): ("
             << result[0] << ", " << result[1] << ")"
             << endl;
    }
    result = newtonMethod(2, 2, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (2, 2): ("
             << result[0] << ", " << result[1] << ")"
             << endl;
    }
    result = newtonMethod(1.1, 1.1, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (1.1, 1.1): ("
             << result[0] << ", " << result[1] << ")"
             << endl;
    }
    result = newtonMethod(1.0001, 1.0001, pow(10,-9), pow(10,-9), 1000);
    if (!result.empty()) {
        cout << "Solution for x = (1.0001, 1.0001): ("
             << result[0] << ", " << result[1] << ")"
             << endl;
    }
    return 0;
}

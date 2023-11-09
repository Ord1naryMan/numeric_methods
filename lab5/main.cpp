#include <iostream>

#include "functions.h"
#include "simpsons_method.h"
#include "cubic_simpsons_method.h"
#include "trapezoid_method.h"

using namespace std;

int main() {
    cout << "Trapezoid method:" << endl;
    cout << "Epsilon = 1e-4: "
        << trapezoid::solve_integral(function_v5, 0.0, 1.234, 1e-4)
        << endl;
    cout << "Epsilon = 1e-5: "
        << trapezoid::solve_integral(function_v5, 0.0, 1.234, 1e-5)
        << endl;

    cout << endl;

    cout << "Simpsons method:" << endl;
    cout << "Epsilon = 1e-4: "
        << simpson::solve_integral(function_v5, 0.0, 1.234, 1e-4)
        << endl;
    cout << "Epsilon = 1e-5: "
        << simpson::solve_integral(function_v5, 0.0, 1.234, 1e-5)
        << endl;

    cout << endl;

    cout << "Cubic simpsons method (V 30):" << endl;
    cout << "Epsilon = 1e-4: "
        << cubic_simpson::solve_integral(
                function_v30, 3.0,
                4.0, 1.0,
                2.0, 1e-4
            )
        << endl;
    cout << "Epsilon = 1e-5: "
        << cubic_simpson::solve_integral(
                function_v30, 3.0,
                4.0, 1.0,
                2.0, 1e-5
            )
        << endl;

    cout << endl;
}
#include <iostream>

#include "functions.h"
#include "simpsons_method.h"
#include "cubic_simpsons_method.h"
#include "trapezoid_method.h"

using namespace std;

int main() {

    //https://www.kontrolnaya-rabota.ru/s/integral/opredelennyij/?top=1.234&function=sin%5E2%28x%29%2F%281+%2B+x%5E3%29%5E%281%2F2%29&X=x&bottom=0

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


    //https://calculator-online.org/doubleintegral?base_pod=integral.double&xtop=4&xbottom=3&x=x&ytop=2&ybottom=1&function_2=1%2F(x%2By)%5E2&y=y&function_1=4*x*y%20%2B%203*x%5E2*y%5E2&y_1=y&x_1=x&cond_1=y%20%3D%20x&cond_2=y%20%3D%202*x%20%2B%209&cond_3=x%5E2%20%3D%20y&cond_4=x%20%3E%200&cond_5=y%20%3E%200

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
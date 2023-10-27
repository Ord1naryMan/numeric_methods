#pragma once

#include<vector>
#include<iostream>
#include<cmath>

#include "../lab1/functions.h"

using namespace std;

bool isShowSteps;

double f1(double x1, double x2);

double f2(double x1, double x2);

double df1_dx1(double x1);

double df1_dx2(double x2);

double df2_dx1(double x1);

double df2_dx2(double x2);

double mod_vec(vector<double> x);

vector<double> newtonMethod(
        double x1,
        double x2,
        double e1,
        double e2,
        int NIT,
        double M,
        vector<vector<double>> (&jacobian_calc)(vector<double>, double)
);

vector<vector<double>> jacobian1(vector<double> x, double M);

vector<vector<double>> jacobian2(vector<double> x, double M);

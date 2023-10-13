#pragma once
#include<iostream>
#include<vector>

using namespace std;

void printMatrix(vector<vector<double>> &vector);

bool makeFirstOne(vector<vector<double>>& table, int row);

void makeZerosInCol(vector<vector<double>> &table, int col);

bool makeDiagonal(vector<vector<double>> &table);

vector<double> calculate(const vector<vector<double>>& table);

vector<double> solve(const vector<vector<double>>& table);

vector<double> residual_vec(const vector<vector<double>>& table, const vector<double>& ans);

vector<double> my_ans(const vector<vector<double>>& table, const vector<double>& ans);
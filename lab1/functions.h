#pragma once
#include<iostream>
#include<vector>

using namespace std;

void makeFirstOne(vector<vector<double>>& table, int row);

void makeZerosInCol(vector<vector<double>> &table, int col);

void makeDiagonal(vector<vector<double>> &table);

double* calculate(vector<vector<double>>& table);

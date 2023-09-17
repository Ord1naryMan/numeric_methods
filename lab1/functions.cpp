#include "functions.h"


void makeFirstOne(vector<vector<double>>& table, int row) {
	double first = table[row][row];
	for (int i = row; i < table[row].size(); i++) {
		table[row][i] /= first;
	}
}

void makeZerosInCol(vector<vector<double>> &table, int col) {
	for (int row = col + 1; row < table.size(); row++) {
		double fst = table[row][col];
		for (int i = col; i < table[0].size(); i++) {
			 table[row][i] -= table[col][i] * fst;
		}
	}
}

void makeDiagonal(vector<vector<double>> &table) {
	double len = min(table.size(), table[0].size());
	for (int i = 0; i < len; i++) {
		makeFirstOne(table, i);
		makeZerosInCol(table, i);
	}
}

double* calculate(vector<vector<double>>& table) {
	double* ans = new double[table.size() + 1];
	ans[table.size()] = 1;
	for (int i = table.size() - 1; i >= 0; i--) {
		ans[i] = table[i][table[0].size() - 1];
		for (int j = table[0].size() - 2; j > i; j--) { 
			ans[i] -= table[i][j] * ans[j];
		}
	}
	return ans;

}

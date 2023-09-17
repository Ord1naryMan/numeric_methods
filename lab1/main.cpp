#include<iostream>
#include<vector>
#include "functions.h"


using namespace std;

int main(int argc, char** argv) {
	vector<vector<double>> table = vector<vector<double>>();
	for (int i = 0; i < 3; i++) {
		table.push_back(vector<double>());
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			table[i].push_back(stof(argv[i * 4 + j + 1]));
		}
	}
	makeDiagonal(table);
	double* ans = calculate(table);

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}

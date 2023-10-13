#include "functions.h"


bool makeFirstOne(vector<vector<double>>& table, int row) {
	double first = table[row][row];
    if (first == 0) {
        cout << "NO ZERO IN DIAGONAL!!! / no solutions\n";
        printMatrix(table);
        return false;
    }
	for (int i = row; i < table[row].size(); i++) {
		table[row][i] /= first;
	}
    return true;
}

void makeZerosInCol(vector<vector<double>> &table, int col) {
	for (int row = col + 1; row < table.size(); row++) {
		double fst = table[row][col];
		for (int i = col; i < table[0].size(); i++) {
			 table[row][i] -= table[col][i] * fst;
		}
	}
}

bool makeDiagonal(vector<vector<double>> &table) {
	double len = min(table.size(), table[0].size());
	for (int i = 0; i < len; i++) {
		if (!makeFirstOne(table, i)) {
            return false;
        }
		makeZerosInCol(table, i);
    }
    return true;
}

void printMatrix(vector<vector<double>> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        for (int j = 0; j < vector[0].size(); j++) {
            cout << vector[i][j] << " ";
        }
        cout << endl;
    }
}

vector<double> calculate(const vector<vector<double>>& table) {
//	double* ans = new double[table.size()];
    vector<double> ans(table.size());
    ans[table.size() - 1] = 1;
	for (int i = table.size() - 1; i >= 0; i--) {
		ans[i] = table[i][table[0].size() - 1];
		for (int j = table[0].size() - 2; j > i; j--) { 
			ans[i] -= table[i][j] * ans[j];
		}
	}
	return ans;
}

vector<double> solve(const vector<vector<double>>& table) {
    vector<vector<double>> copy(table);
    if (!makeDiagonal(copy)) {
        return {};
    }
    return calculate(copy);
}

vector<double> residual_vec(const vector<vector<double>>& table, const vector<double>& ans) {
    vector<double> resid;
    for (int i = 0; i < table.size(); i++) {
        double my_res = 0;
        for (int j = 0; j < table[i].size() - 1; j++) {
            my_res += table[i][j] * ans[j];
        }
        resid.push_back(my_res - table[i][table[i].size() - 1]);
    }
    return resid;
}

vector<double> my_ans(const vector<vector<double>>& table, const vector<double>& ans) {
    vector<double> my_ans;
    for (int i = 0; i < table.size(); i++) {
        double my_res = 0;
        for (int j = 0; j < table[i].size() - 1; j++) {
            my_res += table[i][j] * ans[j];
        }
        my_ans.push_back(my_res);
    }
    return my_ans;
}
#include<iostream>
#include<vector>
#include "functions.h"


using namespace std;

int main(int argc, char** argv) {
	vector<vector<double>> table{};

    int rowCount = stoi(argv[1]);
    int colCount = stoi(argv[2]);

	for (int i = 0; i < rowCount; i++) {
		table.push_back(vector<double>());
	}
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			table[i].push_back(stof(argv[i * colCount + j + 3]));
		}
	}

    cout << "starting computation\n";
	vector<double> ans = solve(table);
    vector<double> resid = residual_vec(table, ans);
	for (int i = 0; i < rowCount; i++) {
		cout << ans[i] << " ";
	}

    cout << "\n resid vec\n";
    for (double i : resid) {
        cout << i << " ";
    }

    vector<double> my_ans_vec = my_ans(table, ans);

    vector<vector<double>> help_sys(table);
    for (int i = 0; i < table.size(); i++) {
        help_sys[i][table[i].size() - 1] = my_ans_vec[i];
    }

    vector<double> help_ans = solve(help_sys);

    double max_diff = INT_MIN, max_ans = INT_MIN;
    for (int i = 0; i < ans.size(); i++) {
        max_ans = max(max_ans, ans[i]);
        max_diff = max(max_diff, abs(ans[i] - help_ans[i]));
    }

    if (max_ans == 0) {
        cout << "NO!";
        exit(1);
    }
    double relative_error = max_diff / max_ans;

    cout << "\nrelative error: " << relative_error;

	return 0;
}

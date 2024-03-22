#ifndef ALGORITHM_LC2617_H
#define ALGORITHM_LC2617_H

#include "main.h"

class LC_2617 {
public:
	int minimumVisitedCells(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		dp[0][0] = 1;
		vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> row(m), col(n);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				while (!row[i].empty() && row[i].top().second + grid[i][row[i].top().second] < j) {
					row[i].pop();
				}

				while (!col[j].empty() && col[j].top().second + grid[col[j].top().second][j] < i) {
					col[j].pop();
				}

				if (!row[i].empty()) {
					dp[i][j] = dp[i][j] == -1 ?
							dp[i][row[i].top().second] + 1
							: min(dp[i][j], dp[i][row[i].top().second] + 1);
				}

				if (!col[j].empty()) {
					dp[i][j] = dp[i][j] == -1 ?
					           dp[col[j].top().second][j] + 1
	                           : min(dp[i][j], dp[col[j].top().second][j] + 1);
				}

				if (dp[i][j] != -1) {
					row[i].emplace(dp[i][j], j);
					col[i].emplace(dp[i][j], i);
				}
			}
		}

		return dp[m - 1][n - 1];
	}

	static void test() {
		vector<vector<int>> grid = {{3, 4, 2, 1}, {4, 2, 3, 1}, {2, 1, 0, 0}, {2, 4, 0, 0}};
		std::cout << LC_2617().minimumVisitedCells(grid) << std::endl;
		grid = {{3, 4, 2, 1}, {4, 2, 1, 1}, {2, 1, 1, 0}, {3, 4, 1, 0}};
		std::cout << LC_2617().minimumVisitedCells(grid) << std::endl;
		grid = {{2, 1, 0}, {1, 0, 0}};
		std::cout << LC_2617().minimumVisitedCells(grid) << std::endl;
	}
};

#endif //ALGORITHM_LC2617_H

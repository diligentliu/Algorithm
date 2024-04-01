#ifndef ALGORITHM_TX_5_H
#define ALGORITHM_TX_5_H

#include "main.h"

class TX_5 {
	void solution() {
		int m, n;
		cin >> m >> n;
		vector<string> grid(m);
		for (int i = 0; i < m; ++i) {
			cin >> grid[i];
		}

		vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		string s = "tencent";
		int ans = 0;

		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(s.size())));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				dp[i][j][0] = grid[i][j] == 't' ? 1 : 0;
			}
		}
		for (int k = 1; k < s.size(); ++k) {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] != s[k]) {
						continue;
					}
					for (auto &d : dirs) {
						int i_ = i + d[0], j_ = j + d[1];
						if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] == s[k - 1]) {
							dp[i][j][k]++;
						}
					}
					if (k == s.size() - 1) {
						ans += dp[i][j][k];
					}
				}
			}
		}
		cout << ans << endl;
	}
};

#endif //ALGORITHM_TX_5_H

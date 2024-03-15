#ifndef ALGORITHM_LC2312_H
#define ALGORITHM_LC2312_H

#include "main.h"

class LC_2312 {
public:
	long long sellingWood(int m, int n, vector<vector<int>>& prices) {
		long long dp[m + 1][n + 1];
		memset(dp, 0, sizeof(dp));
		unordered_map<long long, int> um;
		for (auto &price : prices) {
			um[(long long) price[0] << 32 | price[1]] = price[2];
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				long long index = (long long) i << 32 | j;
				if (um.count(index)) {
					dp[i][j] = um[index];
				}
				for (int k = 1; k < i; ++k) {
					dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
				}
				for (int k = 1; k < j; ++k) {
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
				}
			}
		}
		return dp[m][n];
	}

	static void test() {
		int m = 3, n = 5;
		vector<vector<int>> prices = {{1, 4, 2}, {2, 2, 7}, {2, 1, 3}};
		std::cout << LC_2312().sellingWood(m, n, prices) << std::endl;
	}
};


#endif //ALGORITHM_LC2312_H

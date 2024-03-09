#ifndef ALGORITHM_MT13_H
#define ALGORITHM_MT13_H

#include "main.h"

class MT_1_3 {
public:
	void solution() {
		int n;
		cin >> n;
		vector<string> graph(n);
		for (int i = 0; i < n; ++i) {
			cin >> graph[i];
		}
		vector<vector<int>> per_sum(n + 1, vector<int>(n + 1));
		vector<int> ans(n + 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int num = graph[i][j] - '0';
				per_sum[i + 1][j + 1] = per_sum[i + 1][j] + per_sum[i][j + 1]
						- per_sum[i][j] + (graph[i][j] - '0');
				for (int k = 2; k <= n; k += 2) {
					int cnt = k * k / 2;
					if (i + 1 - k >= 0 && j + 1 - k >= 0) {
						ans[k] += (per_sum[i + 1][j + 1] + per_sum[i + 1 - k][j + 1 - k]
								- per_sum[i + 1][j + 1 - k] - per_sum[i + 1 - k][j + 1] == cnt);
					} else {
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << endl;
		}
	}
};


#endif //ALGORITHM_MT13_H

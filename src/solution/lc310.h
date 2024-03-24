#ifndef ALGORITHM_LC310_H
#define ALGORITHM_LC310_H

#include "main.h"

class LC_310 {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
		vector<vector<int>> graph(n);
		vector<int> ans, degree(n);
		for (auto &edge: edges) {
			int u = edge[0], v = edge[1];
			graph[u].emplace_back(v);
			graph[v].emplace_back(u);
			++degree[u];
			++degree[v];
		}

		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (degree[i] <= 1) {
				q.emplace(i);
			}
		}

		int cnt = n;
		while (cnt > 2) {
			int m = q.size();
			cnt -= m;
			for (int i = 0; i < m; ++i) {
				int cur = q.front();
				q.pop();
				for (int &next: graph[cur]) {
					if (--degree[next] == 1) {
						q.emplace(next);
					}
				}
			}
		}
		while (!q.empty()) {
			ans.emplace_back(q.front());
			q.pop();
		}
		return ans;
	}

	static void test() {
		int n = 6;
		vector<vector<int>> edges = {{3, 0},
		                             {3, 1},
		                             {3, 2},
		                             {3, 4},
		                             {5, 4}};
		std::cout << LC_310().findMinHeightTrees(n, edges) << std::endl;
	}
};


#endif //ALGORITHM_LC310_H

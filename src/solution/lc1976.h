#ifndef ALGORITHM_LC1976_H
#define ALGORITHM_LC1976_H

#include "main.h"

class LC_1976 {
public:
	/*
	 * 稠密图朴素写法
	 */
	/*
	int countPaths(int n, vector<vector<int>>& roads) {
		vector<vector<long long>> graph(n, vector<long long>(n, LLONG_MAX >> 1));
		for (auto &road: roads) {
			int u = road[0], v = road[1], w = road[2];
			graph[u][v] = w;
			graph[v][u] = w;
		}

		vector<long long> dist(n, LLONG_MAX >> 1);
		dist[0] = 0;
		vector<int> dp(n);
		vector<bool> done(n);
		dp[0] = 1;
		while (true) {
			int x = -1;
			for (int i = 0; i < n; ++i) {
				if (!done[i] && (x < 0 || dist[i] < dist[x])) {
					x = i;
				}
			}
			if (x == n - 1) {
				return dp[n - 1];
			}
			done[x] = true;
			for (int y = 0; y < n; ++y) {
				long long new_dist = dist[x] + graph[x][y];
				if (new_dist < dist[y]) {
					dist[y] = new_dist;
					dp[y] = dp[x];
				} else if (new_dist == dist[y]) {
					dp[y] = (dp[y] + dp[x]) % 1'000'000'007;
				}
			}
		}
	}
	 */
	int countPaths(int n, vector<vector<int>> &roads) {
		vector<vector<pair<int, int>>> graph(n);
		for (auto &road: roads) {
			int x = road[0], y = road[1], d = road[2];
			graph[x].emplace_back(y, d);
			graph[y].emplace_back(x, d);
		}

		vector<ll> dist(n, LLONG_MAX);
		dist[0] = 0;
		vector<int> dp(n);
		dp[0] = 1;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
		pq.emplace(0, 0);
		while (true) {
			auto [d, x] = pq.top();
			pq.pop();
			if (x == n - 1) {
				return dp[x];
			}
			if (d > dist[x]) {
				continue;
			}
			for (auto &[y, w]: graph[x]) {
				ll new_dist = d + w;
				if (new_dist < dist[y]) {
					dist[y] = new_dist;
					dp[y] = dp[x];
					pq.emplace(new_dist, y);
				} else {
					dp[y] = (dp[y] + dp[x]) % MOD;
				}
			}
		}
	}

	static void test() {
		int n = 7;
		vector<vector<int>> roads = {{0, 6, 7},
		                             {0, 1, 2},
		                             {1, 2, 3},
		                             {1, 3, 3},
		                             {6, 3, 3},
		                             {3, 5, 1},
		                             {6, 5, 1},
		                             {2, 5, 1},
		                             {0, 4, 5},
		                             {4, 6, 2}};
		cout << LC_1976().countPaths(n, roads) << endl;
	}
};

#endif //ALGORITHM_LC1976_H

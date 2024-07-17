#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_2959 {
namespace Test {
int n = 3;
int maxDistance = 5;
vector<vector<int>> roads = {{0, 1, 20}, {0, 1, 10}, {1, 2, 2}, {0, 2, 2}};
}  // namespace Test

#endif

class Solution {
 public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX >> 1));
        for (int i = 0; i < n; ++i) {
            graph[i][i] = 0;
        }
        for_each(roads.begin(), roads.end(), [&](const auto& r) {
            int u = r[0], v = r[1], d = r[2];
            graph[u][v] = min(graph[u][v], d);
            graph[v][u] = graph[u][v];
        });

        vector<vector<int>> f(n);
        auto check = [&](int s) -> bool {
            for (int i = 0; i < n; ++i) {
                if ((s >> i) & 1) {
                    f[i] = graph[i];
                } else {
                    vector<int>().swap(f[i]);
                }
            }

            for (int k = 0; k < n; ++k) {
                if (f[k].empty()) {
                    continue;
                }
                for (int i = 0; i < n; ++i) {
                    if (f[i].empty()) {
                        continue;
                    }
                    for (int j = 0; j < n; ++j) {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                if (f[i].empty()) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (!f[j].empty() && f[i][j] > maxDistance) {
                        return false;
                    }
                }
            }
            return true;
        };

        int ans = 0;
        for (int s = 0; s < 1 << n; ++s) {
            ans += check(s);
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2959, numberOfSets(Test::n, Test::maxDistance, Test::roads));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2959
#endif

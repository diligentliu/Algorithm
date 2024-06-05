#ifndef ALGORITHM_LC3067_H
#define ALGORITHM_LC3067_H

#ifdef LSK_LOCAL
#include "main.h"

namespace LC_3067 {

namespace Test {
vector<vector<int>> edges = {{0, 1, 1},
                             {1, 2, 5},
                             {2, 3, 13},
                             {3, 4, 9},
                             {4, 5, 2}};
int signalSpeed = 1;
}  // namespace Test
#endif

class Solution {
 public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        for (const auto &edge: edges) {
            int a = edge[0], b = edge[1], weight = edge[2];
            graph[a].emplace_back(b, weight);
            graph[b].emplace_back(a, weight);
        }

        function<int(int, int, int)> dfs = [&](int x, int father, int sum) -> int {
            int cnt = sum % signalSpeed == 0;
            for (auto &[y, w]: graph[x]) {
                if (y != father) {
                    cnt += dfs(y, x, sum + w);
                }
            }
            return cnt;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                continue;
            }
            int sum = 0;
            for (auto &[y, w]: graph[i]) {
                int cnt = dfs(y, i, w);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
        return ans;
    }

#ifdef LSK_LOCAL
    TEST(LC_3067, countPairsOfConnectableServers(Test::edges, Test::signalSpeed));
};
}
#endif

#endif //ALGORITHM_LC3067_H

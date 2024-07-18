#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"
namespace LC_3112 {
namespace Test {
int n = 3;
vector<vector<int>> edges = {{0, 1, 2}, {1, 2, 1}, {0, 2, 4}};
vector<int> disappear = {1, 3, 5};
}  // namespace Test
#endif

class Solution {
 public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        vector<int> ans(n, INT_MAX);
        for_each(edges.begin(), edges.end(), [&](const auto& edge) {
            int u = edge[0], v = edge[1], t = edge[2];
            graph[u].emplace_back(v, t);
            graph[v].emplace_back(u, t);
        });

        ans[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [t, i] = pq.top();
            pq.pop();

            if (t > ans[i]) {
                continue;
            }

            for_each(graph[i].begin(), graph[i].end(),
                     [&t, &ans, &pq, &disappear](const auto& nn) {
                int next_t = nn.second + t;
                int j = nn.first;
                if (next_t < ans[j] && next_t < disappear[j]) {
                    ans[j] = next_t;
                    pq.emplace(next_t, j);
                }
            });
        }

        replace(ans.begin(), ans.end(), INT_MAX, -1);
        return ans;
    }
#ifdef LOCAL_LEETCODE
    TEST(LC_3112, minimumTime(Test::n, Test::edges, Test::disappear));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3112
#endif

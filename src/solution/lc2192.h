#pragma once

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class LC_2192 {
 public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);
        vector<set<int>> ordered_ans(n);
        for (auto &edge: edges) {
            int u = edge[0], v = edge[1];
            graph[v].push_back(u);
        }
        vector<bool> visited(n);
        function<void(int)> dfs = [&](int node) -> void {
            if (visited[node]) {
                return;
            }
            visited[node] = true;
            for (int &next: graph[node]) {
                dfs(next);
                ordered_ans[node].insert(next);
                ordered_ans[node].insert(ordered_ans[next].begin(), ordered_ans[next].end());
            }
        };

        for (int i = 0; i < n; ++i) {
            dfs(i);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i].insert(ans[i].begin(), ordered_ans[i].begin(), ordered_ans[i].end());
        }
        return ans;
    }

    static void test() {
        int n = 8;
        vector<vector<int>> edges = {{0, 3},
                                     {0, 4},
                                     {1, 3},
                                     {2, 4},
                                     {2, 7},
                                     {3, 5},
                                     {3, 6},
                                     {3, 7},
                                     {4, 6}};
        cout << LC_2192().getAncestors(n, edges) << endl;
    }
};

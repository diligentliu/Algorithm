#pragma once

#include "main.h"

class LC_2684 {
    constexpr const static int dirs[3][2] = {{-1, 1},
                                             {0,  1},
                                             {1,  1}};
 public:
    int maxMoves(vector<vector<int>> &grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        auto bfs = [&](int x, int y) {
            queue<pair<int, int>> q;
            q.emplace(x, y);
            int cnt = -1;
            while (!q.empty()) {
                int k = q.size();
                for (int i = 0; i < k; ++i) {
                    auto [row, col] = q.front();
                    q.pop();
                    for (auto &dir: dirs) {
                        int new_row = row + dir[0], new_col = col + dir[1];
                        if (new_row >= 0 && new_row < m &&
                            new_col >= 0 && new_col < n &&
                            !visited[new_row][new_col] && grid[new_row][new_col] > grid[row][col]) {
                            q.emplace(new_row, new_col);
                            visited[new_row][new_col] = true;
                        }
                    }
                }
                ++cnt;
            }
            ans = max(ans, cnt);
        };

        for (int i = 0; i < m; ++i) {
            bfs(i, 0);
        }
        return ans;
    }

    static void test() {
        vector<vector<int>> grid = {
                {2,  4, 3,  5},
                {5,  4, 9,  3},
                {3,  4, 2,  11},
                {10, 9, 13, 15}
        };
        std::cout << LC_2684().maxMoves(grid) << std::endl;
    }
};

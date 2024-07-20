#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"
namespace LC_2850 {
namespace Test {
vector<vector<int>> grid = {{1, 3, 0}, {1, 0, 0}, {1, 0, 3}};
}  // namespace Test
#endif

class Solution {
    static constexpr int dirs[9][4] = {{-1, 3, -1, 1},
                                       {-1, 4, 0, 2},
                                       {-1, 5, 1, -1},
                                       {0, 6, -1, 4},
                                       {1, 7, 3, 5},
                                       {2, 8, 4, -1},
                                       {3, -1, -1, 7},
                                       {4, -1, 6, 8},
                                       {5, -1, 7, -1}};
 public:
    int minimumMoves(vector<vector<int>>& grid) {
        std::string begin;
        std::queue<std::string> q;
        std::unordered_set<std::string> set;
        for_each(grid.begin(), grid.end(), [&](const auto& g) {
            for_each(g.begin(), g.end(), [&](const auto& v) {
                begin.push_back(static_cast<char>(v + '0'));
            });
        });

        int ans = 0;
        std::string res = "111111111";

        if (begin == res) {
            return 0;
        }

        q.emplace(begin);
        set.emplace(std::move(begin));

        while (!q.empty()) {
            ++ans;
            int n = q.size();
            for (int k = 0; k < n; ++k) {
                std::string cur = q.front();
                q.pop();
                std::string next = cur;

                for (int i = 0; i < 9; ++i) {
                    if (next[i] <= '1') {
                        continue;
                    }
                    for (int j = 0; j < 4; ++j) {
                        if (dirs[i][j] < 0) {
                            continue;
                        }
                        next[i] -= 1;
                        next[dirs[i][j]] += 1;
                        if (!set.count(next)) {
                            if (next == res) {
                                return ans;
                            }
                            q.emplace(next);
                            set.emplace(next);
                        }
                        next = cur;
                    }
                }
            }
        }
        return -1;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2850, minimumMoves(Test::grid));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2850
#endif

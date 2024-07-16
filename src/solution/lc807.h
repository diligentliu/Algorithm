#pragma once

#ifdef LOCAL_LEETCODE

#include "main.h"

namespace LC_807 {
namespace Test {
vector<vector<int>> grid = {{3, 0, 8, 4},
                            {2, 4, 5, 7},
                            {9, 2, 6, 3},
                            {0, 3, 1, 0}};
}  // namespace Test
#endif

class Solution {
 public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row_max(m, INT_MIN), col_max(n, INT_MIN);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int h = grid[i][j];
                row_max[i] = max(row_max[i], h);
                col_max[j] = max(col_max[j], h);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_807, maxIncreaseKeepingSkyline(Test::grid));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_807
#endif

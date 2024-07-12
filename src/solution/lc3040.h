#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3040 {

namespace Test {
vector<int> nums = {3, 2, 1, 4, 1};
}  // namespace Test

#endif

class Solution {
 public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<long long, int> map;
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int, const int&)> dfs = [&](int left, int right, const int& scores) -> int {
            if (right <= left) {
                return 0;
            }

            if (memo[left][right] >= 0) {
                return memo[left][right];
            }

            int ans = 0;
            if (nums[left] + nums[left + 1] == scores) {
                ans = 1 + dfs(left + 2, right, scores);
            }
            if (nums[left] + nums[right] == scores) {
                ans = max(ans, 1 + dfs(left + 1, right - 1, scores));
            }
            if (nums[right - 1] + nums[right] == scores) {
                ans = max(ans, 1 + dfs(left, right - 2, scores));
            }

            memo[left][right] = ans;
            return ans;
        };

        return 1 + max(dfs(2, n - 1, nums[0] + nums[1]),
                       max(dfs(1, n - 2, nums[0] + nums[n - 1]),
                           dfs(0, n - 3, nums[n - 2] + nums[n - 1])));
    }

#ifdef LOCAL_LEETCODE

    TEST(LC_3040, maxOperations(Test::nums));
#endif
};
#ifdef LOCAL_LEETCODE
}  // namespace LC_3040
#endif

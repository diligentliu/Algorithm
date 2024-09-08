#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3176 {
namespace Test {
vector<int> nums = {1, 2, 1, 1, 3};
int k = 2;
}  // namespace Test
#endif

class Solution {
 public:
    int maximumLength(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> dp;
        vector<array<int, 3>> records(k + 1);
        for (int& num : nums) {
            auto& f = dp[num];
            f.resize(k + 1);
            for (int j = k; j >= 0; --j) {
                f[j]++;
                if (j) {
                    auto& r = records[j - 1];
                    int mx = r[0], mx2 = r[1], y = r[2];
                    f[j] = max(f[j], (num != y ? mx : mx2) + 1);
                }

                // update records[j]
                if (f[j] > records[j][0]) {
                    if (num != records[j][2]) {
                        records[j][2] = num;
                        records[j][1] = records[j][0];
                    }
                    records[j][0] = f[j];
                } else if (num != records[j][2] && f[j] > records[j][1]) {
                    records[j][1] = f[j];
                }
            }
        }
        return records[k][0];
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3176, maximumLength(Test::nums, Test::k));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3176
#endif

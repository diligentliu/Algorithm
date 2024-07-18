#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3011 {
namespace Test {
vector<int> nums = {8, 4, 2, 30, 15};
}  // namespace Test

#endif

class Solution {
 public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int mx_ = INT_MIN;
        int mn = nums[0], mx = nums[0], m = __builtin_popcount(nums[0]);
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            int cnt = __builtin_popcount(num);
            if (cnt == m) {
                mn = min(mn, num), mx = max(mx, num);
            } else {
                if (mn < mx_) {
                    return false;
                }
                mx_ = mx;
                mn = num, mx = num;
                m = cnt;
            }
        }
        return mn >= mx_;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3011, canSortArray(Test::nums));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3011
#endif

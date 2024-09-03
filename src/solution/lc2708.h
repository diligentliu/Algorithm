#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_2708 {
namespace Test {
std::vector<int> nums = {3, -1, -5, 2, 5, -9};
}  // namespace Test
#endif

class Solution {
 public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1LL;
        bool has_res = false;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l + 1 < n) {
            int a = nums[l];
            int b = nums[l + 1];
            if (a < 0 && b < 0) {
                has_res = true;
                ans *= (long long) a * b;
                l += 2;
            } else {
                break;
            }
        }

        while (r >= 0 && nums[r] > 0) {
            has_res = true;
            ans *= (long long) nums[r--];
        }
        return has_res ? ans : nums.back();
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2708, maxStrength(Test::nums));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2708
#endif

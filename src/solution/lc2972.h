#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_2972 {

namespace Test {
vector<int> nums = {8, 7, 6, 6};
}  // namespace Test

#endif

class Solution {
 public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n - 1 && nums[i + 1] > nums[i]) {
            ++i;
        }
        if (i == n - 1) {
            return (long long) (n + 1) * n / 2;
        }

        long long ans = i + 2;
        for (int j = n - 1; j == n - 1 || nums[j] < nums[j + 1]; --j) {
            while (i >= 0 && nums[i] >= nums[j]) {
                --i;
            }
            ans += i + 2;
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2972, incremovableSubarrayCount(Test::nums));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2972
#endif
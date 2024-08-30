#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3153 {
namespace Test {
vector<int> nums = {13, 23, 12};
}  // namespace Test
#endif

class Solution {
 public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int tag = nums[0], cnt = 0;
        while (tag) {
            tag /= 10;
            ++cnt;
        }
        long long ans = 0;
        int set[cnt][10];
        memset(set, 0, sizeof(set));
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int j = 0;
            while (num) {
                int bit = num % 10;
                num = (num - bit) / 10;
                ans += i - set[j][bit];
                ++set[j][bit];
                ++j;
            }
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3153, sumDigitDifferences(Test::nums));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3153
#endif

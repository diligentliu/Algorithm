#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"
namespace LC_3133 {
namespace Test {
int n = 3, x = 4;
}  // namespace Test
#endif

class Solution {
 public:
    long long minEnd(int n, int x) {
        --n;
        long long ans = x;
        int i = 0, j = 0;
        while (n >> i) {
            if ((ans >> j & 1) == 0) {
                ans |= (long long) (n >> i & 1) << j;
                ++i;
            }
            ++j;
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3133, minEnd(Test::n, Test::x));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3133
#endif

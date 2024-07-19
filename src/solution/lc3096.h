#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3096 {
namespace Test {
vector<int> possible = {1, 1, 1, 1, 1};
}  // namespace Test
#endif

class Solution {
 public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        replace(possible.begin(), possible.end(), 0, -1);
        int sum = accumulate(possible.begin(), possible.end(), 0);
        int score = 0;
        for (int i = 0; i < n; ++i) {
            int p = possible[i];
            score += p;
            if (i != n - 1 && score > sum - score) {
                return i + 1;
            }
        }
        return -1;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3096, minimumLevels(Test::possible));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3096
#endif
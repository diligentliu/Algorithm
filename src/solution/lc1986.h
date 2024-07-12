#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_1986 {

namespace Test {
vector<int> tasks = {3, 1, 3, 1, 1};
int sessionTime = 8;
}  // namespace Test

#endif

class Solution {
 public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int m = 1 << n;
        vector<int> sum(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = 1 << i; j < k; ++j) {
                sum[j | k] = sum[j] + tasks[i];
            }
        }

        vector<int> f(m, n);
        f[0] = 0;
        for (int s = 0; s < m; ++s) {
            for (int sub = s; sub; sub = (sub - 1) & s) {
                if (sum[sub] <= sessionTime) {
                    f[s] = min(f[s], f[s ^ sub] + 1);
                }
            }
        }
        return f[m - 1];
    }

#ifdef LOCAL_LEETCODE

    TEST(LC_1986, minSessions(Test::tasks, Test::sessionTime));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_1986
#endif

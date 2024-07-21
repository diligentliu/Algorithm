#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_1186 {
namespace Test {
vector<int> arr = {1, -4, -5, -2, 5, 0, -1, 2};
}  // namespace Test
#endif

class Solution {
 public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return arr[0];
        }
        int no_delete = max(arr[0] + arr[1], arr[1]),
            one_delete = max(arr[0], arr[1]), ans = max(no_delete, one_delete);
        for (int i = 2; i < n; ++i) {
            int num = arr[i];
            int t = no_delete;
            no_delete = max(num, num + no_delete);
            one_delete = max(one_delete + num, t);
            ans = max(ans, max(no_delete, one_delete));
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_1186, maximumSum(Test::arr));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_1186
#endif

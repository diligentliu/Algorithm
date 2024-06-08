#ifndef ALGORITHM_LC927_H
#define ALGORITHM_LC927_H

#ifdef LOCAL_LEETCODE

#include "main.h"

namespace LC_927 {

namespace Test {
vector<int> arr = {1, 1, 1, 0, 1, 0, 0, 1, 0, 1,
                   0, 0, 0, 1, 0, 0, 1, 1, 1, 0,
                   1, 0, 0, 1, 0, 1, 0, 0, 0, 1,
                   0, 0, 0, 0, 1, 1, 1, 0, 1, 0,
                   0, 1, 0, 1, 0, 0, 0, 1, 0, 0};
}

#endif

class Solution {
 public:
    vector<int> threeEqualParts(vector<int> &arr) {
        int n = arr.size(), cnt = accumulate(arr.begin(), arr.end(), 0);
        if (cnt == 0) {
            return {0, 2};
        } else if (cnt % 3) {
            return {-1, -1};
        }

        cnt /= 3;

        vector<vector<int>> ans(2, vector<int>(3));
        int cnt_1 = 0, p = 0;
        for (int i = 0; i < n && p < 2; ++i) {
            cnt_1 += arr[i];
            if (cnt_1 == cnt) {
                cnt_1 = 0;
                ans[p][0] = i;
                int j = i + 1;
                while (j < n && !arr[j]) {
                    ++j;
                }
                ans[p][1] = j;
                ans[p++][2] = j - i - 1;
                i = j - 1;
            }
        }

        // 后缀 0
        int suffix = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i]) {
                break;
            }
            suffix++;
        }

        if (ans[0][2] < suffix || ans[1][2] < suffix) {
            return {-1, -1};
        }

        int i = 0, j = ans[0][1], k = ans[1][1];
        while (!arr[i]) {
            ++i;
        }

        if ((ans[0][0] - i != ans[1][0] - j) || (ans[0][0] - i != n - 1 - suffix - k)) {
            return {-1, -1};
        }

        while (i <= ans[0][0]) {
            if (arr[i] != arr[j++] || arr[i++] != arr[k++]) {
                return {-1, -1};
            }
        }

        return {ans[0][0] + suffix, ans[1][0] + suffix + 1};
    }

#ifdef LOCAL_LEETCODE

    TEST(LC_927, threeEqualParts(Test::arr));
#endif
};

#ifdef LOCAL_LEETCODE
}
#endif

#endif //ALGORITHM_LC927_H

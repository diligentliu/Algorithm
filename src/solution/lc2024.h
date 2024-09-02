#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_2024 {
namespace Test {
std::string answerKey = "TTFTTFTT";
int k = 1;
}  // namespace Test
#endif

class Solution {
 public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        auto check = [&](char c) -> int {
            int l = 0, r = 0, cnt = 0, ans = 0;
            while (r < n) {
                while (r < n && cnt <= k) {
                    cnt += (answerKey[r++] == c);
                }
                ans = max(ans, r - l - (cnt > k));
                cnt -= (answerKey[l++] == c);
            }
            return ans;
        };
        return max(check('F'), check('T'));
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2024, maxConsecutiveAnswers(Test::answerKey, Test::k));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2024
#endif
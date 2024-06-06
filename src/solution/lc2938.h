#ifndef ALGORITHM_LC2938_H
#define ALGORITHM_LC2938_H

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_2938 {

namespace Test {
string s = "10100";
}  // namespace Test

#endif

class Solution {
 public:
    enum State {
        ZERO,
        ONE
    };
    long long minimumSteps(string s) {
        long long num0 = 0, num1 = 0, ans = 0;
        State state = ZERO;
        for (const char &c : s) {
            switch (c) {
                case '0':
                    if (state == ZERO) {
                        ++num0;
                    } else {
                        state = ZERO;
                        num0 = 1;
                    }
                    break;
                case '1':
                    if (state == ZERO) {
                        state = ONE;
                        ans += num0 * num1;
                        num1++;
                        num0 = 0;
                    } else {
                        num1++;
                    }
                    break;
                default:
                    break;
            }
        }
        ans += num0 * num1;
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2938, minimumSteps(Test::s));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2938
#endif

#endif //ALGORITHM_LC2938_H

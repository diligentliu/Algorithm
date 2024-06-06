#ifndef ALGORITHM_LC1625_H
#define ALGORITHM_LC1625_H

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_1625 {

namespace Test {
string s = "5525";
int a = 9, b = 2;
}
#endif

class Solution {
 public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        unordered_set<string> visited;
        deque<string> queue;
        queue.emplace_back(s);
        visited.insert(s);
        while (!queue.empty()) {
            string front = queue.front();
            queue.pop_front();
            string t = front;
            for (int i = 0; i < n; ++i) {
                char &c = t[i];
                if (i % 2) {
                    c = (c - '0' + a) % 10 + '0';
                }
            }

            if (!visited.count(t)) {
                visited.insert(t);
                ans = min(ans, t);
                queue.emplace_back(std::move(t));
            }

            t = front;
            for (int i = 0; i < b; ++i) {
                char c = t[n - 1];
                for (int j = n - 1; j > 0; --j) {
                    t[j] = t[j - 1];
                }
                t[0] = c;
            }

            if (!visited.count(t)) {
                visited.insert(t);
                ans = min(ans, t);
                queue.emplace_back(std::move(t));
            }
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_1625, findLexSmallestString(Test::s, Test::a, Test::b));
#endif
};
#ifdef LOCAL_LEETCODE
}  // namespace LC_1625
#endif

#endif //ALGORITHM_LC1625_H

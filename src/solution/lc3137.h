#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3137 {
namespace Test {
std::string word = "leetcoleet";
int k = 2;
}  // namespace Test
#endif

class Solution {
 public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        int m = n / k, mx_cnt = 0;
        std::unordered_map<std::string, int> map;
        for (int i = 0; i < n; i += k) {
            std::string s(word, i, k);
            auto it = map.find(s);
            if (it == map.end()) {
                map[s] = 1;
                mx_cnt = std::max(mx_cnt, 1);
            } else {
                ++it->second;
                mx_cnt = std::max(mx_cnt, it->second);
            }
        }
        return m - mx_cnt;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3137, minimumOperationsToMakeKPeriodic(Test::word, Test::k));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3137
#endif

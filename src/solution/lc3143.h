#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3143 {
namespace Test {
vector<vector<int>> points = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
std::string s = "abdca";
}  // namespace Test
#endif

class Solution {
 public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        vector<pair<int, char>> sum;
        for (int i = 0; i < n; ++i) {
            sum.emplace_back(max(abs(points[i][0]), abs(points[i][1])), s[i]);
        }
        sort(sum.begin(), sum.end());
        unordered_set<char> had;
        int i = 0;
        while (i < n) {
            int len = sum[i].first;
            int t = i;
            while (i < n && sum[i].first == len) {
                if (had.contains(sum[i].second)) {
                    return t;
                }
                had.insert(sum[i].second);
                ++i;
            }
        }
        return n;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3143, maxPointsInsideSquare(Test::points, Test::s));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3143
#endif

#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3102 {

namespace Test {
vector<vector<int>> points = {{3, 10},
                              {5, 15},
                              {10, 2},
                              {4, 4}};
}  // namespace Test

#endif

class Solution {
 public:
    int minimumDistance(vector<vector<int>>& points) {
        vector<pair<int, int>> sums, subs;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            sums.emplace_back(x + y, i);
            subs.emplace_back(x - y, i);
        }
        sort(sums.begin(), sums.end());
        sort(subs.begin(), subs.end());
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int sum_max = sums[n - 1].second == i ? sums[n - 2].first : sums[n - 1].first;
            int sum_min = sums[0].second == i ? sums[1].first : sums[0].first;
            int sub_max = subs[n - 1].second == i ? subs[n - 2].first : subs[n - 1].first;
            int subs_min = subs[0].second == i ? subs[1].first : subs[0].first;
            ans = min(ans, max(sum_max - sum_min, sub_max - subs_min));
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3102, minimumDistance(Test::points));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_3102
#endif

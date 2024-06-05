#ifndef ALGORITHM_LC936_H
#define ALGORITHM_LC936_H

#ifdef LSK_LOCAL
#include "main.h"

namespace LC_936 {

namespace Test {
std::vector<std::vector<int>> points = {
        {3, 1},
        {1, 1},
        {0, 1},
        {2, 1},
        {3, 3},
        {3, 2},
        {0, 2},
        {2, 3}
};
}  // namespace LC_936
#endif

class Solution {
 public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_set<long long> set;
        for (const auto &point: points) {
            set.insert((long long) point[0] << 32 | point[1]);
        }

        double ans = INT_MAX;
        function<void(const vector<int>&, const vector<int>&, const vector<int>&)> update =
                [&](const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) -> void {
            int x1 = p3[0] + p2[0] - p1[0], y1 = p3[1] + p2[1] - p1[1];
            if (set.count((long long) x1 << 32 | y1)) {
                pair<int, int> p12 = {p2[0] - p1[0], p2[1] - p1[1]};
                pair<int, int> p13 = {p3[0] - p1[0], p3[1] - p1[1]};
                if (p12.first * p13.first + p12.second * p13.second == 0) {
                    double a = sqrt(pow(p12.first, 2) + pow(p12.second, 2));
                    double b = sqrt(pow(p13.first, 2) + pow(p13.second, 2));
                    double area = a * b;
                    ans = min(ans, area);
                }
            }
        };

        int n = points.size();
        for (int i = 0; i < n; ++i) {
            const auto &p1 = points[i];
            for (int j = i + 1; j < n; ++j) {
                const auto &p2 = points[j];
                for (int k = j + 1; k < n; ++k) {
                    const auto &p3 = points[k];
                    update(p3, p2, p1);
                    update(p3, p1, p2);
                    update(p2, p1, p3);
                    update(p2, p3, p1);
                    update(p1, p2, p3);
                    update(p1, p3, p2);
                }
            }
        }
        return abs(ans - INT_MAX) < 1e-5 ? 0.0 : ans;
    }

#ifdef LSK_LOCAL
    TEST(LC_936, minAreaFreeRect(Test::points));
#endif
};
#ifdef LSK_LOCAL
}  // namespace LC_936
#endif

#endif //ALGORITHM_LC936_H

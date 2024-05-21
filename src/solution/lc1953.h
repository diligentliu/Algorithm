#ifndef LC1953_H
#define LC1953_H

#include "main.h"

namespace LC_1953 {
class Solution {
 public:
    long long numberOfWeeks(vector<int> &milestones) {
        const long long &sum = accumulate(milestones.begin(), milestones.end(), 0LL);
        const long long &mx = *max_element(milestones.begin(), milestones.end());
        return mx > sum - mx + 1 ? (sum - mx) * 2 + 1 : sum;
    }

    static void test() {
        vector<int> milestones = {5, 2, 1};
        std::cout << Solution().numberOfWeeks(milestones) << std::endl;
    }
};
} // namespace LC_1953

#endif //LC1953_H

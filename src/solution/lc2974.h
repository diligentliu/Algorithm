#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_2974 {

namespace Test {
vector<int> nums = {5, 4, 2, 3};
}  // namespace Test

#endif

class Solution {
 public:
    vector<int> numberGame(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.end());
        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();
            if (pq.empty()) {
                ans.push_back(a);
                break;
            }
            int b = pq.top();
            pq.pop();
            ans.push_back(b);
            ans.push_back(a);
        }
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2974, numberGame(Test::nums));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2974
#endif
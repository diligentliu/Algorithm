#ifndef ALGORITHM_LC1793_H
#define ALGORITHM_LC1793_H

#include "main.h"

class LC_1793 {
 public:
    /*
     * 单调栈
     */
    /*
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0;
        int stack[n], left[n], top = 0;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (top > 0 && nums[stack[top - 1]] >= num) {
                --top;
            }
            left[i] = top > 0 ? i - stack[top - 1] - 1 : i;
            stack[top++] = i;
        }

        top = 0;
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            while (top > 0 && nums[stack[top - 1]] >= num) {
                --top;
            }
            int right = top > 0 ? stack[top - 1] - i : n - i;
            stack[top++] = i;
            if (i - left[i] <= k && k < i + right) {
                ans = max(ans, (left[i] + right) * num);
            }
        }
        return ans;
    }
     */
    /*
     * 双指针
     */
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = nums[k], min_h = nums[k];
        int i = k, j = k;
        for (int t = 0; t < n - 1; ++t) {
            if (j == n - 1 || i && nums[i - 1] > nums[j + 1]) {
                min_h = min(min_h, nums[--i]);
            } else {
                min_h = min(min_h, nums[++j]);
            }
            ans = max(ans, min_h * (j - i + 1));
        }
        return ans;
    }

    static void test() {
        vector<int> nums = {1, 4, 3, 7, 4, 5};
        int k = 3;
        std::cout << LC_1793().maximumScore(nums, k) << std::endl;
    }
};

#endif //ALGORITHM_LC1793_H

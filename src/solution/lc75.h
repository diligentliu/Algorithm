#pragma once

#include "main.h"

class LC_75 {
 public:
    void sortColors(std::vector<int> &nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1++]);
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }

    static void test() {
        std::vector<int> nums = {2, 0, 2, 1, 1, 0};
        LC_75().sortColors(nums);
        std::cout << nums << std::endl;
    }
};

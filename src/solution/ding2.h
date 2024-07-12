#pragma once

#include "main.h"

class Ding_2 {
 public:
    int binary_length(int num) {
        int len = 0;
        while (num) {
            num >>= 1;
            ++len;
        }
        return len;
    }

    bool solution(vector<int> &nums) {
        int n = nums.size(), binary_len[n], max_binary_len = 0;
        for (int i = 0; i < n; ++i) {
            binary_len[i] = binary_length(nums[i]);
            max_binary_len = max(max_binary_len, binary_len[i]);
        }
        bool ans = false;
        // 枚举最终相同数的二进制位长度
        for (int i = 1; i < max_binary_len; ++i) {
            // 确定最终相同数的二进制长度后, 这个相同的数绝对是每一位左移或者右移得到的
            int same_num = binary_len[0] > i ? (nums[0] >> (binary_len[0] - i)) : (nums[0] << (i - binary_len[0]));
            int cnt = i - binary_len[0];
            bool can = true;
            for (int j = 1; j < n; ++j) {
                int num = binary_len[j] > i ? (nums[j] >> (binary_len[j] - i)) : (nums[j] << (i - binary_len[j]));
                if (same_num != num) {
                    // 此时左移或右移到相同的二进制位数后仍然不相同, 所以直接 pass
                    can = false;
                    break;
                }
                cnt += i - binary_len[j];
            }
            if (can && cnt == 0) {
                // 这证明所有的数左移或右移后得到的数都是相同的, 且移动的位数和为0
                return true;
            }
        }
        return false;
    }

    static void test() {
        vector<int> nums1 = {1, 2, 4, 8, 16};
        vector<int> nums2 = {1, 2, 7, 4};
        std::cout << std::boolalpha << Ding_2().solution(nums1) << std::endl;
        std::cout << std::boolalpha << Ding_2().solution(nums2) << std::endl;
    }
};

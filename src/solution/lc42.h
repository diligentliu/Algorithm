#ifndef ALGORITHM_LC42_H
#define ALGORITHM_LC42_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LC_42 {
 public:
    /*
     * 动态规划
     * 对于每个位置雨水的高度等于两侧最高点的相对更小值
     * 维护两个数组分别表示左侧和右侧的最高点
     */
    /*
    int trap(vector<int> &height) {
        int n = height.size(), ans = 0;
        int left_max[n], right_max[n];
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
     */
    /*
     * 单调栈
     */
    /*
    int trap(vector<int> &height) {
        int n = height.size(), ans = 0;
        int stack[n], top = 0;
        for (int i = 0; i < n; ++i) {
            int h = height[i];
            while (top > 0 && height[stack[top - 1]] < h) {
                int base = height[stack[--top]];
                if (top == 0) {
                    break;
                }
                int left = stack[top - 1];
                int up = min(height[left], h);
                ans += (up - base) * (i - left - 1);
            }
            stack[top++] = i;
        }
        return ans;
    }
     */
    /*
     * 双指针
     *
     */
    int trap(vector<int> &height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        while (left < right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (height[left] < height[right]) {
                // left_max 是绝对正确的, 在 left 的右侧必然有比 left_max 高的值
                ans += left_max - height[left++];
            } else {
                // right_max 是绝对正确的, 在 right 的左侧必然有比 right_max 高的值
                ans += right_max - height[right--];
            }
        }
        return ans;
    }

    static void test() {
        vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        cout << LC_42().trap(height) << endl;
    }
};


#endif //ALGORITHM_LC42_H

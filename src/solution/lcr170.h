#ifndef ALGORITHM_LCR170_H
#define ALGORITHM_LCR170_H

#ifdef LSK_LOCAL
#include "main.h"

namespace LCR_170 {

namespace Test {
vector<int> record = {9, 7, 5, 4, 6};
}  // namespace Test
#endif

class Solution {
    vector<int> nums;
    int ans = 0;

    void merge(vector<int> &record, int l, int mid, int r) {
        int i = l, j = mid + 1;
        for (int k = l; k <= r; ++k) {
            if (i > mid) {
                nums[k] = record[j++];
            } else if (j > r) {
                nums[k] = record[i++];
                ans += r - mid;
            } else if (record[i] > record[j]) {
                nums[k] = record[j++];
            } else {
                nums[k] = record[i++];
                ans += j - mid - 1;
            }
        }
        copy(nums.begin() + l, nums.begin() + r + 1, record.begin() + l);
    }

    void sort(vector<int> &record, int l, int r) {
        if (l == r) {
            return;
        }
        int mid = l + ((r - l) >> 1);
        sort(record, l, mid);
        sort(record, mid + 1, r);
        merge(record, l, mid, r);
    }

 public:
    int reversePairs(vector<int> &record) {
        int n = record.size();
        nums.resize(n);
        sort(record, 0, n - 1);
        return ans;
    }

#ifdef LSK_LOCAL
    TEST(LCR_170, reversePairs(Test::record));
};
}  // namespace LCR_170
#endif

#endif //ALGORITHM_LCR170_H

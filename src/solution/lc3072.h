#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_3072 {

namespace Test {
vector<int> nums = {2, 1, 3, 3};
}  // namespace Test
#endif

class Fenwick {
 public:
    vector<int> tree;

    Fenwick(int n) : tree(n) {}

    void add(int i) {
        while (i < tree.size()) {
            tree[i]++;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i &= i - 1;
        }
        return sum;
    }
};

class Solution {
 public:
    vector<int> resultArray(vector<int> &nums) {
        auto sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> map;
        int i = 1;
        for (const int &num: sorted) {
            auto it = map.find(num);
            if (it == map.end()) {
                map[num] = i++;
            }
        }

        int m = map.size(), n = nums.size();
        vector<int> arr1{nums[0]}, arr2{nums[1]};
        Fenwick t1(m + 1), t2(m + 1);
        t1.add(map[nums[0]]), t2.add(map[nums[1]]);
        for (int i = 2; i < n; ++i) {
            int num = nums[i];
            int val = map[num];
            int gc1 = arr1.size() - t1.query(val);
            int gc2 = arr2.size() - t2.query(val);
            if (gc1 > gc2 || gc1 == gc2 && arr1.size() <= arr2.size()) {
                arr1.push_back(num);
                t1.add(val);
            } else {
                arr2.push_back(num);
                t2.add(val);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_3072, resultArray(Test::nums));
#endif
};
#ifdef LOCAL_LEETCODE
}  // namespace LC_3072
#endif

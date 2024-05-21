#ifndef LC826_H
#define LC826_H

#include "main.h"

namespace LC_826 {
class Solution {
 public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &workers) {
        vector<pair<int, int>> work;
        const int m = difficulty.size(), n = workers.size();
        for (int i = 0; i < m; ++i) {
            work.emplace_back(difficulty[i], profit[i]);
        }
        sort(work.begin(), work.end());
        vector<int> max_profit(m);
        max_profit[0] = work[0].first;
        for (int i = 1; i < m; ++i) {
            max_profit[i] = max(max_profit[i - 1], work[i].second);
        }

        int sum_profit = 0;
        for (int &worker: workers) {
            int i = upper_bound(work.begin(), work.end(), make_pair(worker, INT_MAX)) - work.begin();
            --i;
            if (i >= 0) {
                sum_profit += max_profit[i];
            }
        }
        return sum_profit;
    }

    static void test() {
        vector<int> difficulty = {2, 4, 6, 8, 10},
                profit = {10, 20, 30, 40, 50},
                worker = {4, 5, 6, 7};
        std::cout << Solution().maxProfitAssignment(difficulty, profit, worker) << endl;
    }
};
} // namespace LC_826

#endif //LC826_H

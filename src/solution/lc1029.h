#ifndef ALGORITHM_LC1029_H
#define ALGORITHM_LC1029_H

#include "main.h"

class LC_1029 {
public:
	int twoCitySchedCost(vector<vector<int>> &costs) {
		int sum = 0, n = costs.size(), mid = n >> 1;
		sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b) {
			return a[0] - a[1] > b[0] - b[1];
		});
		for (int i = 0; i < n; ++i) {
			auto &cost = costs[i];
			sum += i < mid ? cost[1] : cost[0];
		}
		return sum;
	}

	static void test() {
		vector<vector<int>> costs = {{515, 563},
		                             {451, 713},
		                             {537, 709},
		                             {343, 819},
		                             {855, 779},
		                             {457, 60},
		                             {650, 359},
		                             {631, 42}};
		cout << LC_1029().twoCitySchedCost(costs) << endl;
	}
};


#endif //ALGORITHM_LC1029_H

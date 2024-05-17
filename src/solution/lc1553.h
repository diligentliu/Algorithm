#ifndef ALGORITHM_LC1553_H
#define ALGORITHM_LC1553_H

#include "main.h"

namespace LC_1553 {
class Solution {
	unordered_map<int, int> memo;

	int dfs(int n) {
		if (n <= 1) return n;
		if (memo.count(n)) return memo[n];

		int result = 1 + n % 2 + dfs(n / 2);
		result = min(result, 1 + n % 3 + dfs(n / 3));
		memo[n] = result;
		return result;
	}

public:
	int minDays(int n) {
		return dfs(n);
	}

	static void test() {
		std::cout << Solution().minDays(3) << endl;
	}
};
}

#endif //ALGORITHM_LC1553_H

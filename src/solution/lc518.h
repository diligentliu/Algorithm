#ifndef ALGORITHM_LC518_H
#define ALGORITHM_LC518_H

#include "main.h"

class LC_518 {
public:
	int change(int amount, vector<int> &coins) {
		vector<int> dp(amount + 1);
		dp[0] = 1;
		for (int &coin : coins) {
			for (int i = coin; i <= amount; ++i) {
				dp[i] += dp[i - coin];
			}
		}
		return dp[amount];
	}

	static void test() {
		int amount = 5;
		vector<int> coins = {1, 2, 5};
		std::cout << LC_518().change(amount, coins) << endl;
	}
};

#endif //ALGORITHM_LC518_H

#ifndef ALGORITHM_LC322_H
#define ALGORITHM_LC322_H

#include "main.h"

class LC_322 {
public:
	int coinChange(vector<int> &coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int &coin : coins) {
				if (coin <= i) {
					dp[i] = min(dp[i], dp[i - coin] + 1);
				}
			}
		}
		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}

	static void test() {
		vector<int> coins = {1, 2, 5};
		int amount = 11;
		std::cout << LC_322().coinChange(coins, amount) << std::endl;
	}
};

#endif //ALGORITHM_LC322_H

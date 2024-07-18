#pragma once

#include "main.h"

class TX_4 {
 public:
    void solution() {
        int n, k;
        cin >> n >> k;
        vector<ll> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LONG_LONG_MIN));
        dp[0][0] = 0;
        vector<ll> pre_xor(n + 1);
        for (int i = 0; i < n; ++i) {
            pre_xor[i + 1] = pre_xor[i] ^ nums[i];
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k && j <= i; ++j) {
                for (int m = j - 1; m < i; ++m) {
                    dp[i][j] = max(dp[i][j], dp[m][j - 1] + (pre_xor[i] ^ pre_xor[m]));
                }
            }
        }

        cout << dp[n][k] << endl;
    }
};

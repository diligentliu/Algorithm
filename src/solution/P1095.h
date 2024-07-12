#pragma once

#include <iostream>
#include <vector>

void solution_p1095() {
    int m, s, t;
    std::cin >> m >> s >> t;
    std::vector<int> dp(t + 1, 0);
    for (int i = 0; i < t; ++i) {
        if (m >= 10) {
            dp[i + 1] = dp[i] + 60;
            m -= 10;
        } else {
            dp[i + 1] = dp[i];
            m += 4;
        }
    }
    for (int i = 0; i < t; ++i) {
        dp[i + 1] = std::max(dp[i + 1], dp[i] + 17);
    }
    if (dp[t] >= s) {
        std::cout << "Yes" << std::endl;
        for (int i = t; i >= 0; --i) {
            if (dp[i] < s) {
                std::cout << i + 1 << std::endl;
                break;
            }
        }
    } else {
        std::cout << "No" << std::endl << dp[t] << std::endl;
    }
}

#ifndef ALGORITHM_LC2834_H
#define ALGORITHM_LC2834_H

#include "main.h"

class LC_2834 {
 public:
    int minimumPossibleSum(int n, int target) {
        const int mod = 1e9 + 7;
        int m = target / 2;
        if (n <= m) {
            return (long long) (1 + n) * n / 2 % mod;
        }
        return ((long long) (1 + m) * m / 2 +
                ((long long) target + target + (n - m) - 1) * (n - m) / 2) % mod;
    }

    static void test() {
        int n = 3, target = 3;
        cout << LC_2834().minimumPossibleSum(n, target) << endl;
    }
};

#endif //ALGORITHM_LC2834_H

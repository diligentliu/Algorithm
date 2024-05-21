#ifndef ALGORITHM_LC1702_H
#define ALGORITHM_LC1702_H

#include "main.h"

class LC_1702 {
 public:
    string maximumBinaryString(string binary) {
        int cnt = 0, n = binary.size(), first_zero = 0;
        while (binary[first_zero] == '1') {
            ++first_zero;
        }
        for (int i = first_zero; i < n; ++i) {
            cnt += binary[i] - '0';
        }
        string ans(n, '0');
        for (int i = 0; i < first_zero; ++i) {
            ans[i] = '1';
        }
        for (int i = first_zero; i < n - cnt - 1; ++i) {
            ans[i] = '1';
        }
        for (int i = n - cnt; i < n; ++i) {
            ans[i] = '1';
        }
        return ans;
    }

    static void test() {
        string binary = "111110000";
        cout << LC_1702().maximumBinaryString(binary) << endl;
    }
};


#endif //ALGORITHM_LC1702_H

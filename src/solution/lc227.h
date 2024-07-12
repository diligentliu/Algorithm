#pragma once

#include "main.h"

class LC_227 {
 public:
    int calculate(string s) {
        int num = 0, n = s.size();
        char pre_sign = '+';
        vector<int> stack;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c) && c != ' ' || i == n - 1) {
                switch (pre_sign) {
                    case '+':
                        stack.push_back(num);
                        break;
                    case '-':
                        stack.push_back(-num);
                        break;
                    case '*':
                        stack.back() *= num;
                        break;
                    default:
                        stack.back() /= num;
                }
                num = 0;
                pre_sign = c;
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }

    static void test() {
        string s = " 3+5 / 2 ";
        cout << LC_227().calculate(s) << endl;
    }
};

#pragma once

#include "main.h"

// 224. 基本计算器
class LC_224 {
    void calc(stack<int> &nums, stack<char> &ops) {
        if (nums.size() < 2 || ops.empty()) {
            return;
        }
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        nums.push(op == '+' ? a + b : a - b);
    }

 public:
    int calculate(string str) {
        int m = str.size();
        string s;
        for (char &c: str) {
            if (c != ' ') {
                s.push_back(c);
            }
        }
        stack<int> nums;
        nums.push(0);
        stack<char> ops;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == ' ') {
                continue;
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (!ops.empty()) {
                    char op = ops.top();
                    if (op != '(') {
                        calc(nums, ops);
                    } else {
                        ops.pop();
                        break;
                    }
                }
            } else {
                if (isdigit(c)) {
                    int cur_num = 0;
                    int j = i;
                    while (j < n && isdigit(s[j])) {
                        cur_num = cur_num * 10 + (s[j++] - '0');
                    }
                    nums.push(cur_num);
                    i = j - 1;
                } else {
                    if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        nums.push(0);
                    }
                    while (!ops.empty() && ops.top() != '(') {
                        calc(nums, ops);
                    }
                    ops.push(c);
                }
            }
        }
        while (!ops.empty()) {
            calc(nums, ops);
        }
        return nums.top();
    }

    static void test() {
        string s = "2-4-(8+2-6+(8+4-(1)+8-10))";
        cout << LC_224().calculate(s) << endl;
    }
};

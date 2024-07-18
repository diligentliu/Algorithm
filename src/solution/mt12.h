#pragma once

#include "main.h"

class MT_1_2 {
    void solution(long long per_sum, int cnt) {
        int l, r;
        cin >> l >> r;
        cout << per_sum + l * cnt << " " << per_sum + r * cnt << endl;
    }
};

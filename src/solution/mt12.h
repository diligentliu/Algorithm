#ifndef ALGORITHM_MT12_H
#define ALGORITHM_MT12_H

#include "main.h"

class MT_1_2 {
	void solution(long long per_sum, int cnt) {
		int l, r;
		cin >> l >> r;
		cout << per_sum + l * cnt << " " << per_sum + r * cnt << endl;
	}
};


#endif //ALGORITHM_MT12_H

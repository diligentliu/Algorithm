#ifndef ALGORITHM_MT11_H
#define ALGORITHM_MT11_H

#include "main.h"

class MT_1_1 {
	int solution() {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ans = 0;
		for (char &c: s) {
			if (c == 'M' || c == 'T') {
				ans++;
			}
		}
		return min(ans + k, n);
	}
};


#endif //ALGORITHM_MT11_H

#ifndef ALGORITHM_MT14_H
#define ALGORITHM_MT14_H

#include "main.h"

class MT_1_4 {
public:
	int count_factor(int n, int f) {
		int count = 0;
		while (n % f == 0 && n > 0) {
			++count;
			n /= f;
		}
		return count;
	}

	void solution() {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for (int &num: nums) {
			cin >> num;
		}

		vector<int> count_two(n + 1), count_five(n + 1);
		for (int i = 0; i < n; ++i) {
			count_two[i + 1] = count_two[i] + count_factor(nums[i], 2);
			count_five[i + 1] = count_five[i] + count_factor(nums[i], 5);
		}

		if (min(count_two[n], count_five[n]) < k) {
			cout << 0 << endl;
			return;
		}
		long long ans = 0;
		for (int left = 0, right = 0; left < n; ++left) {
			while (right < n && min(count_two[n] - (count_two[right + 1] - count_two[left]),
			                        count_five[n] - (count_five[right + 1] - count_five[left])) >= k) {
				++right;
			}
			ans += (right - left);
		}

		cout << ans << endl;
	}
};


#endif //ALGORITHM_MT14_H

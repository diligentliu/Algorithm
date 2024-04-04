#ifndef ALGORITHM_CF_936_2_A_H
#define ALGORITHM_CF_936_2_A_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void CF_936_2_A() {
	int m, n;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> n;
		vector<int> nums(n);
		for (int j = 0; j < n; ++j) {
			cin >> nums[j];
		}
		sort(nums.begin(), nums.end());
		int mid = nums[(n - 1) >> 1];
		cout << upper_bound(nums.begin(), nums.end(), mid) - nums.begin() - ((n - 1) >> 1) << endl;
	}
}
/*
int main() {
	CF_936_2_A();
	return 0;
}
 */

#endif //ALGORITHM_CF_936_2_A_H

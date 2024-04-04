#ifndef ALGORITHM_CF_936_2_B_H
#define ALGORITHM_CF_936_2_B_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int mod = 1e9 + 7;

void CF_936_2_B() {
	int m, n, k;
	function<long long(vector<int> &)> solution = [&](vector<int> &nums) -> long long {
		long long sum = 0LL;
		long long max_sum_subarray = 0, pre = 0;
		for (int &num : nums) {
			sum = (sum + num) % mod;
			pre = max(pre + num, 0LL + num);
			max_sum_subarray = max(max_sum_subarray, pre);
		}
		function<int(int)> e_mod = [](int k) -> int {
			long long ans = 1, a = 2;
			while (k) {
				if (k & 1) {
					ans = (ans * a) % mod;
					--k;
				}
				k >>= 1;
				a = a * a % mod;
			}
			return ans;
		};
		max_sum_subarray = max_sum_subarray % mod;
		for (int i = 0; i < k; ++i) {
			sum = (sum + (max_sum_subarray * e_mod(i)) % mod) % mod;
		}
		return sum;
	};
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> n >> k;
		vector<int> nums(n);
		for (int j = 0; j < n; ++j) {
			cin >> nums[j];
		}
		cout << (solution(nums) + mod) % mod << endl;
	}
}

int main() {
	CF_936_2_B();
	return 0;
}

#endif //ALGORITHM_CF_936_2_B_H

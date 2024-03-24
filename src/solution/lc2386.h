#ifndef ALGORITHM_LC2386_H
#define ALGORITHM_LC2386_H

#include "main.h"

class LC_2386 {
public:
	long long kSum(vector<int> &nums, int k) {
		long long sum = 0;
		for (int &num: nums) {
			if (num >= 0) {
				sum += num;
			} else {
				num = -num;
			}
		}

		sort(nums.begin(), nums.end());

		auto check = [&](long long sum_limit) -> bool {
			int cnt = 1;
			function<void(int, long long)> dfs = [&](int i, long long s) {
				if (cnt == k || i == nums.size() || s + nums[i] > sum_limit) {
					return;
				}
				++cnt;
				dfs(i + 1, s + nums[i]);    // 选
				dfs(i + 1, s);              // 不选
			};
			dfs(0, 0);
			return cnt == k;
		};

		long long l = 0, r = accumulate(nums.begin(), nums.end(), 0LL), ans = 0;
		while (l <= r) {
			long long mid = l + ((r - l) >> 1);
			if (check(mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return sum - ans;
	}

	static void test() {
		vector<int> nums = {2, 4, -2};
		int k = 5;
		cout << LC_2386().kSum(nums, k) << endl;
	}
};

#endif //ALGORITHM_LC2386_H

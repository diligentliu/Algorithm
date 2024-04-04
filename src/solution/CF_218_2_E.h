#ifndef ALGORITHM_CF_218_2_E_H
#define ALGORITHM_CF_218_2_E_H

/**
 * https://codeforces.com/problemset/problem/371/E
 *
 * 输入 n(3≤n≤3e5) 和长为 n 的数组 x(-1e8≤x[i]≤1e8)，然后输入 k(2≤k≤n-1)。
 * 一维数轴上有 n 个点，第 i 个点位于 x[i]。从中选择 k 个点，最小化这 k 个点的两两距离之和。
 * 输出这 k 个点的下标（按照输入顺序，从 1 开始）。多解输出任意解。
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void cf_218_2_e() {
	int n, k;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> nums[i]; 
	}
	std::vector<int> indices(n);
	std::iota(indices.begin(), indices.end(), 0);
	std::sort(indices.begin(), indices.end(), [&](const int &i, const int &j) {
		return nums[i] < nums[j];
	});
	std::cin >> k;
	long long sum_nums = 0LL, sum_distance = 0LL, ans_distance = 0LL;
	int ans_index = 0;
	for (int i = 0; i < k; ++i) {
		int num = nums[indices[i]];
		sum_distance += (long long) i * num - sum_nums;
		sum_nums += num;
	}
	ans_distance = sum_distance;
	for (int i = k; i < n; ++i) {
		int remove_num = nums[indices[i - k]];
		int add_num = nums[indices[i]];
		sum_nums -= remove_num;
		sum_distance = sum_distance - sum_nums + 1LL * (k - 1) * remove_num + 1LL * (k - 1) * add_num - sum_nums;
		sum_nums += add_num;
		if (ans_distance > sum_distance) {
			ans_index = i - k + 1;
			ans_distance = sum_distance;
		}
	}
	for (int i = ans_index; i < ans_index + k; ++i) {
		std::cout << indices[i] + 1 << " ";
	}
	std::cout << std::endl;
}
/*
	int main() {
		cf_218_2_e();
		return 0;
	}
 */

#endif //ALGORITHM_CF_218_2_E_H

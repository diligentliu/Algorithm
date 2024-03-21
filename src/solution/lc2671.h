#ifndef ALGORITHM_LC2671_H
#define ALGORITHM_LC2671_H

#include "main.h"

class FrequencyTracker {
	unordered_map<int, int> nums;
	unordered_map<int, int> freq;
public:
	FrequencyTracker() { }

	void add(int number) {
		--freq[nums[number]];
		++freq[++nums[number]];
	}

	void deleteOne(int number) {
		if (!nums[number]) {
			return;
		}
		--freq[nums[number]];
		++freq[--nums[number]];
	}

	bool hasFrequency(int frequency) {
		return freq[frequency];
	}
};

#endif //ALGORITHM_LC2671_H

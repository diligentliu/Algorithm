#pragma once

#include "main.h"

class FrequencyTracker {
    unordered_map<int, int> nums;
    unordered_map<int, int> freq;
 public:
    FrequencyTracker() {}

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

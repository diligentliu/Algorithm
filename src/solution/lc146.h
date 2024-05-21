#ifndef ALGORITHM_LC146_H
#define ALGORITHM_LC146_H

#include "main.h"

class LC_146 {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
 public:
    LC_146(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.count(key)) {
            auto it = map[key];
            int value = it->second;
            // 将 it 指向的元素移到链表头部
            cache.erase(it);
            cache.emplace_front(key, value);
            map[key] = cache.begin();
            return value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (map.count(key)) {
            auto it = map[key];
            cache.erase(it);
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        } else {
            cache.emplace_front(key, value);
            map[key] = cache.begin();
            if (cache.size() > capacity) {
                auto it = cache.rbegin();
                map.erase(it->first);
                cache.pop_back();
            }
        }
    }
};

#endif //ALGORITHM_LC146_H
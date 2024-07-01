#ifndef ALGORITHM_MAIN_H
#define ALGORITHM_MAIN_H

#include "stdc++.h"
#include "ListNode.h"
#include "TreeNode.h"

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

/*
 * 测试宏, 形如
 *  static void test() {
 *      std::cout << LC_3072::Solution::solution() << std::endl;
 *  }
 */
#define TEST(NAMESPACE, FUNCTION) \
    static void test() { \
        std::cout << NAMESPACE::Solution().FUNCTION << std::endl; \
    }

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> &vec) {
    out << '[';
    for (const auto &row: vec) {
        out << row << ", ";
    }
    out << "\b\b]";
    return out;
}

#endif //ALGORITHM_MAIN_H

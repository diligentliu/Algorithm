#include "solution.h"

int main() {
#ifdef LOCAL_LEETCODE
    LC_328::Solution::test();
#else
    std::cout << "Hello, World!" << std::endl;
#endif
    return 0;
}

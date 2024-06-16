#include "main.h"
#include "solution.h"

int main() {
#ifdef LOCAL_LEETCODE
    LC_1986::Solution::test();
#else
    std::cout << "Hello, World!" << std::endl;
#endif
    return 0;
}

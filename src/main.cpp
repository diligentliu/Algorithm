#include "main.h"
#include "solution.h"

int main() {
#ifdef LSK_LOCAL
    LC_1625::Solution::test();
#else
    std::cout << "Hello, World!" << std::endl;
#endif
    return 0;
}

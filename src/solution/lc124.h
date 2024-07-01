#ifndef ALGORITHM_LC124_H
#define ALGORITHM_LC124_H

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_124 {

namespace Test {
std::string s = "[-10,9,20,null,null,15,7]";
std::unique_ptr<TreeNode> root = std::make_unique<TreeNode>(Test::s);
}  // namespace Test
#endif

class Solution {
    int ans = INT_MIN;
 public:
    int maxPathSum(TreeNode* root) {
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
            if (node == nullptr) {
                return 0;
            }
            int val = node->val;
            int left = max(0, dfs(node->left));
            int right = max(0, dfs(node->right));
            ans = max(ans, val + left + right);
            return val + max(left, right);
        };
        dfs(root);
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_124, maxPathSum(Test::root.get()));
#endif
};
#ifdef LOCAL_LEETCODE
}  // namespace LC_124
#endif

#endif  // ALGORITHM_LC124_H

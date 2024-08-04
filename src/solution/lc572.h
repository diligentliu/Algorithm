#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_572 {
namespace Test {
std::string s = "[3,4,5,1,2]", t = "[4,1,2]";
std::unique_ptr<TreeNode> root = std::make_unique<TreeNode>(Test::s);
std::unique_ptr<TreeNode> subRoot = std::make_unique<TreeNode>(Test::t);
}  // namespace Test
#endif

class Solution {
 public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        function<bool(TreeNode*, TreeNode*)> check = [&](TreeNode* node, TreeNode* sub_node) -> bool {
            if (node == nullptr || sub_node == nullptr) {
                return node == nullptr && sub_node == nullptr;
            }
            if (node->val == sub_node->val) {
                return check(node->left, sub_node->left) && check(node->right, sub_node->right);
            }
            return false;
        };

        function<bool(TreeNode*)> dfs = [&](TreeNode* node) -> bool {
            if (node == nullptr) {
                return false;
            }
            if (node->val == subRoot->val) {
                bool ret = check(node, subRoot);
                if (ret) {
                    return ret;
                }
            }
            return dfs(node->left) || dfs(node->right);
        };

        return dfs(root);
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_572, isSubtree(Test::root.get(), Test::subRoot.get()));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_572
#endif

#ifndef ALGORITHM_LC1026_H
#define ALGORITHM_LC1026_H

#include "main.h"

class LC_1026 {
public:
	int maxAncestorDiff(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int ans = 0;
		function<void(TreeNode *, int, int)> dfs = [&](TreeNode* node, int min_value, int max_value) -> void {
			if (node == nullptr) {
				ans = max(ans, max_value - min_value);
				return;
			}
			max_value = max(max_value, node->val);
			min_value = min(min_value, node->val);
			dfs(node->left, min_value, max_value);
			dfs(node->right, min_value, max_value);
		};
		dfs(root, INT_MAX, INT_MIN);
		return ans;
	}

	static void test() {
		string s = "[8,3,10,1,6,null,14,null,null,4,7,13]";
		TreeNode *root = new TreeNode(s);
		cout << LC_1026().maxAncestorDiff(root) << endl;
		delete root;
	}
};


#endif //ALGORITHM_LC1026_H

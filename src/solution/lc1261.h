#ifndef ALGORITHM_LC1261_H
#define ALGORITHM_LC1261_H

#include "main.h"

class FindElements {
	TreeNode *root;
public:
	FindElements(TreeNode *root) : root(root) {}

	bool find(int target) {
		target++;
		auto cur = root;
		for (int i = 30 - __builtin_clz(target); i >= 0; --i) {
			int bit = target >> i & 1;
			cur = bit ? cur->right : cur->left;
			if (cur == nullptr) {
				return false;
			}
		}
		return true;
	}
};


#endif //ALGORITHM_LC1261_H

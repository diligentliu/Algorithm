#ifndef ALGORITHM_TX_2_H
#define ALGORITHM_TX_2_H

#include "main.h"

class TX_2 {
public:
	bool canSorted(ListNode *list) {
		int cnt = 0;

		int pre = INT_MIN;
		ListNode *p = list;
		while (p != nullptr) {
			if (p->val < pre) {
				cnt++;
			}
			pre = p->val;
			p = p->next;
		}

		return cnt <= 1;
	}

	vector<bool> canSorted(vector<ListNode*>& lists) {
		int n = lists.size();
		vector<bool> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = canSorted(lists[i]);
		}
		return ans;
	}
};

#endif //ALGORITHM_TX_2_H

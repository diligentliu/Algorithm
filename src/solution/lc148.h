#ifndef ALGORITHM_LC148_H
#define ALGORITHM_LC148_H

#include "main.h"

class LC_148 {
public:
	/*
	 * 递归写法, 时间复杂度 O(n log n), 空间复杂度 O(log n)
	 */
	/*
	ListNode *find_mid(ListNode *head, ListNode *tail) {
		ListNode *fast = head, *slow = head;
		while (fast != tail) {
			slow = slow->next;
			fast = fast->next;
			if (fast != tail) {
				fast = fast->next;
			}
		}
		return slow;
	}

	ListNode *merge(ListNode *front, ListNode *back) {
		ListNode *dummy = new ListNode(-1);
		ListNode *p = front, *q = back, *r = dummy;
		while (p != nullptr && q != nullptr) {
			if (p->val <= q->val) {
				r->next = p;
				p = p->next;
			} else {
				r->next = q;
				q = q->next;
			}
			r = r->next;
		}
		if (p != nullptr) {
			r->next = p;
		} else if (q != nullptr) {
			r->next = q;
		}
		r = dummy->next;
		dummy->next = nullptr;
		delete dummy;
		return r;
	}

	ListNode *sortList(ListNode* head, ListNode *tail) {
		if (head == nullptr) {
			return nullptr;
		} else if (head->next == tail) {
			head->next = nullptr;
			return head;
		}
		ListNode *mid = find_mid(head, tail);
		ListNode *front = sortList(head, mid);
		ListNode *back = sortList(mid, tail);
		return merge(front, back);
	}

	ListNode *sortList(ListNode* head) {
		return sortList(head, nullptr);
	}
	 */
	/*
	 * 非递归写法 空间复杂度 O(1)
	 */
	ListNode *merge(ListNode *front, ListNode *back) {
		ListNode *dummy = new ListNode(-1);
		ListNode *p = front, *q = back, *r = dummy;
		while (p != nullptr && q != nullptr) {
			if (p->val <= q->val) {
				r->next = p;
				p = p->next;
			} else {
				r->next = q;
				q = q->next;
			}
			r = r->next;
		}
		if (p != nullptr) {
			r->next = p;
		} else if (q != nullptr) {
			r->next = q;
		}
		r = dummy->next;
		dummy->next = nullptr;
		delete dummy;
		return r;
	}

	ListNode *sortList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		int length = 0;
		ListNode *node = head;
		while (node != nullptr) {
			++length;
			node = node->next;
		}
		ListNode *dummy = new ListNode(0, head);
		for (int sub_len = 1; sub_len < length; sub_len <<= 1) {
			ListNode *pre = dummy, *cur = dummy->next;
			while (cur != nullptr) {
				ListNode *p = cur;
				for (int i = 1; i < sub_len && cur->next != nullptr; ++i) {
					cur = cur->next;
				}
				ListNode *q = cur->next;
				cur->next = nullptr;
				cur = q;
				for (int i = 1; i < sub_len && cur != nullptr && cur->next != nullptr; ++i) {
					cur = cur->next;
				}
				ListNode *next = nullptr;
				if (cur != nullptr) {
					next = cur->next;
					cur->next = nullptr;
				}
				ListNode *merged = merge(p, q);
				pre->next = merged;
				while (pre->next != nullptr) {
					pre = pre->next;
				}
				cur = next;
			}
		}
		ListNode *ans = dummy->next;
		dummy->next = nullptr;
		delete dummy;
		return ans;
	}

	static void test() {
		std::string s = "[-1,5,3,4,0]";
		ListNode *head = new ListNode(s);
		std::cout << LC_148().sortList(head) << std::endl;
		delete head;
	}
};


#endif //ALGORITHM_LC148_H

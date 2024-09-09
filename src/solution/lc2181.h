#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_2181 {
namespace Test {
std::unique_ptr<ListNode> head = std::make_unique<ListNode>("[0,1,0,3,0,2,2,0]");
}  // namespace Test
#endif

class Solution {
 public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode* last_zero = nullptr;
        ListNode dummy;
        int between_sum = 0;
        ListNode* p = head;
        ListNode* q = &dummy;
        while (p) {
            int val = p->val;
            if (val == 0) {
                if (last_zero) {
                    q->next = new ListNode(between_sum);
                    q = q->next;
                }
                between_sum = 0;
                last_zero = p;
            } else {
                between_sum += val;
            }
            p = p->next;
        }
        ListNode* ans = dummy.next;
        dummy.next = nullptr;
        return ans;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_2181, mergeNodes(Test::head.get()))
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_2181
#endif

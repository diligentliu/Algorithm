#pragma once

#ifdef LOCAL_LEETCODE
#include "main.h"

namespace LC_328 {
namespace Test {
std::unique_ptr<ListNode> head = std::make_unique<ListNode>("[2,1,3,5,6,4,7]");
}  // namespace Test
#endif

class Solution {
 public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode dummy;
        ListNode* cur = head, *per = head, *dummy_pos = &dummy;
        int cnt = 1;
        while (cur) {
            if (cnt % 2 == 0) {
                per->next = cur->next;
                dummy_pos->next = cur;
                dummy_pos = cur;
                cur->next = nullptr;
                cur = per->next;
            } else {
                per = cur;
                cur = cur->next;
            }
            ++cnt;
        }
        if (per) {
            per->next = dummy.next;
            dummy.next = nullptr;
        }
        return head;
    }

#ifdef LOCAL_LEETCODE
    TEST(LC_328, oddEvenList(Test::head.get()));
#endif
};

#ifdef LOCAL_LEETCODE
}  // namespace LC_328
#endif

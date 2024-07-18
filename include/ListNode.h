#pragma once

#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <sstream>

class ListNode {
 public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode(const std::string &s) {
        ListNode *list = deserialize(s);
        this->val = list ? list->val : 0;
        this->next = list ? list->next : nullptr;
    }

    ~ListNode();

    static ListNode *deserialize(const std::string &data);

    std::string serialize();

    static std::vector<std::string> split(const std::string &s, char delimiter);

    friend std::ostream &operator<<(std::ostream &out, ListNode *root);
};

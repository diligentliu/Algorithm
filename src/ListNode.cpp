#include "ListNode.h"

ListNode::~ListNode() {
    delete next;
}

ListNode *ListNode::deserialize(const std::string &data) {
    std::string arr = data.substr(1, data.size() - 2);
    std::vector<std::string> dataArray = split(arr, ',');
    ListNode *dummy = new ListNode();
    ListNode *current = dummy;
    for (const auto &str: dataArray) {
        if (!str.empty()) {
            current->next = new ListNode(std::stoi(str));
            current = current->next;
        }
    }
    return dummy->next;
}

std::string ListNode::serialize() {
    std::string data;
    ListNode *current = this;
    while (current != nullptr) {
        data += std::to_string(current->val) + ", ";
        current = current->next;
    }
    if (!data.empty()) {
        data.pop_back();
        data.pop_back();
    }
    return data;
}

std::vector<std::string> ListNode::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::ostream &operator<<(std::ostream &out, ListNode *node) {
    out << '[' << node->serialize() << ']';
    return out;
}
#include "TreeNode.h"

TreeNode *TreeNode::rdeserialize(std::vector<std::string> &dataArray) {
    if (dataArray.empty() || dataArray[0] == "null") {
        return nullptr;
    }
    TreeNode *root = new TreeNode(std::stoi(dataArray[0]));
    std::queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < dataArray.size()) {
        TreeNode *node = q.front();
        q.pop();

        if (dataArray[i] != "null") {
            node->left = new TreeNode(stoi(dataArray[i]));
            q.push(node->left);
        }
        i++;

        if (i < dataArray.size() && dataArray[i] != "null") {
            node->right = new TreeNode(stoi(dataArray[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}

TreeNode *TreeNode::deserialize(std::string data) {
    data = data.substr(1, data.size() - 2);
    std::vector<std::string> dataArray;
    std::string str;
    for (auto &ch: data) {
        if (ch == ',') {
            dataArray.emplace_back(str);
            str.clear();
        } else {
            str.push_back(ch);
        }
    }
    if (!str.empty()) {
        dataArray.emplace_back(str);
        str.clear();
    }
    return rdeserialize(dataArray);
}

void TreeNode::rserialize(TreeNode *root, std::string &str) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur != nullptr) {
            q.push(cur->left);
            q.push(cur->right);
            str += std::to_string(cur->val) + ',';
        } else {
            str.append("null,");
        }
    }
}

std::string TreeNode::serialize() {
    std::string ans;
    rserialize(this, ans);
    int n = ans.size();
    int i = n - 5;
    while (ans.substr(i, 4) == "null") {
        n = i;
        i -= 5;
    }
    return ans.substr(0, n);
}

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

TreeNode::TreeNode(std::string &s) {
    TreeNode *root = deserialize(s);
    this->val = root->val;
    this->left = root->left;
    this->right = root->right;
}

std::ostream &operator<<(std::ostream &out, TreeNode *root) {
    out << '[' << root->serialize() << "\b]";
    return out;
}

TreeNode::~TreeNode() {
    if (left != nullptr) {
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        delete right;
        right = nullptr;
    }
}

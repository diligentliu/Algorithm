#pragma once

#include <iostream>
#include <queue>
#include <list>
#include <string>

class TreeNode {
 private:
    TreeNode *rdeserialize(std::vector<std::string> &dataArray);

    TreeNode *deserialize(std::string data);

    void rserialize(TreeNode *root, std::string &str);

    std::string serialize();

 public:
    int val;
    TreeNode *left, *right;

    TreeNode();

    TreeNode(int x);

    TreeNode(int x, TreeNode *left, TreeNode *right);

    TreeNode(std::string &s);

    ~TreeNode();

    friend std::ostream &operator<<(std::ostream &out, TreeNode *root);
};

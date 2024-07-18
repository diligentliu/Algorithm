#pragma once

#include "main.h"

class ThroneInheritance {
    unordered_set<string> is_dead;
    unordered_map<string, vector<string>> sons;
    string king;
 public:
    ThroneInheritance(string king_name) {
        king = king_name;
    }

    void birth(string parent_name, string child_name) {
        sons[parent_name].emplace_back(child_name);
    }

    void death(string name) {
        is_dead.emplace(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        function<void(string &)> dfs = [&](string &name) -> void {
            if (!is_dead.count(name)) {
                ans.emplace_back(name);
            }
            for (string &son: sons[name]) {
                dfs(son);
            }
        };
        dfs(king);
        return ans;
    }
};

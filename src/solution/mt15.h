#pragma once

#include "main.h"

class MT_1_5 {
 public:
    vector<int> parents;

    int find_parents(int x) {
        while (x != parents[x]) {
            x = parents[x];
        }
        return parents[x];
    }

    void union_u_v(int p, int q) {
        int root_p = find_parents(p);
        int root_q = find_parents(q);
        if (root_p != root_q) {
            parents[root_p] = root_q;
        }
    }

    void solution() {
        int n, m, q;
        cin >> n >> m >> q;
        parents.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parents[i] = i;
        }
        vector<pair<int, int>> friendships;
        unordered_set<long long> delete_ships;
        vector<vector<int>> queries(q, vector<int>(3));
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            friendships.emplace_back(u, v);
        }
        for (int i = 0; i < q; ++i) {
            int op, u, v;
            cin >> op >> u >> v;
            queries.push_back({op, u, v});
            if (op == 1) {
                delete_ships.insert((long long) u << 32 | v);
                delete_ships.insert((long long) v << 32 | u);
            }
        }

        for (int i = 0; i < m; ++i) {
            if (delete_ships.count((long long) friendships[i].first << 32 | friendships[i].second)) {
                continue;
            }
            union_u_v(friendships[i].first, friendships[i].second);
        }

        vector<bool> ans(q);
        for (int i = q - 1; i >= 0; --i) {
            int op = queries[i][0], u = queries[i][1], v = queries[i][2];
            if (op == 1) {
                ans[i] = find_parents(u) == find_parents(v);
                union_u_v(u, v);
            } else {
                ans[i] = find_parents(u) == find_parents(v);
            }
        }

        for (int i = 0; i < q; ++i) {
            cout << (ans[i] ? "YES" : "NO") << endl;
        }
    }
};

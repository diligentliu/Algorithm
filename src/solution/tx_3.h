#ifndef ALGORITHM_TX_3_H
#define ALGORITHM_TX_3_H

#include "main.h"

class TX_3 {
    void solution() {
        int n, m;
        cin >> n >> m;
        int count = n;
        vector<int> parents(n), size(n, 1);
        iota(parents.begin(), parents.end(), 0);
        function<int(int)> find_parents = [&](int node) -> int {
            if (parents[node] != node) {
                parents[node] = find_parents(parents[node]);
            }
            return parents[node];
        };

        auto connected = [&](int u, int v) -> bool {
            return find_parents(u) == find_parents(v);
        };

        auto union_u_v = [&](int u, int v) -> void {
            if (connected(u, v)) {
                return;
            }
            int root_u = find_parents(u), root_v = find_parents(v);
            int size_u = size[root_u], size_v = size[root_v];
            if (size_u < size_v) {
                parents[root_u] = root_v;
                size[root_v] += size[root_u];
            } else {
                parents[root_v] = root_u;
                size[root_u] += size[root_v];
            }
            --count;
        };

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            union_u_v(u, v);
        }
        if (count > 2) {
            cout << 0 << endl;
            return;
        }
        int ans = size[find_parents(0)];
        ans *= (n - ans);
        cout << ans << endl;
    }
};

#endif //ALGORITHM_TX_3_H

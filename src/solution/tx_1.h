#ifndef ALGORITHM_TX_1_H
#define ALGORITHM_TX_1_H

#include "main.h"

class TX_1 {
 public:
    void solution() {
        int n, m, ans = 0;
        cin >> n >> m;
        vector<bool> good_points(n, true);
        vector<vector<pair<int, bool>>> graph(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            u--, v--;
            if (c == 'W') {
                good_points[u] = false;
                good_points[v] = false;
            }
        }
        cout << count(good_points.begin(), good_points.end(), true) << endl;
    }
};

#endif //ALGORITHM_TX_1_H

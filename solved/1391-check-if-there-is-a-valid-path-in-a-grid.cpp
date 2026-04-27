#include <bits/stdc++.h>
using namespace std;

// Algorithm: Breadth-First Search

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        static const int directions[7][2][2] = {
            {},
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}},
        };

        queue<array<int, 2>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));

        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()) {
            auto [ui, uj] = q.front();
            q.pop();
            
            if (ui == m - 1 and uj == n - 1) {
                return true;
            }

            for (auto& d : directions[grid[ui][uj]]) {
                int vi = ui + d[0];
                int vj = uj + d[1];

                if (vi < 0 or vi >= m or vj < 0 or vj >= n or visited[vi][vj]) {
                    continue;
                }

                for (auto& d : directions[grid[vi][vj]]) {
                    if (vi + d[0] == ui and vj + d[1] == uj) {
                        q.push({vi, vj});
                        visited[vi][vj] = true;
                    }
                }
            }
        }

        return false;
    }
};

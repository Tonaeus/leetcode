#include <bits/stdc++.h>
using namespace std;

// Algorithm: Flood Fill

// Time Complexity: O(r * c)
// Space Complexity: O(r * c)

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size(); 

        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                long long res = dfs(grid, r, c, i, j);
                if (res > 0 and res % k == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }

private:
    long long dfs(vector<vector<int>>& grid, int r, int c, int i, int j) {
        if (i < 0 or i >= r or j < 0 or j >= c or grid[i][j] == 0) {
            return 0;
        }

        long long res = grid[i][j];
        grid[i][j] = 0;

        static const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto& d : directions) {
            res += dfs(grid, r, c, i + d[0], j + d[1]);
        }

        return res;
    }
};

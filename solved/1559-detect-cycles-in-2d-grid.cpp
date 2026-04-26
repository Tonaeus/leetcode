#include <bits/stdc++.h>
using namespace std;

// Algorithm: Depth-First Search

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] and dfs(grid, visited, rows, cols, grid[i][j], -1, -1, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int rows, int cols, char c, int pi, int pj, int i, int j) {
        if (i < 0 or i >= rows or j < 0 or j >= cols or grid[i][j] != c) {
            return false;
        }

        if (visited[i][j]) {
            return true;
        }

        visited[i][j] = true;

        static const int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (!(pi == ni and pj == nj) and dfs(grid, visited, rows, cols, c, i, j, ni, nj)) {
                return true;
            } 
        }

        return false;
    }
};

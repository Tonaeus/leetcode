#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m + n)

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for (int layer = 0; layer < min(m / 2, n / 2); layer++) {
            vector<int> arr;
            int l = layer;
            int t = layer;
            int r = n - layer - 1;
            int b = m - layer - 1;

            for (int j = l; j <= r; j++) {
                arr.push_back(grid[t][j]);
            }
            for (int i = t + 1; i <= b; i++) {
                arr.push_back(grid[i][r]);
            }
            for (int j = r - 1; j >= l; j--) {
                arr.push_back(grid[b][j]);
            }
            for (int i = b - 1; i > t; i--) {
                arr.push_back(grid[i][l]);
            }

            int sz = arr.size();
            int idx = k;

            for (int j = l; j <= r; j++) {
                grid[t][j] = arr[idx % sz];
                idx++;
            }
            for (int i = t + 1; i <= b; i++) {
                grid[i][r] = arr[idx % sz];
                idx++;
            }
            for (int j = r - 1; j >= l; j--) {
                grid[b][j] = arr[idx % sz];
                idx++;
            }
            for (int i = b - 1; i > t; i--) {
                grid[i][l] = arr[idx % sz];
                idx++;
            }
        }

        return grid;
    }
};

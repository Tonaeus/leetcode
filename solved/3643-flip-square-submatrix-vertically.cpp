#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(k^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int t = x;
        int b = x + k - 1;

        while (t < b) {
            for (int i = 0; i < k; i++) {
                swap(grid[t][y + i], grid[b][y + i]);
            }
            t++;
            b--;
        }

        return grid;
    }
};

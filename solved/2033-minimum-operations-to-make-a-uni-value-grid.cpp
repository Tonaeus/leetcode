#include <bits/stdc++.h>
using namespace std;

// Concept: Optimization

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> arr;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        nth_element(arr.begin(), arr.begin() + (m * n) / 2, arr.end());
        int median = arr[(m * n) / 2];

        int ans = 0;

        for (int i = 0; i < m * n; i++) {
            if ((arr[i] - median) % x != 0) {
                return -1;
            }

            ans += abs((arr[i] - median) / x);
        }

        return ans;
    }
};

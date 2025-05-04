#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^N * 2^N)
// Space Complexity: O(2^N * 2^N)

class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;
        vector<vector<int>> ans(size, vector<int>(size));

        int cnt = 0;
        fill(ans, cnt, 0, 0, N);

        return ans;
    }

private:
    void fill(vector<vector<int>>& grid, int& cnt, int i, int j, int n) {
        if (n == 0) {
            grid[i][j] = cnt;
            cnt++;
            return;
        }

        int half = 1 << (n - 1);

        fill(grid, cnt, i, j + half, n - 1);
        fill(grid, cnt, i + half, j + half, n - 1);
        fill(grid, cnt, i + half, j, n - 1);
        fill(grid, cnt, i, j, n - 1);

        return;
    }
};

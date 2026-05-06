#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++) {
            int r = n - 1;
            for (int l = n - 1; l >= 0; l--) {
                if (boxGrid[i][l] == '#') {
                    swap(boxGrid[i][l], boxGrid[i][r]);
                    r--;
                }
                else if (boxGrid[i][l] == '*') {
                    r = l - 1;
                }
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
};

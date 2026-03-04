#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m + n)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> rowSum(m, 0);
        vector<int> colSum(n, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        } 

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 and rowSum[i] == 1 and colSum[j] == 1) {
                    ans++;
                }
            }
        } 

        return ans; 
    }
};

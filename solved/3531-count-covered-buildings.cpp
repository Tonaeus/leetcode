#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> xMin(n + 1, INT_MAX);
        vector<int> xMax(n + 1, 0);
        vector<int> yMin(n + 1, INT_MAX);
        vector<int> yMax(n + 1, 0);

        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            xMin[y] = min(xMin[y], x);
            xMax[y] = max(xMax[y], x);
            yMin[x] = min(yMin[x], y);
            yMax[x] = max(yMax[x], y);
        } 

        int ans = 0;

        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            if (xMin[y] < x and x < xMax[y] and 
                yMin[x] < y and y < yMax[x] 
            ) {
                ans++;
            }
        }

        return ans;
    }
};

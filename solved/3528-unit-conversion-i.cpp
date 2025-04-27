#include <bits/stdc++.h>
using namespace std;

// Algorithm: Breadth-First Search

// Time Complexity: O(v + e)
// Space Complexity: O(v + e)

class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const int MOD = 1e9 + 7;
        int n = conversions.size();
        
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto& c : conversions) {
            g[c[0]].push_back({c[1], c[2]});
        }

        vector<int> ans(n + 1);
        ans[0] = 1;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();        
            
            for (auto& [v, w] : g[u]) {
                ans[v] = 1LL * ans[u] * w % MOD; 
                q.push(v);
            }
        }

        return ans;
    }
};

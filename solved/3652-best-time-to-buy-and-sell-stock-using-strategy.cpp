#include <bits/stdc++.h>
using namespace std;

// Technique: Sliding Window

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += prices[i] * strategy[i];
        }

        long long res = ans;

        for (int i = 0; i < n; i++) {
            if (i < k / 2) {
                res -= prices[i] * strategy[i];
            }
            else if (i < k) {
                res -= prices[i] * strategy[i];
                res += prices[i];
            }
            else {
                res += prices[i - k] * strategy[i - k];
                
                res -= prices[i - k / 2];
                
                res -= prices[i] * strategy[i];
                res += prices[i];
            }

            if (i >= k - 1) {
                ans = max(ans, res);
            }
        }

        return ans;
    }
};

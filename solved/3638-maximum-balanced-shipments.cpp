#include <bits/stdc++.h>
using namespace std;

// Technique: Greedy

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ans = 0;

        for (int i = 1; i < weight.size(); i++) {
            if (weight[i] < weight[i - 1]) {
                ans++;
                i++;
            }
        }

        return ans;
    }
};

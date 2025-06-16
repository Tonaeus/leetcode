#include <bits/stdc++.h>
using namespace std;

// Technique: Sliding Window

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;

        long long ans = LLONG_MIN;
        for (int i = m - 1; i < nums.size(); i++) {
            mn = min(mn, static_cast<long long>(nums[i - m + 1]));
            mx = max(mx, static_cast<long long>(nums[i - m + 1]));
            ans = max({ ans, mn * nums[i], mx * nums[i] }); 
        }

        return ans;
    }
};

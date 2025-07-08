#include <bits/stdc++.h>
using namespace std;

// Data Structure: Unordered Map

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        unordered_map<int, int> l;
        unordered_map<int, int> r;
        for (int i = 0; i < n; i++) {
            r[nums[i]]++;
        }

        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int dbl = 2 * val;
            
            r[val]--;
            
            ans = (ans + 1LL * l[dbl] * r[dbl]) % MOD;

            l[val]++;
        }

        return ans;
    }
};

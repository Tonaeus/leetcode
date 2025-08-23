#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(q * n)
// Space Complexity: O(1)

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            int idx = l;
            while (idx <= r) {
                nums[idx] = (1ll * nums[idx] * v) % MOD;
                idx += k;
            }
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};

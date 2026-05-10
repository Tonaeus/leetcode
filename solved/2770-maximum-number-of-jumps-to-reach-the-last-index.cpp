#include <bits/stdc++.h>
using namespace std;

// Technique: Dynamic Programming

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dfs(nums, target, n - 1, dp);
        return dp[n - 1] == INT_MIN ? -1 : dp[n - 1];
    }

private:
    int dfs(vector<int>& nums, int target, int j, vector<int>& dp) {
        if (j == 0) {
            return 0;
        }

        if (dp[j] != -1) {
            return dp[j];
        }

        dp[j] = INT_MIN;

        for (int i = 0; i < j; i++) {
            if (abs(nums[j] - nums[i]) <= target) {
                int res = dfs(nums, target, i, dp);
                if (res != INT_MIN) {
                    dp[j] = max(dp[j], res + 1);
                }
            }
        }

        return dp[j];
    }
};

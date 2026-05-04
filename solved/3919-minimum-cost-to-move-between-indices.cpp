#include <bits/stdc++.h>
using namespace std;

// Technique: Prefix Sum

// Time Complexity: O(n + q)
// Space Complexity: O(n + q)

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> leftRight(n);
        vector<long long> rightLeft(n);

        for (int i = 0; i < n - 1; i++) {
            if (i == 0 or (nums[i + 1] - nums[i] < nums[i] - nums[i - 1])) {
                leftRight[i + 1] = leftRight[i] + 1;
            }
            else {
                leftRight[i + 1] = leftRight[i] + (nums[i + 1] - nums[i]);
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            if (i == n - 1 or (nums[i] - nums[i - 1] <= nums[i + 1] - nums[i])) {
                rightLeft[i - 1] = rightLeft[i] + 1;
            }
            else {
                rightLeft[i - 1] = rightLeft[i] + (nums[i] - nums[i - 1]);
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            if (l < r) {
                ans.push_back(leftRight[r] - leftRight[l]);
            }
            else {
                ans.push_back(rightLeft[r] - rightLeft[l]);
            }
        }

        return ans;
    }
};

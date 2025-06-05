#include <bits/stdc++.h>
using namespace std;

// Technique: Greedy

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans = 1;
        int maxNum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= maxNum) {
                ans++;
                maxNum = nums[i];
            }
        }

        return ans;
    }
};

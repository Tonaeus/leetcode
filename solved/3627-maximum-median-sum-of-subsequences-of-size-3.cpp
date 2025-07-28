#include <bits/stdc++.h>
using namespace std;

// Technique: Two Pointers

// Time Complexity: O(n·log(n))
// Space Complexity: O(log(n))

class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long ans = 0;

        int l = 0;
        int r = nums.size() - 2;

        while (l < r) {
            ans += nums[r];
            l++;
            r -= 2;
        }

        return ans;
    }
};

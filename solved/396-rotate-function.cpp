#include <bits/stdc++.h>
using namespace std;

// Technique: Dynamic Programming

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int f = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += i * nums[i];
        }

        int ans = f;

        for (int i = 1; i < n; i++) {
            f += sum - n * nums[n - i];
            ans = max(ans, f);
        }

        return ans;
    }
};

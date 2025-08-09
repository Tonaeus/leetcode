#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i + 1 < n and nums[i] < nums[i + 1]) {
            i++;
        }
        int p = i;

        while (i + 1 < n and nums[i] > nums[i + 1]) {
            i++;
        }
        int q = i;

        while (i + 1 < n and nums[i] < nums[i + 1]) {
            i++;
        }
        
        return 0 < p and p < q and q < i and i == n - 1;
    }
};

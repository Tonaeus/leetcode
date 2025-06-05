#include <bits/stdc++.h>
using namespace std;

// Technique: Bitmasking

// Time Complexity: O(2^n * n)
// Space Complexity: O(1)

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        
        __int128 ans = 1;
        for (int num : nums) {
            ans *= num;
        }

        for (int i = 1; i < (1 << n) - 1; i++) {
            __int128 subset1 = 1;
            __int128 subset2 = ans;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subset1 *= nums[j];
                    subset2 /= nums[j];
                }
            }

            if (subset1 == target and subset2 == target) {
                return true;
            }
        }

        return false; 
    }
};

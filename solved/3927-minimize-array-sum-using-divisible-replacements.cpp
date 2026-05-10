#include <bits/stdc++.h>
using namespace std;

// Algorithm: Sieve of Eratosthenes

// Time Complexity: O(n log n + k * n) where n = size of nums, k = number of factors
// Space Complexity: O(M) where M = maximum value of nums

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<int> factor(mx + 1); 
        iota(factor.begin(), factor.end(), 0);

        set<int> set(nums.begin(), nums.end());

        for (int num : set) {
            if (num == factor[num]) {
                for (int mul = num; mul <= mx; mul += num) {
                    if (mul == factor[mul]) {
                        factor[mul] = num;
                    }
                }
            }
        }

        long long ans = 0;

        for (int num : nums) {
            ans += factor[num];
        }

        return ans;
    }
};

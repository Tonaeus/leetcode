#include <bits/stdc++.h>
using namespace std;

// Algorithm: Sieve of Eratosthenes

// Time Complexity: O(n·log(log(n)))
// Space Complexity: O(n)

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += prime[i] ? nums[i] : -nums[i];
        }

        return abs(sum);
    }
};

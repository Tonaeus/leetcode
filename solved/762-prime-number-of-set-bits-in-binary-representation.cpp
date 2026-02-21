#include <bits/stdc++.h>
using namespace std;

// Algorithm: Brian Kernighan

// Time Complexity: O(r - l)
// Space Complexity: O(1)

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

        int ans = 0;

        for (int i = left; i <= right; i++) {
            int n = i;
            int cnt = 0;

            while (n) {
                n &= n - 1;
                cnt++;
            }

            ans += primes.contains(cnt);
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

// Algorithm: Sieve of Eratosthenes

// Time Complexity: O(m log log m) where m = max(n, r)
// Space Complexity: O(m)

class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int nCopy = n;
        int r = 0;
        while (nCopy != 0) {
            r = r * 10 + nCopy % 10;
            nCopy /= 10;
        }

        int mn = min(n, r);
        int mx = max(n, r);

        vector<bool> prime(mx + 1, true);
        if (mx >= 0) {
            prime[0] = false;
        }
        if (mx >= 1) {
            prime[1] = false;
        }
        for (int p = 2; p * p <= mx; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= mx; i += p) {
                    prime[i] = false;
                }
            }
        }
        
        int ans = 0;
        for (int i = mn; i <= mx; i++) {
            if (prime[i]) {
                ans += i;
            }
        }

        return ans;
    }
};

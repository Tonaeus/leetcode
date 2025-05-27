#include <bits/stdc++.h>
using namespace std;

// Algorithm: Optimized Trial Division Primality Test

// Time Complexity: O(n^2 * √(10^n))
// Space Complexity: O(n)

class Solution {
public:
    long long sumOfLargestPrimes(string s) {
        int n = s.length();
        set<long long> set;
        
        for (long long i = 0; i < n; i++) {
            for (long long j = i; j < n; j++) {
                long long num = stoll(s.substr(i, j - i + 1));
                if (isPrime(num)) {
                    set.insert(num);
                    if (set.size() > 3) {
                        set.erase(set.begin());
                    }
                }
            }
        }

        return accumulate(set.begin(), set.end(), 0ll);
    }

private:
    bool isPrime(long long n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }

        if (n % 2 == 0 or n % 3 == 0) {
            return false;
        }

        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 or n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
};

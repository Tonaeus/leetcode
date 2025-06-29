#include <bits/stdc++.h>
using namespace std;

// Algorithm: Optimized Trial Division Primality Test

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int n : nums) {
            map[n]++;
        }

        for (auto& pair : map) {
            if (isPrime(pair.second)) {
                return true;
            }
        }

        return false;
    }

private:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }

        if (n % 2 == 0 or n % 3 == 0) {
            return false;
        }

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 or n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
};

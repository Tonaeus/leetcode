#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log10(n))
// Space Complexity: O(log10(n))

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;

        for (char c : to_string(n)) {
            sum += c - '0';
            product *= c - '0';
        }

        return n % (sum + product) == 0;
    }
};

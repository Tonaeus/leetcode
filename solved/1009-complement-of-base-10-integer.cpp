#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while (mask < n) {
            mask = (mask << 1) | 1;
        }

        return n ^ mask;
    }
};

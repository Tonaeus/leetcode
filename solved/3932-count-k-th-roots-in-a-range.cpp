#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int lowerRoot = ceil(pow(l, 1.0 / k) - 1e-9);
        int higherRoot = floor(pow(r, 1.0 / k) + 1e-9);
        return higherRoot - lowerRoot + 1;
    }
};

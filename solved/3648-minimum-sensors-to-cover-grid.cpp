#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int minSensors(int n, int m, int k) {
        float side = 2 * k + 1;
        int r = ceil(n / side);
        int c = ceil(m / side);
        return r * c;
    }
};

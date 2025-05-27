#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long ans = 0;

        ans += n <= k ? 0 : static_cast<long long>(k) * (n - k);
        ans += m <= k ? 0 : static_cast<long long>(k) * (m - k);

        return ans;
    }
};

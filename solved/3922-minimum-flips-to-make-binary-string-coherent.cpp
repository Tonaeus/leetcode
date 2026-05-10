#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        if (n < 3) {
            return 0;
        }

        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = n - cnt0;

        int res1 = cnt0;
        int res2 = cnt1;
        int res3 = max(0, cnt1 - 1);
        int res4 = cnt1 - (s[0] - '0') - (s[n - 1] - '0');

        return min({res1, res2, res3, res4});
    }
};

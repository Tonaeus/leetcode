#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prev = 0;
        int curr = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
            else {
                curr++;
            }
        }

        return ans += min(prev, curr);
    }
};

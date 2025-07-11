#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log16(n^2) + log36(n^3)) = O(log(n))
// Space Complexity: O(log16(n^2) + log36(n^3)) = O(log(n))

class Solution {
public:
    string concatHex36(int n) {
        vector<char> map(36);
        for (int i = 0; i <= 9; i++) {
            map[i] = i + '0';
        }
        for (int i = 10; i <= 35; i++) {
            map[i] = (i - 10) + 'A';
        }

        int n2 = n * n;
        int n3 = n * n * n;

        string s;
        while (n2 > 0) {
            s += map[n2 % 16];
            n2 /= 16;
        }
        reverse(s.begin(), s.end());
        s = s.empty() ? "0" : s;

        string t;
        while (n3 > 0) {
            t += map[n3 % 36];
            n3 /= 36;
        }
        reverse(t.begin(), t.end());
        t = t.empty() ? "0" : t;

        return s + t;
    }
};

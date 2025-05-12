#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> freq(26);

        int vMax = 0;
        int cMax = 0;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;

            if (vowels.contains(s[i])) {
                vMax = max(vMax, freq[s[i] - 'a']);
            }
            else {
                cMax = max(cMax, freq[s[i] - 'a']);
            }
        }

        return vMax + cMax;
    }
};

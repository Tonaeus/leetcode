#include <bits/stdc++.h>
using namespace std;

// Data Structure: Unordered Set

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        
        unordered_set<string> set;
        string t;

        for (char c : s) {
            t += c;
            if (!set.contains(t)) {
                set.insert(t);
                ans.push_back(t);
                t.clear();
            }
        }

        return ans;
    }
};

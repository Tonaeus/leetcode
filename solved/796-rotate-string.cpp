#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() and (s + s).contains(goal);
    }
};

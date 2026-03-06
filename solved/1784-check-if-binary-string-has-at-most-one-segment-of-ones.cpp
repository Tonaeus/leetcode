#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool checkOnesSegment(string s) {
        return !s.contains("01");
    }
};

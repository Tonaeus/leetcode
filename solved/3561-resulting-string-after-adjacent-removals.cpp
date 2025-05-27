#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string resultingString(string s) {
        string stack;

        for (char c : s) {
            if (!stack.empty()) {
                int top = stack.back();
                int diff = abs(c - top);

                if (diff == 1 or diff == 25) {
                    stack.pop_back();
                    continue;
                }
            }
            
            stack.push_back(c);
        }

        return stack;
    }
};

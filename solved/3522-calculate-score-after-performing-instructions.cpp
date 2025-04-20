#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ans = 0;
        int n = instructions.size();

        int i = 0;
        while (i >= 0 and i < n) {
            if (instructions[i] == "add") {
                ans += values[i];
                instructions[i] = "";
                i++;
            }
            else if (instructions[i] == "jump") {
                instructions[i] = "";
                i += values[i];
            }
            else {
                break;
            }
        }

        return ans;
    }
};

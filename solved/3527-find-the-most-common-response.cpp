#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n * l) -> m = number of responses, n = average number of strings, l = average number of characters
// Space Complexity: O(m * n * l)

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> map;

        for (auto& r : responses) {
            unordered_set<string> set(r.begin(), r.end());
            for (auto& ele : set) {
                map[ele]++;
            }
        }

        string ans;
        int cnt = 0;

        for (auto& [key, val] : map) {
            if (val > cnt or (val == cnt and key < ans)) {
                ans = key;
                cnt = val;
            }
        }

        return ans;
    }
};

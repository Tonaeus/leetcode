#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";

        for (int i = 0; i < caption.size(); i++) {
            if (!isalpha(caption[i])) {
                continue;
            }

            if (i > 0 and caption[i - 1] == ' ') {
                ans.push_back(toupper(caption[i]));
            }
            else {
                ans.push_back(tolower(caption[i]));
            }

            if (ans.size() == 100) {
                break;
            }
        }

        ans[1] = tolower(ans[1]);
        return ans;
    }
};

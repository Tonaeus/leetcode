#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * k + n·log(n)) -> n = number of coupons, k = average length of coupons
// Space Complexity: O(n * k)

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_set<string> set = {"electronics", "grocery", "pharmacy", "restaurant"};
        
        auto pred = [](char c) {
            return isalnum(c) or c == '_';
        };

        vector<array<string, 2>> arr;
        for (int i = 0; i < code.size(); i++) {
            if (code[i].empty()) {
                continue;
            }
            if (!all_of(code[i].begin(), code[i].end(), pred)) {
                continue;
            }
            if (!set.contains(businessLine[i])) {
                continue;
            }
            if (!isActive[i]) {
                continue;
            }

            arr.push_back({businessLine[i], code[i]});
        }

        sort(arr.begin(), arr.end());

        vector<string> ans;
        for (auto& ele : arr) {
            ans.push_back(ele[1]);
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

// Data Structure: Monotonic Stack

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> ims;

        for (int i = 0; i < n; i++) {
            array<int, 3> curr = {nums[i], i, i};

            while (!ims.empty() and ims.back()[0] > nums[i]) {
                auto [val, l, r] = ims.back();
                ims.pop_back();
                curr[0] = max(curr[0], val);
                curr[1] = l;
            }

            ims.push_back(curr);
        }

        vector<int> ans(n);
        for (auto& [val, l, r] : ims) {
            for (int i = l; i <= r; i++) {
                ans[i] = val;
            }
        }

        return ans;
    }
};

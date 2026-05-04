#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = 0;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                ans[i] = odd;
                even++;
            }
            else {
                ans[i] = even;
                odd++;
            }
        }

        return ans;
    }
};

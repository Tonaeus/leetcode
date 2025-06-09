#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        return min(helper(nums, -1), helper(nums, 1)) <= k;
    }

private:
    int helper(vector<int>& nums, int target) {
        int cnt = 0;

        int res = 0;
        int idx = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) {
                continue;
            }

            if (idx == -1) {
                idx = i;
            } 
            else {
                res += i - idx;
                idx = -1;
            }

            cnt++;
        }

        return cnt % 2 == 0 ? res : INT_MAX;
    }
};

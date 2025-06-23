#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> even, odd; 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even.push_back(i);
            }
            else {
                odd.push_back(i);
            }
        }

        int evenCnt = even.size();
        int oddCnt = odd.size();

        if (abs(evenCnt - oddCnt) > 1) {
            return -1;
        }

        int ans = INT_MAX;

        if (evenCnt >= oddCnt) {
            ans = min(ans, helper(even));
        }
        if (oddCnt >= evenCnt) {
            ans = min(ans, helper(odd));
        }

        return ans;
    }

private:
    int helper(vector<int>& arr) {
        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            res += abs((i * 2) - arr[i]);
        }

        return res;
    }
};

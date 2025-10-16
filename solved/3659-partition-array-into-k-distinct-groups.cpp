#include <bits/stdc++.h>
using namespace std;

// Data Structure: Unordered Map

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        if (n % k != 0) {
            return false;
        }

        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }

        int g = n / k;
        for (const auto& pair : map) {
            if (pair.second > g) {
                return false;
            }
        }

        return true;
    }
};

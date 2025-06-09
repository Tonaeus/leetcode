#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n·log(n))
// Space Complexity: O(n)

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> map;
        for (int i = 0; i < y.size(); i++) {
            map[x[i]] = max(map[x[i]], y[i]);
        }

        if (map.size() < 3) {
            return -1;
        }

        vector<int> arr;
        for (auto& [key, val] : map) {
            arr.push_back(val);
        }

        sort(arr.begin(), arr.end(), greater<>());
        return arr[0] + arr[1] + arr[2];
    }
};

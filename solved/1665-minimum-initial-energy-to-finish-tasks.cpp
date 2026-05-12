#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(log n)

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [](auto& a, auto& b) {
            return a[1] - a[0] > b[1] - b[0];
        };
        sort(tasks.begin(), tasks.end(), cmp);

        int ans = tasks[0][1];
        int bal = tasks[0][1] - tasks[0][0];

        for (int i = 1; i < tasks.size(); i++) {
            if (bal < tasks[i][1]) {
                ans += tasks[i][1] - bal;
                bal += tasks[i][1] - bal;
            }

            bal -= tasks[i][0];
        }

        return ans;
    }
};

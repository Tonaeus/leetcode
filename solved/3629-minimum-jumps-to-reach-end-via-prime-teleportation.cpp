#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + M log log M) where n = size of nums, M = maximum value of nums
// Space Complexity: O(n + M)

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> prime(mx + 1, true);
        if (mx >= 0) {
            prime[0] = false;
        }
        if (mx >= 1) {
            prime[1] = false;
        }
        for (int p = 2; p * p <= mx; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= mx; i += p) {
                    prime[i] = false;
                }
            }
        }

        vector<vector<int>> pos(mx + 1);
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(n);
        vis[0] = true;

        while (!q.empty()) {
            auto [i, t] = q.front();
            q.pop();

            if (i == n - 1) {
                return t;
            }

            if (i > 0 and !vis[i - 1]) {
                q.push({i - 1, t + 1});
                vis[i - 1] = true;
            }

            if (i < n - 1 and !vis[i + 1]) {
                q.push({i + 1, t + 1});
                vis[i + 1] = true;
            }

            if (prime[nums[i]]) {
                int p = nums[i];
                for (int m = p; m <= mx; m += p) {
                    for (int j : pos[m]) {
                        if (!vis[j]) {
                            q.push({j, t + 1});
                            vis[j] = true;
                        }
                    }
                    pos[m].clear();
                }
                prime[p] = false;
            }
        }

        return n - 1;
    }
};

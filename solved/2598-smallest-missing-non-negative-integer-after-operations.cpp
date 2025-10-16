#include <bits/stdc++.h>
using namespace std;

// Concept: Modulo

// Time Complexity: O(n)
// Space Complexity: O(v)

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainders(value);
        for (int n : nums) {
            remainders[(n % value + value) % value]++;
        }

        int stop = 0;
        for (int i = 0; i < value; i++) {
            if (remainders[i] < remainders[stop]) {
                stop = i;
            }
        }

        return value * remainders[stop] + stop;
    }
};

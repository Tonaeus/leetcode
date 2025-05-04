#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log10(n))
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        vector<int> freq(10);

        while (n > 0) {
            int d = n % 10;
            if (freq[d] < 2) {
                digits.push_back(d);
                freq[d]++;
            }
            n /= 10;
        }

        sort(digits.begin(), digits.end());
        
        int m = digits.size();
        return digits[m - 1] * digits[m - 2];
    }
};

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> vowels = {
            {'a', 0},
            {'e', 1},
            {'i', 2},
            {'o', 3},
            {'u', 4},
        };
        
        vector<array<int, 3>> vec(5, {0, -1, 0});

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (vowels.contains(c)) {
                vec[vowels[c]][0]++;

                if (vec[vowels[c]][1] == -1) {
                    vec[vowels[c]][1] = i;
                    vec[vowels[c]][2] = c;
                }
            }
        }

        auto cmp = [](auto& a, auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; 
        };
        sort(vec.begin(), vec.end(), cmp);

        for (char& c : s) {
            if (vowels.contains(c)) {
                auto& arr = vec.back();
                
                c = arr[2];

                arr[0]--;
                if (arr[0] == 0) {
                    vec.pop_back();
                }
            }
        }

        return s;
    }
};

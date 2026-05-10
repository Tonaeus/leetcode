#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter = 0;
    
        for (string& e : events) {
            if (counter == 10) {
                break;
            }
            
            if (e == "W") {
                counter += 1;
            }
            else if (e == "WD") {
                score += 1;
            }
            else if (e == "NB") {
                score += 1;
            }
            else {
                score += stoi(e);
            }
        }

        return {score, counter};
    }
};

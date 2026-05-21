#include <bits/stdc++.h>
using namespace std;

// Data Structure: Trie

// Time Complexity: O(m + n) where m = size of arr1 and n = size of arr2
// Space Complexity: O(m)

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isLeaf;

    TrieNode() : children(10, nullptr) {
        isLeaf = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* curr = root;
        string numStr = to_string(num);

        for (char dig : numStr) {
            if (!curr->children[dig - '0']) {
                curr->children[dig - '0'] = new TrieNode();
            }

            curr = curr->children[dig - '0'];
        }

        curr->isLeaf = true;
    }

    int prefixCount(int num) {
        TrieNode* curr = root;
        string numStr = to_string(num);
        int cnt = 0;

        for (char dig : numStr) {
            if (!curr->children[dig - '0']) {
                return cnt;
            }

            curr = curr->children[dig - '0'];
            cnt++;
        }

        return cnt;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for (int x : arr1) {
            trie.insert(x);
        }

        int ans = 0;

        for (int y : arr2) {
            ans = max(ans, trie.prefixCount(y));
        }

        return ans;
    }
};

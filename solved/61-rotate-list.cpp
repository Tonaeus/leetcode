#include <bits/stdc++.h>
using namespace std;

// Data Structure: Linked List

// Time Complexity: O(n)
// Space Complexity: O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head or !head->next or k == 0) {
            return head;
        }

        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        k %= n;
        if (k == 0) {
            return head;
        }

        tail->next = head;

        ListNode* newTail = head;
        int steps = n - k - 1;
        while (steps) {
            newTail = newTail->next;
            steps--;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        ListNode* fast = head;
        ListNode* slow = head;

        while(n--)
        {
            fast=fast->next;
        }

        ListNode* prev = head;

        if (!fast) {
            // If fast is null, it means the node to remove is the head i.e n is len of LL
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while(fast)
        {
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }

        //both move len-n

        prev->next = slow->next;
        delete(slow);

        return head;
    }
};
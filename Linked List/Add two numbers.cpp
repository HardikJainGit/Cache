#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-two-numbers/description/

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* head = new ListNode();  

    ListNode* temp = head; 
    ListNode* temp_ = head; 
    int carry = 0;
    int sum = 0;

    while (l1 || l2 || carry != 0) { //non zero carry needs to be catered

        sum = carry; // initialise sum for each while loop

        if (l1) 
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) 
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        temp = new ListNode(sum % 10);

        head -> next = temp;
        head = temp;
    }

    return temp_ -> next;
}

};
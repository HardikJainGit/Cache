#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head)
        {
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = head;

        int len = 0;

        while(temp)
        {
            temp=temp->next;
            len+=1;
        }

        temp = head;
        k = k % len;
    
        while(k--)
        {
            temp = head;
            prev = head;
            
            while(temp && temp->next)
            {
                prev = temp;
                temp=temp->next;
            }

            temp->next = head;
            prev->next=NULL;
            head = temp;
        }
        return head;
    }
};
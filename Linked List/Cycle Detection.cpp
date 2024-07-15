#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {

        unordered_map <ListNode*,int> m;

        ListNode* temp = head;
        while(temp)
        {
            if(m[temp])
            {
                return true;
            }
            m[temp]=1;
            temp=temp->next;
        }

        return false;

    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast = head;

        if(!head)
        {
            return NULL;
        }

        if(head->next==NULL)
        {
            return NULL;
        }

        slow=slow->next;
        fast=fast->next->next;
        
        while(fast && fast->next && slow!=fast)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast && slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return slow;
        }

        else
        {
            return NULL;
        }
    }
};
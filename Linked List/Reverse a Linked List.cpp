#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursion :
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* newHead = NULL;

        newHead=reverseList(head->next);

        ListNode* temp = head -> next;

        temp -> next = head;
        head -> next = NULL;

        return newHead;
    }
};

// Stack 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        temp = head;
        stack<int> st;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            temp->val=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
};

// Prev temp Fwd

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* temp;
        ListNode* prev;
        ListNode* fwd;

        fwd=NULL;
        prev=NULL;
        temp=head;

        while(temp!=NULL)
        {
            fwd=temp->next;
            temp->next=prev;
            prev=temp;
            temp=fwd;
        }
        return prev;
    }
};
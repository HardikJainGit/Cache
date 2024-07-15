#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-linked-list/description/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Compare original and reversed

class Solution {
private:
    ListNode* reverseList(ListNode* head) {

            if(head==NULL || head->next==NULL)
            {
                return head;
            }

            ListNode* tail_recursive_reversed = NULL;
            ListNode* newHead = NULL;

            newHead=reverseList(head->next);
            tail_recursive_reversed=head->next;
            tail_recursive_reversed->next=head;
            head->next=NULL; ////

            return newHead;

        }
public:
    bool isPalindrome(ListNode* head) {

        ListNode* head_copy = new ListNode(head->val); //Deep Copy as they say!>
        ListNode* copy_ptr = head_copy;

        ListNode* temp = NULL;
        temp = head;

        while (temp->next) 
        {
            copy_ptr->next = new ListNode(temp->next->val);
            temp = temp->next;
            copy_ptr = copy_ptr->next;
        }

        //created a new linked list in new O(n) memory

        ListNode* revHead=reverseList(head_copy);

        ListNode* temp2=revHead;
        ListNode* temp1=head;

        while(temp1)
        {
            if(temp1->val!=temp2->val)
            {
                return false;
            }

            temp1=temp1->next;
            temp2=temp2->next;
            
        }
        return true;
    }
};

// Stack

class Solution {
private:

public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        while(temp)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
            if(temp->val!=st.top())
            {
                return false;
            }
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};

// Fast slow

class Solution {
private:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* tail_recursive_reversed = NULL;
        ListNode* newHead = NULL;

        newHead=reverseList(head->next);
        tail_recursive_reversed=head->next;
        tail_recursive_reversed->next=head;
        head->next=NULL;

        return newHead;

    }
public:
    bool isPalindrome(ListNode* head) {

        if (head == NULL || head->next == NULL) 
        {
            return true;
        }

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast && fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* newHead = reverseList(slow->next);

        ListNode* temp1 = head;
        ListNode* temp2 = newHead;
        
        while(temp1 && temp2)
        {
            if(temp1->val!=temp2->val)
            {
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return true;

    }
};
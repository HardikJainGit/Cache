#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Push elements in a unordered set of first and iterate second and call find in the set :

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> st;

        ListNode* head1=headA;
        ListNode* head2=headB;

        while(head1 != NULL) 
        {
            st.insert(head1);
            head1 = head1->next;
        }

        while(head2 != NULL) 
        {
            if(st.find(head2) != st.end()) return head2; //head2 is intersection
            head2 = head2->next;
        }
        return NULL;
    }
};

// Move the head by n2 - n1

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* head1=headA;
        ListNode* head2=headB;

        int len1 = 0;
        int len2 = 0;

        while(head1 || head2) 
        {
            if(head1 != NULL) 
            {
                len1+=1;
                head1 = head1->next;
            }
            if(head2 != NULL) 
            {
                len2+=1;
                head2 = head2->next;
            }
        }

            head1= headA;
            head2=headB;

            int rem = abs(len1-len2);
            
            if(len1>len2)
            {
                while(rem-- && head1)
                {
                    head1=head1->next;
                }
            }
            else
            {
                while(rem-- && head2)
                {
                    head2=head2->next;
                }
            }

            while(head1 && head2 && head1!=head2)
            {
                head1=head1->next;
                head2=head2->next;
            }
            
        return head2;
    }
};

// pA ends then move to pB and vice versa

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA!=pB)
        {
            if(!pA)
            {
                pA=headB;
            }
            else if(pA)
            {
                pA=pA->next;
            }
            if(!pB)
            {
                pB=headA;
            }
            else if(pB)
            {
                pB=pB->next;
            }
        }

        return pA;
    }
};
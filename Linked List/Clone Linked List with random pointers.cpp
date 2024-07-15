#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    Node* copyRandomList(Node* head) {
        
        if (!head) 
        {
            return NULL;
        }

        // Interleave the original and copied nodes 1->1'->2->2' ...

        Node* curr = head;

        while (curr) 
        {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Set the random pointers for the copied nodes

        curr = head;

        while (curr) {
            if (curr->random) 
            {
                curr->next->random = curr->random->next; /////
            }
            if(curr->next)
            {
                curr = curr->next->next;
            }
        }

        // Separate the original and copied lists

        Node* newHead = head->next;
        Node* temp = newHead;

        // while (head) 
        // {
        //     head->next = temp->next;
        //     if(temp->next) 
        //     {
        //         temp->next = temp->next->next;
        //     }
        //     head = head->next;
        //     temp = temp->next;
        // }

        Node* c = head->next;
        Node* c_copy = c;

        while(head)
        {
            c = head -> next;
            head->next = head -> next -> next;
            head = head -> next;
            if(c->next)
            c->next = c -> next -> next;
        }

        return c_copy;
    }
};

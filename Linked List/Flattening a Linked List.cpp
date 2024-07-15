#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(-1);
    Node *temp_copy = temp; 

    // Same logic to merge 2 sorted linked list but for bottom pointers
    
    while(a && b) {
        if(a->data < b->data) 
        {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else 
        {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) 
    {
        temp->bottom = a;
        temp=temp->bottom;
        a=a->bottom;
    }
    
    else 
    {
        temp->bottom = b;
        temp=temp->bottom;
        b=b->bottom;
    }
    
    return temp_copy -> bottom; //bottom of the dummy head (temp)
    
    }
    
    //main function
    
    Node *flatten(Node *root)
    {
       if (!root || !(root->next)) 
       {
            return root; //base case for merging
       }
            
       root->next = flatten(root->next); //sort after root->next
       root = mergeTwoLists(root, root->next); 

       return root; 
    }


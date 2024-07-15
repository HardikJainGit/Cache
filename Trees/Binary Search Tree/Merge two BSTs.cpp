#include<bits/stdc++.h>
using namespace std;

// 	https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
    }
};


class Solution
{
    public:
    Node* flattenBST(Node* root) 
    {
        if(!root)
        {
            return NULL;
        }
        
        Node* l = flattenBST(root -> left);
        Node* r = flattenBST(root -> right);
        
        root->left = NULL;

        Node* temp = l;

        Node* final_head = l;
        
        if(temp)
        {   
            while(temp->right)
            {
                temp = temp->right;
            }
    
            Node* tail = temp;
    
            tail -> right = root;
            tail = root;
    
            tail -> right = r;
    
            return final_head;
        }
        else
        {
            root->right = r;
            return root;
        }
    }
    
    Node* mergeTwoLists(Node* list1, Node* list2) {

        Node* head;
        head=nullptr;

        Node* returnhead;
        returnhead=new Node(-1);
        returnhead->right=head;

        if(!list1)
        {
            return list2;
        }

        if(!list2)
        {
            return list1;
        }

        if(list1->data>list2->data)
        {
            head=list2;
            returnhead->right=head;
            list2=list2->right;
        }

        else
        {
            head=list1;
            returnhead->right=head;
            list1=list1->right;
        }

        while(list1 && list2)
        {

            if(list1->data>list2->data)
            {
                head->right=list2;
                list2=list2->right;
            }
            else
            {
                head->right=list1;
                list1=list1->right;
            }

            head=head->right;

        }

        if (list1 != nullptr) 
        {
            head->right = list1;
        }
        
        else 
        {
            head->right = list2;
        }

        return returnhead->right;

    }

    int countNodes(Node* head) 
    {
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL) 
        {
            cnt++;
            temp = temp->right;
        }
        return cnt;
    }
    
    Node* LL_2_BST(Node* head, int n) 
    {
         
        // Same logic as inorder to BST :
        
        if(n <= 0) 
        {
            return NULL;
        }
    
        int temp = n/2;
        Node* root = head;
        while(temp--) {
            root = root->right;
        }
    
        root->left = LL_2_BST(head, n/2);   
        root->right = LL_2_BST(root->right, n-n/2-1);
        return root; 
    
    }
    
    Node* MergeBST(Node* root1, Node* root2) 
    {
        Node* head1 = flattenBST(root1);
        Node* head2 = flattenBST(root2);
    
        Node* list = mergeTwoLists(head1, head2);

        Node* result = LL_2_BST(list, countNodes(list));
    
        return result;
    }
    void inOrder(Node* root, vector<int>& ans) 
    {
        if(root == NULL) 
        {
            return;
        }
    
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       Node* newRoot = MergeBST(root1 , root2);
       vector<int> newInorder;
       inOrder(newRoot , newInorder);
       return newInorder;
    }
};
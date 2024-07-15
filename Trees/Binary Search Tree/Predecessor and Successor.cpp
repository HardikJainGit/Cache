#include<bits/stdc++.h>
using namespace std;

// 	https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

struct Node
{
    int key;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Max in left subtree is pre Min in right subtree is suc
        
        // int f = 0; // no need for global as used for one call only
        if(!root)
        {
            return;
        }

        if(root->key == key)
        {
            // f = 1;
            if(root -> left)
            {
                Node* temp = root -> left;
                while(temp -> right)
                {
                    temp = temp -> right;
                }
                pre = temp;
            }
            
            if(root -> right)
            {
                Node* temp2 = root -> right;
                while(temp2 -> left)
                {
                    temp2 = temp2 -> left;
                }
                suc = temp2;
            }
            // return here if dont want to use f
            return;
        }
        
        // The commented lines are used if the key is not in the tree
        // If they are not used code returns -1 -1 but gfg expects to return
        // the nos less than and greater than key even if key isn't in tree
        // Don't use the lines if the key is present in the tree
        
        if (key < root->key)
        {
            // if(!f) suc = root; //
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        else 
        {
            // if(!f) pre = root; //
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};
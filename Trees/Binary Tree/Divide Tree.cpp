// https://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};

int checkRec(Node* root, int n, bool &res)
{
    // Base case
    if (root == NULL)
       return 0;

    // Bottom Up
    
    // Compute sizes of left and right children
    int l = checkRec(root->left, n, res);
    int r = checkRec(root->right, n, res);

    int c = l + r + 1;
 
    // If required property is true for current node
    // set "res" as true
    if (c == n-c)
        res = true;
 
    // Return size since int return type
    return c;
}
#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/mirror-tree/1

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

class Solution {
  public:
    Node* dfs(Node* node)
    {
        if(!node) return NULL;
        Node* l = dfs(node->left);
        Node* r = dfs(node->right);
        
        node->right = l;
        node->left = r;
    }
    void mirror(Node* node) {
        dfs(node);
    }
};


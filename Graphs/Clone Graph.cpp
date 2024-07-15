#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/clone-graph/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> cloned;

    void dfs (Node* node)
    {
        if(!node)
        {
            return;
        }

        if (cloned.find(node) == cloned.end()) 
        {
            cloned[node] = new Node(node->val);
        }

        for(auto it : node -> neighbors)
        {
            if (cloned.find(it) == cloned.end()) 
            {
                cloned[it] = new Node(it->val);
                cloned[node]->neighbors.push_back(cloned[it]);
                dfs(it);
            }
            else
            {
                cloned[node]->neighbors.push_back(cloned[it]);
            }
        }
    }
    Node* cloneGraph(Node* node) 
    {
        dfs(node);
        return cloned[node];
    }
};
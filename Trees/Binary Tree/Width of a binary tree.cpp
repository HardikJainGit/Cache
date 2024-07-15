#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/maximum-width-of-binary-tree/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if (!root) 
        {
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long>> q;  // node, x
        q.push({root, 1}); 

        int maxWidth = 0;

        while (!q.empty()) {
            unsigned long long x = q.front().second; // the rightmost (first entry)
            unsigned long long rpos = -1;
            unsigned long long level = q.size(); 
            unsigned long long pos = -1; 

            for (unsigned long long i = 0; i < level; i++) 
            {
                auto it = q.front();
                TreeNode* cur = it.first;
                pos = it.second; // last node of the current level
                q.pop();

                // rpos = pos; // assign current position to rpos // 

                if (cur->left) q.push({cur->left, 2 * pos});
                if (cur->right) q.push({cur->right, 2 * pos + 1});
            }
            maxWidth = max(maxWidth, static_cast<int>(pos - x + 1));  // or use rpos here //
        }

        return maxWidth;
    }
};

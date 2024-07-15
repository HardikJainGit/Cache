#include<bits/stdc++.h>
using namespace std;

// 	https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* dfs(vector<int> nums,int start,int end)
    {
        if (start > end) 
        {
            return NULL;
        }

        // nums from start to end

        int split = upper_bound(nums.begin() + start, nums.begin() + end + 1, nums[start]) - nums.begin();

        TreeNode* node = new TreeNode(nums[start]);
        node->left = dfs(nums, start + 1, split - 1);
        node->right = dfs(nums, split, end);

        // if(!nums.size())
        // {
        //     return NULL;
        // }

        // int split = upper_bound(nums.begin(), nums.end(), nums[0]) - nums.begin();

        // vector<int> nums_l (nums.begin() + 1 , nums.begin() + split);
        // vector<int> nums_r (nums.begin() + split , nums.end());

        // TreeNode* node = new TreeNode(nums[0]);
        
        // node -> right = dfs(nums_r);
        // node -> left = dfs(nums_l);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode* root = dfs(preorder,0,preorder.size()-1);
        
        return root;
    }
};
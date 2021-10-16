/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// mid ko root banao and mast raho

class Solution {
public:
    TreeNode* solve(vector<int>&nums, int s, int e)
    {
        if(s>e) //array khatam kya dudh rhe ho.. haha..
            return NULL;
        else if(s==e)
        {
            // jitna dundhna tha dundh liya ab kuch nhi bacha
            TreeNode* root=new TreeNode(nums[e]);
            return root;
        }
        else{
        // mid nikalo dono side ke lements ko daal do
            //mid ese hi nikalna warna royega
        int mid=s + (e - s) / 2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=solve(nums,s,mid-1);
        root->right=solve(nums,mid+1,e);
        
        return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *newroot=solve(nums,0,nums.size()-1);
        return newroot;
    }
};

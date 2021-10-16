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
// bfs se dund lo
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
            return NULL;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.empty()==false)
        {
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr->val==val)
                return curr;
            
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
                
        }
        return NULL;
    }
};

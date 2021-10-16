// simple app: inorder traversal nikal lo and delh lo har elem biche wale se chota to hai na
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
class Solution {
public:
    void inOrder(TreeNode*root,vector<int>&inorder){
       if(root!=nullptr){
           inOrder(root->left,inorder);
          inorder.push_back(root->val);
          inOrder(root->right,inorder);
       }
     else return ;
   }
    
    bool isValidBST(TreeNode* root) {
   vector<int> inorder;
       if(root==nullptr) return true;
       else{
          inOrder(root,inorder);
           for(int i=0;i<inorder.size()-1;i++){
              if(inorder[i]>=inorder[i+1]) return false; 
           }
       return true;
       }
    }
};

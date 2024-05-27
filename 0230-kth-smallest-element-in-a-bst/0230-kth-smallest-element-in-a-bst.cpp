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
 void inorder(TreeNode* root,vector<int>&inorderv){
    if(root==nullptr)return;
     inorder( root->left,inorderv);
     inorderv.push_back(root->val);
     inorder( root->right,inorderv);
 }
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       vector<int>inorderv;
       inorder(root,inorderv);

       return inorderv[k-1];
    }
};
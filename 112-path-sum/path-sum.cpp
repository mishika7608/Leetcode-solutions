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
    bool func(TreeNode* root, int targetSum){
        if (root==NULL){return false;}
        if (targetSum==root->val && root->left==NULL && root->right==NULL){return true;}
        targetSum-=root->val;
        return func(root->left,targetSum) || func(root->right,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==NULL){return false;}
        return func(root,targetSum);
    }
};
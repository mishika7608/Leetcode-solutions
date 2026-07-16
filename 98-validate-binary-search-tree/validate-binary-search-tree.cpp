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
    bool isValid(TreeNode* root,long mn, long mx){
        if (root==NULL){return true;}
        if (root){
            if (root->val>mn && root->val<mx){
                return isValid(root->left,mn,root->val) && isValid(root->right,root->val,mx);
            }return false;
        }return false;
    }
    bool isValidBST(TreeNode* root) {
        long mn=LONG_MIN;
        long mx=LONG_MAX;
        // if ((root->val==mx || root->val==mn) && root->left==NULL && root->right==NULL ){return true;}
        return isValid(root,mn,mx);
    }
};
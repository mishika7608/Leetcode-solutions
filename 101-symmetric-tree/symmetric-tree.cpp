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
    bool isSame(TreeNode* leftPointer, TreeNode* rightPointer){
        if (leftPointer==NULL && rightPointer==NULL){return  true;}
        else if (leftPointer==NULL && rightPointer!=NULL){return  false;}
        else if (leftPointer!=NULL && rightPointer==NULL){return  false;}
        else if (leftPointer!=NULL && rightPointer!=NULL &&
            leftPointer->val!=rightPointer->val){return false;}
        else if (isSame(leftPointer->left, rightPointer->right)!=true &&
        isSame(leftPointer->right, rightPointer->left)==true ){return false;}
        else if (isSame(leftPointer->left, rightPointer->right)==true &&
        isSame(leftPointer->right, rightPointer->left)!=true ){return false;}
        else if (isSame(leftPointer->left, rightPointer->right)!=true &&
        isSame(leftPointer->right, rightPointer->left)!=true ){return false;}
        else{return true;}

    }


    bool isSymmetric(TreeNode* root) {
        if (root==NULL || root->left==NULL && root->right==NULL){return true;}
        return isSame(root->left, root->right);
    }
};
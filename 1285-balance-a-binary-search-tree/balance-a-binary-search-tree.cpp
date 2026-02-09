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
    vector<int> temp;
    void inorder(TreeNode* root){
        if (root==NULL){return ;}
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* createTree(int l, int r,vector<int> &temp){
        if (l<=r){
            int m = (l+r)/2;
            TreeNode* root = new TreeNode(temp[m]);
            root->left = createTree(l,m-1,temp); 
            root->right = createTree(m+1,r,temp); 
            return root;
        }return NULL;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return createTree(0,temp.size()-1,temp);
    }
};
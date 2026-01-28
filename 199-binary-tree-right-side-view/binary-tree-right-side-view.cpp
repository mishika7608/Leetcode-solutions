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
    vector<int> res;
    void dfs(TreeNode* root, int depth){
        if (root==NULL){return; }
        if (depth==res.size()){res.push_back(root->val);}
        dfs(root->right,depth+1);
        dfs(root->left,depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root==NULL ){return {};}
        if (root->left==NULL && root->right==NULL){return {root->val};}
        dfs(root,0);
        return res;
    }
};
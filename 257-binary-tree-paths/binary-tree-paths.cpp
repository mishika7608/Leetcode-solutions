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
    void dfs(TreeNode* root, vector<string> &res,string temp)
    {
        if (root==NULL){return ;}
        if (root->left==NULL && root->right==NULL){
            string ch=to_string(root->val);
            temp+=ch;
            res.push_back(temp); 
            return ;
        }
        string s = to_string(root->val);
        s+="-";s+=">";
        temp+=s;
        dfs(root->left,res,temp);
        dfs(root->right, res,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string temp;
        dfs(root, res, temp);
        return res;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) {
                s += "N,";
                continue;
            }
            s += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            getline(ss, val, ',');
            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(ss, val, ',');
            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
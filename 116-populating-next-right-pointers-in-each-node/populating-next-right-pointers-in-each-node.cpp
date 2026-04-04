/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (!root || !root->left && !root->right){return root;}
        q.push(root);
        while (!q.empty()){
            int size=q.size();
            for (int i=0;i<size;i++){
                Node* u = q.front();q.pop();
                if (i<size-1) {u->next=q.front();}
                if (u->left){q.push(u->left);}
                if (u->right){q.push(u->right);}
            }
        }
        return root;
    }
};
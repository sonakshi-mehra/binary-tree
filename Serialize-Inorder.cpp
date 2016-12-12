#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string s = "";
    queue<TreeNode*> q;
    if(!root) return "#";
    s += to_string(root->val) + ",";
    q.push(root);
    while(!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        if(!front->left) {
            s += "#,";
        }
        else {
            s += to_string(front->left->val) + ",";
            q.push(front->left);
        }
        if(!front->right) {
            s += "#,";
        }
        else {
            s += to_string(front->right->val) + ",";
            q.push(front->right);
        }
    }
    s.pop_back();
    return s;
}

int main() {
    TreeNode *A = new TreeNode(5);
    A->left = new TreeNode(4);
    A->left->right = new TreeNode(6);
    A->left->right->left = new TreeNode(8);
    A->right = new TreeNode(9);
    A->right->left = new TreeNode(10);
    cout << serialize(A);
}

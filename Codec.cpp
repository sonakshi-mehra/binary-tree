#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:

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

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode **> q;
        TreeNode *root=NULL;
        q.push(&root);
        int index = 0;
        while(!q.empty() && index<data.length()) {
            TreeNode **front = q.front();
            q.pop();
            string val = "";
            if(data[index]=='#') {
                index += 2;
                continue;
            }
            while(index<data.length() && data[index]!=',') {
                val.push_back(data[index]);
                index += 1;
            }
            index += 1;
            *front = new TreeNode(stoi(val));
            q.push(&((*front)->left));
            q.push(&((*front)->right));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

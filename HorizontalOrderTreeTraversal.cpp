#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val):val(val),left(NULL),right(NULL) {}
};

vector<vector<int> > horizontalOrderTraversal(TreeNode *root) {
	map<int, vector<int> > mp;
	queue<pair<TreeNode*, int> > st;
	while(root) {
		st.push({root, 0});
		mp[0].push_back(root->val);
		root = root->right;
	}
	while(!st.empty()) {
		TreeNode *curr = st.front().first;
		int index = st.front().second;
		st.pop();
		curr = curr->left;
		while(curr) {
			st.push({curr, index+1});
			mp[index+1].push_back(curr->val);
			curr = curr->right;
		}
	}
	vector<vector<int> > ans;
	for(map<int, vector<int> >::iterator it=mp.begin() ; it!=mp.end() ; ++it) {
		ans.push_back(it->second);
	}
	return ans;
	
}

int main() {
	TreeNode *A = new TreeNode(5);
	A->left = new TreeNode(4);
	A->left->right = new TreeNode(6);
	A->left->right->left = new TreeNode(8);
	A->right = new TreeNode(9);
	A->right->left = new TreeNode(10);
	vector<vector<int> > ans = horizontalOrderTraversal(A);
	for(int i=0 ; i<ans.size() ; ++i) {
		for(int j=0 ; j<ans[i].size() ; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

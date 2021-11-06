#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int data){
		val = data;
		left = nullptr;
		right = nullptr;
	}
};
TreeNode *buildTree(){
	int val;
	cin >> val;
	TreeNode *root = new TreeNode(val);
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *f = q.front();
		q.pop();
		int val1,val2;
		cin >> val1 >> val2;
		if(val1 != -1){
			f->left = new TreeNode(val1);
			q.push(f->left);
		}
		if(val2 != -1){
			f->right = new TreeNode(val2);
			q.push(f->right);
		}
	}
	return root;
}
void preorder(TreeNode *root,int d,map<int,vector<int>> &mp){
	if(!root){
		return;
	}
	mp[d].push_back(root->val);
	preorder(root->left,d-1,mp);
	preorder(root->right,d+1,mp);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int levels;
		cin >> levels;
		TreeNode *root = buildTree();
		map<int,vector<int>> mp;
		preorder(root,0,mp);
		for(auto it:mp){
			vi v = it.second;
			for(int x:v){
				cout << x << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
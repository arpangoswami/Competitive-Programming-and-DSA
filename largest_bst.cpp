#include <bits/stdc++.h>
#define int long long
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int d){
		val = d;
		left = nullptr;
		right = nullptr;
	}
};
TreeNode *buildTree(vector<int> &preorder,vector<int> &inorder,int start,int end,int &ct,unordered_map<int,int> &mp){
	if(start > end){
		return nullptr;
	}
	TreeNode *root = new TreeNode(preorder[ct]);
	ct++;
	int idx = mp[root->val];
	root->left = buildTree(preorder,inorder,start,idx-1,ct,mp);
	root->right = buildTree(preorder,inorder,idx+1,end,ct,mp);
	return root;
}
int cntNodes(TreeNode *root){
	if(!root){
		return 0;
	}
	return 1 + cntNodes(root->left) + cntNodes(root->right);
}
bool checkBST(TreeNode *root,int minV ,int maxV ,int &ans){
	if(!root){
		return true;
	}
	if(root->val < minV || root->val > maxV){
		return false;
	}
	bool f = checkBST(root->left,minV,root->val-1,ans) && checkBST(root->right,root->val+1,maxV,ans);
	if(f){
		int cd = cntNodes(root);
		ans = max(ans,cd);
		return true;
	}
	return false;
}
void postOrder(TreeNode *root,int &ans){
	if(!root){
		return;
	}
	postOrder(root->left,ans);
	postOrder(root->right,ans);
	checkBST(root,INT_MIN,INT_MAX,ans);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> inorder(n);
	vector<int> preorder(n);
	for(int i=0;i<n;i++){
		cin >> preorder[i];
	}
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> inorder[i];
		mp[inorder[i]] = i;
	}
	int ct = 0;
	TreeNode *root = buildTree(preorder,inorder,0,n-1,ct,mp);
	int ans = 0;
	postOrder(root,ans);
	cout << ans << "\n";
	return 0;
}
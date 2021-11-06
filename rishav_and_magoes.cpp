#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
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
TreeNode* buildTree(int &i,int left,int right,vector<int> &inorder,vector<int> &postorder,unordered_map<int,int> &mp){
	if(left > right){
		return nullptr;
	}
	TreeNode *root = new TreeNode(postorder[i]);
	i--;
	int idx = mp[root->val];
	root->right = buildTree(i,idx+1,right,inorder,postorder,mp);
	root->left = buildTree(i,left,idx-1,inorder,postorder,mp);
	return root;
}
bool isLeaf(TreeNode *root){
	return (!(root->left) && !(root->right));
}
void minSum(TreeNode *root,int currSum,int &minm,int &ans){
	if(!root){
		return;
	}
	if(isLeaf(root)){
		if(minm >= (currSum + root->val)){
			minm = currSum + root->val;
			ans = min(ans,root->val);
		}
		return;
	}
	minSum(root->left,currSum + root->val,minm,ans);
	minSum(root->right,currSum + root->val,minm,ans);
}
int32_t main(int32_t argc, char const* argv[]) {
// #ifndef ONLINE_JUDGE

// 	freopen("input.txt", "r", stdin);

// 	freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> input;
	int n;
	while(cin >> n){
		input.push_back(n);
	}
	int len = input.size();
	vector<int> inorder(len/2);
	vector<int> postorder(len/2);
	unordered_map<int,int> mp;
	n = len/2;
	for(int i=0;i<n;i++){
		inorder[i] = input[i];
		mp[inorder[i]] = i;
		postorder[i] = input[i+n];
	}
	int idx = n-1;
	TreeNode *root = buildTree(idx,0,n-1,inorder,postorder,mp);
	int minm = INT_MAX;
	int ans = INT_MAX;
	minSum(root,0,minm,ans);
	cout << ans << "\n";
	return 0;
}
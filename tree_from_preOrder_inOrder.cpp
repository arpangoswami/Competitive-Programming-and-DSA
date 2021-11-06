#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int data){
		val = data;
		left = nullptr;
		right = nullptr;
	}
};
void printPreOrder(TreeNode* root){
	if(!root->left && !root->right){
		cout<<"END => "<<root->val<<" <= END"<<"\n";
		return;
	}
	else if(!root->left && root->right){
		cout<<"END => "<<root->val<<" <= "<<root->right->val<<"\n";
		printPreOrder(root->right);
	}
	else if(root->left && !root->right){
		cout<<root->left->val<<" => "<<root->val<<" <= END"<<"\n";
		printPreOrder(root->left);
	}
	else{
		cout<<root->left->val<<" => "<<root->val<<" <= "<<root->right->val<<"\n";
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}
unordered_map<int,int> mp;
TreeNode* treeBuilder(vector<int> &preorder,vector<int> &inorder,int i,int j,int &toPick){
	if(i>j){
		return nullptr;
	}
	int data = preorder[toPick++];
	TreeNode* root = new TreeNode(data);
	int idx = mp[data];
	root->left = treeBuilder(preorder,inorder,i,idx-1,toPick);
	root->right = treeBuilder(preorder,inorder,idx+1,j,toPick);
	return root;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> preorder(n),inorder(n);
	for(int i=0;i<n;i++){
		cin>>preorder[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>inorder[i];
		mp[inorder[i]] = i;
	}
	int toPick = 0;
	TreeNode *root = treeBuilder(preorder,inorder,0,n-1,toPick);
	printPreOrder(root);
	return 0;
}
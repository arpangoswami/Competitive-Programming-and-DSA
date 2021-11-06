#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct TreeNode *cons(int dt){
	struct TreeNode *root = new TreeNode();
	root->data = dt;
	root->left = nullptr;
	root->right = nullptr;
	return root;
}
void inorder(TreeNode *root,vector<int> &arr,int minValue,int maxValue){
	if(!root){
		return;
	}
	if(root->data > minValue){
		inorder(root->left,arr,minValue,maxValue);
	}
	if(root->data >= minValue && root->data <= maxValue){
		arr.push_back(root->data);
	}
	if(root->data < maxValue){
		inorder(root->right,arr,minValue,maxValue);
	}
}
struct TreeNode *constructBSTInorder(vector<int> &arr,int left,int right){
	if(left > right){
		return nullptr;
	}
	int mid = (left + right)/2;
	struct TreeNode *root = cons(arr[mid]);
	root->left = constructBSTInorder(arr,left,mid-1);
	root->right = constructBSTInorder(arr,mid+1,right);
	return root;
}
struct TreeNode *TrimBinarySearchTree(struct TreeNode *root,int minValue,int maxValue){
	vector<int> inorderAfterTrim;
	inorder(root,inorderAfterTrim,minValue,maxValue);
	return constructBSTInorder(inorderAfterTrim,0,inorderAfterTrim.size() - 1);
}
void preorder(struct TreeNode *root){
	if(!root){
		return;
	}
	preorder(root->left);
	cout<<root->data<<" ";
	preorder(root->right);
}
void solveQuestion(){
	struct TreeNode *root = cons(8);
	root->left = cons(3);
	root->left->left = cons(1);
	root->left->right = cons(6);
	root->left->right->left = cons(4);
	root->left->right->right = cons(7);
	root->right = cons(10);
	root->right->right = cons(14);
	root->right->right->left = cons(13);
	root = TrimBinarySearchTree(root,5,13);
	cout<<root->data<<"\n";
	preorder(root);
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
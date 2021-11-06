#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct treeNode {
	int data;
	treeNode *left;
	treeNode *right;
	treeNode(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
void preorder(treeNode *root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
treeNode* insertNode(treeNode *root,int val){
	if(!root){
		treeNode *temp = new treeNode(val);
		return temp;
	}
	if(root->data < val){
		root->right = insertNode(root->right,val);
	}
	else if(root->data > val){
		root->left = insertNode(root->left,val);
	}
	return root;
}
void inorder(treeNode *root,int left,int right){
	if(!root){
		return;
	}
	inorder(root->left,left,right);
	if(root->data >= left && root->data <=right){
		cout<<root->data<<" ";
	}
	inorder(root->right,left,right);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int left,right;
		cin>>left>>right;
		treeNode *root = new treeNode(arr[0]);
		for(int i=1;i<n;i++){
			root = insertNode(root,arr[i]);
		}
		cout<<"# Preorder : ";
		preorder(root);
		cout<<"\n";
		cout<<"# Nodes within range are : ";
		inorder(root,left,right);
		cout<<"\n";
	}
	return 0;
}
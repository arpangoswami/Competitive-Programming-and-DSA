#include <bits/stdc++.h>
using namespace std;
struct treeNode{
	int data;
	treeNode* left;
	treeNode* right;
	treeNode(int num){
		data = num;
		left = nullptr;
		right = nullptr;
	}
};
treeNode* buildTree(){
	int num;
	cin>>num;
	treeNode* root = new treeNode(num);
	string s;
	cin>>s;
	if(s == "false"){
		root->left = nullptr;
	}else{
		root->left = buildTree();
	}
	cin>>s;
	if(s == "false"){
		root->right = nullptr;
	}else{
		root->right = buildTree();
	}
	return root;
}
// void preorder(treeNode* root){
// 	if(!root){
// 		return;
// 	}
// 	cout<<root->data<<" ";
// 	preorder(root->left);
// 	preorder(root->right);
// }
void zigzag(treeNode* root){
	queue<treeNode*> q;
	q.push(root);
	q.push(nullptr);
	int level = 0;
	stack<treeNode*> reverse;
	while(!q.empty()){
		treeNode* toPrint = q.front();
		q.pop();
		if(toPrint == nullptr){
			if(!q.empty()){
				q.push(nullptr);
			}
			while(!reverse.empty()){
				cout<<reverse.top()->data<<" ";
				reverse.pop();
			}
			cout<<"\n";
			level++;
		}else{
			if(toPrint->left){
				q.push(toPrint->left);
			}
			if(toPrint->right){
				q.push(toPrint->right);
			}
			if(level%2 == 0){
				cout<<toPrint->data<<" ";
			}else{
				reverse.push(toPrint);
			}
		}
	}
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	treeNode* root = buildTree();
	//preorder(root);
	zigzag(root);
	return 0;
}
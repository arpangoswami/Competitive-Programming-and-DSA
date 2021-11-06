/*
Given a binary tree , print its nodes from root to bottom as visible from left side of tree

Input Format
Level order input for the binary tree will be given.

Constraints
No of nodes in the tree can be less than or equal to 10^7

Output Format
A single line containing space separated integers representing the left view of the tree

Sample Input
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
Sample Output
1 2 4
Explanation
The tree looks like

             1
          /      \
       2           3
    /     \           \
   4       5           6
When viewed from the left , we would see the nodes 1,2 and 4.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct treeNode{
	int data;
	treeNode *left;
	treeNode *right;
	treeNode(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
typedef pair<int,treeNode*> pit;
treeNode *buildTree(){
	int x;
	cin>>x;
	treeNode *root = new treeNode(x);
	queue<treeNode*> q;
	q.push(root);
	while(!q.empty()){
		treeNode *temp = q.front();
		q.pop();
		cin>>x;
		if(x!=-1){
			temp->left = new treeNode(x);
			q.push(temp->left);
		}
		cin>>x;
		if(x!=-1){
			temp->right = new treeNode(x);
			q.push(temp->right);
		}
	}
	return root;
}
void printLeftView(treeNode *root,int lvl,int &max_lvl){
	if(!root){
		return;
	}
	if(lvl > max_lvl){
		cout<<root->data<<" ";
		max_lvl = lvl;
	}
	printLeftView(root->left,lvl+1,max_lvl);
	printLeftView(root->right,lvl+1,max_lvl);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	treeNode *root = buildTree();
	cout<<root->data<<" ";
	int max_lvl = 0;
	printLeftView(root,0,max_lvl);
}
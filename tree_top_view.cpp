/*Given a binary tree , print the nodes in left to right manner as visible from above the tree

Input Format
Level order input for the binary tree will be given.

Constraints
No of nodes in the tree can be less than or equal to 10^7

Output Format
A single line containing space separated integers representing the top view of the tree

Sample Input
1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
Sample Output
4 2 1 3
Explanation
The tree looks like

             1
          /      \
       2           3
    /     \       /
   4       5     6
When viewed from the top , we would see the nodes 4, 2, 1 and 3.*/
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
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	treeNode *root = buildTree();
	map<int,int> mp;
	queue<pit> q;
	q.push({0,root});
	while(!q.empty()){
		pit temp = q.front();
		q.pop();
		int dist = temp.first;
		treeNode *node = temp.second;
		if(!mp.count(dist))
			mp[dist] = node->data;
		if(node->left){
			q.push({dist-1,node->left});
		}
		if(node->right){
			q.push({dist+1,node->right});
		}
	}
	for(auto it = mp.begin();it!=mp.end();it++){
		cout<<it->second<<" ";
	}
	return 0;
}
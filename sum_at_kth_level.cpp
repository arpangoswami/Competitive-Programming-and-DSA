/*
Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

Input Format
Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.

Constraints
1 <= Nodes in tree <=1000
1<K<10

Output Format
A single line containing the sum at level K.

Sample Input
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2
Sample Output
20
Explanation
Here the tree looks like

                     1                                 Level 0
                /          \
              2              5                         Level 1
           /      \       /     \
          3       4      6        7                    Level 2
Sum at Level 2 = 3 + 4 + 6 + 7 = 20
*/
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
treeNode *buildTree(){
	int data,child;
	cin>>data>>child;
	treeNode *root = new treeNode(data);
	if(child == 2){
		root->left = buildTree();
		root->right = buildTree();
	}else if(child == 1){
		root->left = buildTree();
	}
	return root;
}
int sumAtKthLevel(treeNode *root,int k){
	if(!root){
		return 0;
	}
	if(k == 0){
		return root->data;
	}
	int l = sumAtKthLevel(root->left,k-1);
	int r = sumAtKthLevel(root->right,k-1);
	return (l+r);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	treeNode *root = buildTree();
	int k;
	cin>>k;
	cout<<sumAtKthLevel(root,k)<<"\n";
	return 0;
}
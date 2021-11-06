/*
Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. Include the current node's data also.

Input Format
The first line contains a number n showing the length of the inorder array of BST. The next line contains n integers denoting the elements of the array.

Constraints
2 ≤ N ≤ 10^3

Output Format
Print the preorder traversal of the new tree.

Sample Input
7
20 30 40 50 60 70 80
Sample Output
260 330 350 300 150 210 80
Explanation
The original tree looks like

            50             
        /        \                
      30          70
    /    \       /   \ 
  20    40      60    80
We are supposed to replace the elements by the sum of elements larger than it.
80 being the largest element remains unaffected .
70 being the second largest element gets updated to 150 (70+80)
60 becomes 210 (60 + 70 + 80)
50 becomes 260 (50 + 60 + 70 + 80)
40 becomes 300 (40 + 50 + 60 + 70 + 80)
30 becomes 330 (30 + 40 + 50 + 60 + 70 + 80)
20 becomes 350 (20 + 30 + 40 + 50 + 60 + 70 + 80)

The new tree looks like

           260             
        /        \                
     330         150
    /    \       /   \ 
  350    300   210    80
The Pre-Order traversal (Root->Left->Right) looks like :
260 330 350 300 150 210 80.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
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
treeNode *buildTree(vector<int> &arr,int left,int right){
	if(left > right){
		return nullptr;
	}
	int mid = (left + right)/2;
	treeNode *root = new treeNode(arr[mid]);
	root->left = buildTree(arr,left,mid-1);
	root->right = buildTree(arr,mid+1,right);
	return root;
}
void preorder(treeNode *root){
	if(!root){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void reversePostOrder(treeNode *root,int &cum_sum){
	if(!root){
		return;
	}
	reversePostOrder(root->right,cum_sum);
	int temp = root->data;
	root->data = root->data + cum_sum;
	cum_sum += temp;
	reversePostOrder(root->left,cum_sum);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	treeNode *root = buildTree(arr,0,n-1);
	int cum_sum = 0;
	reversePostOrder(root,cum_sum);
	preorder(root);
	return 0;
}
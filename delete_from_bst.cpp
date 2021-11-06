/*
You are given an array A1 of integers. You have to form first Binary Search tree and then you are provided another array A2. You have to delete each node from the BST which is present in the array A2. Now you have to print preorder traversal of the tree. It is assured that the elements of array A2 will be present in the tree.
Note : In case of node with 2 children, consider its inorder successor as its replacement.

Input Format
First line contains integer t as number of test cases.
Each test case contains four lines. First line contains integer n which represents the length of the array A1 and next line contains n space separated integers denoting the elements of array A1. Similarly third line contains integer m which represents the length of the array A2 and next line contains m space separated integers denoting the elements of array A2.

Constraints
1 < t < 100
1< n,m < 1000

Output Format
Print the preorder traversal of the final resultant tree.

Sample Input
1
7
5 3 2 4 7 6 8
3
2 3 5
Sample Output
6 4 7 8
Explanation
Initially the tree looks like

             5
          /      \
       3           7
    /     \      /    \
   2       4    6      8
After the deletion , the tree looks like

               6
            /     \
           4       7
                     \
                      8
We print the preorder of the final tree.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int d) {
		val = d;
		left = nullptr;
		right = nullptr;
	}
};
TreeNode* insertNode(TreeNode *root, int val) {
	if (!root) {
		TreeNode *temp = new TreeNode(val);
		return temp;
	}
	if (root->val < val) {
		root->right = insertNode(root->right, val);
	}
	else if (root->val > val) {
		root->left = insertNode(root->left, val);
	} else if (root->val == val) {
		return root;
	}
	return root;
}
TreeNode *deleteNode(TreeNode *root, int key) {
	if (!root) {
		return nullptr;
	}
	if (root->val > key) {
		root->left = deleteNode(root->left, key);
		return root;
	} else if (root->val < key) {
		root->right = deleteNode(root->right, key);
		return root;
	}
	if (!(root->left) && !(root->right)) {
		delete root;
		return nullptr;
	} else if ((root->left) && !(root->right)) {
		TreeNode *temp = root->left;
		delete root;
		return temp;
	}
	else if (!(root->left) && (root->right)) {
		TreeNode *temp = root->right;
		delete root;
		return temp;
	}  else {
		TreeNode *replace = root->right;
		while (replace->left != nullptr) {
			replace = replace->left;
		}
		root->val = replace->val;
		root->right = deleteNode(root->right, replace->val);
		return root;
	}
	root->right = deleteNode(root->right, key);
	return root;
}
void preorder(TreeNode *root) {
	if (!root) {
		return;
	}
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int x;
		cin >> x;
		TreeNode *root = new TreeNode(x);
		n--;
		while (n--) {
			cin >> x;
			root = insertNode(root, x);
		}
		cin >> n;
		while (n--) {
			cin >> x;
			root = deleteNode(root, x);
		}
		preorder(root);
		cout << endl;
	}
	return 0;
}
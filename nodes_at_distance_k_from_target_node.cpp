/*
Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available. Print 0 if no such node exist at distance k.

Input Format
The first line of input will contain an integer n. The next line will contain n integers denoting the the preorder traversal of the BT. The next line will contain n more integers denoting the inorder traversal of the BT. The next line will contain an integer T. Then T lines follow you will be given 2 integers the first one denoting the value of Node and the second one denoting the value of k.

Constraints
2 ≤ N ≤ 10^3

Output Format
On T lines print space separated desired output for each test case in sorted form

Sample Input
4
60 65 50 70
50 65 60 70
2
60 1
65 2
Sample Output
65 70
70
Explanation
The tree looks like

             60
          /      \
       65         70
     /
  50
For testcase 1 : The nodes 65 and 70 are the only ones at distance k=1 from 60.
For testcase 2 : The node 70 is at distance k=2 from 65.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() {
		val = 0;
		left = nullptr;
		right = nullptr;
	}
	TreeNode(int data) {
		val = data;
		left = nullptr;
		right = nullptr;
	}
};
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int start, int end, int &ct, unordered_map<int, int> &mp, unordered_map<int, TreeNode*> &mp2) {
	if (start > end) {
		return nullptr;
	}
	TreeNode *root = new TreeNode(preorder[ct]);
	mp2[root->val] = root;
	ct++;
	int idx = mp[root->val];
	root->left = buildTree(preorder, inorder, start, idx - 1, ct, mp, mp2);
	root->right = buildTree(preorder, inorder, idx + 1, end, ct, mp, mp2);
	return root;
}
void nodesKlevelsDown(TreeNode *root, int k, vector<int> &sol) {
	if (!root) {
		return;
	}
	if (k == 0) {
		sol.push_back(root->val);
		return;
	}
	nodesKlevelsDown(root->left, k - 1, sol);
	nodesKlevelsDown(root->right, k - 1, sol);
}
int allNodesKdistance(TreeNode *root, TreeNode *target, int k, vector<int> &sol) {
	if (!root) {
		return -1;
	}
	if (root == target) {
		nodesKlevelsDown(root, k, sol);
		return 0;
	}
	int DL = allNodesKdistance(root->left, target, k, sol);
	if (DL != -1) {
		if (DL + 1 == k) {
			sol.push_back(root->val);
		} else {
			nodesKlevelsDown(root->right, k - 2 - DL, sol);
		}
		return 1 + DL;
	}
	int DR = allNodesKdistance(root->right, target, k, sol);
	if (DR != -1) {
		if (DR + 1 == k) {
			sol.push_back(root->val);
		} else {
			nodesKlevelsDown(root->left, k - 2 - DR, sol);
		}
		return 1 + DR;
	}
	return -1;
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> preorder(n);
	vector<int> inorder(n);
	for (int i = 0; i < n; i++) {
		cin >> preorder[i];
	}
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		mp[inorder[i]] = i;
	}
	unordered_map<int, TreeNode*> mp2;
	int ct = 0;
	TreeNode *root = buildTree(preorder, inorder, 0, n - 1, ct, mp, mp2);
	int test;
	cin >> test;
	while (test--) {
		int value, k;
		cin >> value >> k;
		vector<int> sol;
		allNodesKdistance(root, mp2[value], k, sol);
		sort(sol.begin(), sol.end());
		if (sol.size()) {
			for (int x : sol) {
				cout << x << " ";
			}
			cout << "\n";
		}else{
			cout << 0 << "\n";
		}
	}
	return 0;
}
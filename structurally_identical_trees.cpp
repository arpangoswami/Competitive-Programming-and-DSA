// Given two trees check if they are structurally identically. Structurally identical trees are trees that have same structure. They may or may not have the same data though.

// Input Format
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Constraints
// 1 <= N <= 10^4

// Output Format
// Display the Boolean result

// Sample Input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// Sample Output
// true
// Explanation
// The given two trees have the exact same structure and hence we print true.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
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
treeNode *buildTree() {
	int x;
	cin >> x;
	string s;
	cin >> s;
	treeNode *root = new treeNode(x);
	if (s == "true") {
		root->left = buildTree();
	}
	cin >> s;
	if (s == "true") {
		root->right = buildTree();
	}
	return root;
}
bool preOrder(treeNode *root1, treeNode *root2) {
	if (!root1 && !root2) {
		return true;
	} else if (!root1 && root2) {
		return false;
	} else if (root1 && !root2) {
		return false;
	}
	bool flag = preOrder(root1->left, root2->left) && preOrder(root1->right, root2->right);
	return flag;
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	treeNode *root1 = buildTree();
	treeNode *root2 = buildTree();
	bool flag = preOrder(root1, root2);
	string s = flag ? "true" : "false";
	cout << s << "\n";
	return 0;
}

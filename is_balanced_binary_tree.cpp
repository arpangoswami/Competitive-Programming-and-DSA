#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pr;
struct treeNode {
	int data;
	treeNode *left;
	treeNode *right;
	int height;
	treeNode(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
		height = 1;
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
	int h1 = 0, h2 = 0;
	if (root->left) {
		h1 = root->left->height;
	}
	if (root->right) {
		h1 = root->right->height;
	}
	root->height = 1 + max(h1, h2);
	return root;
}
bool postOrder(treeNode *root) {
	if (!root) {
		return true;
	}
	bool flag = postOrder(root->left);
	flag &= postOrder(root->right);
	int h1 = 0, h2 = 0;
	if (root->left) {
		h1 = root->left->height;
	}
	if (root->right) {
		h2 = root->right->height;
	}
	int diff = abs(h1 - h2);
	return (flag && diff <= 1);
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	treeNode *root = buildTree();
	bool flag = postOrder(root);
	string s = flag ? "true" : "false";
	cout << s << "\n";
	return 0;
}
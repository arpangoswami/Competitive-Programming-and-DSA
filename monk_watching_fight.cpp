#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct treeNode {
	int data;
	treeNode* left;
	treeNode* right;
	treeNode(int num) {
		data = num;
		left = nullptr;
		right = nullptr;
	}
};
void insertNode(treeNode* root, int value) {
	if(root->data<value){
		if(!root->right){
			root->right = new treeNode(value);
			return;
		}
		else{
			insertNode(root->right,value);
		}
	}
	else{
		if(!root->left){
			root->left = new treeNode(value);
			return;
		}
		else{
			insertNode(root->left,value);
		}
	}
}
int height(treeNode* root){
	if(!root){
		return 0;
	}
	return 1+max(height(root->left),height(root->right));
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	treeNode* root = new treeNode(arr[0]);
	for (int i = 1; i < n; i++) {
		insertNode(root, arr[i]);
	}
	cout << height(root) << endl;
	return 0;
}
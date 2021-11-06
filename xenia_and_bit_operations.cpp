#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
	int level;
	int data;
	node(){
		level = -1;
		data = -1;
	}
	node(int l,int d){
		level = l;
		data = d;
	}
};
void buildTree(node *seg_tree,vector<int> &arr,int start,int end,int treeNode){
	if(start == end){
		seg_tree[treeNode].level = 0;
		seg_tree[treeNode].data = arr[start];
		return;
	}
	int mid = (start + end)/2;
	buildTree(seg_tree,arr,start,mid,2*treeNode);
	buildTree(seg_tree,arr,mid+1,end,2*treeNode+1);
	seg_tree[treeNode].level = seg_tree[2*treeNode].level + 1;
	if(seg_tree[treeNode].level % 2 == 0){
		seg_tree[treeNode].data = seg_tree[2*treeNode].data ^ seg_tree[2*treeNode+1].data;
	}else{
		seg_tree[treeNode].data = seg_tree[2*treeNode].data | seg_tree[2*treeNode+1].data;
	}
}
void updateTree(node *seg_tree,int start,int end,int treeNode,int idx,int val){
	if(start == end){
		seg_tree[treeNode].data = val;
		return;
	}
	int mid = (start + end)/2;
	if(idx > mid){
		updateTree(seg_tree,mid+1,end,2*treeNode+1,idx,val);
	}else{
		updateTree(seg_tree,start,mid,2*treeNode,idx,val);
	}
	if(seg_tree[treeNode].level % 2 == 0){
		seg_tree[treeNode].data = seg_tree[2*treeNode].data ^ seg_tree[2*treeNode+1].data;
	}else{
		seg_tree[treeNode].data = seg_tree[2*treeNode].data | seg_tree[2*treeNode+1].data;
	}
}
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int total = (1LL << n);
	vector<int> arr(total+1, 0);
	for (int i = 1; i <= total; i++) {
		cin >> arr[i];
	}
	node *seg_tree = new node[4*total]();
	buildTree(seg_tree, arr, 1, total, 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u] = v;
		updateTree(seg_tree, 1, total, 1, u, v);
		cout << seg_tree[1].data << "\n";
	}
	delete []seg_tree;
	return 0;
}
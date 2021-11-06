#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char> pii;
struct treeNode{
	int data;
	treeNode* left;
	treeNode* right;
	treeNode(int num){
		data = num;
		left = nullptr;
		right = nullptr;
	}
};
treeNode* buildTree(treeNode* root,vector<pii>* adj_list){
	for(int i=0;i<adj_list[root->data].size();i++){
		pii p = adj_list[root->data][i];
		if(p.second == 'L'){
			root->left = new treeNode(p.first);
			root->left = buildTree(root->left,adj_list);
		}else{
			root->right = new treeNode(p.first);
			root->right = buildTree(root->right,adj_list);
		}
	}
	return root;
}
bool searchInTree(treeNode* root,int val,string &path){
	if(!root){
		return false;
	}
	if(root->data == val){
		return true;
	}
	path.push_back('L');
	bool f = searchInTree(root->left,val,path);
	if(f){
		return true;
	}
	path.pop_back();
	path.push_back('R');
	f = searchInTree(root->right,val,path);
	if(f){
		return true;
	}
	path.pop_back();
	return f;
}
int traverseMirror(treeNode* curr,string &path,int idx){
	if(!curr){
		return -1;
	}
	else if(idx == path.size()){
		return curr->data;
	}
	else if(path[idx] == 'L'){
		return traverseMirror(curr->right,path,idx+1);
	}
	return traverseMirror(curr->left,path,idx+1);
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<pii> *adj_list = new vector<pii> [n+1]();
	treeNode* root= new treeNode(1);
	for(int i=0;i<(n-1);i++){
		int parent,child;
		char type;
		cin>>parent>>child>>type;
		adj_list[parent].push_back({child,type});
	}
	root = buildTree(root,adj_list);
	unordered_map<int,int> mirror_images;
	while(q--){
		int node;
		cin>>node;
		if(mirror_images.count(node)){
			cout<<mirror_images[node]<<"\n";
		}
		else{
			string path;
			searchInTree(root,node,path);
			int mirrorNode = traverseMirror(root,path,0);
			if(mirrorNode!=-1){
				mirror_images[node] = mirrorNode;
				mirror_images[mirrorNode] = node;
				cout<<mirrorNode<<"\n";
			}
			else{
				mirror_images[node] = -1;
				cout<<-1<<"\n";
			}
		}
	}
	delete []adj_list;
	return 0;
}
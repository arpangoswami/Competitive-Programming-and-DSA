#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct TreeNode{
	char data;
	unordered_map<char,int> freq_mp;
	vector<TreeNode*> children;
	TreeNode(char c){
		data = c;
		for(int i=0;i<26;i++){
			arr.push_back(0);
		}
		arr[data - 'a'] = 1;
	} 
};
TreeNode* buildTree(int node,string &s,vector<bool> &visited,unordered_map<int,TreeNode*> &lookup_table,vector<int>* adj_list){
	TreeNode* root = new TreeNode(s[node-1]);
	//cout<<"node: "<<node<<" data: "<<root->data<<endl;
	visited[node] = true;
	vector<int> all_children;
	for(int x:adj_list[node]){
		if(!visited[x]){
			all_children.push_back(x);
		}
	}
	// if(children == 1){
	// 	root->left = buildTree(lchild,s,visited,lookup_table,adj_list);
	// 	for(int i=0;i<26;i++){
	// 		root->arr[i]+=root->left->arr[i];
	// 	}
	// }
	// else if(children == 2){
	// 	root->left = buildTree(lchild,s,visited,lookup_table,adj_list);
	// 	root->right = buildTree(rchild,s,visited,lookup_table,adj_list);
	// 	for(int i=0;i<26;i++){
	// 		root->arr[i]+=(root->left->arr[i] + root->right->arr[i]);
	// 	}
	// }
	int num_child = all_children.size();
	vector<TreeNode*> child_addr;
	for(int i=0;i<children.size();i++){
		TreeNode* child = buildTree(all_children[i],s,visited,lookup_table,adj_list);
		child_addr.push_back(child);
	}
	for(int i=0;i<all_children.size();i++){
		root->children.push_back(child_addr[i]);
	}
	for(int i=0;i<all_children.size();i++){
		for(int j=0;j<26;j++){
			root->arr[j]+=root->children[i]->arr[j];
		}
	}
	lookup_table[node] = root;
	return root;
}
int main(int argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	unordered_map<int,TreeNode*> lookup_table;
	vector<int> *adj_list = new vector<int>[n+1]();
	vector<bool> visited(n+1,false);
	for(int i=1;i<=(n-1);i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	TreeNode* root = buildTree(1,s,visited,lookup_table,adj_list);
	while(q--){
		int num;
		char c;
		cin>>num>>c;
		TreeNode* ans = lookup_table[num];
		cout<<ans->arr[c-'a']<<"\n";
	}
	delete []adj_list;
	return 0;
}
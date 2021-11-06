#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct TrieNode{
	TrieNode *left;
	TrieNode *right;
	TrieNode(){
		left = nullptr;
		right = nullptr;
	}
};
void addNumber(int number,TrieNode *root){
	TrieNode *curr = root;
	for(int i=30;i>=0;i--){
		int bit = (number >> i) & 1;
		if(bit){
			if(!(curr->right)){
				curr->right = new TrieNode();
			}
			curr = curr->right;
		}else{
			if(!(curr->left)){
				curr->left = new TrieNode();
			}
			curr = curr->left;
		}
	}
}
int maxXor(int num,TrieNode *root){
	TrieNode *curr = root;
	int ans = 0;
	for(int i=30;i>=0;i--){
		int bit = (num >> i) & 1;
		if(bit){
			if(curr->left){
				curr = curr->left;
				ans += (1<<i);
			}else{
				curr = curr->right;
			}
		}else{
			if(curr->right){
				curr = curr->right;
				ans += (1<<i);
			}else{
				curr = curr->left;
			}
		}
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	TrieNode *root = new TrieNode();
	addNumber(0,root);
	int pref_xor = 0,ans = 0;
	for(int i=0;i<n;i++){
		pref_xor ^= arr[i];
		int max_xor = maxXor(pref_xor,root);
		ans = max(ans,max_xor);
		addNumber(pref_xor,root);
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
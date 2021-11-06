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
void insertValue(int val,TrieNode *root){
	TrieNode *curr = root;
	for(int i=31;i>=0;i--){
		int bit = (val >> i) & 1;
		if(bit){
			if(curr->right == nullptr){
				curr->right = new TrieNode();
			}
			curr = curr->right;
		}else{
			if(curr->left == nullptr){
				curr->left = new TrieNode();
			}
			curr = curr->left;
		}
	}
}
int maximumXORpair(int val,TrieNode *root){
	int xor_now = 0;
	TrieNode *curr = root;
	for(int i=31;i>=0;i--){
		int bit = (val >> i) & 1;
		if(bit){
			if(curr->left){
				xor_now += (1LL<<i);
				curr = curr->left;
			}else{
				curr = curr->right;
			}
		}else{
			if(curr->right){
				xor_now += (1LL<<i);
				curr = curr->right;
			}else{
				curr = curr->left;
			}
		}
	}
	return xor_now;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<int> lbest(n);
		vector<int> rbest(n);
		TrieNode *head = new TrieNode();
		int left_val = 0,right_val = 0;
		insertValue(left_val,head);
		for(int i=0;i<n;i++){
			cin >> arr[i];
			left_val ^= arr[i];
			lbest[i] = max((i == 0) ? 0 : lbest[i-1], maximumXORpair(left_val,head));
			insertValue(left_val,head);
		}
		head = new TrieNode();
		int ans = 0;
		insertValue(right_val,head);
		for(int i=n-1;i>=0;i--){
			right_val ^= arr[i];
			rbest[i] = max((i == n-1) ? 0 :rbest[i+1],maximumXORpair(right_val,head));
			insertValue(right_val,head);
			int value = rbest[i] + ((i == 0) ? INT_MIN : lbest[i-1]);
			ans = max(ans,value); 
		}
		cout << ans << "\n";
	}
	return 0;
}
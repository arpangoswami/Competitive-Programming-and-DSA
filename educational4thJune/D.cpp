#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

vector<int> tree;
string s;
void buildTree(int idx,int left,int right){
	if(left == right){
		tree[idx] = 1;
		return;
	}
	int mid = (left + right)/2;
	buildTree(2*idx,left,mid);
	buildTree(2*idx+1,mid+1,right);
	if(s[idx-1] == '1'){
		tree[idx] = tree[2*idx];
	}else if(s[idx-1] == '0'){
		tree[idx] = tree[2*idx+1];
	}else{
		tree[idx] = tree[2*idx] + tree[2*idx+1];
	}
}

void update(int idx){
	if(idx == 0){
		return;
	}
	if(s[idx-1] == '1'){
		tree[idx] = tree[2*idx];
	}else if(s[idx-1] == '0'){
		tree[idx] = tree[2*idx+1];
	}else{
		tree[idx] = tree[2*idx] + tree[2*idx+1];
	}
	update(idx/2);
}

int query(){
	return tree[1];
}

void solveQuestion(){
	int k,n;
	cin >> k;
	n = (1 << k);
	cin >> s;
	int len = s.size();
	tree.resize(2*n + 10);
	reverse(s.begin(),s.end());
	buildTree(1,1,n);
	int q;
	cin >> q;
	while(q--){
		int idx;
		char change;
		cin >> idx >> change;
		idx = n-idx;
		s[idx-1] = change;
		update(idx);
		cout << query() << "\n";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	string ans;
	int len = 0;
	while(len < n){
		ans.push_back('a');
		ans.push_back('b');
		ans.push_back('c');
		//ans.push_back('d');
		len+=3;
	}
	while(len > n){
		ans.pop_back();
		len--;
	}
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
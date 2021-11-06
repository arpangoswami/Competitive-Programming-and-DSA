#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int MOD = 998244353;
bool fairNum(int n){
	string s = to_string(n);
	for(char c:s){
		if(c == '0'){
			continue;
		}
		int dig = c - '0';
		if(n % dig != 0){
			return false;
		}
	}
	return true;
}
void solveQuestion(){
	int n;
	cin >> n;
	if(fairNum(n)){
		cout<<n<<'\n';
		return;
	}
	for(int i=n;i<=1e18;i++){
		if(fairNum(i)){
			cout<<i<<'\n';
			return;
		}
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
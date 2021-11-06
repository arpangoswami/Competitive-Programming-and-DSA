#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int n;
	cin >> n;
	if(n % 2 == 0){
		int high = n/2,low = n/2;
		int ans = (low + low)/2 + 1;
		ans *= (high + high)/2 + 1;
		cout<<ans<<'\n';
	}else{
		int high = (n + 1)/2,low = n/2;
		int ans = (low + low)/2 + 1;
		ans *= (high + high)/2 + 1;
		cout<<2 * ans<<'\n';
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int power(int x,int y){
	int ans = 1LL;
	while(y){
		if(y & 1){
			ans *= x;
		}
		x *= x;
		y>>=1;
	}
	return ans;
}
int opsReq(int a,int b,int original){
	int ans = (b-original);
	if(b > a){
		return (ans+1);
	}
	for(int i=2LL;i<=40;i++){
		if(power(b,i) > a){
			return (ans + i);
		}
	}
	return 1e9;
}
void solveQuestion(){
	int a,b;
	cin >> a >> b;
	if(a < b){
		cout<<1<<'\n';
		return;
	}
	if(a == b){
		cout<<2<<'\n';
		return;
	}
	if(b > 100){
		cout<<opsReq(a,b,b)<<'\n';
		return;
	}
	int ans = 1e9;
	for(int i=b;i<=100;i++){
		ans = min(ans,opsReq(a,i,b));
	}
	cout<<ans<<'\n';
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
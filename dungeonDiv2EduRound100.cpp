#include <bits/stdc++.h>
#define int long long
using namespace std;
void solveQuestion(){
	int a,b,c;
	cin >> a >> b >> c;
	int minm = (a + b + c)/9;
	if((a + b + c) % 9 == 0 && minm <= min({a,b,c})){
		cout<<"YES"<<'\n';
	}else{
		cout<<"NO"<<'\n';
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
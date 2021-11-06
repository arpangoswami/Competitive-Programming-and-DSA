#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	if(n < 2020){
		cout<<"NO"<<'\n';
		return;
	}
	int div = (n/2020);
	int rem = (n%2020);
	if(rem <= div){
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
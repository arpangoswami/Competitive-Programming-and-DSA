#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int mod = 1e9+7;
int solve(int m,int n){
	if(m <=0 || n <= 0){
		return 0LL;
	}
	if(m % 2 && n % 2){
		return 0LL;
	}
	if(m == 1 || n == 1){
		return 1LL;
	}
	
}
void solveQuestion(){
	int m,n;
	cin >> m >> n;
	cout<<solve(m,n)<<'\n';
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
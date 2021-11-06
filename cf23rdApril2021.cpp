#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
vector<int> quo = {1LL,10LL,100LL,1000LL,10000LL,100000LL,1000000LL,10000000LL,100000000LL,1000000000LL,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	if(n % 2050LL != 0){
		cout << -1 << '\n';
		return;
	}
	int ans = 0;
	while(n > 0){
		int div = (n/2050LL);
		int pos = lower_bound(quo.begin(),quo.end(),div) - quo.begin();
		if(quo[pos] > div){
			pos--;
		}
		int add = (div/quo[pos]);
		ans += add;
		n -= (2050LL * quo[pos] * add);
	}
	cout << ans << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
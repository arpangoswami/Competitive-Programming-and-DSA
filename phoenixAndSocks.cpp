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
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 998244353;
const int sz = 2e5+1;
int colors[sz];
int leftCnt[sz],rightCnt[sz];
void solveQuestion(){
	int n,l,r;
	cin >> n >> l >> r;
	for(int i=0;i<=n;i++){
		colors[i] = 0;
		leftCnt[i] = 0;
		rightCnt[i] = 0;
	}
	for(int i=1;i<=n;i++){
		cin >> colors[i];
		if(i <= l){
			leftCnt[colors[i]]++;
		}else{
			rightCnt[colors[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		int minFreq = min(leftCnt[i],rightCnt[i]);
		leftCnt[i] -= minFreq;
		rightCnt[i] -= minFreq;
		l -= minFreq;
		r -= minFreq;
	}
	if(l < r){
		swap(l,r);
		swap(leftCnt,rightCnt);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		int extra = l-r;
		if(extra == 0){
			break;
		}
		int change = leftCnt[i];
		change/=2;
		int sub = min(2*change,extra);
		ans += (sub/2);
		l -= sub;
	}
	ans += (l-r)/2 + (l+r)/2;
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
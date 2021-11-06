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
const int sz = 2e5+5;
int kadSum(vector<int> &arr){
	int curr = 0,maxSum = 0;
	for(int x:arr){
		curr += x;
		maxSum = max(maxSum,curr);
		curr = max(curr,0LL);
	}
	return maxSum;
}
void solveQuestion(){
	int n;
	cin >> n;
	string s,t;
	cin >> s >> t;
	int one1 = 0,one2 = 0;
	for(char c:s){
		if(c == '1'){
			one1++;
		}
	}
	for(char c:t){
		if(c == '1'){
			one2++;
		}
	}
	if(one1 != one2){
		cout << -1 << '\n';
		return;
	}
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		arr[i] = (int)s[i] - (int)t[i];
	}
	int ans = kadSum(arr);
	for(int &i:arr){
		i*=-1;
	}
	ans = max(ans,kadSum(arr));
	cout << ans << '\n';
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
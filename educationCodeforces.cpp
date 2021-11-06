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
void solveQuestion(){
	int n,c;
	cin >> n >> c;
	vi pay(n);
	for(int &i:pay){
		cin >> i;
	}
	vi course(n-1);
	for(int &i:course){
		cin >> i;
	}
	course.push_back(1e18);
	int ans = 1e18;
	int curr = 0LL,balance = 0LL;
	for(int i=0;i<n;i++){
		ans = min(ans,curr + max(0LL,(c - balance + (pay[i]-1))/pay[i]));
		int timeToEarnCourse = max(0LL,(course[i] - balance + (pay[i]-1))/pay[i]);
		curr += (timeToEarnCourse + 1LL);
		balance = max(0LL,timeToEarnCourse * pay[i] + balance - course[i]);
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
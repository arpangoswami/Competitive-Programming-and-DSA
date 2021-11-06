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
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vi ones;
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			ones.push_back(i);
		}
	}
	if(ones.empty() || ones.size() == 1){
		cout<<0<<"\n";
		return;
	}
	int groups = (ones.back()/k) - (ones[0]/k) + 1;
	vi grouping(k,0);
	for(int x:ones){
		grouping[x%k]++;
	}
	int sum = 0;
	for(int i=0;i<k;i++){
		sum += grouping[i];
	}
	int ans = n;
	for(int i=0;i<k;i++){
		int add = groups - grouping[i];
		int sub = sum - grouping[i];
		cout<<"ans: "<<ans<<" add: "<<add<<" sub: "<<sub<<"\n";
		ans = min(ans,add + sub);
	}
	cout << ans << "\n";
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
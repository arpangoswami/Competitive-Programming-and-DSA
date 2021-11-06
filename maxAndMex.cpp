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
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	int maxm = *max_element(arr.begin(),arr.end());
	set<int> present(arr.begin(),arr.end());
	if(present.size() == (maxm+1)){
		cout<<present.size() + k << '\n';
	}else{
		int ans = present.size();
		int mex = n;
		for(int i=0;i<=n;i++){
			if(present.count(i) == 0){
				mex = i;
				break;
			}
		}
		if(k > 0){
			if(present.count((mex+maxm+1)/2) == 0){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
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
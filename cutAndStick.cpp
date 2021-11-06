#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
vector<int> mp[300005];
typedef pair<int,int> pii;
void solveQuestion(){
	int n,q;
	cin >> n >> q;
	vi arr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		mp[arr[i]].push_back(i);
	}
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	while(q--){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		int len = v-u+1;
		int ans = 1;
		for(int randInt=0;randInt<40;randInt++){
			int idx = uniform_int_distribution<int>(u,v)(rng);
			int val = arr[idx];
			int occ = upper_bound(mp[val].begin(),mp[val].end(),v) - lower_bound(mp[val].begin(),mp[val].end(),u);
			ans = max(ans,2*occ-len);
			if(ans > 1){
				break;
			}
		}
		cout << ans << '\n';
	}
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
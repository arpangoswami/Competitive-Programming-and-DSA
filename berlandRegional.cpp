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
const int sz =  2e5 + 1;
vector<int> university[sz];
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> colleges(n);
	vector<int> skills(n);
	for(int i=0;i<n;i++){
		cin >> colleges[i];
		university[i].clear();
	}
	university[n].clear();
	for(int i=0;i<n;i++){
		cin >> skills[i];
	}
	for(int i=0;i<n;i++){
		university[colleges[i]].push_back(skills[i]);
	}
	for(int i=1;i<=n;i++){
		sort(university[i].begin(),university[i].end(),greater<int>());
	}
	vector<int> ans(n+1);
	for(int i=1;i<=n;i++){ 
		int N = university[i].size();
		for(int j=1;j<N;j++){
			university[i][j] += university[i][j-1];
		}
		for(int j=1;j<=N;j++){
			int pick = (N/j) * j;
			ans[j] += university[i][pick-1];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
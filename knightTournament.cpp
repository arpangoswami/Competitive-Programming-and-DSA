#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	set<int> knights;
	for(int i=1;i<=n;i++){
		knights.insert(i);
	}
	vi sol(n+1);
	while(m--){
		int l,r,winner;
		cin >> l >> r >> winner;
		auto begin = knights.lower_bound(l);
		auto end = knights.upper_bound(r);
		vector<int> losers;
		while(begin != end){
			losers.push_back(*begin);
			begin++;
		}
		for(int x:losers){
			knights.erase(x);
			sol[x] = winner;
		}
		knights.insert(winner);
		sol[winner] = 0;
	}
	for(int i=1;i<=n;i++){
		cout<<sol[i]<<" ";
	}
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
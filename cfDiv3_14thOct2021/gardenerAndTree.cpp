#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> adj_list[n];
	for(int i=0;i<(n-1);i++){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	vector<int> sizes(n);
	for(int i=0;i<n;i++){
		sizes[i] = adj_list[i].size();
	}
	vector<int> dep(n);
	queue<int> q;
	for(int i=0;i<n;i++){
		if(sizes[i] <= 1){
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x:adj_list[v]){
			if(sizes[x] <= 1){
				continue;
			}
			sizes[x]--;
			dep[x] = max(dep[x],1+dep[v]);
			if(sizes[x] == 1){
				q.push(x);
			}
		}
	}
	int ans = 0;
	for(int x:dep){
		if(x >= k){
			ans++;
		}
	}
	cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
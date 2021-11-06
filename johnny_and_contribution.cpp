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
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vector<int> adj_list[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	vi topics(n+1);
	for(int i=1;i<=n;i++){
		cin >> topics[i];
	}
	vpi nodes(n+1);
	for(int i=1;i<=n;i++){
		nodes[i] = {topics[i],i};
	}
	sort(nodes.begin(),nodes.end());
	vector<set<int>> st(n+1);
	vector<int> arr;
	for(int i=1;i<=n;i++){
		int v = nodes[i].ss,subject = nodes[i].ff;
		if(st[v].size() < (subject-1)){
			cout<<"-1\n";
			return;
		}
		if(st[v].count(subject)){
			cout<<"-1\n";
			return;
		}
		arr.push_back(v);
		for(int x:adj_list[v]){
			st[x].insert(subject);
		}
	}
	for(int x:arr){
		cout<<x<<" ";
	}
	cout<<"\n";
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
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
const int INF = 1e16;
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	map<int,int> adj_list[n];
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		if(u == v){
			continue;
		}
		if((adj_list[u].count(v) && adj_list[u][v] > w) || (!adj_list[u].count(v))){
			adj_list[u][v] = w;
		}
		if((adj_list[v].count(u) && adj_list[v][u] > w) || (!adj_list[v].count(u))){
			adj_list[v][u] = w;
		}
	}
	vector<int> dist(n,2*INF);
	vector<int> city_number(n,n+1);
	city_number[0] = 0;
	dist[0] = 0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		int v = pq.top().ss,d_v = pq.top().ff;
		pq.pop();
		if(d_v != dist[v]){
			continue;
		}
		for(auto edge:adj_list[v]){
			int to = edge.ff,wt = edge.ss;
			if(dist[to] > dist[v] + (city_number[v] + 1)*wt){
				dist[to] = dist[v] + (city_number[v] + 1)*wt;
				pq.push({dist[to],to});
				city_number[to] = min(city_number[to],1 + city_number[v]);
			}
		}
	}
	for(int x:dist){
		if(x > INF){
			cout<<"-1\n";
		}else{
			cout<<x<<"\n";
		}
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
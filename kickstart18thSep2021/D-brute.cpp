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
const int MX = 2e5;

int n,m,k;
vector<vector<int>> adj_list;
vector<int> leftP;
vector<int> rightP;
vector<int> points;
set<vector<int>> ans;
vector<bool> visited;
void allPaths(int v,int magicPoints,vector<int> &path,set<int> available){
	if(path.size() >= n*n){
		return;
	}
	if(magicPoints > k){
		return;
	}
	else if(magicPoints == k){
		vector<int> np;
		set<int> st;
		for(int x:path){
			if(!st.count(x)){
				st.insert(x);
				np.push_back(x);
			}
		}
		ans.insert(np);
		return;
	}
	visited[v] = true;
	for(int x:available){
		bool f = count(path.begin(),path.end(),x);
		if(!f && !visited[x]){
			if(leftP[x] <= magicPoints && rightP[x] >= magicPoints){
				path.push_back(x);
				for(int z:adj_list[x]){
					available.insert(z);
				}
				allPaths(x,magicPoints+points[x],path,available);
			}
			
		}
		// }else{
		// 	path.push_back(x);
		// 	allPaths(x,magicPoints,path);
		// 	path.pop_back();
		// }
		
	}
}
void solveQuestion(){
	cin >> n >> m >> k;
	adj_list.resize(n);
	for(int i=0;i<n;i++){
		adj_list[i].clear();
	}
	visited.clear();
	visited.resize(n);
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	ans.clear();
	leftP.clear();
	leftP.resize(n);
	rightP.clear();
	rightP.resize(n);
	points.clear();
	points.resize(n);
	for(int i=0;i<n;i++){
		cin >> leftP[i] >> rightP[i] >> points[i];
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	for(int i=0;i<n;i++){
		vector<int> v;
		v.push_back(i);
		visited[i] = true;
		set<int> available(adj_list[i].begin(),adj_list[i].end());
		allPaths(i,points[i],v,available);
	}
	cout << ans.size() << "\n";
}

int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}
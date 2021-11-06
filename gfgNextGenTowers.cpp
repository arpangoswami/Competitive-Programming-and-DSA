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
/*
2
4 2 3
1 2
0 3
4 3 3
0 1
1 2
2 3
*/
class dsu{
public:
	int n;
	vector<int> parent;
	vector<int> height;
	vector<int> sz;
	dsu(int _n){
		n = _n;
		parent.resize(n+1);
		height.resize(n+1,0);
		sz.resize(n+1,1);
		for(int i=0;i<=n;i++){
			parent[i] = i;
		}
	}
	int getSize(int x){
		return sz[findPar(x)];
	}
	int findPar(int x){
		if(parent[x] == x){
			return x;
		}
		int p = findPar(parent[x]);
		parent[x] = p;
		return p;
	}
	void unite(int x,int y){
		int x_par = findPar(x),y_par = findPar(y);
		if(x_par == y_par){
			return;
		}
		if(height[x_par] < height[y_par]){
			parent[x_par] = y_par;
			sz[y_par] += sz[x_par];
		}else{
			parent[y_par] = x_par;
			sz[x_par] += sz[y_par];
		}
	}
};

void solveQuestion(){
	int n,x,m;
	cin >> n >> m >> x;
	dsu d(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		d.unite(u,v);
	}
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int par = d.findPar(i);
		mp[par] = d.getSize(par);
	}
	vector<int> componentSize;
	for(auto it:mp){
		componentSize.push_back(it.second);
	}
	int ans = 0;
	int N = componentSize.size();
	// for(int x:componentSize){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	vector<vector<int>> knapSack(2,vector<int>(x+1,0));
	int prevRow = 0,currRow = 1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=x;j++){
			knapSack[currRow][j] = knapSack[currRow][j-1];
			if(componentSize[i-1] <= j){
				knapSack[currRow][j] = max(knapSack[currRow][j],knapSack[prevRow][j-componentSize[i-1]] + componentSize[i-1]);
			}
		}
		currRow ^= 1;
		prevRow ^= 1;
	}
	cout << knapSack[prevRow][x] << "\n";
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
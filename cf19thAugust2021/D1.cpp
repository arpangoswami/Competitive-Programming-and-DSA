#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
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
	int n,m1,m2;
	cin >> n >> m1 >> m2;
	dsu d1(n);
	dsu d2(n);
	for(int i=0;i<m1;i++){
		int x,y;
		cin >> x >> y;
		d1.unite(x,y);
	}
	for(int i=0;i<m2;i++){
		int x,y;
		cin >> x >> y;
		d2.unite(x,y);
	}
	vector<pii> arr;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((d1.findPar(i) != d1.findPar(j)) && (d2.findPar(i) != d2.findPar(j))){
				d1.unite(i,j);
				d2.unite(i,j);
				arr.push_back({i,j});
			}
		}
	}
	
	cout << arr.size() << "\n";
	for(pii x:arr){
		cout<<x.ff<<" "<<x.ss<<"\n";
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
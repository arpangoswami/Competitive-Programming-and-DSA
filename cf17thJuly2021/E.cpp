#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
class dsu{
public:
	int n;
	vector<int> parent;
	vector<int> height;
	dsu(int _n){
		n = _n;
		parent.resize(n+1);
		height.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i] = i;
		}
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
		}else{
			parent[y_par] = x_par;
		}
	}
};
int swapsReq(int shift,vector<int> &arr,int n){
	vector<int> afterShift(n);
	for(int i=0;i<n;i++){
		afterShift[i] = (i-shift+n)%n;
	}
	dsu d(n);
	for(int i=0;i<n;i++){
		d.unite(afterShift[i],arr[i]);
	}
	int cmp = 0;
	for(int i=0;i<n;i++){
		if(d.findPar(i) == i){
			cmp++;
		}
	}
	return (n-cmp);
}
void solveQuestion(){
	int n,m;
	cin >> n >> m;
	vi arr(n);
	for(int &x:arr){
		cin >> x;
		x--;
	}
	vector<int> offset(n);
	for(int i=0;i<n;i++){
		offset[(i - arr[i] + n)%n]++;
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(offset[i] + 2*m >= n && swapsReq(i,arr,n) <= m){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<" ";
	for(int x:ans){
		cout<<x<<" ";
	}
	cout<<"\n";
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
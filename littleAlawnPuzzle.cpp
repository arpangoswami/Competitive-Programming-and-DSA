#include <bits/stdc++.h>
#include <cstdlib>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
int power(int a, int b){int res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;}a=(a*a)%MOD;b>>=1;}return res;}
int fermat_inv(int y){return power(y,MOD-2);}
int gcd(int a, int b){return (b==0)?a:gcd(b,a%b);}
class dsu{
public:
	int n;
	vector<int> parent;
	vector<int> height;
	dsu(int _n){
		n = _n;
		parent.resize(n+1);
		height.resize(n+1);
		for(int i=1;i<=n;i++){
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
void solveQuestion(){
	int n;
	cin >> n;
	dsu d(n);
	vector<int> first(n);
	vector<int> second(n);
	for(int i=0;i<n;i++){
		cin >> first[i];
	}
	for(int i=0;i<n;i++){
		cin >> second[i];
	}
	for(int i=0;i<n;i++){
		d.unite(first[i],second[i]);
	}
	int ans = 1LL;
	for(int i=0;i<n;i++){
		if(first[i] == d.findPar(first[i])){
			ans *= 2LL;
			ans %= MOD;
		}
	}
	cout<<ans<<"\n";
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
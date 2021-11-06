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
map<vector<int>,int> mp;
int determineLastElement(int num,int n){
	vector<int> inp;
	for(int i=0;i<(n-1);i++){
		inp.push_back(1+num);
	}
	inp.push_back(1);
	if(mp.count(inp)){
		return mp[inp];
	}else{
		cout<<"? ";
		for(int x:inp){
			cout<<x<<" ";
		}
		cout<<endl;
		int val;
		cin >> val;
		return mp[inp] = val;
	}
}
int detPositionGreater(int num,int n){
	vector<int> inp;
	for(int i=0;i<(n-1);i++){
		inp.push_back(1);
	}
	inp.push_back(1+num);
	if(mp.count(inp)){
		return mp[inp];
	}else{
		cout<<"? ";
		for(int x:inp){
			cout<<x<<" ";
		}
		cout<<endl;
		int val;
		cin >> val;
		return mp[inp] = val;
	}
}
int detPositionSmaller(int num,int n){
	vector<int> inp;
	for(int i=0;i<(n-1);i++){
		inp.push_back(1+num);
	}
	inp.push_back(1);
	if(mp.count(inp)){
		return mp[inp];
	}else{
		cout<<"? ";
		for(int x:inp){
			cout<<x<<" ";
		}
		cout<<endl;
		int val;
		cin >> val;
		return mp[inp] = val;
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vi sol(n);
	sol[n-1] = n;
	for(int i=1;i<n;i++){
		if(determineLastElement(i,n) == 0){
			sol[n-1] = i;
			break;
		}
	}
	set<int> toFind;
	for(int i=1;i<=n;i++){
		if(i != sol.back()){
			toFind.insert(i);
		}
	}
	for(int x:toFind){
		if(x > sol.back()){
			int v = detPositionGreater(x-sol.back(),n);
			v--;
			sol[v] = x;
		}else{
			int v = detPositionSmaller(sol.back() - x,n);
			v--;
			sol[v] = x;
		}
	}
	cout<<"! ";
	for(int x:sol){
		cout<<x<<" ";
	}
	cout<<endl;
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
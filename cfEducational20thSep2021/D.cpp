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
void print(vector<int> &v){
	for(int x:v){
		cout<<x<<" ";
	}
	cout<<"\n";
}
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> slots[n];
	for(int i=0;i<n;i++){
		int sz;
		cin >> sz;
		slots[i].resize(sz);
		for(int j=0;j<sz;j++){
			cin >> slots[i][j];
		}
	}
	int m;
	cin >> m;
	vector<vector<int>> arr(m);
	map<vector<int>,int> banned;
	for(int i=0;i<m;i++){
		vi ban(n);
		int sum = 0;
		for(int &x:ban){
			cin >> x;
			sum += x;
		}
		banned[ban] = sum;
		arr[i] = ban;
	}
	auto isSafe = [&](vector<int> &v1){
		return !banned.count(v1);
	};
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		ans[i] = slots[i].size();
	}
	if(isSafe(ans)){
		print(ans);
		return;
	}
	int maxAns = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == 1){
				continue;
			}
			vector<int> copy = arr[i];
			copy[j]--;	
			if(isSafe(copy)){
				int val = 0;
				for(int k=0;k<n;k++){
					val += slots[k][copy[k]-1];
				}
				if(val > maxAns){
					maxAns = val;
					ans = copy;
				}
			}
		}
	}
	print(ans);
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
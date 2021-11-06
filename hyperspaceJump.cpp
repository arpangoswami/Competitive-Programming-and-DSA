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
void solveQuestion(){
	int n;
	cin >> n;
	vector<pii> arr(n);
	map<pii,int> mp;
	for(int i=0;i<n;i++){
		char c1,c2,c3,c4;
		int a,b,c;
		cin >> c1 >> a >> c2 >> b >> c3 >> c4 >> c;
		int sum = (a+b);
		int g = gcd(sum,c);
		arr[i] = {sum/g,c/g};
		mp[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		cout<<mp[{arr[i].first,arr[i].second}]<<" ";
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
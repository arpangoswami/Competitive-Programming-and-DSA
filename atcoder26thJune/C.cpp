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
	vector<pair<double,double>> arr(n);
	for(int i=0;i<n;i++){
		double x,y;
		int type;
		cin >> type >> x >> y;
		if(type == 1){
			arr[i] = {x,y};
		}else if(type == 2){
			arr[i] = {x,y-0.1};
		}else if(type == 3){
			arr[i] = {x+0.1,y};
		}else{
			arr[i] = {x+0.1,y-0.1};
		}
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	for(int i=0;i<(n-1);i++){
		double lt = arr[i].second;
		for(int j=(i+1);j<n && arr[j].first <= lt;j++){
			ans++;
		}
	}
	cout<<ans<<"\n";
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
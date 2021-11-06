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
const int INF = 2e9;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi sol(n,INF);
	vector<pii> acs(k);
	for(int i=0;i<k;i++){
		cin >> acs[i].first;
	}
	for(int i=0;i<k;i++){
		cin >> acs[i].second;
	}
	vi AC(n,INF);
	for(int i=0;i<k;i++){
		AC[acs[i].first-1] = acs[i].second;
	}
	int minTemp = INF;
	for(int i=0;i<n;i++){
		if(minTemp < INF){
			minTemp++;
		}
		minTemp = min(minTemp,AC[i]);
		sol[i] = minTemp;
	}
	for(int i=n-1;i>=0;i--){
		if(minTemp < INF){
			minTemp++;
		}
		minTemp = min(minTemp,AC[i]);
		sol[i] = min(sol[i],minTemp);
	}
	for(int x:sol){
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
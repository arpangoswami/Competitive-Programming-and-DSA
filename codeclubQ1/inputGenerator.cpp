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
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	int sz;
	cin >> sz;
	cout<<sz<<"\n";
	int upper_limit;
	cin >> upper_limit;
	for(int i=0;i<sz;i++){
		cout << (rng()%upper_limit) + 1 <<" ";
	}
	cout<<"\n";
	cin >> sz;
	cout<<sz<<"\n";
	for(int i=0;i<sz;i++){
		cout << (rng()%upper_limit) + 1 <<" ";
	}

}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	#ifndef ONLINE_JUDGE
		freopen("changeParameters.txt", "r", stdin);
		freopen("tc11.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	Boost();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
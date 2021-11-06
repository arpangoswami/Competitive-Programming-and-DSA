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
	vi arr(n+1);
	vi pref(n+1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		pref[i] = arr[i] ^ pref[i-1];
	}
	if(n > 60){
		cout<<"1\n";
		return;
	}
	int ans = 2*n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int left = pref[j]^pref[i-1];
				int right = pref[k]^pref[j];
				if(right < left){
					ans = min(ans,k-i-1);
				}
			}
		}
	}
	if(ans > n){
		cout<<"-1\n";
		return;
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
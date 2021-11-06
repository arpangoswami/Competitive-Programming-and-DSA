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
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> prMaxm(n+2),prMinm(n+2),values(n+1),suffMin(n+2),suffMax(n+2);
	for(int i=1;i<=n;i++){
		if(s[i-1] == '-'){
			values[i] = values[i-1] - 1;
		}else{
			values[i] = values[i-1] + 1;
		}
	}
	for(int i=1;i<=n;i++){
		prMaxm[i] = max(values[i],prMaxm[i-1]);
		prMinm[i] = min(values[i],prMinm[i-1]);
	}
	prMaxm[n+1] = prMaxm[n];
	prMinm[n+1] = prMinm[n];
	suffMin[n] = values[n];
	suffMax[n] = values[n];
	for(int i=n-1;i>=0;i--){
		suffMin[i] = min(suffMin[i+1],values[i]);
		suffMax[i] = max(suffMax[i+1],values[i]);
	}
	suffMin[n+1] = suffMin[n];
	suffMax[n+1] = suffMax[n];
	while(q--){
		int l,r;
		cin >> l >> r;
		int loss = values[r] - values[l-1];
		int min1 = prMinm[l-1],max1 = prMaxm[l-1];
		int max2 = suffMax[r+1] - loss, min2 = suffMin[r+1] - loss;
		cout << max(max1,max2) - min(min1,min2) + 1 << "\n"; 
	}
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
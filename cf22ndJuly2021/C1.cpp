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
	string s;
	cin >> s;
	int n = 10;
	int aBetterA = 0,bBetterA = 0,aBetterB = 0,bBetterB = 0;
	for(int i=1;i<=10;i++){
		int aShots = (i+1)/2,bShots = (i/2);
		if(i&1){
			if(s[i-1] == '1'){
				aBetterB++;
				aBetterA++;
			}else if(s[i-1] == '?'){
				aBetterA++;
			}
		}else{
			if(s[i-1] == '1'){
				bBetterB++;
				bBetterA++;
			}else if(s[i-1] == '?'){
				bBetterB++;
			}
		}
		if((5-aShots) + aBetterB < bBetterB){
			//cout<<"HERE\n";
			cout<<i<<"\n";
			return;
		}
		if((5-bShots) + bBetterA < aBetterA){
			//cout<<"THERE\n";
			cout<<i<<"\n";
			return;
		}
	}
	cout<<10<<"\n";
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
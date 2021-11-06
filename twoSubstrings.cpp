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
	int n = s.size();
	for(int i=0;i<(n-1);i++){
		if(s[i] == 'A' && s[i+1] == 'B'){
			for(int j=i+2;j<(n-1);j++){
				if(s[j] == 'B' && s[j+1] == 'A'){
					cout<<"YES\n";
					return;
				}
			}
			break;
		}
	}
	for(int i=0;i<(n-1);i++){
		if(s[i] == 'B' && s[i+1] == 'A'){
			for(int j=i+2;j<(n-1);j++){
				if(s[j] == 'A' && s[j+1] == 'B'){
					cout<<"YES\n";
					return;
				}
			}
			break;
		}
	}
	cout<<"NO\n";
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
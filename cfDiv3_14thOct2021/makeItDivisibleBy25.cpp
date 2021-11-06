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
int lastDigit(const string &s,char c){
	int n = s.size();
	for(int i=n-1;i>0;i--){
		if(s[i] == c){
			for(int j=i-1;j>=0;j--){
				if(c == '0' && (s[j] == '0' || s[j] == '5')){
					return ((n-1-i)+(i-j-1));
				}else if(c == '5' && (s[j] == '2' || s[j] == '7')){
					return ((n-1-i)+(i-j-1));
				}
			}
		}
	}
	return n+1;
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	s = to_string(n);
	int toRemove = s.size() + 1;
	toRemove = min(toRemove,lastDigit(s,'5'));
	toRemove = min(toRemove,lastDigit(s,'0'));
	cout << toRemove << "\n";
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
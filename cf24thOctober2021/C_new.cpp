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
int longestPalindrome(const string &s,char c){
	int n = s.size();
	int low = 0,high = n-1;
	int ans = 0;
	while(low < high){
		if(s[low] == s[high]){
			ans += 2;
			low++;
			high--;
		}else if(s[low] != c && s[high] != c){
			return -1;
		}else if(s[low] == c){
			low++;
		}else{
			high--;
		}
	}
	if(low == high){
		ans++;
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = -1;
	for(char c='a';c<='z';c++){
		ans = max(ans,longestPalindrome(s,c));
	}
	if(ans > 0){
		ans = (n-ans);
	}
	cout << ans << "\n";
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
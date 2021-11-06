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
	int n,p,k;
	cin >> n >> p >> k;
	string s;
	cin >> s;
	int x,y;
	cin >> x >> y;
	reverse(s.begin(),s.end());
	for(int i=1;i<p;i++){
		s.pop_back();
	}
	reverse(s.begin(),s.end());
	n = s.size();
	vector<int> gaps(k);
	for(int i=0;i<n;i++){
		if(s[i] == '0'){
			gaps[i%k]++;
		}
	}
	p = 1;
	int ans = 1e9;
	for(int i=0;i<n;i++){
		ans = min(ans,(x*gaps[i%k])+(y*i));
		if(s[i] == '0'){
			gaps[i%k]--;
		}
	}
	cout<<ans<<"\n";
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
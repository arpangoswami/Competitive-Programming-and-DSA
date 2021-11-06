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
vector<int> checkFactors(int n){
	vector<int> ans;
	for(int i=1;i*i<=n;i++){
		if(i*i == n){
			ans.push_back(i);
		}else if((n % i) == 0){
			ans.push_back(i);
			ans.push_back(n/i);
		}
	}
	return ans;
}
int solve(int period,string &s){
	vector<int> ans(period,0);
	int n = s.size();
	int sum = 0,maxm = 0;
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			ans[(i%period)]++;
			sum++;
			maxm = max(maxm,ans[(i%period)]);
		}
	}
	int on = max(0LL,(n/period) - maxm); // turn them from 0 to 1
	int off = sum - maxm; // turn the others from 1 to 0;
	return (on + off);
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for(char c:s){
		if(c == '1'){
			cnt++;
		}
	}
	if(cnt == 0){
		cout<<"1\n";
		return;
	}else if(cnt == 1){
		cout<<"0\n";
		return;
	}
	vector<int> factors = checkFactors(n);
	sort(factors.begin(),factors.end());
	int ans = cnt-1;
	for(int x:factors){
		ans = min(ans,solve(x,s));
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
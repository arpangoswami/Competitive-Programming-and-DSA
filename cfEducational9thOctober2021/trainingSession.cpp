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
void solveQuestion(){
	int n;
	cin >> n;
	vi topic(n);
	vi diff(n);
	vector<int> topicMp(n+1);
	vector<int> diffMp(n+1);
	int ans = (n*(n-1)*(n-2))/6;
	for(int i=0;i<n;i++){
		cin >> topic[i] >> diff[i];
		topicMp[topic[i]]++;
		diffMp[diff[i]]++;
	}
	int add = 0LL;
	for(int i=0;i<n;i++){
		int toAdd = (topicMp[topic[i]]-1)*(diffMp[diff[i]]-1);
		add += toAdd;
		//cout<<"toAdd: "<<toAdd<<"\n";
	}
	ans -= add;
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
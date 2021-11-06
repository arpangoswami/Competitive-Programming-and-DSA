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
string exact(int i,const string &s,int k){
	int len = i+1;
	int mul = 1;
	while(len < k){
		len *= 2;
		mul++;
	}
	int sub = 0;
	while(len > k){
		sub++;
		len--;
	}
	string ans = s.substr(0,i+1);
	//cout<<"here ans: "<<ans<<"\n";
	string copy = ans;
	for(int i=1;i<mul;i++){
		ans += copy;
		copy = ans;
	}
	for(int i=0;i<sub;i++){
		ans.pop_back();
	}
	//cout<<"mul: "<<mul<<" sub: "<<sub<<"\n";
	return ans;
}
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ans;
	//cout<<"Hello: "<<exact(0,s,16)<<"\n";
	for(int i=0;i<5000;i++){
		ans.push_back('z');
	}
	//cout<<ans<<"\n";
	for(int i=0;i<n;i++){
		string newString = exact(i,s,k);
		//cout<<"s: "<<s<<"\n";
		if(ans > newString){
			ans = newString;
		}
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
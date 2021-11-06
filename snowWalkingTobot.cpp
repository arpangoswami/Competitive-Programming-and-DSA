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
	vi freq(26);
	for(char c:s){
		freq[c-'A']++;
	}
	int vert = min(freq['U'-'A'],freq['D'-'A']);
	int hort = min(freq['R'-'A'],freq['L'-'A']);
	string ans1,ans2;
	for(int i=0;i<vert;i++){
		ans1.push_back('U');
		ans2.push_back('D');
	}
	for(int i=0;i<hort;i++){
		ans1.push_back('L');
		ans2.push_back('R');
	}
	if(ans1.size() > 0 && ans2.size() > 0 && ans1.back() == 'U' && ans2.front() == 'D'){
		cout<<2<<"\n";
		cout<<"UD\n";
		return;
	}
	if(ans1.size() > 0 && ans2.size() > 0 && ans1.back() == 'L' && ans2.front() == 'R'){
		cout<<2<<"\n";
		cout<<"LR\n";
		return;
	}
	cout<<ans1.size()+ans2.size()<<"\n";
	cout<<ans1+ans2<<"\n";
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
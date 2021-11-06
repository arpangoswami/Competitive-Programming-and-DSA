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
vector<char> let = {'R','G','B'};
char differentLetter(string &s,int i){
	for(int j=0;j<3;j++){
		if(s[i] != let[j] && s[i+1] != let[j]){
			return let[j];
		}
	}
	return 'B';
}
void solveQuestion(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cons(n);
	cons[0] = 1;
	for(int i=1;i<n;i++){
		if(s[i] == s[i-1]){
			cons[i] = 1 + cons[i-1];
		}else{
			cons[i] = 1;
		}
	}
	s.push_back('$');
	int idx = n-1;
	int ans = 0;
	while(idx >= 0){
		if(cons[idx] == 1){
			idx--;
			continue;
		}
		ans += cons[idx]/2;
		int startIdx = idx-cons[idx]+1;
		int lastIdx = startIdx + ((cons[idx]/2)*2) - 1;
		char dif = differentLetter(s,lastIdx);
		for(int i=lastIdx;i>=startIdx;i-=2){
			s[i] = dif;
		}
		idx -= cons[idx];
	}
	s.pop_back();
	cout<<ans<<"\n";
	cout<<s<<"\n";
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
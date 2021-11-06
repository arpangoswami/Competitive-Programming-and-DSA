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
	string s;
	cin >> s;
	vector<vector<char>> match(n,vector<char>(n,'#'));
	for(int i=0;i<n;i++){
		match[i][i] = 'X';
	}
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			for(int j=0;j<n;j++){
				if(match[i][j] != '#'){
					continue;
				}
				match[i][j] = '=';
				match[j][i] = '=';
			}
		}
	}
	vector<int> victories(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(match[i][j] != '#'){
				continue;
			}
			if(victories[i] <= victories[j]){
				match[i][j] = '+';
				match[j][i] = '-';
				victories[i]++;
			}else{
				match[i][j] = '-';
				match[j][i] = '+';
				victories[j]++;
			}
		}	
	}
	for(int i=0;i<n;i++){
		if((!victories[i]) && (s[i] == '2')){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	for(auto v:match){
		for(char c:v){
			cout<<c;
		}
		cout<<"\n";
	}
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
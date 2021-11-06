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
	int left = -2,right = -2;
	vector<int> pref(n);
	pref[0] = s[0] == 'a';
	for(int i=1;i<n;i++){
		pref[i] = pref[i-1] + (s[i] == 'a');
	}
	// for(int x:pref){
	// 	cout<<x<<" ";
	// }
	// cout<<"\n";
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			//cout<<"i: "<<i<<" j: "<<j<<"\n";
			int countA = pref[j];
			int length = j-i+1;
			if(i > 0){
				countA -= pref[i-1];
			}
			int countB = length - countA;
			if(countA == countB){
				cout<<(i+1)<<" "<<(j+1)<<"\n";
				return;
			}
		}
	}
	cout << -1 << " " << -1 << "\n";
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
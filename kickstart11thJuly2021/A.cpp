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
	vector<vector<int>> mat(3,vector<int>(3));
	cin >> mat[0][0] >> mat[0][1] >> mat[0][2];
	cin >> mat[1][0] >> mat[1][2];
	cin >> mat[2][0] >> mat[2][1] >> mat[2][2];
	int ans = 0;
	if(mat[0][0]+mat[0][2] == 2*mat[0][1]){
		ans++;
	}
	if(mat[0][0] + mat[2][0] == 2*mat[1][0]){
		ans++;
	}
	if(mat[0][2] + mat[2][2] == 2*mat[1][2]){
		ans++;
	}
	if(mat[2][0] + mat[2][2] == 2*mat[2][1]){
		ans++;
	}
	map<int,int> mp;
	if((mat[0][0] + mat[2][2])%2 == 0){
		mp[(mat[0][0] + mat[2][2])/2]++;
	}
	if((mat[0][2] + mat[2][0])%2 == 0){
		mp[(mat[0][2] + mat[2][0])/2]++;
	}
	if((mat[0][1] + mat[2][1])%2 == 0){
		mp[(mat[0][1] + mat[2][1])/2]++;
	}
	if((mat[1][0] + mat[1][2])%2 == 0){
		mp[(mat[1][2] + mat[1][0])/2]++;
	}
	int maxF = 0;
	for(auto it:mp){
		maxF = max(maxF,it.second);
	}
	cout<<ans+maxF<<"\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int tt = 1;
	cin >> tt;
	for(int i=1;i<=tt;i++){
		cout<<"Case #"<<i<<": ";
		solveQuestion();
	}
	return 0;
}
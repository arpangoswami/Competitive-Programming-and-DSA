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
	int m,n,i,j;
	cin >> m >> n >> i >> j;
	int ans = 0;
	int ans1 = abs(m-i) + abs(n-j) + (m+n-2) + abs(i-1) + abs(j-1);
	array<int,4> ar = {m,n,1,1};
	int ans2 = abs(1-i) + abs(n-j) + (m+n-2) + abs(i-m) + abs(1-j);
	array<int,4> ar2 = {1,n,m,1};
	if(ans1 < ans2){
		//cout<<"hi\n";
		for(int x:ar2){
			cout<<x<<" ";
		}
		cout<<"\n";
	}else{
		//cout<<"lo\n";
		for(int x:ar){
			cout<<x<<" ";
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
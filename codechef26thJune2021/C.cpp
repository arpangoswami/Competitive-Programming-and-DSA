/*
10                                                                                                                      
1 2                                                                                                                     
3 4                                                                                                                     
1 4                                                                                                                     
4 9                                                                                                                     
5 9                                                                                                                     
3 10                                                                                                                    
31 32                                                                                                                   
1 32                                                                                                                    
4 15                                                                                                                    
13 16 
*/
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
	int a,b;
	cin >> a >> b;
	int pr = 2LL;
	while(pr < b){
		pr *= 2LL;
	}
	if(pr == b){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
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
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
	int n,a,b;
	cin >> n >> a >> b;
	vi sol(n);
	sol[0] = a;
	sol[1] = b;
	for(int i=2;i<n;i++){
		sol[i] = sol[i-1] + (b-a);
	}
	int maxElement = sol.back();
	for(int i=n-1;i>1;i--){
		for(int j=0;j<i;j++){
			int diffIdx = (i-j),diff = (b-a);
			
			if((diff % diffIdx) != 0){
				continue;
			}
			int consDiff = diff/diffIdx;
			int sub = (j*consDiff);
			if(sub >= a){
				continue;
			}
			int maxEl = (a-sub)+(n-1)*consDiff;
			if(maxEl < maxElement){
				vi temp(n);
				temp[0] = (a-sub);
				for(int k=1;k<n;k++){
					temp[k] = temp[k-1] + consDiff;
				} 
				for(int k=0;k<n;k++){
					sol[k] = temp[k];
				}
				maxElement = maxEl;
			}
		}
	}
	for(int x:sol){
		cout<<x<<" ";
	}
	cout<<"\n";
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
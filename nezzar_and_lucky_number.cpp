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
	int n,d;
	cin >> n >> d;
	vector<int> input(n);
	for(int i=0;i<n;i++){
		cin >> input[i];
	}
	vector<bool> ans(n,false);
	vector<int> bag;
	int num = d;
	while(num <= 10*d){
		bag.push_back(num);
		num += 10;
	}
	vector<bool> knpsk(10*d,false);
	knpsk[0] = true;
	for(int i=1;i<10*d;i++){
		for(int j=0;j<bag.size();j++){
			if(bag[j] <= i){
				knpsk[i] = knpsk[i] || knpsk[i-bag[j]];
			}
		}
	}
	// for(bool x:knpsk){
	// 	cout<<x<<" "; 
	// }
	// cout<<"\n";
	for(int i=0;i<n;i++){
		if(input[i] >= 10*d){
			ans[i] = true;
		}else{
			ans[i] = knpsk[input[i]];
		}
	}
	for(int i=0;i<n;i++){
		if(ans[i]){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
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
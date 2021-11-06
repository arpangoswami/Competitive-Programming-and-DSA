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
	int n,k;
	cin >> n >> k;
	if(k == 0){
		cout<<"YES\n";
		cout<<"0\n";
		return;
	}
	if(k % 2 == 0){
		cout<<"NO\n";
		return;
	}
	for(int i=1;i<=60;i++){
		if((k+1) == (1LL << i)){
			cout<<"YES\n";
			cout<<i<<"\n";
			for(int j=0;j<i;j++){
				int num = (1LL << j);
				cout<<(k-num+1)<<"\n";
				k-=num;
			}
			return;
		}  
	}
	int msb = 0;
	int breakPoint = 0;
	for(int i=1;i<=60;i++){
		if((k >> i)&1){
			msb = i;
		}
	}
	int minSpace = 0;
	for(int i=msb;i>=0;i--){
		minSpace += (1LL << i);
		if(((k >> i)&1) == 0){
			breakPoint = i;
			break;
		}
	}
	if(minSpace > n){
		cout<<"NO\n";
		return;
	}
	vector<int> steps;
	int temp = k;
	for(int i=1;i<=breakPoint;i++){
		int sz = (1LL << (i-1));
		if((k >> i) & 1){
			steps.push_back(temp - sz + 1);
			temp -= (sz);
		}else{
			steps.push_back(temp+1);
			temp += (sz);
		}
		if(i == breakPoint){
			for(int j=breakPoint;j<=msb;j++){
				steps.push_back(temp - (1LL << j)+1);
				temp -= (1LL << j);
			}
		}
	}
	cout<<"YES\n";
	cout<<steps.size()<<"\n";
	for(int x:steps){
		cout<<x<<"\n";
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
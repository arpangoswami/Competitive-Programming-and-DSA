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
int prime[100001];
void pre(){
	for(int i=0;i<=100000;i++){
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i=6;i<=100000;i+=2){
		prime[i] = 0;
	}
	for(int i=3;i<=100000;i+=2){
		if(prime[i]){
			for(int j=i*i;j<=100000;j+=i){
				prime[j] = 0;
			}
		}
	}
}
void solveQuestion(){
	int n;
	cin >> n;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	int minm = *min_element(arr.begin(),arr.end());
	if(minm == 1){
		cout<<"YES\n";
		return;
	}
	vector<int> factors;
	if(n % 2 == 0 && (n/2) > 2){
		factors.push_back(n/2);
	}
	for(int i=3;i*i<=n;i++){
		if(n % i == 0){
			factors.push_back(i);
			factors.push_back(n/i);
		}
	}
	for(int x:factors){
		if(prime[x]){
			for(int i=0;i<(n/x);i++){
				if(arr[i]){
					int cnt = 0;
					for(int j=i;j<n;j+=(n/x)){
						if(arr[j]){
							cnt++;
						}
					}
					if(cnt == x){
						cout<<"YES\n";
						return;
					}
				}
			}
		}
	}
	cout<<"NO\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	pre();
	int tt = 1;
	//cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}
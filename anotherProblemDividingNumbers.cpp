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
vector<int> primes;
void pre(){
	const int N = 1e5;
	vector<int> sieve(N+1);
	fill(sieve.begin()+2,sieve.end(),1);
	for(int i=2;i<=N;i++){
		if(sieve[i]){
			primes.push_back(i);
		}
		for(auto p:primes){
			if(i * p > N){
				break;
			}
			sieve[i * p] = 0;
			if(i % p == 0){
				continue;
			}
		}
	}
}
int sumPowers(int num){
	int ans = 0;
	for(int x:primes){
		if(x * x > num){
			break;
		}
		while(num % x == 0){
			ans++;
			num /= x;
		}
	}
	if(num > 1){
		ans++;
	}
	return ans;
}
void solveQuestion(){
	int a,b,k;
	cin >> a >> b >> k;
	int pa = sumPowers(a),pb = sumPowers(b);
	if(k > (pa+pb)){
		cout<<"NO\n";
		return;
	}else if(k == 1 && pa >= 1 && pb >= 1){
		if((a % b == 0 && a > b) || (b % a == 0 && b > a)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
		return;
	} 
	cout<<"YES\n";
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	pre();
	int tt = 1;
	cin >> tt;
	while(tt-- > 0){
		solveQuestion();
	}
	return 0;
}

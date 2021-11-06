#include <bits/stdc++.h>
#define int long long
#define N 1e7
using namespace std;
bitset<10000000> sieve;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	vector<int> primes;
	sieve.set();
	primes.push_back(2);
	for(int i=3;i<=N;i+=2){
		if(sieve[i]){
			primes.push_back(i);
			for(int j=i*i;j<=N;j+=i){
				sieve[j] = 0;
			}
		}
	}
	int n;
	cin >> n;
	cout << primes[n-1];
}
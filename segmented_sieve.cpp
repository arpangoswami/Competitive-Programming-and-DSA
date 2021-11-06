/*
PRIME1 - Prime Generator
#number-theory
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10).
 In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
Warning: large Input/Output data, be careful with certain languages (though most should be OK if the algorithm is well designed)
Information
After cluster change, please consider PRINT as a more challenging problem.
*/
#include <bits/stdc++.h>
#define int long long
#define N 1e5
using namespace std;
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin>>test;
	vector<int> primes;
	vector<bool> sieve(N+1,true);
	primes.push_back(2);
	for(int i=3;i<=N;i+=2){
		if(sieve[i]){
			primes.push_back(i);
			for(int j=i*i;j<=N;j+=i){
				sieve[j] = false;
			}
		}
	}
	while(test--){
		int m,n;
		cin >> m >> n;
		vector<bool> segment(n-m+1,true);
		for(int x:primes){
			if(x * x > n){
				break;
			}
			int start = (m / x) * x;
			if(start < m){
				start += x;
			}
			if(start == x){
				start += x;
			}
			for(int i=start;i<=n;i+=x){
				segment[i-m] = false;
			}
		}
		for(int i=m;i<=n;i++){
			if(segment[i-m] && i!=1){
				cout << i << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}
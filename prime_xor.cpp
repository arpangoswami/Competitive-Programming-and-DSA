/*Penny has an array of  integers, . She wants to find the number of unique multisets she can form using elements from the array such that the bitwise XOR of all the elements of the multiset is a prime number. Recall that a multiset is a set which can contain duplicate elements.

Given  queries where each query consists of an array of integers, can you help Penny find and print the number of valid multisets for each array? As these values can be quite large, modulo each answer by  before printing it on a new line.

Input Format

The first line contains a single integer, , denoting the number of queries. The  subsequent lines describe each query in the following format:

The first line contains a single integer, , denoting the number of integers in the array.
The second line contains  space-separated integers describing the respective values of .
Constraints

Output Format

On a new line for each query, print a single integer denoting the number of unique multisets Penny can construct using numbers from the array such that the bitwise XOR of all the multiset's elements is prime. As this value is quite large, your answer must be modulo .

Sample Input

1   
3   
3511 3671 4153  
Sample Output

4
Explanation

The valid multisets are:

 is prime.
 is prime.
 is prime.
, which is prime.
Because there are four valid multisets, we print the value of  on a new line.*/
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
long long dp[2][8192];
bool sieve[8192];
int mod = 1e9 + 7;
void solveQuestion(){
	int n;
	cin >> n;
	vector<int> freq(4502,0);
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		freq[tmp]++;
	}
	memset(dp,0,sizeof(dp));
	int flag = 1;
	dp[0][0] = 1;
	for(int i=3500;i<=4500;i++){
		int cnt = freq[i];
		for(int j=0;j<=8191;j++){
			if(cnt > 0)
				dp[flag][j] = ((dp[1-flag][j] * ((cnt/2) + 1))%mod + (dp[1-flag][j^i] * ((cnt+1)/2))%mod)%mod;
			else{
				dp[flag][j] = dp[1-flag][j];
			}
		}
		flag = 1-flag;
	}
	int ans = 0;
	for(int i=1;i<=8191;i++){
		if(sieve[i] == true){
			ans =(ans + dp[1-flag][i])%mod;
		}
	}
	cout<<ans<<"\n";
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	for(int i=0;i<=8191;i++){
		sieve[i] = true;
	}
	sieve[0] = false;
	sieve[1] = false;
	for(int i=4;i<=8191;i+=2){
		sieve[i] = false;
	}
	for(int i=3;i<=8191;i+=2){
		if(i*i > 8191){
			break;
		}
		if(sieve[i]){
			for(int j=i*i;j<=8191;j+=i){
				sieve[j] = false;
			}
		}
	}
	while(test--){
		solveQuestion();
	}
	return 0;
}
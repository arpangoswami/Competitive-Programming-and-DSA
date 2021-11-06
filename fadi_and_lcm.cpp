/*C. Fadi and LCM
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Today, Osama gave Fadi an integer X, and Fadi was wondering 
about the minimum possible value of max(a,b) such that LCM(a,b) equals X. Both a and b should be positive integers.

LCM(a,b) is the smallest positive integer that is divisible by both a and b. For example, LCM(6,8)=24, LCM(4,12)=12, LCM(2,3)=6.

Of course, Fadi immediately knew the answer. Can you be just like Fadi and find any such pair?

Input
The first and only line contains an integer X (1≤X≤1012).

Output
Print two positive integers, a and b, such that the value of max(a,b) is minimum possible 
and LCM(a,b) equals X. If there are several possible such pairs, you can print any.*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
vi factors(int n){
	int i=1;
	vi sol;
	while(i*i<=n){
		if(n % i == 0){
			sol.push_back(i);
		}
		i++;
	}
	return sol;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> ft = factors(n);
	int sz = ft.size();
	int max_num = n,other_num = 1;
	for(int i=0;i<sz;i++){
		int val = ft[i];
		int other_val = n/val;
		if(__gcd(val,other_val) == 1){
			other_num = val;
			max_num = other_val;
		}
	}
	cout << other_num << " " << max_num << "\n";
	return 0;
}
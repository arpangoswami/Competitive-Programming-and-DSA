/*
B. Divide and Sum
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given an array a of length 2n. Consider a partition of array a into two subsequences p and q of length n each (each element of array a should be in exactly one subsequence: either in p or in q).

Let's sort p in non-decreasing order, and q in non-increasing order, we can denote the sorted versions by x and y, respectively. Then the cost of a partition is defined as f(p,q)=∑ni=1|xi−yi|.

Find the sum of f(p,q) over all correct partitions of array a. Since the answer might be too big, print its remainder modulo 998244353.

Input
The first line contains a single integer n (1≤n≤150000).

The second line contains 2n integers a1,a2,…,a2n (1≤ai≤109) — elements of array a.

Output
Print one integer — the answer to the problem, modulo 998244353.

Examples
inputCopy
1
1 4
outputCopy
6
inputCopy
2
2 1 2 1
outputCopy
12
inputCopy
3
2 2 2 2 2 2
outputCopy
0
inputCopy
5
13 8 35 94 9284 34 54 69 123 846
outputCopy
2588544
Note
Two partitions of an array are considered different if the sets of indices of elements included in the subsequence p are different.

In the first example, there are two correct partitions of the array a:

p=[1], q=[4], then x=[1], y=[4], f(p,q)=|1−4|=3;
p=[4], q=[1], then x=[4], y=[1], f(p,q)=|4−1|=3.
In the second example, there are six valid partitions of the array a:

p=[2,1], q=[2,1] (elements with indices 1 and 2 in the original array are selected in the subsequence p);
p=[2,2], q=[1,1];
p=[2,1], q=[1,2] (elements with indices 1 and 4 are selected in the subsequence p);
p=[1,2], q=[2,1];
p=[1,1], q=[2,2];
p=[2,1], q=[2,1] (elements with indices 3 and 4 are selected in the subsequence p).

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int mod = 998244353;
vector<int> fact(3e5+1);
int binPow(int x,int y){
	int ans = 1;
	int mul = x;
	while(y){
		if(y & 1){
			ans = (ans * mul)%mod;
		}
		mul = (mul * mul)%mod;
		y >>= 1LL;
	}
	return ans;
}
int ferm_inv(int x){
	return binPow(x,mod-2);
}
int nCr(int n,int r){
	int ans = fact[n];
	int multiply = ferm_inv((fact[r] * fact[n-r])%mod);
	ans = (ans * multiply)%mod;
	return ans;
}
void pre(){
	fact[0] = 1;
	for(int i=1;i<=3e5;i++){
		fact[i] = i * fact[i-1];
		fact[i] %= mod;
	}
}
void solveQuestion(){
	pre();
	int n;
	cin >> n;
	vector<int> arr(2*n);
	for(int i=0;i<2*n;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += (arr[2*n-i-1] - arr[i]);
		ans %= mod;
	}
	int ways = nCr(2*n,n);
	ans = (ans * ways)%mod;
	cout<<ans;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
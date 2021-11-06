/*
F. Equalize the Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp was gifted an array a of length n. Polycarp considers an array beautiful if there exists a number C, such that each number in the array occurs either zero or C times. Polycarp wants to remove some elements from the array a to make it beautiful.

For example, if n=6 and a=[1,3,2,1,4,2], then the following options are possible to make the array a array beautiful:

Polycarp removes elements at positions 2 and 5, array a becomes equal to [1,2,1,2];
Polycarp removes elements at positions 1 and 6, array a becomes equal to [3,2,1,4];
Polycarp removes elements at positions 1,2 and 6, array a becomes equal to [2,1,4];
Help Polycarp determine the minimum number of elements to remove from the array a to make it beautiful.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The first line of each test case consists of one integer n (1≤n≤2⋅105) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — array a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output one integer — the minimum number of elements that Polycarp has to remove from the array a to make it beautiful.

Example
inputCopy
3
6
1 3 2 1 4 2
4
100 100 4 100
8
1 2 3 3 3 2 6 6
outputCopy
2
1
2

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
inline int calSum(vector<int> &arr,int low,int high){
	if(low > high){
		return 0;
	}
	if(low > 0){
		return arr[high] - arr[low-1];
	}
	return arr[high];
}
int check(vector<int> &pref,vector<int> &freq,int minFreq,int maxFreq,int n,int inf){
	int ans = inf;
	for(int i=minFreq;i<=maxFreq;i++){
		int temp = 0;
		auto it = lower_bound(freq.begin(),freq.end(),i);
		if(it != freq.begin()){
			it--;
			int idx = it - freq.begin();
			temp += calSum(pref,0,idx);
		}
		it = upper_bound(freq.begin(),freq.end(),i);
		if(it != freq.end()){
			int idx = it - freq.begin();
			int higher = (calSum(pref,idx,n-1) - (n-idx)*i);
			temp += higher;
		}
		ans = min(ans,temp);
	}
	return ans;
}
void solveQuestion(){
	int n;
	cin >> n;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		mp[v]++;
	}
	int N = mp.size();
	vector<int> freq(N);
	int ptr = 0;
	for(auto it:mp){
		freq[ptr++] = it.second;
	}
	sort(freq.begin(),freq.end());
	vector<int> pref(N);
	int maxm = freq[N-1],minm = freq[0];
	pref[0] = freq[0];
	for(int i=1;i<N;i++){
		pref[i] = freq[i] + pref[i-1];
	}
	int ans = check(pref,freq,minm,maxm,N,n);
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
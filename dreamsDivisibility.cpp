/*
Every night, Mario dreams of divisibility problems. In one such dream, Mario is given an array a of length n, and a number k. He performs as many operations as he wants to this array; in the end, he wants to make every element divisible by k.

In a single operation, Mario selects two indices i and j (in particular, he can choose i=j), and does a[i]=a[i]+a[j].

Help Mario decide if he can make everything divisible by k eventually, thus ending his dream.
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int &i:arr){
		cin >> i;
	}
	while(k % 2 == 0){
		k/=2;
	}
	bool f = true;
	for(int i:arr){
		if(i % k){
			f = false;
		}
	}
	string ans = f ? "YES" : "NO";
	cout<<ans<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
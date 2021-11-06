#pragma GCC optimize(2)
#pragma GCC optimize(3)   
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<cstdlib>
#define int long long
#define ff first
#define ss second
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int askQuery(int l,int r){
	cout << "? "<<l<<" "<<r<<endl;
	int sum;
	cin >> sum;
	return sum;
}
void solveQuestion(){
	int n,t;
	cin >> n >> t;
	int k;
	cin >> k;
	int zeros = 0;
	int left = 1,right = n;
	while(left < right){
		int mid = (left + right)/2;
		int sum = askQuery(left,mid);
		int zeroQuery = ((mid-left+1) - sum);
		if((zeros + zeroQuery)< k){
			zeros += zeroQuery;
			left = mid+1;
		}else{
			right = mid;
		}
	}
	cout << "! "<<left << endl;
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
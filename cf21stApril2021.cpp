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
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	vi arr(n);
	for(int &i:arr){
		cin >> i;
	}
	for(int i=0;i<(n-1)&&k;){
		while(k > 0 && arr[i] > 0){
			arr[i]--;
			arr.back()++;
			k--;
		}
		if(arr[i] == 0){
			i++;
		}else if(k == 0){
			break;
		}
	}
	for(int x:arr){
		cout << x << " ";
	}
	cout << '\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//pre();
	int test = 1;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
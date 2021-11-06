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
	int n;
	cin >> n;
	vi arr(2*n);
	for(int &i:arr){
		cin >> i;
	}
	sort(arr.begin(),arr.end());
	for(int i=1;i<(2*n);i+=2){
		if(arr[i] % 2 == 1 || arr[i] != arr[i-1]){
			cout << "NO" << '\n';
			return;
		}
	}
	if(arr.back() % (2*n) != 0){
		cout << "NO" << '\n';
		return;
	}
	vi dist(n+1);
	for(int i=0;i<2*n;i+=2){
		dist[((i/2) + 1)] = arr[i];
	}
	vi coeff(n+1);
	int sum = (arr.back())/(2*n);
	for(int i=2;i<=n;i++){
		int mul = (i-1)*2;
		if((dist[i] - dist[i-1]) % mul != 0){
			cout << "NO" << '\n';
			return;
		}else{
			coeff[i] = (dist[i] - dist[i-1]) / mul;
		}
	}
	int sm = 0;
	for(int i=2;i<=n;i++){
		sm += coeff[i];
	}
	coeff[1] = sum - sm;
	for(int i=1;i<=n;i++){
		if(coeff[i] <= 0){
			cout << "NO" << '\n';
			return;
		}

	}
	cout << "YES" << '\n';
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
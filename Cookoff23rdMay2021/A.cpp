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
inline int getValue(int i,int j){
	int diag = (i+j);
	return (diag*(diag+1))/2 + (i+1);
}
void solveQuestion(){
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--,y1--,x2--,y2--;
	int ans = 0;
	for(int i=x1;i<=x2;i++){
		ans += getValue(i,y1);
	} 
	for(int j=y1+1;j<=y2;j++){
		ans += getValue(x2,j);
	}
	cout << ans << "\n";
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
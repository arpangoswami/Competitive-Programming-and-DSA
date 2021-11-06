#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n;
vi arr;
int solve(int i,int OR){
	if(i == n){
		return OR;
	}
	return min(solve(i+1,OR | arr[i]),(OR | arr[i]) ^ solve(i+1,0));
}
void solveQuestion(){
	cin >> n;
	arr.resize(n);
	for(int &i:arr){
		cin >> i;
	}
	cout << solve(0,0);
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
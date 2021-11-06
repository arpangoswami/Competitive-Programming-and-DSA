#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int sumOfDigits(int val){
	if(val == 0){
		return val;
	}
	return val % 10 + sumOfDigits(val/10);
}
void solveQuestion(){
	int n;
	cin >> n;
	while(__gcd(n,sumOfDigits(n)) == 1){
		n++;
	}
	cout << n << '\n';
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
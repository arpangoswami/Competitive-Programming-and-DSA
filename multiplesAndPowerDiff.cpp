#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int power(int x,int y){
	int ans = 1LL;
	while(y){
		if(y & 1){
			ans *= x;
		}
		x *= x;
		y>>=1;
	}
	return ans;
}
void solveQuestion(){
	
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
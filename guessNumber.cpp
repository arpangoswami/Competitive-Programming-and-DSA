#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> squares(1001);
void solveQuestion(){
	for(int i=1;i<=1000;i++){
		cout << i * i << endl;
		int v;
		cin >> v;
		if(v){
			return;
		}
	}
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
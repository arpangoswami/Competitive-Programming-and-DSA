#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	if(n % 2){
		cout<<"YES"<<'\n';
		return;
	}
	while(n % 2 == 0){
		n/=2;
	}
	if(n == 1){
		cout<<"NO"<<'\n';
	}else{
		cout<<"YES"<<'\n';
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
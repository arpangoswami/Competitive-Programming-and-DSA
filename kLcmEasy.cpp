#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	if(n % 4 == 0){
		cout << (n/4) << " " << (n/4) << " " << (n/2) << '\n';
	}else if(n % 2 == 0){
		cout << 2 << " " << (n-1)/2 << " " << (n-1)/2 << '\n';
	}else{
		cout << 1 << " " << (n/2) << " " << (n/2) << '\n';
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
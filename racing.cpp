#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int x,r,m;
	cin >> x >> r >> m;
	r *= 60;
	m *= 60;
	if(m < r){
		cout << "NO" << '\n';
		return;
	}
	if(x >= r){
		cout << "YES" << '\n';
		return;
	}
	int rem = (r-x);
	if((x + 2*rem) <= m){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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
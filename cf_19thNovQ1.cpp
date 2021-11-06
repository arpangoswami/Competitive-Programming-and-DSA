#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int x,y;
	cin >> x >> y;
	int moves = 2*min(x,y);
	if(x == y){
		cout<<moves<<'\n';
		return;
	}
	int extra = max(x,y) - min(x,y);
	moves += 2*(extra - 1) + 1;
	cout<<moves<<'\n';
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
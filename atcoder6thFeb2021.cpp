#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int v,t,s,d;
	cin >> v >> t >> s >> d;
	int dx = v*t;
	int dx2 = v*s;
	if(d > dx2 || d < dx){
		cout<<"Yes";
	}else{
		cout<<"N";
	}
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
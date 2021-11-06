#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n;
	cin >> n;
	if(n == 2 || n == 3){
		cout<<"NO SOLUTION"<<"\n";
		return;
	}
	for(int i=2;i<=n;i+=2){
		cout<<i<<" ";
	}
	for(int i=1;i<=n;i+=2){
		cout<<i<<" ";
	}
}
int32_t main(int32_t argc,char const* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test = 1;
	//cin>>test;
	while(test--){
		solveQuestion();
	}
	return 0;
}
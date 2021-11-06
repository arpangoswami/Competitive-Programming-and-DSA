#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solveQuestion(){
	int n,k;
	cin >> n >> k;
	int pt = n;
	int ans = 0;
	if(k >= n){
		cout<<(k-n)<<"\n";
		return;
	}
	int val = n-k;
	if(val%2 == 0){
		cout<<0<<"\n";
	}else{
		cout<<1<<"\n";
	}
	
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